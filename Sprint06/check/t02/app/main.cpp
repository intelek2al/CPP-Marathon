#include "src/Child.h"

int main(int argc, char **argv)
{
    Redguard red("JoJo");
    red.sayPhrase();

    Imperial imp("Dio");
    imp.sayPhrase();

    red.setHealth(100);
    red.setMana(100);
    imp.setHealth(100);
    imp.setMana(100);

    std::cout << red << std::endl;
    std::cout << imp << std::endl;

    red.learnSpell(new Spells::Healing);
    red.learnSpell(new Spells::Fireball);
    imp.learnSpell(new Spells::Equilibrium);
    imp.learnSpell(new Spells::Equilibrium);
    red.castSpell(Spells::SpellType::Fireball, imp);
    imp.castSpell(Spells::SpellType::Equilibrium, red);

    std::cout << red << std::endl;
    std::cout << imp << std::endl;

    imp.castSpell(Spells::SpellType::Flames, red);
    imp.learnSpell(new Spells::Flames);
    imp.learnSpell(new Spells::Freeze);

    red.castSpell(Spells::SpellType::Healing, red);
    imp.castSpell(Spells::SpellType::Freeze, red);

    std::cout << red << std::endl;
    std::cout << imp << std::endl;

    red.castSpell(Spells::SpellType::Fireball, red);
    red.castSpell(Spells::SpellType::Fireball, red);
    red.castSpell(Spells::SpellType::Fireball, red);

    std::cout << red << std::endl;
    std::cout << imp << std::endl;

    return 0;
}
