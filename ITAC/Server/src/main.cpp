#include "Server.h"
#include <Logger.h>

int main(void)
{
    using namespace itac::server;
    Server server(80);
    server.MainCycle();

    using level = ITAC::common::Logger::LVL;
    {
        std::stringstream log_output;
        auto *log = ITAC::common::Logger::GetInstance();
        log->SetOutput(log_output);
        log->SetLvl(ITAC::common::Logger::LVL::TRC);
        log->Log(level::TRC, __func__, __LINE__, "trace");
        log->Log(level::DBG, __func__, __LINE__, "debug");
        log->Log(level::INF, __func__, __LINE__, "info");
        log->Log(level::WRN, __func__, __LINE__, "warning");
        log->Log(level::ERR, __func__, __LINE__, "error");

        auto t = ITAC::common::ParseLogLines(log_output.str());
        std::cout << t.size() << std::endl;
        log->SetOutput(std::cout);
    }

    auto *log = ITAC::common::Logger::GetInstance();
    auto path = "../file3.log"_p;
    if (std::filesystem::exists(path))
    {
        std::filesystem::remove(path);
    }
    log->SetOutput(path);
    log->Log(level::ERR, __func__, __LINE__, "trace");
    log->Log(level::WRN, __func__, __LINE__, "debug");
    log->SetOutput(std::cout);
    {
        std::ifstream stream(path, std::ios::in);
        if (!stream)
        {
            std::cout << "open fail" << std::endl;
        }

        std::string file_content =
                std::string(std::istreambuf_iterator<char>(stream),
                            std::istreambuf_iterator<char>());
        std::cout << file_content.empty() << std::endl;
        auto t = ITAC::common::ParseLogLines(file_content);
        std::cout << t.size() << std::endl;
    }
    return 0;
}

