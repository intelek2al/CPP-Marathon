#include <iostream>
#include <regex>
#include <algorithm>
#include "src/dragonborn.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define cerr std::cerr
#define string std::string
#define invalid_argument std::invalid_argument

void PrintUsage()
{
    cout << "usage: ./dragonborn [action]" << endl;
}

int main(int argc, char *argv[])
{
    Dragonborn db;
    if (argc != 2)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    string keyword(argv[1]);
    if (keyword == "shout")
        db.executeAction(Dragonborn::Actions::Shout);
    else if (keyword == "magic")
        db.executeAction(Dragonborn::Actions::Magic);
    else if (keyword == "weapon")
        db.executeAction(Dragonborn::Actions::Weapon);
    else
        cerr << "Invalid action" << endl;
    return 0;
}
