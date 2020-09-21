#include <iostream>
#include <regex>
#include "src/draugr.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: ./draugr [shoutNumber]" << std::endl;
        exit(EXIT_FAILURE);
    }
    Draugr dr;
    std::cmatch result;
    std::regex regular("\\d");
    if (!std::regex_match(argv[1], result, regular))
    {
        std::cerr << "Invalid shoutNumber" << std::endl;
        exit(EXIT_FAILURE);
    }
    dr.shoutPhrase(std::atoi(argv[1]));
    return 0;
}
