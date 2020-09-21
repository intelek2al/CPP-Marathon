#include <iostream>
#include <regex>
#include "src/draugr.h"

std::pair<std::string, std::string> getNames(char *argv)
{
    std::cmatch result;
    std::regex regular("([a-zA-Z]+),([a-zA-Z]+)");
    if (!std::regex_match(argv, result, regular))
    {
        throw std::invalid_argument("Invalid names");
    }
    return make_pair(std::string(result[1]), std::string(result[2]));
}

template <typename T>
T getNum(char *argv)
{
    std::cmatch result;
    std::regex regular("(^[0-9]*)|(^[0-9]+\\.?[0-9]+)");
    if (!std::regex_match(argv, result, regular))
    {
        throw std::invalid_argument("Error");
    }
    if (typeid(T) == typeid(int))
        return std::stoi(std::string(argv));
    return std::stod(std::string(argv));
}

int main()
{
    Draugr d1;
    d1.setName("Death Overlord");
    d1.shoutPhrase(3);
    // Draugr d2 = d1;
    Draugr d3(10.0, 30);
    d3.setName("Thrall");
    d3.shoutPhrase(4);
    // Draugr d4 = std::move(d3);
    return 0;
}
