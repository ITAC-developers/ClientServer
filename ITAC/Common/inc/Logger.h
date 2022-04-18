#pragma once

#include <Logger.h>

#include <atomic>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <utility> //move
#include <vector>

#include <own_literals.h>

namespace ITAC::common
{

/**
 * @brief Callback function that reset output in Logger, if ostream was destroyed
 * @param ev      Event of stream
 * @param stream  Object of stream that rise event
 * @param index   I don't no
 */
void ostream_callback(std::ios::event ev, std::ios_base& stream, int index);

//Test:
//2 - Test SetLvl()
//3 - Test SetOutput()
//5 - Add function SetSplitter that split output arguments with given string
//6 - Test SetSplitter
//7 - Test PraseLogLine


/**
 * Class loger provide easy way to centralization logging
 * It's a thread-safe singelton class
 */
class Logger {
public:

    /**
     * Levels of log enum
     */
    enum class LVL
    {
        TRC, /** For trace massage, like input or output parameters, counter etc. */
        DBG, /** For debug massage, like start/end functions, create/destroy objects etc. */
        INF, /** For information massage, like start server, config state etc. */
        WRN, /** for warning message, like non-critical errors */
        ERR  /** for error message, like error that make it impossible to normally continue app. */
    };

    /** Logger is singelton, copy/move constructor/assigment operator deleted */
    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(const Logger &) = delete;
    Logger &operator=(Logger &&) = delete;

    /**
     * @brief  Get instance of logger. In first time this function call constructor
     *         and return pointer to created instance of logger
     *         In next calls it return pointer in exists instance of logger
     * @return Pointer to the Logger instance
     */
    static Logger *GetInstance();

    /**
     * @brief Set logger level. If function Log called with level lower that logger level,
     *         Log function immediately return without white log
     * @param lvl Any level from LVL enum that be set
     */
    void SetLvl(LVL lvl);

    /**
     * @brief Set output stream. This function register callback for event when
     *        stream is destroyed
     * @param out Any opened stream.
     */
    void SetOutput(std::ostream& out);

    /**
     * @brief Set output file for log. Create all directories if it's not exists
     * @param path Path for opened log file.
     */
    void SetOutput(const std::filesystem::path& path);

    /**
     * @brief Get string representation of current output
     * @return std::cout" || "std::stream" || output file name
     */
    std::string GetOutput();

    /**
     * @brief Get current output level
     * @return Current level
     */
    LVL GetLvl();

    /**
     * @brief Add log line to current output. Each of log line have next format:
     *        [time] [lvl] {func: line} message. This function can construct
     *        message from any count and any type of arguments. But all of args
     *        must be printable (it must have overloaded of operator<< to ostream)
     * @tparam Args Variadic template type
     * @param lvl   Level of message
     * @param func  Function where this method called (use macro from this file
     *              for auto filling this value, or use __func__)
     * @param line  Line where this method called (use macro from this file for
     *              auto filling this value, ot use __LINE__)
     * @param args  Any printable args, that will be concat to message
     */
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
    ~Logger();

    /** This function needed when template args have only one value */
    template<typename T>
    void InnerLog(T t)
    {
        *m_output << t << std::endl;
    }

    /** Recursive function for any count of args */
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

struct LogLine {
    LogLine() = default;
    LogLine(std::string d, std::string l, std::string f, std::string li, std::string c)
        : date(std::move(d))
        , level(std::move(l))
        , func(std::move(f))
        , line(std::move(li))
        , content(std::move(c))
    {}
    std::string date;
    std::string level;
    std::string func;
    std::string line;
    std::string content;
};

/**
 * @brief Create vector of LogLine structure's - one structure for each line
 *        Split input line by '\n'
 * @param line Input line. It can contain many lines separate by '\n'
 * @return
 */
std::vector<LogLine> ParseLogLines(const std::string &lines);

#define TRC(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::TRC, __func__, __LINE__, __VA_ARGS__)
#define DBG(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::DBG, __func__, __LINE__, __VA_ARGS__)
#define INF(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::INF, __func__, __LINE__, __VA_ARGS__)
#define WRN(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::WRN, __func__, __LINE__, __VA_ARGS__)
#define ERR(...) common::Logger::GetInstance()->Log(ITAC::common::Logger::LVL::ERR, __func__, __LINE__, __VA_ARGS__)

} // namespace ITAC::common
