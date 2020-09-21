#pragma once

#include "Container.h"

class Barrel : public Container
{
public:
    Barrel(bool isLocked = false, const LockpickDifficulty difficulty = LockpickDifficulty::None);
    std::string name() const;
};

class Chest : public Container
{
public:
    Chest(bool isLocked = false, const LockpickDifficulty difficulty = LockpickDifficulty::None);
    std::string name() const;
};

class Safe : public Container
{
public:
    Safe(bool isLocked = false, const LockpickDifficulty difficulty = LockpickDifficulty::None);
    std::string name() const;
};
