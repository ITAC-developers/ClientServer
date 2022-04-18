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

    auto t = ITAC::common::ParseLogLines(log_output.str());
    EXPECT_STREQ(t[0].level.c_str(), "ERROR");
    EXPECT_STREQ(t[1].level.c_str(), "ERROR");
    EXPECT_STREQ(t[0].func.c_str(), "function_name");
    EXPECT_STREQ(t[1].func.c_str(), "function_name");
    EXPECT_STREQ(t[0].line.c_str(), "666");
    EXPECT_STREQ(t[1].line.c_str(), "666");
    EXPECT_STREQ(t[0].content.c_str(), "Log");
    EXPECT_STREQ(t[1].content.c_str(), "150.576");
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
    auto t = ITAC::common::ParseLogLines(log_output.str());

    ASSERT_EQ(t.size(), 5U);

    EXPECT_STREQ(t[0].level.c_str(), "TRACE");
    EXPECT_STREQ(t[1].level.c_str(), "DEBUG");
    EXPECT_STREQ(t[2].level.c_str(), "INFO");
    EXPECT_STREQ(t[3].level.c_str(), "WARNING");
    EXPECT_STREQ(t[4].level.c_str(), "ERROR");

    EXPECT_STREQ(t[0].content.c_str(), "trace");
    EXPECT_STREQ(t[1].content.c_str(), "debug");
    EXPECT_STREQ(t[2].content.c_str(), "info");
    EXPECT_STREQ(t[3].content.c_str(), "warning");
    EXPECT_STREQ(t[4].content.c_str(), "error");

    for (int i = 0; i < 5; ++i)
    {
        EXPECT_STREQ(t[i].func.c_str(), "TestBody");
        EXPECT_EQ(t[i].line, std::to_string(i + 46).c_str());
    }
}

TEST(Logger, SetLvl) {
    auto *log = ITAC::common::Logger::GetInstance();
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::ERR);
        ITAC::TRC("trace");
        ITAC::DBG("debug");
        ITAC::INF("info");
        ITAC::WRN("warning");
        ITAC::ERR("error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 1U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::WRN);
        ITAC::TRC("trace");
        ITAC::DBG("debug");
        ITAC::INF("info");
        ITAC::WRN("warning");
        ITAC::ERR("error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 2U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::INF);
        ITAC::TRC("trace");
        ITAC::DBG("debug");
        ITAC::INF("info");
        ITAC::WRN("warning");
        ITAC::ERR("error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 3U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::DBG);
        ITAC::TRC("trace");
        ITAC::DBG("debug");
        ITAC::INF("info");
        ITAC::WRN("warning");
        ITAC::ERR("error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 4U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::TRC);
        ITAC::TRC("trace");
        ITAC::DBG("debug");
        ITAC::INF("info");
        ITAC::WRN("warning");
        ITAC::ERR("error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 5U);
        log->SetOutput(std::cout);
    }
}

