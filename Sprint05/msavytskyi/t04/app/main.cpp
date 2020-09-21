#include <iostream>
#include <regex>
#include <algorithm>
#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"
#include "src/Axe.h"
#include "src/Sword.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define cerr std::cerr
#define string std::string
#define invalid_argument std::invalid_argument

void PrintUsage()
{
    cout << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]" << endl;
}

void Parser(char **argv, ImperialSoldier &is, StormcloakSoldier &ss)
{
    std::cmatch result;
    std::regex regular("(\\d+)");
    if (!std::regex_match(argv[0], result, regular))
        exit(EXIT_FAILURE);
    if (std::stoi(result[1]) < 10 || std::stoi(result[1]) > 20)
    {
        cerr << "Damage has to be in a range of 10-20 points." << endl;
        exit(EXIT_FAILURE);
    }
    is.setWeapon(new Sword(std::stoi(result[1])));
    if (!std::regex_match(argv[1], result, regular))
        exit(EXIT_FAILURE);
    ss.setWeapon(new Axe(std::stoi(result[1])));
    if (std::stoi(result[1]) < 10 || std::stoi(result[1]) > 20)
    {
        cerr << "Damage has to be in a range of 10-20 points." << endl;
        exit(EXIT_FAILURE);
    }
}

void startBattle()
{
    cout << "\n***The battle has begun!***\n"
         << endl;
}

void Fight(ImperialSoldier &is, StormcloakSoldier &ss)
{
    is.attack(ss);
    ss.attack(is);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
}

int main(int argc, char *argv[])
{
    string name = "Martin";
    string name1 = "Flynn";
    ImperialSoldier is(std::move(name), 100);
    StormcloakSoldier ss(std::move(name1), 100);
    if (argc != 3)
    {
        PrintUsage();
        exit(EXIT_FAILURE);
    }
    ++argv;
    Parser(argv, is, ss);
    startBattle();
    while (true)
    {
        if (ss.getHealth() <= 0)
        {
            cout << "Imperial has won!\n"
                 << endl;
            return EXIT_SUCCESS;
        }
        if (is.getHealth() <= 0)
        {
            cout << "Stormcloack has won!\n"
                 << endl;
            return EXIT_SUCCESS;
        }
        try
        {
            Fight(is, ss);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << " has won!" << endl;
            break;
        }
    }
    return 0;
}
