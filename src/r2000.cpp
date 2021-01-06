#include "main.h"

using namespace std;
using namespace pepperl_fuchs;
mutex mute;
char strbuffer[300000];
int position = 0;
#define CONFIG11x
#define READ_FROM_SENSOR
const double pi = acos(-1.0);
MatrixXf m(8400, 3);
R2000::R2000()
{
	updateParams();
	count = 0;
	raw_data_file_idx = 0;
	indentif_ts = 0;
	update = false;

#ifndef READ_FROM_SENSOR
	read_r2000_scan_data_from_file();
#endif
}

R2000::~R2000() {}

void R2000::updateParams()
{
}

#define CYC_BUF_EXT_ANGLE 12.0f

bool R2000::init(void)
{
	std::cout << "Connecting to scanner at " << param->r2000_sens_ip << " ... ";
	if (driver.connect(param->r2000_sens_ip, 80))
		std::cout << "OK" << std::endl;
	else
	{
		std::cout << "FAILED!" << std::endl;
		std::cerr << "Connection to scanner at " << param->r2000_sens_ip << " failed!" << std::endl;
		return false;
	}

	driver.setScanFrequency(param->r2000_sens_smp_frq);
	driver.setSamplesPerScan(param->r2000_sens_smp_cnt);
	auto params = driver.getParameters();

	if (driver.startCapturingUDP())
		std::cout << "OK" << std::endl;
	else
	{
		std::cout << "FAILED!" << std::endl;
		return false;
	}
	return true;
}
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

void R2000::NavStart(void)
{
#ifdef READ_FROM_SENSOR
	while (false == init())
	{
		cout << "SENSOR INIT FAIL" << endl;
		usleep(100000);
	}
#endif
	cout << "SENSOR INIT SUCCESS" << endl;

	inited = true;
	count = 5;
	while (1)
	{
		usleep(20000); //2->10
		driver.setSamplesPerScan(8400);
		while (1)
		{
			if (sample(8400) == 0)
			{
				break;
			}
		}

		usleep(20000); //2->10
		driver.setSamplesPerScan(7200);
		while (1)
		{
			if (sample(7200) == 0)
			{
				break;
			}
		}
	}
}

