#pragma once
#include <thread>
extern "C"
{
   #include<sys/socket.h>
   #include<arpa/inet.h>
}

class Server
{
   const unsigned short PORT = 7828;
   const unsigned char  MAX_CONNECTION = 8;
   unsigned short port;

   struct sockaddr_in serverAddr,clientAddr;
   int serverFd, clientFd;
   socklen_t addr_len;
   bool runningLoader;

   
public:
	Server();
   Server(unsigned short port);   
	~Server();
	void init(void);
   void connectionHandler(int socketFd);
   void loader(int socketFd);
};