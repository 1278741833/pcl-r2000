#include "main.h"
using namespace Eigen;




DFILTER::DFILTER()
{

	dlist.clear();
}





static int recode_cnt = 5;
void DFILTER::filter_main()
{


	long int last_time = 0;
	
	while(1)
	{

		util::sleep(10); //2->10
		
	
		if(last_time == sys->r2000.sourcedata.ts)
		{
			continue;
		}
		last_time = sys->r2000.sourcedata.ts;

		if(false == record_start || sys->param.sim_record_cnt >= dlist.size())
		{
			if(sys->param.sim_record_cnt >= dlist.size())
			{
				dlist.clear();
				record_start = false;
			}
			continue;
		}
#if 0

		MatrixXf temp(sys->param.r2000_sens_smp_cnt,2);
		temp.setZero();
		if(1 == sys->param.sim_noise_active)
		{
			temp = MatrixXd::Random(sys->param.r2000_sens_smp_cnt,2);
			temp.col(S_FEA_DIST) *= sys->param.sim_noise_dist;
			temp.col(S_FEA_ANG)  *= sys->param.sim_noise_ang;
		}
		temp += sys->r2000.sourcedata.m;

		FRAME_DATA sim_data;
		sim_data.height = sys->r2000.sourcedata.height;
		sim_data.m = temp;
		dlist.push_back(sim_data);
#endif

	}

}



