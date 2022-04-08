#include "Server.h"

int main(void)
{
    using namespace itac::server;
    Server server(80);
    server.MainCycle();
    return 0;
}

