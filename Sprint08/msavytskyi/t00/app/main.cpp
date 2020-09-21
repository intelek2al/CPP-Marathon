#include <iostream>
#include <regex>
#include "src/Manager.h"
#include "src/Player.h"
#include "src/Map.h"

int main(int argc, char *argv[])
{
    srand(time(0));
    if (argc != 3)
    {
        std::cerr << "usage: ./smartPointers [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
    size_t w;
    size_t h;
    try
    {
        w = std::stoul(std::string(argv[1]));
        h = std::stoul(std::string(argv[2]));
    }
    catch (...)
    {
        std::cerr << "Wrong input" << std::endl;
    }

    auto player = std::make_shared<Player>();
    auto map = std::make_shared<Map>(w, h, player);

    MoveManager manager(player, map);
    std::cout << ":> ";
    for (std::string line; getline(std::cin, line);)
    {
        try
        {
            if (line == "e")
                return 0;
            manager.processInputAndMove(line);
        }
        catch (std::invalid_argument &ex)
        {
            std::cerr << ex.what() << std::endl;
        }
        std::cout << ":> ";
    }
    return 0;
}
