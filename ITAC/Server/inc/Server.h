#pragma once

namespace itac::server
{
    enum class ServerState
    {
        OFF,
        CONNECTING,
        ERROR,
        ON
    };

    class Server
    {
    public:
        Server(int port);
        ~Server();

        void Stop();
        void MainCycle();

        ServerState GetStatus();
    private:
        ServerState m_state = ServerState::OFF;
        int m_port;
    };

}