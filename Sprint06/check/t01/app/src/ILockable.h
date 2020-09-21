#pragma once

#include "iostream"
#include "Difficulty.h"

class ILockable
{
public:
    virtual ~ILockable() = default;

protected:
    virtual LockpickDifficulty lockDifficulty() const = 0;
    virtual bool isLocked() const = 0;
};
