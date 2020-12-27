#include "main.h"

void *pth_udp(void *ip);
// bool SplitBuffer(const char *strBuffer);
// bool biz1(int clientfd, char *buf, int *position);
void xmltobiz(char *strxmlbuffer, struct st_tcppointcloud *m_tcppointcloud);
vector<st_tcpdatalist> v_stdatalist;
extern MatrixXf m;
TCP_SERVER::TCP_SERVER()
{

	
	
		revbuffer = new char[revbuf_lenmax];
	
}
TCP_SERVER::~TCP_SERVER()
{
	if(NULL != revbuffer)
	{
		delete[] revbuffer;
		revbuffer = NULL;
	}


}


int TCP_SERVER::init(int port,bool longconnection)
{
	long_connection = longconnection;
	struct sockaddr_in server_addr;

	if((listenfd = (socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) == -1)
	{
		//LOG_ERROR("NetBase")<<"Create tcp server local socket failed!"<<endl;
		return 1;
	}
#if 1
	struct timeval timeout = {5, 0};
	setsockopt(listenfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));

	int reuseon = 1;
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuseon, sizeof(reuseon))<0)
	{
		//LOG_ERROR("NetBase")<<"Tcp server set address reuse failed! errno:"<<errno<<":"<<strerror(errno)<<endl;
	}
#endif
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr(localIP);

	

	if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1)
	{

		//LOG_WARN("NetBase")<<"TCP server band success,port:"<<  port <<endl;
	}

	if (listen(listenfd, 128) < 0) {
		//LOG_ERROR("NetBase")<<"TCP server listen on server socket error. errno:"<<errno<<":"<<strerror(errno)<<endl;
		close(listenfd);
		return 3;
	}else{
		//LOG_INFO("NetBase")<<"TCP server:"<<server_addr.sin_addr.s_addr<<":"<<port<<"  listening ."<<endl;
	}
	return 0;
}


void TCP_SERVER::close_connection()
{
//	printf("###############TCP SERVER close connection\n");
	close(connfd);
	connected = false;

}

int TCP_SERVER::rev_data(int &cltaddr)
{
   //senderip = addr_serv.sin_addr.s_addr;

   
	struct sockaddr_in client_addr;
	socklen_t length = sizeof(client_addr);
	if(connected == false || long_connection == false)
	{
		if(-1 ==(connfd = accept(listenfd, (struct sockaddr*)&(client_addr), &length)))
		{
			printf("connfd:%d\n",connfd);
			return -1;
		}

		else
		{
			m_clientaddr.sin_addr = client_addr.sin_addr;
			
			connected = true;
			if(cltaddr == 0)
				cltaddr = client_addr.sin_addr.s_addr;
			//cout<<((client_addr.sin_addr.s_addr))<<endl;;
		}
	  
	}
	
	memset(revbuffer, 0,revbuf_lenmax);
	int getbuflen  = recv(connfd, revbuffer, revbuf_lenmax, 0);
	
   
	if(getbuflen <=0)
	{
		if(errno ==	11)
		{
		   //LOG_WARN("NetBase")<<"TCP server receive data timeout on port:"<<endl;
		}
		else

		{
		  // LOG_ERROR("NetBase")<<"TCP server recieve data failed! port:"<<" errno:"<<errno<<":"<<strerror(errno)<<endl;
		}
		if( long_connection == false)
		{
		   close_connection();

		}

		return -1;
	}

	return getbuflen;


}

void TCP_SERVER::send_ackdata(char * ack_packet,int len)
{
	//tcpdata.clientIP = inet_ntoa(tcpdata.remoteaddr.sin_addr);

	send(connfd,ack_packet,len,0);
}



char *TCP_SERVER::GetIP()
{
  return(inet_ntoa(m_clientaddr.sin_addr));
}
Network::Network()
{
}

