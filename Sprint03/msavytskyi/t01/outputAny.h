#pragma once
#include <iostream>

template <class Container>
void outputAny(const Container &c)
{
    for (const auto &l : c)
        std::cout << l << "\n";
}
