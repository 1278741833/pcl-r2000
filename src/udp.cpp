
#include "udp.h"
#include "_freecplus.h"
CUdpClient::CUdpClient()
{

}
bool CUdpClient::ConnectToServer(const char *ip,const int port)
{
//1 创建udp通信socket
	udp_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(udp_socket_fd == -1)
	{
		perror("socket failed!\n");
		return -1;
	}
    
	//设置目的IP地址
    
    dest_addr.sin_family = AF_INET;//使用IPv4协议
    dest_addr.sin_port = htons(port);//设置接收方端口号
    dest_addr.sin_addr.s_addr = inet_addr(ip); //设置接收方IP 
	
  return true;
}



bool CUdpClient::Write(const char *buffer,const int ibuflen)
{
    
	//2 发送数据
 
        if(sendto(udp_socket_fd, buffer, ibuflen, 0, (struct sockaddr *)&dest_addr,sizeof(dest_addr))== -1)
			return false;
		return true; 
	
	
}

void CUdpClient::Close()
{
  close(udp_socket_fd);
}
CUdpClient::~CUdpClient()
{

  close(udp_socket_fd);
}



CUdpServer::CUdpServer()
{

  udp_socket_fd=-1;
}

bool CUdpServer::InitServer(const unsigned int port)
{
	// 1.创建udp通信socket  
	udp_socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(udp_socket_fd < 0 )
	{
		perror("creat socket fail\n");
		return -1;
	}
 
	//2.设置UDP的地址并绑定 
	struct sockaddr_in  local_addr = {0};
	local_addr.sin_family  = AF_INET; //使用IPv4协议
	local_addr.sin_port	= htons(port);   //网络通信都使用大端格式
	local_addr.sin_addr.s_addr = INADDR_ANY;//让系统检测本地网卡，自动绑定本地IP
 
	int ret = bind(udp_socket_fd,(struct sockaddr*)&local_addr,sizeof(local_addr));
	if(ret < 0)
	{
		perror("bind fail:");
		close(udp_socket_fd);
		return -1;
	}
	else
	{
		printf("recv ready!!!\n");
	}
  return true;
}

/*
	//4 关闭通信socket
	close(udp_socket_fd);*/

char *CUdpServer::GetIP()
{
  return(inet_ntoa(src_addr.sin_addr));
}

bool CUdpServer::Read(char *buffer,const int ibuflen)
{


    len = sizeof(src_addr);  //地址信息大小
	//char buf[1024] = {0};//消息缓冲区

	//3 接收客户发送过来的数据  
	
		int ret = recvfrom(udp_socket_fd, buffer, ibuflen, 0, (struct sockaddr *)&src_addr,(socklen_t *)&len);
		if(ret == -1)
		{
			return false;
		}

		printf("[%s:%d]",inet_ntoa(src_addr.sin_addr),ntohs(src_addr.sin_port));//打印消息发送方的ip与端口号
	    printf("buf=%s\n",buffer);
		
	

}


CUdpServer::~CUdpServer()
{

  close(udp_socket_fd);
}



