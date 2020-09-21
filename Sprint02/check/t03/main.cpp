#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <regex>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define cerr std::cerr
#define string std::string
#define invalid_argument std::invalid_argument

void PrintUsage()
{
    cerr << "./tesLibrary [file_name]" << endl;
}

std::multimap<string, string> Parse(std::ifstream &file, std::set<string> &authors)
{
    std::multimap<string, string> list;
    int Line = 0;
    std::cmatch result;
    for (string line; getline(file, line);)
    {
        Line++;
        if (line.empty())
            continue;
        std::regex regular("\\s*\"([^\"]+)\"\\s*:\\s*\"([^\"]+)\"\\s*");
        if (std::regex_match(line.c_str(), result, regular))
        {
            list.insert(make_pair(result.str(1), result.str(2)));
            authors.insert(result.str(1));
        }
        else
        {
            cerr << "Line " << Line << " is invalid" << endl;
            exit(EXIT_FAILURE);
        }
    }
    return list;
}

template <typename Iteretor>
void PrintBooks(Iteretor begin, Iteretor end)
{
    size_t counter = 1;
    for (auto it = begin; it != end; it++)
    {
        cout << "  " << counter << ". " << it->second << endl;
        counter++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    std::ifstream file(argv[1]);
    std::set<string> authors;
    std::multimap<string, string> list;
    if (!file)
    {
        cerr << "error" << endl;
        exit(EXIT_FAILURE);
    }
    list = Parse(file, authors);
    for (const auto &a : authors)
    {
        auto range = list.equal_range(a);
        cout << a << ":" << endl;
        PrintBooks(range.first, range.second);
    }

    return 0;
}
