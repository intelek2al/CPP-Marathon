#include "Menu.h"

Menu::Menu(WindowInfo *_w) : w(_w)
{

    Background_Text.loadFromFile("./resources/menu.jpg", sf::IntRect(0, 0, w->SCREEN_W / 1.3, w->SCREEN_H)); // !!!!!! Путь у тебя другой
    Background.setTexture(Background_Text);
    Background.setPosition(w->SCREEN_W - w->SCREEN_W / 1.3, 0);

    Back_texture.loadFromFile("./resources/Back_button.png", sf::IntRect(0, 0, w->SCREEN_W / 1.3, w->SCREEN_H)); // !!!!!! Путь у тебя другой
    Back.setTexture(Back_texture);
    Back.setPosition(w->SCREEN_W - w->SCREEN_W / 1.6, w->SCREEN_H - w->SCREEN_H / 5);

    Game_button_text.loadFromFile("./resources/button_game.png", sf::IntRect(0, 0, w->SCREEN_W / 2, w->SCREEN_H - w->SCREEN_H / 1.25));
    Game_button.setTexture(Game_button_text);
    Game_button.setPosition(1, w->SCREEN_H - w->SCREEN_H / 1.05263158);

    Leder_board_text.loadFromFile("./resources/button_leader.png", sf::IntRect(0, 0, w->SCREEN_W / 2, w->SCREEN_H / 2));
    Leder_board.setTexture(Leder_board_text);
    Leder_board.setPosition(1, w->SCREEN_H - w->SCREEN_H / 1.4285);

    font.loadFromFile("./resources/Pacifico-Regular.ttf");
    Leader_board_tittle.setFont(font); // font is a sf::Font
    Leader_board_tittle.setString("Score");
    Leader_board_tittle.setCharacterSize(80);
    Leader_board_tittle.setPosition(w->SCREEN_W - w->SCREEN_W / 1.2, w->SCREEN_H - w->SCREEN_H / 1.05);
    Leader_board_tittle.setFillColor(sf::Color::Red);

    double delta = (w->SCREEN_H - w->SCREEN_H / 1.05) + 80;

    for (int i = 0; i < 10; i++)
    {
        rec[i].setFont(font); // font is a sf::Font
        rec[i].setString("Score");
        rec[i].setCharacterSize(60);
        rec[i].setPosition(w->SCREEN_W - w->SCREEN_W / 1.2, delta);
        rec[i].setFillColor(sf::Color::Magenta);
        delta += 80;
    }
}

void Menu::mouse_over_buttons(sf::RenderWindow &window, std::set<int> &recordes)
{
    auto i = sf::Mouse::getPosition(window);
    // std::cout << i.x << " " << i.y << "\n";
    if (main_menu)
    {
        if (sf::IntRect(1, w->SCREEN_H - w->SCREEN_H / 1.05263158, w->SCREEN_W / 2, w->SCREEN_H / 5).contains(sf::Mouse::getPosition(window)))
        {
            Game_button.setColor(sf::Color::Blue);
            menuNum = 1;
        }
        if (sf::IntRect(1, w->SCREEN_H - w->SCREEN_H / 1.4285, w->SCREEN_W / 2, w->SCREEN_H - w->SCREEN_H / 1.25).contains(sf::Mouse::getPosition(window)))
        {
            Leder_board.setColor(sf::Color::Blue);
            menuNum = 2;
            // std::cout << "POSITION " << Game_button.getPosition().x << " " << Game_button.getPosition().y << "\n";
            // std::cout << "SCALE " << Game_button.getScale().x << " " << Game_button.getScale().y << "\n";
            // std::cout << w->SCREEN_H - w->SCREEN_H / 1.4285 << "\n";
        }
        // Game_button.getPosition().x

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1)
                in_menu = false; //если нажали первую кнопку, то заходим в игру (оно просто выйдет с цыкла)
            if (menuNum == 2)
            { //в лидерборд
                main_menu = false;
                Build_leader(recordes);
            }
        }
    }
    else
    {

        if (sf::IntRect(w->SCREEN_W - w->SCREEN_W / 1.6, w->SCREEN_H - w->SCREEN_H / 5, w->SCREEN_W / 2, w->SCREEN_H / 2).contains(sf::Mouse::getPosition(window)))
        {
            Back.setColor(sf::Color::Blue);
            menuNum = 3;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && menuNum == 3)
            main_menu = true;
    }
}

void Menu::Build_leader(std::set<int> recordes)
{
    int size = recordes.size();
    if (size > 10)
        size = 10;
    record_num = size;
    int number = 0;
    int i = 0;
    std::set<int>::reverse_iterator rit;
    for (rit = recordes.rbegin(); rit != recordes.rend() && i < size; rit++, i++)
    {
        number = *rit;
        rec[i].setString(std::to_string(number));
    }
}

void Menu::draw_menu(sf::RenderWindow &window)
{
    if (main_menu == true)
    {
        window.draw(Background);
        window.draw(Game_button);
        window.draw(Leder_board);
        Game_button.setColor(sf::Color::White);
        Leder_board.setColor(sf::Color::White);
    }
    else
    {
        window.draw(Background);
        window.draw(Leader_board_tittle);
        for (int i = 0; i < record_num; i++)
            window.draw(rec[i]);
        window.draw(Back);
        Back.setColor(sf::Color::White);
    }
}
