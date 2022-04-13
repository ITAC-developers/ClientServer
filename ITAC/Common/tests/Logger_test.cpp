#include <gtest/gtest.h>

#include <Logger.h>
#include <FS.h>

#include <sstream>
#include <string>

TEST(Logger, SetOutput)
{
    using namespace std::string_literals;
    ITAC::common::Logger* log = ITAC::common::Logger::GetInstance();

    //set stream
    std::stringstream result;
    ASSERT_TRUE(log->SetOutput(result));

    //set file
}

