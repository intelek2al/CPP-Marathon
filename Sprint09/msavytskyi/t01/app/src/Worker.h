#pragma once

#include <iostream>
#include <thread>
#include <functional>
#include <vector>

class Worker
{
public:
    Worker() = default;
    ~Worker();

    template <typename Function, class... Args>
    void startNewThread(Function &&func, Args &&... args);

    void joinAllThreads();

private:
    std::vector<std::thread> m_workerThreads;
};

Worker::~Worker()
{
    joinAllThreads();
}

template <typename Function, class... Args>
void Worker::startNewThread(Function &&func, Args &&... args)
{
    m_workerThreads.push_back(std::thread(func, std::forward<Args>(args)...));
}

void Worker::joinAllThreads()
{
    for (auto &thread : m_workerThreads)
    {
        if (thread.joinable())
            thread.join();
    }
}
