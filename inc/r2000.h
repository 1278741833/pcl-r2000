#ifndef __R2000__H__
#define __R2000__H__







#include <vector>

#include <pepperl_fuchs_r2000/r2000_driver.h>
#include "main.h"
using namespace std;
using namespace pepperl_fuchs;
using namespace Eigen;

class NAV;
class R2000{

public:
	
	//vector<REFBAR> mod_buf;

	//vector<LOCSTATE> refbar_buf;//x,y,dist,angle,usr or not.
	

	int thread_sample_consuming_time;
	int thread_identify_consuming_time;

	int raw_data_file_idx;

	long int indentif_ts;
	//bool mod_buf_cleared = false;

	int sample_and_identify_thread_stopflag;
	
	
	/* r2000 sensor state init */
	bool inited = false;

	bool update;
	long int last_getdata = 0;
	
public:
	R2000();
	~R2000();

	void updateParams(void);
	
	bool init(void);

	void NavStart(void);
	
	int  sample(void);
	void send(void);
	void sendstart(void);
	void ICP(void);
	void ThreadR2000Nav(void);
private:
	
	
	float fps_sample_for_sleep = 50.0f; //sample thread sleep freq
	float fps_indentification_for_sleep = 500.0f; //indentification sleep freq
	

	pepperl_fuchs::R2000Driver driver;
	

	ofstream outFile;
	ofstream outFileAll;

	float max_distance = 25.0f;
	float min_distance = 0.3f;

	bool rawDataRecord = false;   //flag that if start record r2000 raw data
	int  rawDataRecordFrameNum = 0;//frame number that r2000 raw data should record 

	ScanData raw_log_data;

	bool	read_log_data_success = false;
	

};






#endif
