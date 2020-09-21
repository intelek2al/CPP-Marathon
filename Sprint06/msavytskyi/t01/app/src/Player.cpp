#include "Player.h"

Player::Player(const std::string &name)
{
    m_name = name;
}
void Player::openContainer(Container *container)
{
    auto resoult = container->tryToOpen(m_lockpickSkill) ? " successfully opened " : " skill is too low to open ";

    std::cout << m_name << resoult << container->name() << std::endl;
}
void Player::setLockpickSkill(LockpickDifficulty skill)
{
    m_lockpickSkill = skill;
}
