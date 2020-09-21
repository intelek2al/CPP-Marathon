#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>

#define cout std::cout
#define endl std::endl
#define cerr std::cerr
#define string std::string

void PrintUsage()
{
    cerr << "usage: ./visitAll [[name,stamina,distance] ...]" << endl;
}

template <typename To, typename Function>
To Converter(const string &str, Function func)
{
    To res;
    size_t ptr;
    res = func(str, &ptr);
    if (str[ptr] != '\0')
        throw std::invalid_argument("");
    return res;
}

struct Town
{
    string name;
    int stamina;
    int distance;
};

struct Person
{
    string name;
    int stamina;
    int distance;
};

Town SingleParse(const string &str)
{
    string name;
    string tmp;
    int stamina;
    int distance;
    auto str_start = str.begin();
    auto str_finish = str.end();

    auto it = find(str_start, str_finish, ',');
    if (it != str_finish)
    {
        name = {str_start, it};
        str_start = it + 1;
    }
    else
        throw std::invalid_argument("str");
    it = find(str_start, str_finish, ',');
    if (it != str_finish)
    {
        tmp = {str_start, it};
        str_start = it + 1;
    }
    else
        throw std::invalid_argument("str");
    stamina = Converter<int>(tmp, [](const string &str, size_t *ptr) { return stoi(str, ptr); });
    tmp = {str_start, str_finish};
    distance = Converter<int>(tmp, [](const string &str, size_t *ptr) { return stoi(str, ptr); });
    return {name, stamina, distance};
}

std::deque<Town> Parser(char **argv, int argc)
{
    std::deque<Town> deq;
    string err;
    try
    {
        for (int i = 0; i < argc; i++)
        {
            err = string(argv[i]);
            deq.push_back(SingleParse(string(argv[i])));
        }
    }
    catch (const std::exception &e)
    {
        cerr << "Argument " << err << " is not valid" << endl;
        exit(EXIT_FAILURE);
    }
    return deq;
}

std::pair<bool, std::deque<size_t>> Calcul(const std::deque<Town> set)
{
    bool flag = false;
    std::deque<size_t> ret;
    for (size_t i = 0; i < set.size(); i++)
    {
        flag = true;
        int pers = set[i].stamina;
        std::deque<size_t> res(set.size());
        size_t counter = 0;
        res[counter++] = i;
        // cout << "Start from " << set[i].name << endl;
        for (size_t j = i + 1; counter < set.size(); j++, counter++)
        {
            if (j == set.size())
                j = 0;
            pers -= set[j].distance;
            if (pers < 0)
            {
                flag = false;
                // cout << "cant move to " << set[j].name << endl;
                break;
            }
            // cout << "\tgo " << set[j].name << endl;
            res[counter] = j;
            pers += set[j].stamina;
        }
        // cout << "--- " << flag << " ---" << endl;
        if (flag)
        {
            // cout << "Index returned" << res[0] << res[1] << res[2] << res[3] << endl;
            ret = res;
            break;
        }
    }
    return {flag, ret};
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        PrintUsage();
    std::deque<Town> deq = Parser(++argv, --argc);
    auto check = Calcul(deq);
    if (!check.first)
    {
        cerr << "Mission: Impossible" << endl;
        exit(EXIT_FAILURE);
    }
    std::deque<size_t> &index = check.second;
    for (const auto &id : index)
    {
        cout << id << ". " << deq[id].name << " " << deq[id].stamina << " " << deq[id].distance << '\n';
    }
    return 0;
}
