#pragma once
#include <thread>
#include <mutex>

class MultithreadedClass
{
public:
    MultithreadedClass() = default;
    ~MultithreadedClass() = default;
    int getInt() const
    {
        return m_int;
    }
    void add(int addValue)
    {
        m_mutex.lock();
        m_int += addValue;
        m_mutex.unlock();
    }
    void subtract(int subtractValue)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_int -= subtractValue;
    }

private:
    int m_int{0};
    std::mutex m_mutex;
};