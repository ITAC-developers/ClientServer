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

//TODO close file in destructor
//Test:
//1 - GetInstance()
//2 - SetLvl()
//3 - SetOutput()
//4 - Log()

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

    template<typename ...Args>
    void Log(LVL lvl, const std::string &func, unsigned line, Args... args)
    {
        if (lvl < level) return;
        std::scoped_lock lock(m_out_mtx);
        InnerLogStartLine(lvl, func, line);
        InnerLog(args...);
    }

private:
    std::filesystem::path m_log_file_name;
    std::ofstream m_log_stream;
    std::ostream *output = &std::cout;
    std::mutex m_out_mtx;
    LVL level = LVL::WRN;
    static std::atomic<Logger*> m_instance;
    static std::mutex m_instance_mtx;

private:
    Logger() = default;

    template<typename T>
    void InnerLog(T t)
    {
        *output << t << std::endl;
    }

    template<typename T, typename ...Args>
    void InnerLog(T t, Args... args)
    {
        *output << t;
        InnerLog(args...);
    }

    void InnerLogStartLine(LVL lvl, const std::string &func, unsigned line);

    void OpenLogFile();
    void CloseLogFile();

};
/*
    std::filesystem::path log_dir = std::filesystem::current_path() / "log"_p;
    std::filesystem::path file_name = "dbg.log"_p;
    std::ostream &output;
     */
    //поток вывода. Если файлб он должен быть открыт/закрыт
    //уровень логгирования

#define TRC(...) Logger::GetInstance()->Log(Logger::LVL::TRC, __func__, __LINE__, __VA_ARGS__)
#define DBG(...) Logger::GetInstance()->Log(Logger::LVL::DBG, __func__, __LINE__, __VA_ARGS__)
#define INF(...) Logger::GetInstance()->Log(Logger::LVL::INF, __func__, __LINE__, __VA_ARGS__)
#define WRN(...) Logger::GetInstance()->Log(Logger::LVL::WRN, __func__, __LINE__, __VA_ARGS__)
#define ERR(...) Logger::GetInstance()->Log(Logger::LVL::ERR, __func__, __LINE__, __VA_ARGS__)

} // namespace ITAC::common

