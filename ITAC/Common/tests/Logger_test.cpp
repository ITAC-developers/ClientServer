#include <gtest/gtest.h>

#include <Logger.h>

#include <sstream>
#include <string>

#include <string_funcs.h>  //trim

TEST(Logger, GetInstance) {
    auto *inst1 =  ITAC::common::Logger::GetInstance();
    auto *inst2 = ITAC::common::Logger::GetInstance();
    EXPECT_EQ(inst1, inst2);

    auto lvl = ITAC::common::Logger::LVL::TRC;
    inst1->SetLvl(lvl);
    EXPECT_EQ(inst1->GetLvl(), inst2->GetLvl());
}

TEST(Logger, Log) {
    auto* log = ITAC::common::Logger::GetInstance();
    log->SetLvl(ITAC::common::Logger::LVL::TRC);
    std::stringstream log_output;
    log->SetOutput(log_output);

    const auto lvl = ITAC::common::Logger::LVL::ERR;
    log->Log(lvl, "function_name", 666, "Log");
    log->Log(lvl, "function_name", 666, 15, .5f, 76ULL);

    EXPECT_STREQ(log_output.str().c_str(), "asdf");
}

TEST(Logger, LogMacro) {
    auto *log = ITAC::common::Logger::GetInstance();
    std::stringstream log_output;
    log->SetOutput(log_output);
    log->SetLvl(ITAC::common::Logger::LVL::TRC);
    ITAC::TRC("trace");
    ITAC::DBG("debug");
    ITAC::INF("info");
    ITAC::WRN("warning");
    ITAC::ERR("error");
}

TEST(Logger, SetLvl) {
    { //Test err lvl, just one line must be created
        ITAC::DBG("a");
    }
}

