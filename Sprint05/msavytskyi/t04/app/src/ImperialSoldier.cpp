#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier(std::string &&name, int health) : Soldier(std::move(name), health)
{
    std::cout << "Imperial soldier was created" << std::endl;
}

ImperialSoldier::~ImperialSoldier()
{
    std::cout << "Imperial soldier was deleted" << std::endl;
}
