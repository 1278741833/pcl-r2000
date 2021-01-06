
/*
class CUdpClient
{
public:
  int  udp_socket_fd;	  // 客户端的socket
  struct sockaddr_in dest_addr = {0};
  CUdpClient();  // 构造函数。

  // 向服务端发起连接请求。
  // ip：服务端的ip地址。
  // port：服务端监听的端口。
  // 返回值：true-成功；false-失败。
  bool ConnectToServer(const char *ip,const int port);

  // 向服务端发送数据。
  // buffer：待发送数据缓冲区的地址。
  // ibuflen：待发送数据的大小，单位：字节，缺省值为0，如果发送的是ascii字符串，ibuflen取0，如果是二进制流数据，ibuflen为二进制数据块的大小。
  // 返回值：true-成功；false-失败，如果失败，表示socket连接已不可用。
  bool Write(const char *buffer,const int ibuflen=0);

  // 断开与服务端的连接
  void Close();

  ~CUdpClient();  // 析构函数自动关闭socket，释放资源。
};

// socket通信的服务端类




class CUdpServer
{
public:
	int  udp_socket_fd; 	// 服务端的socket
    int len;	//地址信息的大小
	struct sockaddr_in  local_addr = {0};  //本地的
	struct sockaddr_in  src_addr = {0};  //用来存放对方(信息的发送方)的IP地址信息

  CUdpServer();  // 构造函数。

  // 服务端初始化。
  // port：指定服务端用于监听的端口。
  // 返回值：true-成功；false-失败，一般情况下，只要port设置正确，没有被占用，初始化都会成功。
  bool InitServer(const unsigned int port);
  
  char *GetIP();//获取对端的ip和端口

  // 向客户端发送数据。
  // buffer：待发送数据缓冲区的地址。
   // ibuflen：待发送数据的大小，单位：字节，缺省值为0，如果发送的是ascii字符串，ibuflen取0，如果是二进制流数据，ibuflen为二进制数据块的大小。
  // 返回值：true-成功；false-失败，如果失败，表示socket连接已不可用。
  bool Read(char *buffer,const int ibuflen);

  ~CUdpServer();  // 析构函数自动关闭socket，释放资源。
};


	*/
 


