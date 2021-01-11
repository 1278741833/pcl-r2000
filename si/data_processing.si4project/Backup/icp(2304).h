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
#include <errno.h>

#define vPos Vector2d
#define PAI 3.1415926f
#define A2R PAI/180
#define R2A 180/PAI
#define LOCSTATE Matrix<double,5,1>


#if 1
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/point_types.h>
#include <pcl/filters/approximate_voxel_grid.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/statistical_outlier_removal.h>

#endif


#include "logging.h"
#include "log_severity.h"

#include "glog.h"
#include "checksum.h"

#include "ini.h"
#include "INIReader.h"
#include "util.h"


#include "r2000.h"
#include "dfilter.h"
#include "terminal_cmd.h"
#include "nav.h"





#include "_freecplus.h"


extern NAV *Nav;


  


#endif
