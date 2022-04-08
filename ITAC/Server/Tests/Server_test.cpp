#include <gtest/gtest.h>
#include "Server.h"

TEST(Server, Status)
{
    using namespace itac::server;
    Server server(8);
    ASSERT_EQ(server.GetStatus(), ServerState::CONNECTING);
    ASSERT_EQ(server.GetStatus(), ServerState::ERROR);
}

