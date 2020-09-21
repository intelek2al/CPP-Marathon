#include "Solder.h"

Soldier::Soldier(std::string &&name, int health) : m_name(std::move(name)), m_health(100), m_weapon(nullptr)
{
    std::cout << "Soldier " << m_name << " was created" << std::endl;
}

Soldier::~Soldier()
{
    delete m_weapon;
    std::cout << "Soldier " << m_name << " was deleted" << std::endl;
}
void Soldier::attack(Soldier &other)
{
    std::cout << m_name << " attacks and deals " << m_weapon->getDamage() << " damage\n";
    other.m_health -= other.m_weapon->getDamage();
}
void Soldier::setWeapon(Weapon *weapon)
{
    m_weapon = weapon;
}
int Soldier::getHealth() const
{
    return m_health;
}
