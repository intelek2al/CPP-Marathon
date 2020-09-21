#pragma once

// #ifndef SH

#include "Includes.h"

class SnakeBlock
{
public:
    SnakeBlock(const sf::Vector2i &pos);
    SnakeBlock(const sf::Vector2i &pos, sf::Color clr);

    const sf::RectangleShape &getShape() const;

    const sf::Vector2<int> &getPosition() const;
    const sf::Vector2<int> &getGlobalPosition() const;

    void setColor(sf::Color clr);

private:
    sf::RectangleShape shape;
    sf::Vector2<int> position;
    sf::Vector2<int> global_position;
};
// #endif
