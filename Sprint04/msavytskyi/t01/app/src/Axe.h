#pragma once

#include <iostream>

class Axe final
{
public:
    Axe(int damage);
    int getDamage() const;

private:
    const int m_damage;
};
