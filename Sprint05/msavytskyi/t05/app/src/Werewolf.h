#pragma once

#include <iostream>
#include "Wolf.h"
#include "Human.h"

class Werewolf : public Wolf, public Human
{
public:
    Werewolf();
    ~Werewolf();
};
