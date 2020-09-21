#pragma once

#include "iostream"
#include "Difficulty.h"

class IOpenable
{
public:
    virtual ~IOpenable() = default;

protected:
    virtual bool tryToOpen(LockpickDifficulty skill) = 0;
};
