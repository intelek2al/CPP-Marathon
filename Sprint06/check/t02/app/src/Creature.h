#pragma once

#include <iostream>
#include <set>
#include <algorithm>

#include "SpellType.h"
#include "Spells.h"

namespace Spells
{
    class ISpell;
    enum class SpellType;
} // namespace Spells

namespace Creatures
{
    class Creature
    {
    public:
        explicit Creature(std::string &&name);
        virtual ~Creature();
        void learnSpell(Spells::ISpell *spell);
        void castSpell(const Spells::SpellType type, Creature &creature);
        virtual void sayPhrase() const = 0;
        std::string getName() const;
        int getHealth() const;
        int getMana() const;
        void setHealth(int health);
        void setMana(int mana);

    private:
        std::string m_name;
        int m_health;
        int m_mana;
        std::set<Spells::ISpell *> m_spells;
    };
} // end namespace Creatures

std::ostream &operator<<(std::ostream &os, const Creatures::Creature &creature);

std::string getTypeString(Spells::SpellType type);