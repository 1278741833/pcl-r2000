#ifndef __NET__
#define __NET__
#include "main.h"

////////////////////////////////////////
//ross add 2019.7.21

class NAV;

class TCP_SERVER{
private:
	struct sockaddr_in m_clientaddr; 
public:
	bool long_connection = true;
	bool connected = false;
	int listenfd;
	int connfd;
	int client_addr=0;
	char *revbuffer;
	int  revbuf_lenmax = 1024;
	
	
public:
	int init(int,bool);

	void close_connection();
	int  rev_data(int&);
	void send_ackdata(char * ack_packet,int len);
	char *GetIP();
	TCP_SERVER();
	~TCP_SERVER();

};
class Network
{
public:
	Network();
	~Network();
	bool NetStart(void);
	TCP_SERVER Tcp_Server;
	bool SplitBuffer(const char *strBuffer);
	bool biz1(int clientfd, char *buf, int *postion);
	pthread_t pthid;

	void ThreadNetwork(void);
};
extern int monitor_ip;


#endif
