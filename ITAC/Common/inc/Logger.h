#pragma once

#include <Logger.h>

#include <atomic>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>

#include <own_literals.h>

namespace ITAC::common
{

void ostream_callback(std::ios::event ev, std::ios_base& stream, int index);

//TODO close file in destructor
//Test:
//1 - Test GetInstance() - DONE
//2 - Test SetLvl()
//3 - Test SetOutput()
//4 - Test Log() - DONE
//5 - Add function SetSplitter that split output arguments with given string
//6 - Test SetSplitter

class Logger {
public:
    enum class LVL
    {
        TRC, //for trace massage, like input or output parameters, counter etc.
        DBG, //for debug massage, like start/end functions, create/destroy objects etc.
        INF, //for information massage, like start server, config state etc.
        WRN, //for warning message, like non-critical errors
        ERR  //for error message, like error that make it impossible to normally continue app.
    };

    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(const Logger &) = delete;
    Logger &operator=(Logger &&) = delete;

    static Logger *GetInstance();

    void SetLvl(LVL lvl);
    void SetOutput(std::ostream& out);
    void SetOutput(const std::filesystem::path& path);
    std::string GetOutput();
    LVL GetLvl();

    template<typename ...Args>
    void Log(LVL lvl, const std::string &func, unsigned line, Args... args)
    {
        if (lvl < m_level) return;
        std::scoped_lock lock(m_out_mtx);
        InnerLogStartLine(lvl, func, line);
        InnerLog(args...);
    }

private:
    std::filesystem::path m_log_file_name;
    std::ofstream m_log_stream;
    std::ostream *m_output = &std::cout;
    std::mutex m_out_mtx;
    LVL m_level = LVL::WRN;
    static std::atomic<Logger*> m_instance;
    static std::mutex m_instance_mtx;

private:
    Logger() = default;

    void CheckOutput();

    template<typename T>
    void InnerLog(T t)
    {
        *m_output << t << std::endl;
    }

    template<typename T, typename ...Args>
    void InnerLog(T t, Args... args)
    {
        *m_output << t;
        InnerLog(args...);
    }

    void InnerLogStartLine(LVL lvl, const std::string &func, unsigned line);

    void OpenLogFile();
    void CloseLogFile();

};

} // namespace ITAC::common

namespace ITAC
{
#define TRC(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::TRC, __func__, __LINE__, __VA_ARGS__)
#define DBG(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::DBG, __func__, __LINE__, __VA_ARGS__)
#define INF(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::INF, __func__, __LINE__, __VA_ARGS__)
#define WRN(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::WRN, __func__, __LINE__, __VA_ARGS__)
#define ERR(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::ERR, __func__, __LINE__, __VA_ARGS__)
}

