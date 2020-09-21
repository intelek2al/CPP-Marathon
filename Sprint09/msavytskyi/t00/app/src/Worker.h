#pragma once

#include <iostream>
#include <thread>
#include <functional>

class Worker
{
public:
    Worker() = default;
    ~Worker();

    template <typename Function, class... Args>
    void startWorker(Function &&func, Args &&... args);

    void joinThread();

private:
    std::thread *m_thread{nullptr};
};

Worker::~Worker()
{
    joinThread();
}

template <typename Function, class... Args>
void Worker::startWorker(Function &&func, Args &&... args)
{
    joinThread();
    m_thread = new std::thread(func, std::forward<Args>(args)...);
}

void Worker::joinThread()
{
    if (!m_thread)
        return;
    m_thread->join();
    delete m_thread;
    m_thread = nullptr;
}
