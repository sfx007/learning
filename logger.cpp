#include "../include/logger.hpp"


/*-------------[MEMBERS]---------------*/

TrustLog::TrustLog(const std::string& file)
{
    _logger.open(file);
    if(!_logger.is_open())
        std::cerr << "Error: failed to open logger" << std::endl;
}

TrustLog::~TrustLog()
{
    _logger.close();
}

void TrustLog::write(std::string level,const std::string& component, const std::string& message)
{
    _logger << now_ms() << "\t" << level << "\t" << component << "\t" << message << "\n";
}



/*---------------[Helpers Functions]---------------*/

std::string level_to_string(Level level)
{
    switch (level)
    {
        case Level::INFO:
            return "INFO";
        case Level::ERROR:
            return "ERROR";
        case Level::WARN:
            return "WARN";
        default:
            break;
    }
    return "UNKNOWN";
}

std::string now_ms()
{
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return std::to_string(ms);
}


Level string_to_level(std::string level)
{
    if(level == "INFO")
        return Level::INFO;
    else if(level == "WARN")
        return Level::WARN;
    else if(level == "ERROR")
        return Level::ERROR;
    else
        return Level::UNKNOWN;
}