vector<MatrixXf> vdatalist;
void R2000::ICP(void)
{
	while (true)
	{
		//cout << "thread icp !vdatalist.size()=%d" << vdatalist.size() << endl;
		if (vdatalist.size() == numberscan)
		{
			cout << "thread icp vdatalist.size()=!!%d!!" << vdatalist.size() << endl;
			pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud(new pcl::PointCloud<pcl::PointXYZ>);
			input_cloud->width = 8400 *count + 7200 * count;
			input_cloud->height = 1;
			input_cloud->is_dense = false;
			input_cloud->points.resize(input_cloud->width * input_cloud->height);
			for (int i = 0; i < numberscan / 2; i++)
			{
				for (int j = 0; j < 8400; j++)
				{
					//each matrixXf
					input_cloud->points[i * 8400 + j].x = vdatalist[i](j, 0);
					input_cloud->points[i * 8400 + j].y = vdatalist[i](j, 1);
					input_cloud->points[i * 8400 + j].z = 0;
				}
			}
			for (int i = numberscan / 2; i < numberscan; i++)
			{
				for (int j = 0; j < 7200; j++)
				{
					//each matrixXf
					input_cloud->points[i * 7200 + j].x = vdatalist[i](j, 0);
					input_cloud->points[i * 7200 + j].y = vdatalist[i](j, 1);
					input_cloud->points[i * 7200 + j].z = 0;
				}
			}
			pcl::io::savePCDFileASCII("input_cloud.pcd", *input_cloud);
			sleep(50);
			//cload icp
			pcl::PointCloud<pcl::PointXYZ>::Ptr target_cloud(new pcl::PointCloud<pcl::PointXYZ>);

			if (pcl::io::loadPCDFile<pcl::PointXYZ>("r2000_1.pcd", *target_cloud) == -1) //*打开点云文件
				printf("load failed\n");
			// if (pcl::io::loadPCDFile<pcl::PointXYZ>("r2000_2.pcd", *input_cloud) == -1) //*打开点云文件
			// 	printf("load failed\n");

			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered1(new pcl::PointCloud<pcl::PointXYZ>);

			// Fill in the cloud data

			// std::cerr << "Cloud before filtering: " << std::endl;
			// std::cerr << *target_cloud << std::endl;

			// Create the filtering object
			pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
			sor.setInputCloud(target_cloud);
			sor.setMeanK(20);
			sor.setStddevMulThresh(0.01);
			sor.setNegative(true);
			sor.filter(*cloud_filtered);

			// std::cerr << "target_cloud after filtering: " << std::endl;
			// std::cerr << *cloud_filtered << std::endl;

			

			pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor1;
			sor.setInputCloud(input_cloud);
			sor.setMeanK(20);
			sor.setStddevMulThresh(0.01);
			sor.setNegative(true);
			sor.filter(*cloud_filtered1);

			// std::cerr << "input_cloud after filtering: " << std::endl;
			// std::cerr << *cloud_filtered1 << std::endl;

			// pcl::io::savePCDFileASCII("cloud_filtered1.pcd", *cloud_filtered1);

			// 创建IterativeClosestPoint的实例
			// setInputSource将target_cloud作为输入点云
			// setInputTarget将平移后的input_cloud作为目标点云
			pcl::Registration<pcl::PointXYZ, pcl::PointXYZ, float>::Matrix4 matrix1;

			// cout<<MatchCloud(5, input_cloud, target_cloud,matrix1)<<endl;
			// cout << MatchCloud(20, input_cloud, target_cloud, matrix1) << endl;
			// cout << MatchCloud(50, input_cloud, target_cloud, matrix1) << endl;
			// cout << MatchCloud(100, input_cloud, target_cloud, matrix1) << endl;

			pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;

			icp.setMaximumIterations(50);
			// Setting maximum step size for More-Thuente line search.

			icp.setInputSource(cloud_filtered);
			icp.setInputTarget(cloud_filtered1);

			// 创建一个 pcl::PointCloud<pcl::PointXYZ>实例 Final 对象,存储配准变换后的源点云,
			// 应用 ICP 算法后, IterativeClosestPoint 能够保存结果点云集,如果这两个点云匹配正确的话
			// （即仅对其中一个应用某种刚体变换，就可以得到两个在同一坐标系下相同的点云）,那么 icp. hasConverged()= 1 (true),
			// 然后会输出最终变换矩阵的匹配分数和变换矩阵等信息。
			pcl::PointCloud<pcl::PointXYZ>
				Final;
			icp.align(Final); // double dcm[3][3] = {0};
			pcl::Registration<pcl::PointXYZ, pcl::PointXYZ, float>::Matrix4 matrix;
			matrix = icp.getFinalTransformation();
			std::cout << matrix << std::endl;

			pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud(new pcl::PointCloud<pcl::PointXYZ>());
			// pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud1 (new pcl::PointCloud<pcl::PointXYZ> ());

			// pcl::transformPointCloud(*cloud_filtered, *transformed_cloud, matrix);
			// pcl::transformPointCloud (*input_cloud,*transformed_cloud1,matrix.inverse());
			// pcl::io::savePCDFileASCII("transformed_cloud.pcd", *transformed_cloud);

			double dcm[3][3] = {0};
			float roll, pitch, yaw = 0.0;
			for (int i = 0; i < 3; i++)
			{
				dcm[i][0] = matrix(i, 0);
				dcm[i][1] = matrix(i, 1);
				dcm[i][2] = matrix(i, 2);
			}

			mavlink_dcm_to_euler(dcm, &roll, &pitch, &yaw);
			// printf("rotatex=%lf\n", roll);
			// printf("rotatey=%lf\n", pitch);
			// printf("rotatez=%lf\n", yaw);

			vdatalist.clear();
		}
	}
}

void addsample(MatrixXf a)
{
	if (vdatalist.size() >= numberscan)
		return;

	vdatalist.push_back(a);
	//cout << "thread !!addsample vdatalist.size()=%d" << vdatalist.size() << endl;
}

int R2000::sample(int perscan)
{
	static int sample = 0;
	int scans_available = driver.getFullScansAvailable();

	if (scans_available == 0)
	{

		return -1;
	}

	ScanData scandata = driver.getFullScan(); //getFullScan

	if (scandata.distance_data.size() != perscan)
		return -1;
	cout<<"scandatasize "<<scandata.distance_data.size()<<endl;
	const float first_angle = ((float)scandata.headers[0].first_angle) / 10000;
	for (int idx = 0; idx < scandata.distance_data.size(); idx++)
	{
		if(scandata.distance_data[idx]>100000)
			continue;
		float ang = first_angle + param->r2000_sens_angstep * idx;
		float r = ang * pi / 180;

		m(idx, 0) = scandata.distance_data[idx] * cos(r);
		m(idx, 1) = scandata.distance_data[idx] * sin(r);
		m(idx, 2) = 0;
	}
	sample++;
	//MatrixXf a;
	// a.col(0) = m.col(0) * m.col(1).array().sin();
	// a.col(1) = m.col(0) * m.col(1).cos();
	// a.col(2) = m.col(2);
	addsample(m);
	if (sample == count)
	{
		sample = 0;
		return 0;
	}
	else
		return sample;
}

void R2000::ThreadR2000Nav()
{
	cout << "[START THREAD] --> R2000 SAMPLE" << endl;
	thread r2000Navthread(&R2000::NavStart, this);
	r2000Navthread.detach();

	cout << "[START THREAD] --> ICP READY" << endl;
	thread ICP(&R2000::ICP, this);
	ICP.detach();
}
