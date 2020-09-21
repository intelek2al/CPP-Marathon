#include "Child.h"

Imperial::Imperial(std::string name) : Creature(std::move(name)) {}

void Imperial::sayPhrase() const
{
    std::cout << "I am " << getName() << ", Imperial soldier! Stop right here!" << std::endl;
}

Redguard::Redguard(std::string name) : Creature(std::move(name)) {}

void Redguard::sayPhrase() const
{
    std::cout << "I am " << getName() << " from Redguards, wanna trade?" << std::endl;
}
