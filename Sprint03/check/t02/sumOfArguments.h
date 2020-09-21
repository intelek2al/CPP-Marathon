#pragma once

#include <iostream>

template <class T, class... Ts>
T sumOfArguments(T t, Ts... args)
{
    return t + (... + args);
}
