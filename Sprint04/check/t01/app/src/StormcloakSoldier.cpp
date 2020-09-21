#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier() : m_health(100), m_weapon(nullptr) {}
StormcloakSoldier::~StormcloakSoldier()
{
    delete m_weapon;
}
void StormcloakSoldier::setWeapon(Axe *sword)
{
    m_weapon = sword;
}
void StormcloakSoldier::attack(ImperialSoldier &enemy)
{
    // if (enemy.getHealth() <= m_weapon->getDamage())
    //     throw std::invalid_argument("Stormcloak");
    std::cout << "Stormcloak soldier attacks and deals " << m_weapon->getDamage() << " damage\n";
    enemy.consumeDamage(m_weapon->getDamage());
}
void StormcloakSoldier::consumeDamage(int amount)
{
    std::cout << "Stormcloak soldier consumes " << amount << " of damage\n";
    m_health -= amount;
}
int StormcloakSoldier::getHealth() const
{
    return m_health;
}
