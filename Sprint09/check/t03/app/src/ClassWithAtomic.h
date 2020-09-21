#pragma once

#include <iostream>
#include <mutex>
#include <vector>

class ClassWithAtomic
{
public:
    ClassWithAtomic() = default;
    ~ClassWithAtomic() = default;
    void addToInt(int addValue)
    {
        for (int i = 0; i < abs(addValue); ++i)
            m_int++;
    }
    void subtractFromInt(int subtractValue)
    {
        for (int i = 0; i < abs(subtractValue); ++i)
            m_int--;
    }
    void pushToVector(int value)
    {
        // m_vecMutex.lock();
        std::lock_guard<std::mutex> lock(m_vecMutex);
        m_vector.push_back(value);
        // m_vecMutex.unlock();
    }
    void eraseFromVector(int value)
    {
        std::lock_guard<std::mutex> lock(m_vecMutex);
        // m_vecMutex.lock();
        auto it = std::remove_if(m_vector.begin(), m_vector.end(), [&](auto item) { return item == value; });
        if (it != m_vector.end())
            m_vector.erase(it, m_vector.end());
        // m_vecMutex.unlock();
    }
    int getInt() const
    {
        return m_int;
    }
    std::vector<int> getVector() const
    {
        return m_vector;
    }

private:
    std::mutex m_vecMutex;
    std::atomic<int> m_int;
    std::vector<int> m_vector;
};