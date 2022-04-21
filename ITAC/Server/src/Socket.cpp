#include "Socket.h"
//using namespace itac::socket;



MySocket::MySocket()
{

	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket == -1)
	{
		throw std :: runtime_error ("socket fled");
	}	
	 addr.sin_family = AF_INET;
	 addr.sin_port = htons(3425);
	 addr.sin_addr.s_addr = htonl(INADDR_ANY);
 
}


std::size_t MySocket::Send(const std::string& buf, int flags)
{	
	if(!active)
	{
		return 0;
	}		
	
	int res = send(Socket, buf.data(), buf.size(), flags);
	if (res == -1)
	{
		throw std :: runtime_error("Can't send");
	}

	return res;
}

std::size_t MySocket::Recv(std::string& buf,int flags)
{

	char buffer[4096]; 
	if(!active)
	{
		return active;
	}

	int res = recv(Socket, buffer, sizeof (buffer), flags);
	if(res == -1)
	{
		throw std :: runtime_error("Recv failed");
	}

	if (res == 0) 
	{
		active = false;
       		std::cout<<("client dead\n")<<std::endl;
	}
	
	buf = std::string(buffer, res);

	return res;
}


int MySocket::Bind()
{
        int res = bind(Socket,(struct sockaddr*) &addr, sizeof addr);
        if (res == -1)
        {
                throw std :: runtime_error("bind faled");

        }
	return res;
}

void MySocket::Listen()
{
        int res = listen(Socket, 5);
        if (res == -1)
        {
                throw std :: runtime_error("listen faled");
        }
}


MySocket::~MySocket(){}

