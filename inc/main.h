#ifndef __MAIN__MAIN_
#define __MAIN__MAIN_
#include <math.h>
#include <Eigen/LU>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <sys/ipc.h>
#include <unistd.h>
#include <pthread.h>
#include <thread>
#include <sys/ioctl.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <time.h>
#include <chrono>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mutex>
#include <signal.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sched.h>
#include <net/if.h>
#include <float.h>
#include <limits.h>  
#include <unistd.h>  
#include <semaphore.h> 
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/point_types.h>
#include <pcl/filters/approximate_voxel_grid.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#define vPos Vector2d
#define PAI 3.1415926f
#define A2R PAI/180
#define R2A 180/PAI
#define LOCSTATE Matrix<double,5,1>
#include "udp.h"
#include "net.h"
#include "r2000.h"
#include "nav.h"



#include "param.h"

#include "_freecplus.h"
extern long int systime;
#define numberscan 5
typedef struct
{
    char ip[31];
    int port;
    int port1;

} st_arg;
#pragma pack(push, 1)
typedef struct 
{
	char header[2];
	float angle;
	int Point_Num;
} m_point;
extern m_point m_tcppoint;

typedef struct
{
	//int index;
	int amplitude;
	float x;
	float y;
} st_tcpdatalist;
extern st_tcpdatalist m_sttcpdatalist;

#pragma pack(pop)
extern st_arg starg;

extern NAV *Nav;
extern NAV::PARAMS* param;



#define PRINT_FB(x,...) {if(x){printf("\x1b[%dm%s(%d)-<%s>:\x1b[0m",31,__FILE__, __LINE__, __FUNCTION__);printf(__VA_ARGS__);}}
#define PRINT_ERRMEM(x,...) {if(x){printf("\x1b[%dm%s(%d)-<%s>:\x1b[0m",32,__FILE__, __LINE__, __FUNCTION__);printf(__VA_ARGS__);exit(0);}}
#define PRINT_ATTCB(x,...) {if(x){printf("\x1b[%dm%s(%d)-<%s>:\x1b[0m",33,__FILE__, __LINE__, __FUNCTION__);printf(__VA_ARGS__);}}
  


#endif
