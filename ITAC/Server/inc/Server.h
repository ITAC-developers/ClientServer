#pragma once
#include "Socket.h"


class MyServer
{

public:
	MyServer();
	~MyServer();
	
	void MainCycle();
	
private:

	MySocket msoc;
	struct sockaddr_in addr = {0};
	int sockfd;
	//int bytes_read;
	
};