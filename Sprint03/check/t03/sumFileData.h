#pragma once
#include <iostream>
#include <fstream>

template <class T>
T sumFileData(const std::string &fileName)
{
    std::ifstream file(fileName);
    T sum = T(0);
    for (auto it = std::istream_iterator<T>(file); it != std::istream_iterator<T>(); it++)
    {
        sum = sum + *it;
    }
    return sum;
}
