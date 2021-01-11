#ifndef __NAV__
#define __NAV__

#include "main.h"

using namespace Eigen;


class NAV{
public:

	typedef struct{

		string r2000_sens_ip;    //r2000 sensor ip
		int    read_local_ip;
		int    r2000_sens_smp_frq;   //r2000 sensor sample frequency
		int    r2000_sens_smp_cnt;  //r2000 sensor sample point per cycle
		float  r2000_sens_angstep;



		float sim_noise_dist;
		float sim_noise_ang;
		int   sim_noise_active;
		int   sim_record_cnt;
		
	}PARAMS;


public:
	NAV();
	void updateParams();
	static NAV* getInstance();
	int run();

public:	
	pthread_t pthid;
	PARAMS param;
	INIReader *configManager;
	R2000     r2000;
	
	DFILTER   dfilter;



	
	long int time;
	

	
};




#endif
