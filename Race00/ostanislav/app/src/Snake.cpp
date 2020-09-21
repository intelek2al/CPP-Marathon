#include "Snake.h"

bool Snake::checkHeadPosition(sf::Vector2<int> &new_head_position)
{
    for (const auto &block : snake)
    {
        if (new_head_position == block.getPosition())
            return false;
    }
    if (new_head_position.x == w->W || new_head_position.y == w->H || new_head_position.x == -1 || new_head_position.y == -1)
        return false;
    return true;
}
void Snake::doMovement(const sf::Vector2<int> &v)
{
    if (is_done_process)
        move_vector.pop_front();
    move_vector.push_back(v);
    is_done_process = false;
}

auto Snake::getHead()
{
    auto front = snake.begin();
    return front;
}

std::deque<SnakeBlock> Snake::getSnake()
{
    return snake;
}

void Snake::updateTimeFrame(size_t step)
{
    // if (FRAME_TIME > )
    (w->FRAME_TIME) += step;
}

void Snake::deleteBlock(size_t size)
{
    size = std::min(size, snake.size());
    for (int i = 0; i < size; i++)
        destroyTail();
}

void Snake::eatFood(Food &f, Food &of)
{
    if (f.getHealthment())
    {
        addBlock();
        f.feedSnake(*this, of);
        updateTimeFrame(FRAME_TIME_STEP);
        std::cout << w->FRAME_TIME << std::endl;
    }
    else
    {
        deleteBlock(RED_PILL);
        f.feedSnake(*this, of);
        std::cout << w->FRAME_TIME << std::endl;
    }
}

sf::Vector2<int> Snake::getHeadPosition()
{
    auto front = getHead();
    return front->getPosition();
}

Snake::Snake(WindowInfo *_w) : w(_w)
{
    snake.push_front(SnakeBlock({w->W / 2, w->H / 2}));
    snake.push_front(SnakeBlock({w->W / 2 + 1, w->H / 2}));
    snake.push_front(SnakeBlock({w->W / 2 + 2, w->H / 2}));
    snake.push_front(SnakeBlock({w->W / 2 + 3, w->H / 2}));
    // auto front = snake.begin();
    // std::cout << front->getPosition().x << " " << front->getPosition().y << std::endl;
}

bool Snake::moveSnake()
{
    if (!is_add_block)
    {
        snake.pop_back();
    }
    is_add_block = false;
    auto front = getHead();
    // std::cout << "!! " << front->getPosition().x << " " << front->getPosition().y << std::endl;
    auto &vector = move_vector.front();
    front->setColor(COLOR_BODY);
    sf::Vector2<int> new_head_position = {front->getPosition().x + SPEED * vector.x, front->getPosition().y + SPEED * vector.y};
    is_done_process = true;
    if (move_vector.size() > 1)
    {
        // std::cout << "removed" << std::endl;
        move_vector.pop_front();
        is_done_process = false;
    }
    if (!checkHeadPosition(new_head_position))
        return false;
    snake.push_front(SnakeBlock(new_head_position, COLOR_HEAD));
    return true;
}

void Snake::destroyTail()
{
    updateTimeFrame(-FRAME_TIME_STEP);
    snake.pop_back();
}

void Snake::drawSnake(sf::RenderWindow &w) const
{
    for (auto &block : snake)
        w.draw(block.getShape());
}

void Snake::addBlock()
{
    is_add_block = true;
}

void Snake::setDirection(Direction dir)
{
    if (std::abs(static_cast<int>(direction)) != std::abs(static_cast<int>(dir)))
        direction = dir;
    // std::cout << "added << " << GET_ENUM(direction) << std::endl;
    switch (direction)
    {
    case Direction::Up:
    {
        doMovement({0, -1});
        break;
    }
    case Direction::Right:
    {
        doMovement({1, 0});
        break;
    }
    case Direction::Left:
    {
        doMovement({-1, 0});
        break;
    }
    case Direction::Down:
    {
        doMovement({0, 1});
        break;
    }
    }
}

void Snake::checkFoodCollision(Food &f, Food &of)
{
    if (f.getPosition() != getHeadPosition())
        return;
    eatFood(f, of);
}

Direction Snake::getDirection()
{
    return direction;
}
