#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier(std::string &&name, int health) : Soldier(std::move(name), health)
{
    std::cout << "Stormcloak soldier was created" << std::endl;
}

StormcloakSoldier::~StormcloakSoldier()
{
    std::cout << "Stormcloak soldier was deleted" << std::endl;
}
