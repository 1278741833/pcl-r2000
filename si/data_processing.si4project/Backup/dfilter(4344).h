#ifndef __D_FILTER__
#define __D_FILTER__

#include "main.h"

using namespace Eigen;


class R2000;
class DFILTER{

public:
	vector<FRAME_DATA> dlist;
	bool record_start = false;
	

public:
	DFILTER();
	void filter_main();
	void ThreadDfilter();


private:


};



#endif
