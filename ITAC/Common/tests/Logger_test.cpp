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
    ASSERT_STREQ(log->GetOutput().c_str(), "Out: {std::cout}");
    log->SetOutput("log.log"_p);
    ASSERT_STREQ(log->GetOutput().c_str(), "Out: {\"log.log\": opened}");
    using namespace ITAC::common;
    ERR("testline"s);
    //set file
}

