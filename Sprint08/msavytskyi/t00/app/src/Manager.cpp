#include "Manager.h"
#include "Player.h"
#include "Map.h"

MoveManager::MoveManager(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map) : m_map(std::move(map)), m_player(std::move(player)) {
    m_map.get()->outputMap();
}

void MoveManager::processInputAndMove(const std::string &inputStr)
{
    if (inputStr.size() != 1 || (inputStr != "u" && inputStr != "r" && inputStr != "d" && inputStr != "l"))
        throw std::invalid_argument("Invalid input");
    if (inputStr[0] == 'u' && checkMove(Direction::Up))
    {
        m_player.get()->movePlayer(Direction::Up);
    }
    else if (inputStr[0] == 'l' && checkMove(Direction::Left))
    {
        m_player.get()->movePlayer(Direction::Left);
    }
    else if (inputStr[0] == 'd' && checkMove(Direction::Down))
    {
        m_player.get()->movePlayer(Direction::Down);
    }
    else if (inputStr[0] == 'r' && checkMove(Direction::Right))
    {
        m_player.get()->movePlayer(Direction::Right);
    }
    else
    {
        throw std::invalid_argument("Invalid direction");
    }
    m_map.get()->outputMap();
}

bool MoveManager::checkMove(Direction dir) const
{
    switch (dir)
    {
    case MoveManager::Direction::Up:
        return (m_player.get())->posY() != 0;
    case MoveManager::Direction::Down:
        return (m_player.get())->posY() != m_map.get()->height() - 1;

    case MoveManager::Direction::Left:
        return (m_player.get())->posX() != 0;

    case MoveManager::Direction::Right:
        return (m_player.get())->posX() != m_map.get()->width() - 1;
    }
}
