#include <iostream>

#include "main.h"
using namespace Eigen;
using namespace std;
// 显示程序的帮助
void _help(char *argv[]);
// 把xml解析到参数starg结构中
bool _xmltoarg(char *strxmlbuffer);
NAV *Nav;
NAV::PARAMS *param;

void EXIT(int sig);

st_arg starg;
bool _xmltoarg(char *strxmlbuffer);




int main(int argc, char **argv)
{
   if (argc != 2)
   {
      _help(argv);
      return -1;
   }
   	if(false == param_load("config.txt"))
	{
		cout<< "Can't load file config.txt !"<< endl;
		exit(-1);
	}
	else
		cout << "load file success"<<endl;
	
	if (_xmltoarg(argv[1]) == false)
		return -1;
	Nav = NAV::getInstance();

	return Nav->run();
   
}
bool _xmltoarg(char *strxmlbuffer)
{
    memset(&starg, 0, sizeof(st_arg));


	GetXMLBuffer(strxmlbuffer, "port", &starg.port);
	if (starg.port == 0)
	{
		printf("port is null.\n");
		return false;
	}
	GetXMLBuffer(strxmlbuffer, "port1", &starg.port1);
	if (starg.port1 == 0)
	{
		printf("port1 is null.\n");
		return false;
	}

  return true;
}  
void _help(char *argv[])
{

	printf("Using:./PCL xmlbuffer\n");
	printf("例如：./PCL  \"<port>9999</port><port1>9000</port1>\"\n");
	printf("这是一个模拟程序，采用UDP将信息传给仿真端，并接受对端传回的信息。\n");
	printf("xmlbuffer     本程序运行的参数，如下：\n");
	printf("port          UDP的端口。\n");
	printf("port1         TCP的端口。\n");
}