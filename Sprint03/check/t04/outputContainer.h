#pragma once
#include <iostream>

template <typename Container>
void outputContainer(const Container &container)
{
    std::ostream_iterator<typename Container::value_type> out_it(std::cout, "\n");
    std::copy(container.begin(), container.end(), out_it);
}
