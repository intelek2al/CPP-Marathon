#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

class MultithreadedFileHandler
{
public:
    MultithreadedFileHandler() = default;
    ~MultithreadedFileHandler() = default;
    void processFile()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condVar.wait(lock, [&] { return m_fileLoaded; });
        m_fileLoaded = false;
        std::cout << m_file << std::endl;
    }

    void loadFile(const std::string &fileName)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::ifstream file(fileName);
        if (!m_file.empty())
        {
            std::cout << "-----1 second sleep-----" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        if (file)
        {
            for (std::string line; getline(file, line);)
                m_file += line + '\n';
            // std::copy(fl, ef, std::back_inserter(m_file));

            m_fileLoaded = true;
        }
        else
            m_fileLoaded = false;
        m_condVar.notify_one();
    }

private:
    std::string m_file;
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_fileLoaded{false};
};
