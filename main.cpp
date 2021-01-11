#include "main.h"


COMMANDER *sys;




int main(int argc, char **argv)
{

	GLOG   mylog;
	
	sys = COMMANDER::getInstance();

	return sys->run();
   
}
