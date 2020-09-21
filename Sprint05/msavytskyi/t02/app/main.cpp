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

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 5)
    {
        std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]" << std::endl;
        exit(EXIT_FAILURE);
    }
    Draugr *dr = NULL;
    try
    {
        std::cmatch result;
        std::regex regular("\\d");
        if (!std::regex_match(argv[1], result, regular))
        {
            throw std::invalid_argument("Invalid shoutNumber");
        }
        if (argc == 4)
            dr = new Draugr{getNum<double>(argv[3])};
        else if (argc == 5)
            dr = new Draugr{getNum<double>(argv[3]), getNum<int>(argv[4])};
        auto names = getNames(argv[2]);
        dr->setName(std::move(names.first));
        dr->shoutPhrase(getNum<double>(argv[1]));
    }
    catch (const std::out_of_range &ex)
    {
        std::cerr << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    Draugr ndr = argc == 4 ? Draugr(*dr) : Draugr(std::move(*dr));
    auto names = getNames(argv[2]);
    ndr.setName(git clone );
    ndr.shoutPhrase(getNum<double>(argv[1]));
    return 0;
}
