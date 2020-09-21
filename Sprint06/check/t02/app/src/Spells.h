#pragma once

#include "ISpell.h"

namespace Spells
{
    class Healing : public ISpell
    {
    public:
        bool cast(Creatures::Creature &owner, Creatures::Creature &other);
        SpellType getType() const;

    private:
        SpellType type = SpellType::Healing;
    };

    class Equilibrium : public ISpell
    {
    public:
        bool cast(Creatures::Creature &owner, Creatures::Creature &other);
        SpellType getType() const;

    private:
        SpellType type = SpellType::Equilibrium;
    };

    class Flames : public ISpell
    {
    public:
        bool cast(Creatures::Creature &owner, Creatures::Creature &other);
        SpellType getType() const;

    private:
        SpellType type = SpellType::Flames;
    };

    class Freeze : public ISpell
    {
    public:
        bool cast(Creatures::Creature &owner, Creatures::Creature &other);
        SpellType getType() const;

    private:
        SpellType type = SpellType::Freeze;
    };

    class Fireball : public ISpell
    {
    public:
        bool cast(Creatures::Creature &owner, Creatures::Creature &other);
        SpellType getType() const;

    private:
        SpellType type = SpellType::Fireball;
    };

} // namespace Spells
