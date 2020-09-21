#include "Container.h"

Container::Container(bool isLocked, const LockpickDifficulty difficulty)
{
    m_isLocked = isLocked;
    m_difficulty = difficulty;
}

LockpickDifficulty Container::lockDifficulty() const
{
    return m_difficulty;
}
bool Container::isLocked() const
{
    return m_isLocked;
}
bool Container::tryToOpen(LockpickDifficulty skill)
{
    // if (!m_isLocked)
    // {
    m_isLocked = m_difficulty <= skill;
    return m_isLocked;
    // }
    return false;
}
