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
    cerr << "./stdAlgoV2 [file_name]" << endl;
}

void Calcul(std::forward_list<string> &names)
{
    for (auto name = names.begin(); name != names.end();)
    {
        // cout << "error" << endl;
        if (name == names.begin())
            if (name->find('c') != name->npos || name->find('b') != name->npos || name->find('l') != name->npos)
            {
                name++;
                names.pop_front();
                continue;
            }
        if (next(name) != names.end() && (next(name)->find('c') != next(name)->npos || next(name)->find('b') != next(name)->npos || next(name)->find('l') != next(name)->npos))
            names.erase_after(name);
        else
        {
            name++;
        }
        // cout << "error1" << endl;
    }
    for (auto name = names.begin(); name != names.end(); name++)
    {
        if (name->length() > 10)
        {
            *name = "Long one";
        }
        else if (name->length() < 4)
            *name = "Short one";
    }
    auto last = std::unique(names.begin(), names.end());
    std::forward_list<string> copy = {names.begin(), last};
    names = move(copy);
    // names.erase_after(last);
    // names.reverse();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    std::ifstream file(string{argv[1]});
    std::ofstream out("names_mod.txt");
    std::forward_list<string> names;
    if (!file)
    {
        cerr << "error" << endl;
        exit(EXIT_FAILURE);
    }
    for (string name; getline(file, name);)
    {
        names.push_front(name);
    }
    if (names.empty())
    {
        cerr << "error" << endl;
        exit(EXIT_FAILURE);
    }
    Calcul(names);
    for (const auto &el : names)
    {
        out << el << endl;
    }
    return 0;
}
