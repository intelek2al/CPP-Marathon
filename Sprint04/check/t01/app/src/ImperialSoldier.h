#pragma once

#include <iostream>
#include "StormcloakSoldier.h"
#include "Sword.h"

class StormcloakSoldier;

class ImperialSoldier final
{
public:
    ImperialSoldier();
    ~ImperialSoldier();
    void setWeapon(Sword *sword);
    void attack(StormcloakSoldier &enemy);
    void consumeDamage(int amount);
    int getHealth() const;

private:
    Sword *m_weapon = nullptr;
    int m_health;
};