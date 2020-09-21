#include "Log.h"
// #include "LoggerWorker.h"

// Log::Log(LogLevel level) : m_logLevel(level) {}

// template <class T>
// Log &Log::operator<<(T const &value)
// {
//     m_inputStream << value << " ";
//     return *this;
// }

// Log::~Log()
// {
//     LoggerWorker::getLogger().log(m_logLevel, m_inputStream.str());
// }

// Log Log::createLog(Log::LogLevel level)
// {
//     // Log l{level};
//     return Log(level);
// }