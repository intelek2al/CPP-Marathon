#pragma once

#include <iostream>
#include <functional>
#include <string>

namespace SpecializedFunctions
{

    namespace Math
    {
        template <typename T>
        auto pow2 = std::bind([](T a) { return a * a; }, std::placeholders::_1);

        template <typename T>
        T add(const T arg1, const T arg2)
        {
            return arg1 + arg2;
        }

        auto iDontWontToCalculate = std::bind([]() { return add(2, 2); });

    } // namespace Math

    namespace Output
    {
        template <typename T>
        void output3Arguments(const T &arg1, const T &arg2, const T &arg3)
        {
            std::cout << arg1 << " " << arg2 << " " << arg3 << std::endl;
        }

        template <typename T>
        void outputPrintWords(const T &arg1, const T &arg2, const T &arg3, const T &arg4)
        {
            std::cout << arg1 << " " << arg2 << " " << arg3 << " " << arg4 << std::endl;
        }

        template <typename T>
        auto outputWeird3Arguments = std::bind(output3Arguments<T>, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);
        auto outputFusRoDah = std::bind([]() { output3Arguments<std::string>("Fus", "Roh", "Dah"); });
        auto outputLovelyWords = std::bind([](auto a, auto b, auto c, auto d) { outputPrintWords<std::string>("I", "love", "you", "!"); }, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
    } // namespace Output
} // namespace SpecializedFunctions
