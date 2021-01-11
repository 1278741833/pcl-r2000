#ifndef __NETWORK__
#define __NETWORK__


class NETWORK{
public:
	typedef enum{
		CMD_INIT_REQUIRE = 0,
		CMD_HEARTBEAT,
	}CMD_LIST;


	struct TCP_DATA{
		char header[2];
		CMD_LIST cmd;
		float    param[3];
		char crc[2];
	};

	struct TCP_ACK{
		char * buf;
		int size;
	
	};

	struct PNT{
		float x;
		float y;
		float amp;
	};
	
public:

	UDP_SERVER udp_server;
	TCP_SERVER tcp_server;



	int         bufsize_max;
	TCP_DATA    tcp_data;
	TCP_ACK     tcp_ack;
	

	char * udp_pocket;
	bool  udp_thread_start;
public:
	NETWORK();
	bool tcpCmdHandle(const TCP_DATA& data);
	int  packageFrameBuf(char *buf,const MatrixXf& s_data);
	int  tcpServerRun();
	void ThreadSimNet();
	int  udpPackingPacket(char *buf);
	int  udpSendRun();
};


#endif
