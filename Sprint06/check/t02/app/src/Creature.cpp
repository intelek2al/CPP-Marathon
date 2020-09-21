#include "Creature.h"

using namespace Creatures;

std::string getTypeString(Spells::SpellType type)
{
    switch (type)
    {
    case Spells::SpellType::Healing:
        return "healling";
    case Spells::SpellType::Freeze:
        return "freeze";
    case Spells::SpellType::Flames:
        return "flames";
    case Spells::SpellType::Fireball:
        return "fireball";
    case Spells::SpellType::Equilibrium:
        return "equilibrium";
    }
    return "";
}

Creatures::Creature::Creature(std::string &&name)
{
    m_name = std::move(name);
    std::cout << m_name << " was born!" << std::endl;
}

Creature::~Creature()
{
    for (auto &it : m_spells)
        delete it;
    m_spells.clear();
}

void Creature::learnSpell(Spells::ISpell *spell)
{
    if (!spell)
        return;
    if (std::count_if(m_spells.begin(), m_spells.end(),
                      [&](const auto &it) { return *it == *spell; }) != 0)
    {
        std::cout << m_name << " already knows " << getTypeString(spell->getType()) << " spell!" << std::endl;
        return;
    }
    std::cout << m_name << " has learned " << getTypeString(spell->getType()) << " spell successfully!" << std::endl;
    m_spells.insert(spell);
}
void Creature::castSpell(const Spells::SpellType type, Creature &creature)
{
    if (count_if(m_spells.begin(), m_spells.end(),
                 [&](const auto &it) { return it->getType() == type; }) != 1)
    {
        std::cout << getTypeString(type) << " spell is not learned by " << m_name << std::endl;
        return;
    }
    auto it = std::find_if(m_spells.begin(), m_spells.end(), [&](const auto &it) { return it->getType() == type; });
    if ((*it)->cast(*this, creature))
        std::cout
            << m_name << " casted " << getTypeString(type) << " spell on " << creature.getName() << std::endl;
    else
        std::cout << m_name << " can't cast " << getTypeString(type) << std::endl;
}
std::string Creature::getName() const
{
    return m_name;
}
int Creature::getHealth() const
{
    return m_health;
}
int Creature::getMana() const
{
    return m_mana;
}

void Creature::setHealth(int health)
{
    m_health = health;
}
void Creature::setMana(int mana)
{
    m_mana = mana;
}

std::ostream &operator<<(std::ostream &os, const Creatures::Creature &creature)
{
    os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP";
    return os;
}
