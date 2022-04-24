#include "Server.h"

MyServer::MyServer()
{
	msoc.Bind();
	msoc.Listen();
}

void MyServer::MainCycle()
{

	while(true)
    {
		sockfd = accept(msoc.GetSock(), NULL, NULL);
		if (sockfd == -1)
		{
			 throw std :: runtime_error("accept faled");
		}

	// while(true)
    // {
        	
    //       bytes_read = msoc.Recv(std::string& buf,int flags);
    //       msoc.Send(const std::string& buf, int flags);
    // }        

	}
}

MyServer::~MyServer()
{
	close(sockfd);
}