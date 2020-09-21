#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier() : m_health(100), m_weapon(nullptr)
{
}
ImperialSoldier::~ImperialSoldier()
{
    delete m_weapon;
}
void ImperialSoldier::setWeapon(Sword *sword)
{
    m_weapon = sword;
}
void ImperialSoldier::attack(StormcloakSoldier &enemy)
{
    // if (enemy.getHealth() <= m_weapon->getDamage())
    // {
    //     throw std::invalid_argument("Imperial");
    // }
    std::cout << "Imperial soldier attacks and deals " << m_weapon->getDamage() << " damage\n";
    enemy.consumeDamage(m_weapon->getDamage());
}
void ImperialSoldier::consumeDamage(int amount)
{
    std::cout << "Imperial soldier consumes " << amount << " of damage\n";
    m_health -= amount;
}
int ImperialSoldier::getHealth() const
{
    return m_health;
}
