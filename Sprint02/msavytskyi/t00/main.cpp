#include <iostream>
#include <fstream>
#include <set>

#define cout std::cout
#define endl std::endl
#define cerr std::cerr
#define string std::string

void PrintUsage()
{
    cerr << "./uniqueWords [file_name]" << endl;
}

void CutPunct(string &str)
{
    while (!str.empty() && !isalpha(str.back()) && !isdigit(str.back()) && str.back() != '\'' && str.back() != '-')
    {
        str.pop_back();
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
    std::ofstream out("uniqueWords_mod.txt");
    std::set<string> group;

    if (!file)
    {
        cerr << "error" << endl;
        exit(EXIT_FAILURE);
    }

    for (/*string line; getline(file, line);*/ string word; !file.eof();)
    {
        file >> word;
        CutPunct(word);
        // cout << word << endl;
        if (!word.empty())
            group.insert(move(word));
    }
    for (const auto &word : group)
    {
        out << word << endl;
    }
    return 0;
}
