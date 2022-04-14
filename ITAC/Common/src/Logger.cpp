#include <Logger.h>
#include <FS.h>

namespace ITAC::common
{

void ostream_callback(std::ios::event ev, std::ios_base& stream, [[maybe_unused]] int index)
{
    if (ev == stream.erase_event)
    {
        Logger::GetInstance()->SetOutput(std::cout);
        Logger::GetInstance()->Log(Logger::LVL::INF, __func__, __LINE__,
                                   "Output stream destroy, set std::cout as output");
    }
}

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
    m_level = lvl;
}

void Logger::SetOutput(std::ostream& out)
{
    std::scoped_lock lock(m_out_mtx);
    if (&out != &std::cout)
    {
        out.register_callback(ostream_callback, 0);
    }
    m_output = &out;
    CloseLogFile();
}

void Logger::SetOutput(const std::filesystem::path &path)
{
    std::scoped_lock lock(m_out_mtx);
    CloseLogFile();
    m_log_file_name = path;
    OpenLogFile();
    m_output = &m_log_stream;
}

std::string Logger::GetOutput()
{
    using namespace std::string_literals;
    if (m_log_file_name.empty())
    {
        return "cout"s;
    }
    std::stringstream result;
    result << m_log_file_name.c_str();
    return result.str();
}

Logger::LVL Logger::GetLvl() { return m_level; }

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
    return out;
}

void Logger::InnerLogStartLine(LVL lvl, const std::string &func, unsigned line)
{
    std::time_t now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);
    *m_output << "[" << std::put_time(&tm, "%x %X %Z") << "] ";
    *m_output << "[" << lvl << "] ";
    *m_output << "{" << func << ": " << line << "} ";
}

void Logger::CloseLogFile()
{
    if (m_log_stream.is_open())
    {
        m_log_stream.close();
        m_log_file_name.clear();
    }
}

void Logger::OpenLogFile()
{
    if (m_log_stream.is_open())
    {
        return;
    }
    if (!std::filesystem::exists(m_log_file_name))
    {
        std::filesystem::path dir = m_log_file_name;
        dir.remove_filename();
        if (!dir.empty()) {
            std::filesystem::create_directories(dir.remove_filename());
        }
    }

    m_log_stream.open(m_log_file_name, std::ios::app);
    if (m_log_stream.fail())
    {
        m_log_stream.clear();
        std::cerr << "Can't open/create log file\n";
        std::cerr << "Output set to stdout\n" << std::endl;
        m_log_file_name.clear();
        m_output = &std::cout;
        return;
    }
    m_output = &m_log_stream;
}

//initialize static variable of Logger
std::atomic<Logger*> Logger::m_instance = nullptr;
std::mutex Logger::m_instance_mtx;

} //namespace ITAC::common

