#pragma once

#include <iostream>

class Sword final
{
public:
    Sword(int damage);
    int getDamage() const;

private:
    const int m_damage;
};
