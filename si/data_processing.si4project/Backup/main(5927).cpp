#include "main.h"


NAV *Nav;




int main(int argc, char **argv)
{
	GLOG   mylog;
	Nav = NAV::getInstance();

	return Nav->run();
   
}
