##pragma once
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
		explicit MySocket(int s) : Socket(s), active(true) {} 
		~MySocket();
		   
		std::size_t Send(const std::string& buf, int flags = 0);
		std::size_t Recv(std::string& buf, int flags = 0);

		int Bind();
        void Listen();

        int GetSock()
        {
        	return Socket;
        }

		bool IsActive()
		{
			return active;
		}

		
	private:
		int Socket;
		bool active;
	    struct sockaddr_in addr = {0};
	   
	};

//}