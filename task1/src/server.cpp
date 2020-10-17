#include "../inc/server.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <chrono>
#include <fstream>
#include <thread>

 Server::Server()
 {

 }

Server::Server(unsigned short port)
{
  this->port = port;
}
Server::~Server()
{

}

 void Server::init()
 {
    /*Create socket*/
    serverFd = socket(AF_INET, SOCK_STREAM, 0); 
	if(serverFd == -1)
	{ 
       std::cout<<"Socket creation failed!"<<std::endl; 
    }
    memset(&serverAddr, 0, sizeof (serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	/*Bind socket*/
	if (bind(serverFd, (struct sockaddr*) &serverAddr, sizeof (serverAddr)) == -1)
	{
	   std::cout<<"Cannot bind socket and socket addr struct!"<<std::endl; 
       close(serverFd);
	}

	/*Listen socket*/
	if (listen(serverFd, 20) == -1)
	{
	   std::cout<<"Listen socket error!\n"<<std::endl;
       close(serverFd);
	}

	addr_len = sizeof(struct sockaddr_in);
    while((clientFd = accept(serverFd, (struct sockaddr *)&clientAddr, (socklen_t*)&addr_len)) )
    {
       std::cout<<"Connection accepted"<<std::endl;
       std::thread t(&Server::connectionHandler,this,clientFd);
       t.join();

	}

 }

 void Server::connectionHandler(int socketFd)
{
   char client_message[255];
   unsigned short read_size;
   std::cout<<"Client has connected!"<<std::endl;
   while( (read_size = recv(socketFd, client_message, 255, 0)) > 0 )
   {
      client_message[read_size-1] = '\0';
	    char cmd[255];
	    sprintf(cmd,"find -name %s > result.txt",client_message);


	  std::thread t(&Server::loader,this,socketFd);
    runningLoader = true;


	  if(!system(cmd))
	  {
	  	std::cout<<"Start search!"<<std::endl;
	  	std::string line;
    	std::ifstream in("result.txt");
    	if (in.is_open())
    	{
        	while (getline(in, line))
        	{
            	write(socketFd,line.c_str(), line.length());
        	}	
    	}
    	in.close();

		  client_message[read_size] = '\0';
		  memset(client_message, 0, 255); 
	   }
	   else
	   {
	   		std::cout<<"Search error!"<<std::endl;
			  write(socketFd,"failure",8);
	   }

      runningLoader = false;
      if (t.joinable())t.join();
   }

}

   void Server::loader(int socketFd)
   {
   		while(runningLoader)
   		{
   			write(socketFd,"Processing\n", strlen("Processing\n"));
   			std::this_thread::sleep_for (std::chrono::seconds(1));
   		}

   }

