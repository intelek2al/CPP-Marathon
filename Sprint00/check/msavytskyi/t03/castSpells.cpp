#include "castSpells.h"

int castFloatToInt(float number)
{
    return static_cast<int>(number);
}
int *castToNonConstIntPtr(const int *ptr)
{
    return const_cast<int *>(ptr);
}

// int main()
// {
//     const int *n = new int(5);
//     std::cout << *castToNonConstIntPtr(n) << std::endl
//               << castFloatToInt(6.4) << std::endl;
// }
