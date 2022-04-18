#include <gtest/gtest.h>

#include <Logger.h>

#include <sstream>
#include <string>


std::string GetFileContents(const std::string &file) {
    std::ifstream stream(file);

    // create string by to iterators
    return {
        (std::istreambuf_iterator<char>(stream)),
        std::istreambuf_iterator<char>()
    };
}

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
    log->SetOutput(std::cout);
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
    log->SetOutput(std::cout);
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

TEST(Logger, SetOutput) {
    auto *log = ITAC::common::Logger::GetInstance();
    auto path = "file.log"_p;
    log->SetOutput(path);
    ITAC::TRC("trace");
    ITAC::DBG("debug");
    ITAC::INF("info");
    log->SetOutput(std::cout);
    {
        std::string file_content = GetFileContents("file.log");
        auto t = ITAC::common::ParseLogLines(file_content);
        EXPECT_EQ(t.size(), 3U);
    }
    std::filesystem::remove(path);

    std::ofstream fs(path);
    log->SetOutput(fs);
    ITAC::DBG("debug");
    ITAC::INF("info");
    fs.close();
    log->SetOutput(std::cout);
    {
        std::string file_content = GetFileContents("file.log");
        auto t = ITAC::common::ParseLogLines(file_content);
        EXPECT_EQ(t.size(), 2U);
    }
    std::filesystem::remove(path);

    std::stringstream ss;
    log->SetOutput(ss);
    ITAC::WRN("warning");
    ITAC::ERR("error");
    log->SetOutput(std::cout);
    {
        auto t = ITAC::common::ParseLogLines(ss.str());
        EXPECT_EQ(t.size(), 2U);
    }
}

TEST(Logger, ParseLogLines) {
    const std::string valid =
            "[04/17/22 21:02:22 MSK] [ TRACE ] {TestBody: 38} trace\n"
            "[04/17/22 21:02:22 MSK] [ WARNING ] {Func: 155} somelog";
    const std::string partial_valid =
            "[04/17/22 21:02:22 MSK] [ TRACE ] {TestBody: 38} trace\n"
            "[04/17/22 21:02:22 MSK] [ TRACE ] TestBody: 38} trace";
    const std::string not_valid =
            "[04/17/22 21:02:22 MSK] [ TRACE  {TestBody: 38} trace\n"
            "I'm bad log line";
    {
        auto t = ITAC::common::ParseLogLines(valid);
        ASSERT_EQ(t.size(), 2U);
        EXPECT_STREQ(t[0].date.c_str(), "04/17/22 21:02:22 MSK");
        EXPECT_STREQ(t[0].level.c_str(), "TRACE");
        EXPECT_STREQ(t[0].func.c_str(), "TestBody");
        EXPECT_STREQ(t[0].line.c_str(), "38");
        EXPECT_STREQ(t[0].content.c_str(), "trace");
        EXPECT_STREQ(t[1].date.c_str(), "04/17/22 21:02:22 MSK");
        EXPECT_STREQ(t[1].level.c_str(), "WARNING");
        EXPECT_STREQ(t[1].func.c_str(), "Func");
        EXPECT_STREQ(t[1].line.c_str(), "155");
        EXPECT_STREQ(t[1].content.c_str(), "somelog");
    }
    {
        auto t = ITAC::common::ParseLogLines(partial_valid);
        ASSERT_EQ(t.size(), 1U);
        EXPECT_STREQ(t[0].date.c_str(), "04/17/22 21:02:22 MSK");
        EXPECT_STREQ(t[0].level.c_str(), "TRACE");
        EXPECT_STREQ(t[0].func.c_str(), "TestBody");
        EXPECT_STREQ(t[0].line.c_str(), "38");
        EXPECT_STREQ(t[0].content.c_str(), "trace");
    }
    {
        auto t = ITAC::common::ParseLogLines(not_valid);
        ASSERT_EQ(t.size(), 0U);
    }
}

