#pragma once

#include <iostream>
#include "Solder.h"

class ImperialSoldier : public Soldier
{
public:
    ImperialSoldier(std::string &&name, int health);
    ~ImperialSoldier();
};
