#include <iostream>
#include <regex>
#include "src/draugr.h"

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
    if (argc < 2 || argc > 4)
    {
        std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]" << std::endl;
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
        switch (--argc)
        {
        case 1:
            dr = new Draugr{};
            dr->shoutPhrase(getNum<double>(argv[1]));
            break;
        case 2:
        {
            dr = new Draugr{getNum<double>(argv[2])};
            dr->shoutPhrase(getNum<double>(argv[1]));
            Draugr drd(getNum<int>(argv[2]));
            drd.shoutPhrase(getNum<double>(argv[1]));
            break;
        }
        case 3:
            dr = new Draugr{getNum<double>(argv[2]), getNum<int>(argv[3])};
            dr->shoutPhrase(getNum<double>(argv[1]));
            break;
        }
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
    return 0;
}
