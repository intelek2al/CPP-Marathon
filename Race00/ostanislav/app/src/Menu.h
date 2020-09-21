#pragma once

#include "Includes.h"

class Menu
{
private:
    WindowInfo *w;
    sf::Texture Background_Text;
    sf::Texture Game_button_text;
    sf::Texture Leder_board_text;
    sf::Texture Back_texture;
    sf::Sprite Background;
    sf::Sprite Game_button;
    sf::Sprite Leder_board;
    sf::Sprite Back;
    sf::Text Leader_board_tittle;
    sf::Font font;
    sf::Text rec[10];
    int record_num = 1;

public:
    bool in_menu = true;
    int menuNum = 0;
    bool main_menu = true;
    Menu(WindowInfo *w);

    void draw_menu(sf::RenderWindow &window);
    void mouse_over_buttons(sf::RenderWindow &windows, std::set<int> &recordes);
    void Build_leader(std::set<int> recordes);
};
