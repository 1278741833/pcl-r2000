#include "main.h"
using namespace Eigen;


COMMANDER::COMMANDER()
{
	configManager = new INIReader("config.ini");
	updateParams();
}

COMMANDER *COMMANDER::getInstance()
{
	static COMMANDER instance;
	return &instance;
}

void COMMANDER::updateParams()
{

	/*  R2000 SENSOR CONFIG   */
	param.r2000_sens_smp_frq = configManager->GetInteger("R2000", "R2000_SENS_FRE",10);
	cout<<"  param->R2000_SENS_FRE:"<<param.r2000_sens_smp_frq<<endl;

	param.r2000_sens_smp_cnt = configManager->GetInteger("R2000", "R2000_SENS_SMP_CNT",8400);
	cout<<"  param->R2000_SENS_SMP_CNT:"<<param.r2000_sens_smp_cnt<<endl;

	param.r2000_sens_ip=configManager->GetString("R2000", "R2000_SENS_IP", "192.168.0.115");
	cout<<"  param->REPORTOR_UDP_LOCAL_IP:"<<param.r2000_sens_ip<<endl;

	param.r2000_sens_angstep = (float)(180/(float)param.r2000_sens_smp_cnt);


	/*  SIMULATION CONFIG   */
	param.sim_noise_active = configManager->GetInteger("SIM", "SIM_NOISE_ACTIVE",0);
	cout<<"  param->SIM_NOISE_ACTIVE:"<<param.sim_noise_active<<endl;

	param.sim_noise_ang  = configManager->GetReal("SIM", "SIM_NOISE_ANG", 0.05);
	cout<<"  param->SIM_NOISE_ANG:"<<param.sim_noise_ang<<endl; 

	param.sim_noise_dist  = configManager->GetReal("SIM", "SIM_NOISE_DIST", 0.05);
	cout<<"  param->SIM_NOISE_DIST:"<<param.sim_noise_dist<<endl; 

	param.sim_record_cnt = configManager->GetInteger("SIM", "SIM_RECORD_CNT",3);
	cout<<"  param->SIM_RECORD_CNT:"<<param.sim_record_cnt<<endl;



	param.net_udp_port = configManager->GetInteger("NET", "NET_UDP_PORT",9999);
	cout<<"  param->NET_UDP_PORT:"<<param.net_udp_port<<endl;
	
	param.net_tcp_port = configManager->GetInteger("NET", "NET_TCP_PORT",9000);
	cout<<"  param->NET_TCP_PORT:"<<param.net_tcp_port<<endl;

	

	
}

int COMMANDER::run()
{

	r2000.ThreadR2000Nav();
//	dfilter.ThreadDfilter();
	startThreadTerminal();
	while(true)
	{
		struct timeval tv;
		struct timezone tz;
		gettimeofday(&tv,&tz);
		sys->time = tv.tv_sec *1000 + tv.tv_usec/1000;
		util::sleep(1); 
	}
	

	return 0;
}
