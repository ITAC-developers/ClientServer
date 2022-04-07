#include "Server.h"

#include <iostream> //cout, endl

using namespace std::string_literals;

namespace itac::server
{
    Server::Server(int port) : port(port) 
    {
        //TODO change to logger
        std::cout << "server started"s << std::endl;
    }
    Server::~Server()
    {
        std::cout << "server destroyed"s << std::endl;
    }

    void Stop()
    {
        std::cout << "server stopped"s << std::endl;
    }

    void MainCycle()
    {
        std::cout << "main cycle started"s << std::endl;
        while (false)
        {
            //TODO somthing useful
        }
        std::cout << "main cycle finished"s << std::endl;
    }
}