Network::~Network() {}
void Network::ThreadNetwork()
{
	cout << "[START THREAD] --> R2000 SAMPLE" << endl;
	thread network(&Network::NetStart, this);
	network.detach();

	
}
bool Network::NetStart()
{
	Tcp_Server.init(starg.port1, false);
	while (true)
	{

		//usleep(100000);

		if (Tcp_Server.long_connection == false && Tcp_Server.connected == true)
			Tcp_Server.close_connection();

		int getbuflen = Tcp_Server.rev_data(Tcp_Server.client_addr);

		//  if (getbuflen > 0)
		//  {
		char ip[20] = {0};

		strcpy(ip, Tcp_Server.GetIP());
		printf("%s is connected!\n", ip);
		if (pthread_create(&pthid, NULL, pth_udp, ip) != 0)
		{
			printf("create thread failed\n");
		}

		//xmltobiz(char *strxmlbuffer, struct st_tcppointcloud *m_tcppointcloud)
		char buf[200000] = {0};
		int buflen = 0;
		biz1(Tcp_Server.connfd, buf, &buflen);
		printf("len=%d\n", buflen);
		char buffer[buflen + 4];
		memset(buffer, 0, sizeof(buffer));
		memcpy(buffer, &buflen, 4);
		memcpy(buffer + 4, buf, buflen);
		Tcp_Server.send_ackdata(buffer, buflen + 4);

			// }
	}
}
bool Network::biz1(int clientfd, char *buf, int *postion)
{
	v_stdatalist.clear();
	int position = 0;
	CFile File;

	if (File.Open("all001.csv", "r") == false)
		printf("open file failed\n");
	char strBuffer[301];

	while (true)
	{

		memset(strBuffer, 0, sizeof(strBuffer));

		// 从文件中获取一行记录
		if (File.Fgets(strBuffer, 300, true) == false)
			break;

		UpdateStr(strBuffer, "  ", " ", true); // 把内容中的两个空格替换成一个空格
		//printf("%s\n", strBuffer);

		// 把用' '分隔的记录拆分到结构体中
		if (SplitBuffer(strBuffer) == false)
		{
			//printf("%s拆分失败\n", strBuffer);
			continue;
		}
	}
	const float first_angle = -180;

	memset(&m_tcppoint, 0, sizeof(m_point));
	m_tcppoint.header[0] = 0x20;
	m_tcppoint.header[1] = 0x03;
	m_tcppoint.angle = param->r2000_sens_angstep;
	//m_tcppoint.Point_Num = v_stdatalist.size();
	m_tcppoint.Point_Num = v_stdatalist.size();
	printf("m_tcppoint.angle %f\n", m_tcppoint.angle);
	printf("m_tcppoint.Point_Num %d\n", m_tcppoint.Point_Num);
	memcpy(buf + position, &m_tcppoint, sizeof(m_point));

	int temp = 0;
	memcpy(&temp, buf + 6, sizeof(temp));
	printf("temp= %d", temp);
	position = position + sizeof(m_point);

	for (int i = 0; i < v_stdatalist.size(); i++)
	{

		memcpy(buf + position, &v_stdatalist[i], sizeof(st_tcpdatalist));

		position = position + sizeof(st_tcpdatalist);
	}
	/*
	  uint16_t checksum;
	  crc_init(&checksum);

	  for (int i = 0; i < position; i++)
	  {
		  crc_accumulate(*(buf + i), &checksum); 
	   }
	   char crc[2];
	   crc[0]=  (0xff)&(checksum&0xff);
	   crc[1]=  (0xff)&(checksum>>8);
	   memcpy(buf + position, &crc, sizeof(char)*2);
	   position = position + 2;*/
	//printf("sizeof(tou=%d),sizeof(struct st_tcpdatalist)=%d,===%d\n", sizeof(struct m_point), sizeof(struct st_tcpdatalist), sizeof(struct st_tcpdatalist) * v_stdatalist.size());
	//printf("\n%x %x\n", (0xff) & (checksum & 0xff), (0xff) & (checksum >> 8));
	*postion = position;
	v_stdatalist.clear();
	return true;
}

void *pth_udp(void *ip)
{
	printf("ip=%s\n", (char *)ip);
	pthread_detach(pthread_self());
	while (true)
	{
		CUdpClient UdpClient;
		UdpClient.ConnectToServer((char *)ip, starg.port);

		char strbuffer[200000];
		memset(strbuffer, 0, sizeof(strbuffer));
		int position = 0;
		memset(&m_tcppoint, 0, sizeof(m_point));
		m_tcppoint.header[0] = 0x20;
		m_tcppoint.header[1] = 0x03;
		m_tcppoint.angle = param->r2000_sens_angstep;
		m_tcppoint.Point_Num = m.rows();

		memcpy(strbuffer + position, &m_tcppoint, sizeof(m_point));

		position = position + sizeof(m_point);


		for (int i = 0; i < m_tcppoint.Point_Num; i++)
		{
			memset(&m_sttcpdatalist,0,sizeof(st_tcpdatalist));
			m_sttcpdatalist.x = m(i, 0);
			m_sttcpdatalist.y = m(i, 1);
			m_sttcpdatalist.amplitude = 100;
			memcpy(strbuffer + position, &m_sttcpdatalist, sizeof(st_tcpdatalist));

			position = position + sizeof(st_tcpdatalist);
		}

		
		if (UdpClient.Write(strbuffer, position) == false)
			printf("send  points failed\n");

	

		// cout << "udp" << m(4000, 0) << endl;

		usleep(100000);
	}
}
bool Network::SplitBuffer(const char *strBuffer)
{
	CCmdStr CmdStr;
	CmdStr.SplitToCmd(strBuffer, ",", true);
	if (CmdStr.CmdCount() != 4)
	{
		return false;
	}

	const double pi = acos(-1.0);

	double distance = 0;
	double angle = 0;
	int amplitude = 0;
	CmdStr.GetValue(1, &distance);
	CmdStr.GetValue(2, &amplitude);
	CmdStr.GetValue(3, &angle);

	if (distance > 100000)
	{
		return false;
	}
	memset(&m_sttcpdatalist, 0, sizeof(st_tcpdatalist));
	float r = angle * pi / 180;
	m_sttcpdatalist.x = float(distance * sin(r));
	m_sttcpdatalist.y = float(distance * cos(r));
	m_sttcpdatalist.amplitude = amplitude;
	v_stdatalist.push_back(m_sttcpdatalist);

	return true;
}
