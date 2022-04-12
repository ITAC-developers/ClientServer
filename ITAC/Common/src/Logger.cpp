#include <Logger.h>
#include <FS.h>

namespace ITAC::common
{

Logger *Logger::GetInstance()
{
    Logger* logger = m_instance.load(std::memory_order_acquire);
    if (!logger)
    {
        std::scoped_lock lock(m_instance_mtx);
        logger = m_instance.load(std::memory_order_relaxed);
        if (!logger)
        {
            logger = new Logger();
            m_instance.store(logger, std::memory_order_release);
        }
    }
    return logger;
}

void Logger::SetLvl(LVL lvl)
{
    std::scoped_lock lock(m_out_mtx);
    level = lvl;
}

bool Logger::SetOutput(std::ostream& out)
{
    std::scoped_lock lock(m_out_mtx);
    output = &out;
    if (!FS::CloseLogFile(logfile)) return false;
    return true;
}

bool Logger::SetOutput(const std::filesystem::path &path)
{
    std::scoped_lock lock(m_out_mtx);
    if (!FS::OpenLogFile(path, output)) return false;
    if (!FS::CloseLogFile(logfile)) return false;
    logfile = path;
}

std::ostream& operator<<(std::ostream& out, Logger::LVL lvl)
{
    using namespace std::string_literals;
    switch(lvl)
    {
        case Logger::LVL::TRC: out << " TRACE "s; break;
        case Logger::LVL::DBG: out << " DEBUG "s; break;
        case Logger::LVL::INF: out << " INFO  "s; break;
        case Logger::LVL::WRN: out << "WARNING"s; break;
        case Logger::LVL::ERR: out << " ERROR "s; break;
    }
}

void Logger::InnerLogStartLine(LVL lvl, const std::string &func, unsigned line) {
    std::time_t now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);
    *output << "[" << std::put_time(&tm, "%x %X %Z") << "] ";
    *output << "[" << lvl << "] ";
    *output << "{" << func << ": " << line << "} ";
}



} //namespace ITAC::common

