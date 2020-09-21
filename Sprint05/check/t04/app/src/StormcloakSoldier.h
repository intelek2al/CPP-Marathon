#pragma once

#include <iostream>
#include "Solder.h"

class StormcloakSoldier : public Soldier
{
public:
    StormcloakSoldier(std::string &&name, int health);
    ~StormcloakSoldier();
};
