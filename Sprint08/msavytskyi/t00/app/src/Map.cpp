#include "Map.h"
#include "Player.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player> &player) : m_width(width), m_height(height), m_player(player), m_map(new char[width * height])
{
    generateMap();
}

void Map::outputMap() const
{
    for (size_t i = 0; i < m_height * m_width; ++i)
    {
        int x = m_player.get()->posX();
        int y = m_player.get()->posY();
        if (i % m_width == 0 && i != 0)
            std::cout << '\n';
        if (i == ((y * m_width) + x % m_width))
            std::cout << m_player.get()->getIdentifier() << ' ';
        else
            std::cout << m_map.get()[i] << ' ';
    }
    std::cout << std::endl;
}

size_t Map::width() const
{
    return m_width;
}

size_t Map::height() const
{
    return m_height;
}

void Map::generateMap()
{
    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        switch (rand() % 3)
        {
        case 0:
            m_map.get()[i] = '.';
            break;
        case 1:
            m_map.get()[i] = 'T';
            break;
        case 2:
            m_map.get()[i] = '@';
            break;
        }
    }
}
