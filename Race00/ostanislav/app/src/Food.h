#pragma once
#include "Includes.h"

#include "Snake.h"

class Snake;

class Food
{
public:
    const sf::Vector2<int> &getPosition() const;

    const sf::Vector2<int> &getGlobalPosition() const;

private:
    sf::Vector2<int> generatePosition(Snake &snake, Food &food);

public:
    Food(WindowInfo *_w, bool _is_good = true);

    bool getHealthment() const;

    void drawFood(sf::RenderWindow &w) const;

    void feedSnake(Snake &snake, Food &food);

private:
    WindowInfo *w;
    sf::RectangleShape shape;
    sf::Color color;
    sf::Vector2<int> position;
    sf::Vector2<int> global_position;
    const bool is_good;
};
