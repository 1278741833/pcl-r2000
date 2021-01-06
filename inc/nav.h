#ifndef __NAV__
#define __NAV__

#include "main.h"

using namespace Eigen;


class NAV{
public:

	typedef struct{
		/* start this thread */
		int thread_r2000_smp_start;
		int thread_r2000_identify_start;

	

		/*log flag*/
		int log_barmod;
		int log_err_mem;
		int log_barlist;


		std::string r2000_sens_ip;    //r2000 sensor ip
		int    read_local_ip;
		int    r2000_sens_smp_frq;   //r2000 sensor sample frequency
		int    r2000_sens_smp_cnt;  //r2000 sensor sample point per cycle
		int	   r2000_sens_smp_cnt_after_filter;
		float r2000_sens_angstep;  //r2000_sens_angstep = 360/r2000_sens_smp_cnt;
		
		int    r2000_smp_amp_hlimit;
		int    r2000_smp_amp_llimit;
		float r2000_smp_dist_hlimit;
		float r2000_smp_dist_llimit;
		
		int    refbar_mod_min_smp_num;     //refbar module match, in this buf, points number shoule more than this num
		float refbar_mod_edist;           //refbar module match, in this buf, all points distance(H-L) should less than this dist
		float refbar_mod_max_errgen;      //refbar module match, err gen shoule less than this param
		float refbar_mod_convex_score;
		int    refbar_mod_amperr_max;
		int    refbar_mod_amp_offset_max;
		float refbar_diameter;            //refbar diameter 
		int    refbar_maxbarnum_for_match; //matching refbar number less than this number
		float refbar_err_dist;   

	}PARAMS;

	typedef struct{
		sem_t sem_reflect_module;
		long int time;

		long int err;
		PARAMS  params;
		int healthy;
	}System;


public:
	NAV();
	void updateParams();
	static NAV* getInstance();
	int run();
	uint64_t get_current_timestamps(void);

public:	
	pthread_t pthid;
	System sys;
	R2000     r2000;
	Network network;
	TCP_SERVER Tcp_Server;
	pthread_mutex_t _time_mutex=PTHREAD_MUTEX_INITIALIZER;
	
private:
	
};




#endif
