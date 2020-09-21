#pragma once

#include <iostream>
#include <utility>
#include <stdlib.h>
#include <deque>
#include <chrono>
#include <random>
#include <set>
#include <fstream>
#include <string>

#include "Graphics.hpp"
#include "Audio.hpp"

#include "leaderboard.h"

#define BLOCK_SIZE 40

#define SPEED 1
#define FOOD_SIZE BLOCK_SIZE

#define COLOR_BODY sf::Color(0, 186, 112)
#define COLOR_BORDER sf::Color(0, 135, 81)
#define COLOR_HEAD sf::Color(255, 241, 17)

#define START_FRAME_TIME 100

#define RED_PILL 2

#define GET_STRING(x) #x
#define GET_VALUE(x) GET_STRING(x)
#define GET_ENUM(x) GET_VALUE(x)

#define FRAME_TIME_STEP 10

template <typename T>
sf::Vector2<T> GET_GLOBAL_POSITION(T x, T y)
{
    return {BLOCK_SIZE * x, BLOCK_SIZE * y};
}

template <typename T>
sf::Vector2<T> GET_GLOBAL_POSITION(sf::Vector2<T> pos)
{
    return GET_GLOBAL_POSITION(pos.x, pos.y);
}

template <typename T>
bool OPERATOR_EQUEL_VECTOR(const sf::Vector2<T> &lhs, const sf::Vector2<T> &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

enum class Direction
{
    Up = -1,
    Right = 2,
    Down = 1,
    Left = -2
};

struct WindowInfo
{
    int W = 20;
    int H = 20;

    int SCREEN_W = BLOCK_SIZE * W;
    int SCREEN_H = BLOCK_SIZE * H;

    size_t FRAME_TIME = START_FRAME_TIME;

    leaderboard retcodes;

    std::chrono::steady_clock::time_point *start;
};

struct VectorObject
{
    sf::Vector2<int> UL;
    sf::Vector2<int> DR;
};
