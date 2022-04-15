#include <gtest/gtest.h>

#include <Logger.h>

#include <sstream>
#include <string>

struct LogLineStruct
{
    std::string time;
    std::string level;
    std::string function;
    std::string line;
    std::string text;
};

/*
 * @Brief Function split each line from log file and tokenize it
 * each line represent in vector with structure LogLineStruct
 * @param name: File name
 * @return: vector of LogLineStruct
 */
std::vector<LogLineStruct> ParseLogFile(const std::filesystem::path& file)
{
    std::ifstream log(file);
    if (!log.is_open()) return {};
    std::vector<LogLineStruct> result;
    std::string line;
    while(std::getline(log, line))
    {
        /*
        LogLineStruct lineStruct;
        auto end_time = line.find("]");
        lineStruct.time = line.substr(1, end_time - 1);
        auto start_lvl = line.find("[", end_time);
        auto end_lvl = line.find("]", start_lvl);
        lineStruct.level = line.substr(start_lvl, end_lvl - start_lvl);
        auto &ls = lineStruct.level;
        auto func_start = line.find("{");
        auto func_end = line.find(":", func_start);
        */
    }
    return {};
}

TEST(Logger, GetInstance)
{
    auto *inst1 =  ITAC::common::Logger::GetInstance();
    auto *inst2 = ITAC::common::Logger::GetInstance();
    EXPECT_EQ(inst1, inst2);

    auto lvl = ITAC::common::Logger::LVL::TRC;
    inst1->SetLvl(lvl);
    EXPECT_EQ(inst1->GetLvl(), inst2->GetLvl());
}

TEST(Logger, Log)
{
    auto* log = ITAC::common::Logger::GetInstance();
    log->SetLvl(ITAC::common::Logger::LVL::TRC);
    std::stringstream log_output;
    log->SetOutput(log_output);

    const auto lvl = ITAC::common::Logger::LVL::ERR;
    log->Log(lvl, "function_name", 666, "Log");
    log->Log(lvl, "function_name", 666, 15, .5f, 76ULL);

    EXPECT_STREQ(log_output.str().c_str(), "asdf");
}

TEST(Logger, LogMacro)
{
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

TEST(Logger, SetLvl)
{
    { //Test err lvl, just one line must be created
        ITAC::DBG("a");
    }
}

