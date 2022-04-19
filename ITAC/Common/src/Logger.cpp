#include <Logger.h>

#include <regex>

#include <string_funcs.h>

using namespace std::literals;

namespace ITAC::common
{

void ostream_callback(std::ios::event ev, std::ios_base& stream, [[maybe_unused]] int index) {
    auto *logger = Logger::GetInstance();
    if (ev == stream.erase_event && &stream == logger->GetOutputPtr()) {
        logger->SetOutput(std::cout);
        logger->Log(Logger::LVL::INF, __func__, __LINE__,
                    "Output stream destroy, set std::cout as output");
    }
}

Logger *Logger::GetInstance() {
    Logger* logger = m_instance.load(std::memory_order_acquire);
    if (!logger) {
        std::scoped_lock lock(m_instance_mtx);
        logger = m_instance.load(std::memory_order_relaxed);
        if (!logger) {
            logger = new Logger();
            m_instance.store(logger, std::memory_order_release);
        }
    }
    return logger;
}

void Logger::SetLvl(LVL lvl) {
    std::scoped_lock lock(m_out_mtx);
    m_level = lvl;
}

void Logger::SetOutput(std::ostream& out) {
    std::scoped_lock lock(m_out_mtx);
    CloseLogFile();
    if (&out != &std::cout) {
        out.register_callback(ostream_callback, 0);
    }
    m_output = &out;
}

void Logger::SetOutput(const std::filesystem::path &path) {
    std::scoped_lock lock(m_out_mtx);
    CloseLogFile();
    m_log_file_name = path;
    OpenLogFile();
    m_output = &m_log_stream;
}

std::string Logger::GetOutput() {
    using namespace std::string_literals;
    if (m_log_file_name.empty()) {
        return m_output == &std::cout ? "std::cout"s : "std::ostream"s;
    }
    std::stringstream result;
    result << m_log_file_name.c_str();
    return result.str();
}

std::ostream *Logger::GetOutputPtr() {
    return m_output;
}

Logger::LVL Logger::GetLvl() { return m_level; }

Logger::~Logger() {
    if (!m_log_file_name.empty()) {
        m_log_stream.close();
    }
}

void Logger::InnerLogStartLine(LVL lvl, const std::string &func, unsigned line) {
    std::time_t now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);
    *m_output << "[" << std::put_time(&tm, "%x %X %Z") << "] ";
    *m_output << "[" << lvl << "] ";
    *m_output << "{" << func << ": " << line << "} ";
}

void Logger::CloseLogFile() {
    if (m_log_stream.is_open()) {
        m_log_stream.flush();
        m_log_stream.close();
    }
    m_log_file_name.clear();
    m_log_stream.clear();
    m_output = &std::cout;
}

void Logger::OpenLogFile() {
    if (m_log_stream.is_open())
    {
        CloseLogFile();
    }
    if (!std::filesystem::exists(m_log_file_name)) {
        std::filesystem::path dir = m_log_file_name;
        dir.remove_filename();
        if (!dir.empty()) {
            std::filesystem::create_directories(dir.remove_filename());
        }
    }

    m_log_stream.open(m_log_file_name, std::ios::app);
    if (!m_log_stream) {
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

std::vector<LogLine> ParseLogLines(const std::string &lines) {
    static std::regex log_regex(R"/(\[([\d\w :\/]*)\] \[\s*([^\s]*)\s*\] \{(\w*): (\d*)} (.*))/");
    std::vector<LogLine> result;

    auto match_begin = std::sregex_iterator(lines.begin(), lines.end(), log_regex);
    auto match_end = std::sregex_iterator();

    for (std::sregex_iterator i = match_begin; i != match_end; ++i) {
        result.emplace_back((*i)[1], (*i)[2], (*i)[3], (*i)[4], (*i)[5]);
    }
    return result;
}

} //namespace ITAC::common

std::ostream& operator<<(std::ostream& out, ITAC::common::Logger::LVL lvl) {
    using namespace std::string_literals;
    using L = ITAC::common::Logger::LVL;
    switch(lvl) {
        case L::TRC: out << " TRACE "s; break;
        case L::DBG: out << " DEBUG "s; break;
        case L::INF: out << " INFO  "s; break;
        case L::WRN: out << "WARNING"s; break;
        case L::ERR: out << " ERROR "s; break;
    }
    return out;
}

