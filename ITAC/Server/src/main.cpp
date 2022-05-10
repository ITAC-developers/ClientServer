#include "Server.h"

int main()
{
    MyServer server;
    server.StartServer();
    server.MainCycle();

    return 0;
}
