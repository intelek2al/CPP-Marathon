#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <queue>
#include <ctime>
#include <iomanip>

#include "Log.h"
#include "Worker.h"

// class LoggerWorker final : public Worker
// {
// public:
//     ~LoggerWorker() override;
//     static LoggerWorker &getLogger();
//     void log(Log::LogLevel level, const std::string &logMessage);

// private:
//     struct LogMessage
//     {
//         std::string message;
//         Log::LogLevel logLevel;
//     };
//     LoggerWorker();
//     void run() override;
//     std::mutex m_runMutex;
//     std::condition_variable m_condVar;
//     std::ofstream m_logFileStream;
//     std::queue<LogMessage> m_logQueue;
//     inline static std::shared_ptr<LoggerWorker> m_logger{nullptr};
// };

class LoggerWorker final : public Worker
{
public:
    ~LoggerWorker() override
    {
        stop();
        m_condVar.notify_all();
        join();
        m_logFileStream.close();
    }
    static LoggerWorker &getLogger()
    {
        static LoggerWorker worker;
        return worker;
    }
    void log(Log::LogLevel level, const std::string &logMessage)
    {
        m_runMutex.lock();
        m_logQueue.push(LogMessage{logMessage, level});
        m_runMutex.unlock();
        m_condVar.notify_one();
    }

private:
    struct LogMessage
    {
        std::string message;
        Log::LogLevel logLevel;
    };
    LoggerWorker()
    {
        time_t now = time(0);
        std::tm *gmtm = gmtime(&now);
        m_logFileStream.open(getTimeFileName() + ".txt");
        start();
    }
    void run() override
    {
        while (true)
        {
            std::unique_lock<std::mutex> lock(m_runMutex);
            m_condVar.wait(lock, [this]() { return !this->isRunning() || !m_logQueue.empty(); });
            if (!Worker::isRunning() && m_logQueue.empty())
                return;
            getLine(m_logQueue.front());
            m_logQueue.pop();
        }
    }

    std::string getTimeInLog()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%d:%m:%YT%H:%M:%S");
        return ss.str();
    }

    std::string getTimeFileName()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%d_%m_%YT%H_%M_%S");
        return ss.str();
    }

    void getLine(LogMessage &message)
    {
        time_t now = time(0);
        std::tm *gmtm = gmtime(&now);
        m_logFileStream << '[' << getTimeInLog() << "] ";
        m_logFileStream << (message.logLevel == Log::LogLevel::Debug ? "[Debag] " : message.logLevel == Log::LogLevel::Warning ? "[Warning] " : "[Info] ");
        m_logFileStream << message.message << '\n';
    }
    std::mutex m_runMutex;
    std::condition_variable m_condVar;
    std::ofstream m_logFileStream;
    std::queue<LogMessage> m_logQueue;
    inline static std::shared_ptr<LoggerWorker> m_logger{nullptr};
};
