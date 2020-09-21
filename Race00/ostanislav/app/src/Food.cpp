#include "Food.h"

const sf::Vector2<int> &Food::getPosition() const
{
    return position;
}

const sf::Vector2<int> &Food::getGlobalPosition() const
{
    return global_position;
}

static bool is_snake_on(Snake &snake, sf::Vector2<int> &pos)
{
    for (auto &block : snake.getSnake())
    {
        if (block.getPosition() == pos)
            return true;
    }
    return false;
}

sf::Vector2<int> Food::generatePosition(Snake &snake, Food &food)
{
    sf::Vector2<int> pos = {std::rand() % (w->W - 1) + 1, std::rand() % (w->H - 1) + 1};
    while (is_snake_on(snake, pos) || food.getPosition() == pos)
    {
        pos = {std::rand() % (w->W - 1) + 1, std::rand() % (w->H - 1) + 1};
    }
    return pos;
}

Food::Food(WindowInfo *_w, bool _is_good) : w(_w), is_good(_is_good)
{
    shape = sf::RectangleShape({FOOD_SIZE, FOOD_SIZE});
    position = {std::rand() % (w->W - 1) + 1, std::rand() % (w->H - 1) + 1};
    global_position = GET_GLOBAL_POSITION(position);
    color = is_good ? sf::Color::Green : sf::Color::Red;
    shape.setPosition(global_position.x, global_position.y);
    shape.setFillColor(color);
    shape.setOutlineThickness(5.f);
    shape.setOutlineColor(sf::Color::Magenta);
}

bool Food::getHealthment() const
{
    return is_good;
}

void Food::drawFood(sf::RenderWindow &w) const
{
    w.draw(shape);
}

void Food::feedSnake(Snake &snake, Food &food)
{
    *(w->start) = std::chrono::steady_clock::now();
    position = generatePosition(snake, food);
    global_position = GET_GLOBAL_POSITION(position);
    shape.setPosition(global_position.x, global_position.y);
}
