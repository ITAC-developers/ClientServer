#pragma once
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

// namespace itac::socket
// {

	class MySocket
	{
		 
	public:
		MySocket();
		
		~MySocket();
		   
		std::size_t Send(const std::string& buf, int flags = 0);
		std::size_t Recv(std::string& buf, int flags = 0);

		//bool operator == (int s);
 
		int Bind();
        void Listen();
        MySocket Accept();

		bool IsActive()
		{
			return active;
		}

		
	private:
		explicit MySocket(int s) : Socket(s), active(true) {} 
		int Socket;
		bool active;
	    struct sockaddr_in addr = {0};
	   
	};

//}