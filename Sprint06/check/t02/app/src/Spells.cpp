#include "Spells.h"

using namespace Spells;

bool Healing::cast(Creatures::Creature &owner, Creatures::Creature &)
{
    if (owner.getMana() - 15 < 0)
        return false;
    owner.setHealth(owner.getHealth() + 10);
    owner.setMana(owner.getMana() - 15);
    return true;
}
SpellType Healing::getType() const
{
    return type;
}

bool Equilibrium::cast(Creatures::Creature &owner, Creatures::Creature &)
{
    if (owner.getHealth() - 25 < 0)
        return false;
    owner.setHealth(owner.getHealth() - 25);
    owner.setMana(owner.getMana() + 25);
    return true;
}
SpellType Equilibrium::getType() const
{
    return type;
}

bool Flames::cast(Creatures::Creature &owner, Creatures::Creature &other)
{
    if (owner.getMana() - 114 < 0)
        return false;
    other.setHealth(other.getHealth() - 8);
    owner.setMana(owner.getMana() - 14);
    return true;
}
SpellType Flames::getType() const
{
    return type;
}

bool Freeze::cast(Creatures::Creature &owner, Creatures::Creature &other)
{
    if (owner.getMana() - 30 < 0)
        return false;
    other.setHealth(other.getHealth() - 20);
    owner.setMana(owner.getMana() - 30);
    return true;
}
SpellType Freeze::getType() const
{
    return type;
}

bool Fireball::cast(Creatures::Creature &owner, Creatures::Creature &other)
{
    if (owner.getMana() - 50 < 0)
        return false;
    other.setHealth(other.getHealth() - 40);
    owner.setMana(owner.getMana() - 50);
    return true;
}
SpellType Fireball::getType() const
{
    return type;
}

bool operator==(Spells::ISpell &lhs, Spells::ISpell &rhs)
{
    return lhs.getType() == rhs.getType();
}
