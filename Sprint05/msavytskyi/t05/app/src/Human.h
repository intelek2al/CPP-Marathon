#pragma once

#include <iostream>
#include "Creature.h"

class Human : virtual public Creature
{
public:
    Human() = default;
    ~Human() = default;
};
