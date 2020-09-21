#pragma once
#include <iostream>

template <class Container>
void squareValue(Container &container)
{
    for (typename Container::iterator it = container.begin(); it != container.end(); it++)
    {
        *it *= *it;
    }
}
