#include "SnakeBlocks.h"

SnakeBlock::SnakeBlock(const sf::Vector2i &pos)
{
    shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
    position = {pos.x, pos.y};
    global_position = GET_GLOBAL_POSITION(position);
    shape.setPosition(global_position.x, global_position.y);
    shape.setOutlineThickness(5.f);
    shape.setOutlineColor(COLOR_BORDER);
    shape.setFillColor(COLOR_BODY);
}
SnakeBlock::SnakeBlock(const sf::Vector2i &pos, sf::Color clr)
{
    shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
    position = {pos.x, pos.y};
    global_position = GET_GLOBAL_POSITION(position);
    shape.setPosition(global_position.x, global_position.y);
    shape.setOutlineThickness(5.f);
    shape.setOutlineColor(COLOR_BORDER);
    shape.setFillColor(clr);
}

const sf::RectangleShape &SnakeBlock::getShape() const
{
    return shape;
}

const sf::Vector2<int> &SnakeBlock::getPosition() const
{
    return position;
}

const sf::Vector2<int> &SnakeBlock::getGlobalPosition() const
{
    return global_position;
}

void SnakeBlock::setColor(sf::Color clr)
{
    shape.setFillColor(clr);
}
