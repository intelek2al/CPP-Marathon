#pragma once

#include <iostream>
#include <memory>

class Map;
class Player;

class MoveManager final
{
public:
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right
    };

    MoveManager(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map);
    ~MoveManager() = default;
    void processInputAndMove(const std::string &inputStr);

private:
    bool checkMove(Direction dir) const;
    std::shared_ptr<Map> m_map;
    std::shared_ptr<Player> m_player;
};