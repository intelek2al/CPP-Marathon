#include <iostream>
#include <algorithm>
#include <array>

#define cout std::cout
#define endl std::endl
#define cerr std::cerr
#define string std::string

void PrintUsage()
{
    cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    std::array<string, 5> arr;
    int i = 1;

    for (auto &el : arr)
        el = argv[i++];
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << (i == 4 ? '\n' : ' ');
    }
    return 0;
}
