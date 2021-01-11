#include "main.h"

using namespace std;
using namespace pepperl_fuchs;



bool R2000::init(void)
{
	std::cout << "Connecting to scanner at " << sys->param.r2000_sens_ip << " ... ";
	if (driver.connect(sys->param.r2000_sens_ip, 80))
		std::cout << "OK" << std::endl;
	else
	{
		std::cout << "FAILED!" << std::endl;
		std::cerr << "Connection to scanner at " << sys->param.r2000_sens_ip << " failed!" << std::endl;
		return false;
	}

	driver.setScanFrequency(sys->param.r2000_sens_smp_frq);
	driver.setSamplesPerScan(sys->param.r2000_sens_smp_cnt);
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


void R2000::NavStart(void)
{
	while (false == init())
	{
		cout << "SENSOR INIT FAIL" << endl;
		util::sleep(1000); //2->10
	}

	cout << "SENSOR INIT SUCCESS" << endl;
	

	while (1)
	{
		util::sleep(20); //2->10

		sample(); 
		
	}
}
int R2000::sample(void)
{
	int scans_available = driver.getFullScansAvailable();

	if (scans_available == 0)
	{

		return -1;
	}

	ScanData scandata = driver.getFullScan(); //getFullScan
	MatrixXf m(8400, 2);  //sourcedata
	const float first_angle = ((float)scandata.headers[0].first_angle) / 10000;
	for (int idx = 0; idx < scandata.distance_data.size(); idx++)
	{

		float ang = first_angle + sys->param.r2000_sens_angstep * idx;
		float r = ang * A2R;

		m(idx, S_FEA_DIST) = scandata.distance_data[idx];// * cos(r);
		m(idx, S_FEA_ANG) = ang;                         //scandata.distance_data[idx] * sin(r);
		
	}
	sourcedata.m = m;
	sourcedata.ts = sys->time;
	//printf("sample:%ld\n",sys->time);

	return 0;
}

void R2000::ThreadR2000Nav()
{
	cout << "[START THREAD] --> R2000 SAMPLE" << endl;
	thread r2000Navthread(&R2000::NavStart, this);
	r2000Navthread.detach();
}
