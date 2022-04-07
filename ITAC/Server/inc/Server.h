#pragma once

namespace itac::server
{
    class Server
    {
    public:
        Server(int port);
        ~Server();

        void Stop();
        void MainCycle();
    private:
        int port;
    };

}