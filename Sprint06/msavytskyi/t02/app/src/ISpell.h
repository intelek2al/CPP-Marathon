#pragma once

#include "Creature.h"
namespace Creatures
{
    class Creature;
}

namespace Spells
{
    class ISpell
    {
    public:
        virtual ~ISpell() = default;
        virtual bool cast(Creatures::Creature &owner, Creatures::Creature &other) = 0;
        virtual SpellType getType() const = 0;
    };

} // namespace Spells
bool operator==(Spells::ISpell &lhs, Spells::ISpell &rhs);
