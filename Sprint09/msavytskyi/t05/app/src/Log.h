#pragma once

#include <iostream>
#include <sstream>

#define logDebug Log::createLog(Log::LogLevel::Debug)
#define logWarning Log::createLog(Log::LogLevel::Warning)
#define logInfo Log::createLog(Log::LogLevel::Info)

class Log final
{
public:
    // using &Log::operator<<;
    enum class LogLevel
    {
        Debug,
        Warning,
        Info
    };
    ~Log();
    static Log createLog(LogLevel level);

    template <class T>
    Log &operator<<(T const &value);

private:
    Log(LogLevel level);
    LogLevel m_logLevel;
    std::stringstream m_inputStream;
};

#include "LoggerWorker.h"

Log::Log(LogLevel level) : m_logLevel(level)
{
}

template <class T>
Log &Log::operator<<(T const &value)
{
    m_inputStream << value << " ";
    return *this;
}

Log::~Log()
{
    LoggerWorker::getLogger().log(m_logLevel, m_inputStream.str());
}

Log Log::createLog(Log::LogLevel level)
{
    return Log(level);
}
