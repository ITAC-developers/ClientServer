#include <gtest/gtest.h>

#include <Logger.h>

#include <sstream>
#include <string>

std::string GetFileContents(std::filesystem::path &path) {
    std::ifstream stream(path);

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
    EXPECT_EQ((int)inst1->GetLvl(), (int)inst2->GetLvl());
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

TEST(Logger, SetLvl) {
    auto *log = ITAC::common::Logger::GetInstance();
    using lvl = ITAC::common::Logger::LVL;
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::ERR);
        log->Log(lvl::TRC, __func__, __LINE__, "trace");
        log->Log(lvl::DBG, __func__, __LINE__, "debug");
        log->Log(lvl::INF, __func__, __LINE__, "info");
        log->Log(lvl::WRN, __func__, __LINE__, "warning");
        log->Log(lvl::ERR, __func__, __LINE__, "error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 1U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::WRN);
        log->Log(lvl::TRC, __func__, __LINE__, "trace");
        log->Log(lvl::DBG, __func__, __LINE__, "debug");
        log->Log(lvl::INF, __func__, __LINE__, "info");
        log->Log(lvl::WRN, __func__, __LINE__, "warning");
        log->Log(lvl::ERR, __func__, __LINE__, "error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 2U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::INF);
        log->Log(lvl::TRC, __func__, __LINE__, "trace");
        log->Log(lvl::DBG, __func__, __LINE__, "debug");
        log->Log(lvl::INF, __func__, __LINE__, "info");
        log->Log(lvl::WRN, __func__, __LINE__, "warning");
        log->Log(lvl::ERR, __func__, __LINE__, "error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 3U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::DBG);
        log->Log(lvl::TRC, __func__, __LINE__, "trace");
        log->Log(lvl::DBG, __func__, __LINE__, "debug");
        log->Log(lvl::INF, __func__, __LINE__, "info");
        log->Log(lvl::WRN, __func__, __LINE__, "warning");
        log->Log(lvl::ERR, __func__, __LINE__, "error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 4U);
        log->SetOutput(std::cout);
    }
    {
        std::stringstream log_output;
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::TRC);
        log->Log(lvl::TRC, __func__, __LINE__, "trace");
        log->Log(lvl::DBG, __func__, __LINE__, "debug");
        log->Log(lvl::INF, __func__, __LINE__, "info");
        log->Log(lvl::WRN, __func__, __LINE__, "warning");
        log->Log(lvl::ERR, __func__, __LINE__, "error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        EXPECT_EQ(t.size(), 5U);
        log->SetOutput(std::cout);
    }
}

TEST(Logger, SetOutput) {
    auto *log = ITAC::common::Logger::GetInstance();
    using lvl = ITAC::common::Logger::LVL;
    log->SetLvl(lvl::TRC);

    auto path = "../file.log"_p;
    if (std::filesystem::exists(path))
    {
        std::filesystem::remove(path);
    }
    log->SetOutput(path);

    ASSERT_TRUE(std::filesystem::exists(path));
    log->Log(lvl::TRC, __func__, __LINE__, "trace");
    log->Log(lvl::DBG, __func__, __LINE__, "debug");
    log->Log(lvl::INF, __func__, __LINE__, "info");
    log->SetOutput(std::cout);
    {
        std::ifstream stream(path, std::ios::in);
        stream.seekg(0);
        ASSERT_TRUE(stream);
        std::string file_content = GetFileContents(path);
        EXPECT_FALSE(file_content.empty());
        auto t = ITAC::common::ParseLogLines(file_content);
        EXPECT_EQ(t.size(), 3U);
    }

    std::ofstream fs(path, std::ios::app);
    ASSERT_TRUE(std::filesystem::exists(path));
    log->SetOutput(fs);
    log->Log(lvl::DBG, __func__, __LINE__, "debug");
    log->Log(lvl::INF, __func__, __LINE__, "info");
    log->SetOutput(std::cout);
    fs.close();
    {
        std::string file_content = GetFileContents(path);
        ASSERT_FALSE(file_content.empty());
        auto t = ITAC::common::ParseLogLines(file_content);
        EXPECT_EQ(t.size(), 5U);
    }

    std::stringstream ss;
    log->SetOutput(ss);
    log->Log(lvl::WRN, __func__, __LINE__, "warning");
    log->Log(lvl::ERR, __func__, __LINE__, "error");
    log->SetOutput(std::cout);
    {
        auto t = ITAC::common::ParseLogLines(ss.str());
        EXPECT_EQ(t.size(), 2U);
    }
}

TEST(Logger, ParseLogLines) {
    const std::string valid =
            "[04/17/22 21:02:22 MSK] [ TRACE ] {TestBody: 38} trace\n"
            "[04/17/22 21:02:22 MSK] [ WARNING ] {Func: 155} somelog\n";
    const std::string partial_valid =
            "[04/17/22 21:02:22 MSK] [ TRACE ] {TestBody: 38} trace\n"
            "[04/17/22 21:02:22 MSK] [ TRACE ] TestBody: 38} trace\n";
    const std::string not_valid =
            "[04/17/22 21:02:22 MSK] [ TRACE  {TestBody: 38} trace\n"
            "I'm bad log line\n";
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

