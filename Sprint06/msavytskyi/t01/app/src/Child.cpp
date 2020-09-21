#include "Child.h"

Barrel::Barrel(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}
Chest::Chest(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}
Safe::Safe(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}

std::string Barrel::name() const
{
    return "Barrel";
}

std::string Chest::name() const
{
    return "Chest";
}

std::string Safe::name() const
{
    return "Safe";
}
