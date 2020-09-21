#include "referenceOrPointer.h"

void multiplyByPointer(int *ptr, int mult)
{
    if (ptr)
        *ptr *= mult;
}
void multiplyByReference(int &ref, int mult)
{
    ref *= mult;
}

// int main()
// {
//     int a = 5;
//     int *n = &a;
//     multiplyByPointer(n, 2);
//     std::cout << *n << std::endl;
//     multiplyByReference(*n, 6);
//     std::cout << *n << std::endl;
// }
