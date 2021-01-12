#include "main.h"
using namespace Eigen;


#include "main.h"

void mavlink_dcm_to_euler(const double dcm[3][3], float *roll, float *pitch, float *yaw)
{
	float phi, theta, psi;
	theta = asin(-dcm[2][0]);

	if (fabsf(theta - (float)M_PI_2) < 1.0e-3f)
	{
		phi = 0.0f;
		psi = (atan2f(dcm[1][2] - dcm[0][1],
					  dcm[0][2] + dcm[1][1]) +
			   phi);
	}
	else if (fabsf(theta + (float)M_PI_2) < 1.0e-3f)
	{
		phi = 0.0f;
		psi = atan2f(dcm[1][2] - dcm[0][1],
					 dcm[0][2] + dcm[1][1] - phi);
	}
	else
	{
		phi = atan2f(dcm[2][1], dcm[2][2]);
		psi = atan2f(dcm[1][0], dcm[0][0]);
	}

	*roll = phi;
	*pitch = theta;
	*yaw = psi;
}


#ifdef PCL_OPEN

void ICP_test(void)
{
	
	pcl::PointCloud<pcl::PointXYZ>::Ptr souce_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("3-2.pcd", *souce_cloud);
	int pnt_size = souce_cloud->size();
	int layer_num = 10;
	float h_step = 5;

	
	pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	input_cloud->width = pnt_size;
	input_cloud->height =  layer_num;
	input_cloud->is_dense = true;
	input_cloud->points.resize(input_cloud->width * input_cloud->height);
	
	for (int i = 0; i < layer_num; i++)
	{
		for (int j = 0; j < pnt_size; j++)
		{
			//each matrixXf
			input_cloud->points[i * pnt_size + j].x = souce_cloud->points[j].x/1000;
			input_cloud->points[i * pnt_size + j].y = souce_cloud->points[j].y/1000;
			input_cloud->points[i * pnt_size + j].z = i * h_step;
		}
	}
			
	pcl::io::savePCDFileASCII("multilayers.pcd", *input_cloud);
}
#endif
void ICP_match(void)
{
#ifdef PCL_OPEN	
	float noise[2] ={0,0};
	pcl::PointCloud<pcl::PointXYZ>::Ptr souce_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("3-2.pcd", *souce_cloud);

	

	
	pcl::PointCloud<pcl::PointXYZ>::Ptr target_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("multilayers.pcd", *target_cloud);

	#if 0
	int pnt_size = souce_cloud->size();
	for (int j = 0; j < pnt_size; j++)
	{
		//each matrixXf
		souce_cloud->points[j].x = target_cloud->points[j].x + noise[0];
		souce_cloud->points[j].y = target_cloud->points[j].y + noise[1];
		//souce_cloud->points[j].z = 20;
	}
	#endif
	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
	
	icp.setMaximumIterations(50);

	icp.setInputSource(souce_cloud);
	icp.setInputTarget(target_cloud);


	pcl::PointCloud<pcl::PointXYZ> Final;
	icp.align(Final); 
	pcl::Registration<pcl::PointXYZ, pcl::PointXYZ, float>::Matrix4 matrix;
	matrix = icp.getFinalTransformation();
	std::cout << matrix << std::endl;
	

	double dcm[3][3] = {0};
	float roll, pitch, yaw = 0.0;
	for (int i = 0; i < 3; i++)
	{
		dcm[i][0] = matrix(i, 0);
		dcm[i][1] = matrix(i, 1);
		dcm[i][2] = matrix(i, 2);
	}
	
	mavlink_dcm_to_euler(dcm, &roll, &pitch, &yaw);
	printf("rotatex=%lf\n", roll);
	printf("rotatey=%lf\n", pitch);
	printf("rotatez=%lf\n", yaw);
#endif
}




