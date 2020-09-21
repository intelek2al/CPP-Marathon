#pragma once

#include "Creature.h"

using namespace Creatures;

class Imperial : public Creature
{
public:
    Imperial(std::string name);
    ~Imperial() = default;
    void sayPhrase() const;
};

class Redguard : public Creature
{
public:
    Redguard(std::string name);
    ~Redguard() = default;
    void sayPhrase() const;
};
