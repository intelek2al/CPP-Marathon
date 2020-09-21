#pragma once

#include <iostream>
#include <vector>

template <typename T>
class ClassWithInitializerList final
{
public:
    template <typename... Args>
    ClassWithInitializerList(Args &&... args) : m_vecOfArs{args...} {}
    ClassWithInitializerList(const std::initializer_list<T> lst)
    {
        std::copy(lst.begin(), lst.end(), std::back_inserter(m_vecOfArs));
    }
    ClassWithInitializerList(const std::vector<T> &vec)
    {
        std::copy(vec.begin(), vec.end(), std::back_inserter(m_vecOfArs));
    }
    void outputVector() const
    {
        for (const auto &el : m_vecOfArs)
            std::cout << el << '\n';
    }

private:
    std::vector<T> m_vecOfArs;
};
