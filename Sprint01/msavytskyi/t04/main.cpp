#include <iostream>
#include <forward_list>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <iomanip>

#define cout std::cout
#define endl std::endl
#define cerr std::cerr
#define string std::string

void PrintUsage()
{
    cerr << "./stdAlgoV1 [file_name]" << endl;
}

struct Resoult
{
    size_t size;
    bool contain_rich = false;
    bool lengths_15 = true;
    bool all_vel = false;
    size_t not_mel = 0;
};

void Calcul(const std::forward_list<string> &names, Resoult &resoult)
{
    for (const auto &name : names)
    {
        resoult.contain_rich = (name.find("rich") != name.npos);
        if (resoult.contain_rich)
            break;
    }
    for (const auto &name : names)
    {
        resoult.lengths_15 = !(name.length() == 15);
        if (!resoult.lengths_15)
            break;
    }
    for (const auto &name : names)
    {
        const string str = "lev";
        resoult.all_vel = (std::tie(*(name.rbegin()), *(name.rbegin() + 1), *(name.rbegin() + 2)) == std::tie(str[0], str[1], str[2]));
        if (!resoult.all_vel)
            break;
    }
    for (const auto &name : names)
    {
        if (!(name.find("mel") != name.npos))
            resoult.not_mel++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    std::ifstream file(string{argv[1]});
    std::forward_list<string> names;
    Resoult resoult;

    if (!file)
    {
        cerr << "error" << endl;
        exit(EXIT_FAILURE);
    }
    for (string name; getline(file, name);)
    {
        resoult.size++;
        names.push_front(name);
    }
    if (names.empty())
    {
        cerr << "error" << endl;
        exit(EXIT_FAILURE);
    }
    Calcul(names, resoult);
    cout << std::boolalpha << "size: " << resoult.size << '\n'
         << "contains 'rich': " << resoult.contain_rich << '\n'
         << "none of lengths is 15: " << resoult.lengths_15 << '\n'
         << "all end with 'vel': " << resoult.all_vel << '\n'
         << "not contains 'mel': " << resoult.not_mel << endl;
    return 0;
}
