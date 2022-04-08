#include "Server.h"

#include <iostream> //cout, endl

using namespace std::string_literals;

namespace itac::server
{
    Server::Server(int port) : m_port(port)
    {
        m_state = ServerState::CONNECTING;
        std::cout << "server started"s << std::endl;
    }
    Server::~Server()
    {
        std::cout << "server destroyed"s << std::endl;
    }

    void Server::Stop()
    {
        m_state = ServerState::OFF;
        std::cout << "server stopped"s << std::endl;
    }

    void Server::MainCycle()
    {
        std::cout << "main cycle started"s << std::endl;
        while (false)
        {
            //TODO somthing useful
        }
        m_state = ServerState::ERROR;
        std::cout << "main cycle finished"s << std::endl;
    }

    ServerState Server::GetStatus()
    {
        return m_state;
    }
}

