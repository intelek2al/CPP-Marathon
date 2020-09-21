#include "src/Includes.h"

#include "src/SnakeBlocks.h"
#include "src/Food.h"
#include "src/Snake.h"
#include "src/Menu.h"
#include "src/leaderboard.h"

void initMusic(sf::Music &music)
{
    if (!music.openFromFile("./resources/electro.ogg"))
        std::cout << -1; // error
    music.play();
    music.setLoop(true);
}

void initGame(WindowInfo *w)
{
    w->FRAME_TIME = START_FRAME_TIME - (std::max(w->W, w->H) * std::max(w->W, w->H)) / 200;
    std::srand(std::time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(w->SCREEN_W, w->SCREEN_H), "Snake", sf::Style::Default, settings);
    // window.setFramerateLimit(120);
    // window.clear();
    auto start_time = std::chrono::steady_clock::now();
    auto start_SEC = std::chrono::steady_clock::now();
    w->start = &start_SEC;
    Snake snake(w);
    Food h_food(w);
    Food b_food(w, false);

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Down && snake.getDirection() != Direction::Down)
            {
                snake.setDirection(Direction::Down);
                break;
            }
            if (event.key.code == sf::Keyboard::Right && snake.getDirection() != Direction::Right)
            {
                snake.setDirection(Direction::Right);
                break;
            }
            if (event.key.code == sf::Keyboard::Up && snake.getDirection() != Direction::Up)
            {
                snake.setDirection(Direction::Up);
                break;
            }
            if (event.key.code == sf::Keyboard::Left && snake.getDirection() != Direction::Left)
            {
                snake.setDirection(Direction::Left);
                break;
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_SEC) >= std::chrono::seconds(4))
        {
            start_SEC = std::chrono::steady_clock::now();
            snake.destroyTail();
        }
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time) >= std::chrono::milliseconds(w->FRAME_TIME))
        {
            start_time = std::chrono::steady_clock::now();
            if (!snake.moveSnake() || snake.size() < 2)
            {
                std::cout << "Game Over" << std::endl;
                w->retcodes.setnewrecord(w->FRAME_TIME);
                std::cout << w->FRAME_TIME;
                window.close();
                break;
            }
            snake.checkFoodCollision(h_food, b_food);
            snake.checkFoodCollision(b_food, h_food);
        }
        snake.drawSnake(window);
        h_food.drawFood(window);
        b_food.drawFood(window);
        window.display();
    }
    // return 0;
}

void ender(char str)
{
    if (str != 0)
        throw 1;
}

void parce_func(int argc, char **argv, int &width, int &height)
{
    if (argc != 3)
    {
        std::cerr << "usage: ./race00 [width] [height]\n";
        exit(1);
    }
    else
    {
        try
        {
            auto pointer = 4ul;
            width = std::stoi(argv[1], &pointer, 10);
            ender(argv[1][pointer]);
            height = std::stoi(argv[2], &pointer);
            ender(argv[2][pointer]);
        }
        catch (...)
        {
            std::cerr << "error\n";
            exit(1);
        }
        if ((width <= 0 || height <= 0))
        {
            std::cerr << "error\n";
            exit(1);
        }
    }
}

bool initMenu(WindowInfo *w)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(w->SCREEN_W, w->SCREEN_H), "Menu", sf::Style::Default, settings);
    window.setFramerateLimit(120);
    Menu menu(w);
    bool is_exit = false;

    while (window.isOpen() && menu.in_menu)
    {
        window.clear();
        menu.mouse_over_buttons(window, w->retcodes.w_retcodes); //Контролю мишку

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Tab)
            {
                break;
            }
            if (event.type == sf::Event::Closed)
            {
                is_exit = true;
                window.close();
            }
        }
        menu.draw_menu(window);
        window.display();
    }
    return is_exit;
}

int main(int argc, char *argv[])
{
    sf::Music music;
    WindowInfo *w = new WindowInfo;
    initMusic(music);
    parce_func(argc, argv, w->W, w->H);

    w->SCREEN_W = w->W * BLOCK_SIZE;
    w->SCREEN_W = w->W * BLOCK_SIZE;
    w->SCREEN_H = w->H * BLOCK_SIZE;

    while (!initMenu(w))
    {
        initGame(w);
    }
    return 0;
}
