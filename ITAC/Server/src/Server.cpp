#include "Server.h"

MyServer :: MyServer()
{

}

void MyServer::StartServer()
{
	msoc.Bind();
	msoc.Listen();
}

void MyServer::MainCycle()
{

	while(true)
    {
		msoc.Accept();

        //int bytes_read = msoc.Recv(std::string& buf,int flags);
            
       
    
        

	}
}

MyServer::~MyServer()
{
	
}