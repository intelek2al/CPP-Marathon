#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#define cout std::cout
#define endl std::endl
#define cerr std::cerr
#define string std::string

void PrintUsage()
{
    cerr << "usage: ./moveAlong [args]" << endl;
}

bool Check(const std::set<string> &group, string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (const auto &w : group)
    {
        auto it = str.find(w);
        if (it != str.npos)
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    std::vector<string> cont;
    std::set<string> group = {"mercer", "emer", "jim"};
    for (int i = 1; i < argc; i++)
        if (Check(group, string(argv[i])))
            cont.push_back(string(argv[i]));
    for (const auto &el : cont)
    {
        cout << el << ", move along!" << endl;
    }
    return 0;
}
