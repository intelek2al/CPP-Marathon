#include "draugr.h"

Draugr::Draugr() : m_health(100),
                   m_frostResist(50)
{
}

void Draugr::shoutPhrase(int shoutNumber) const
{
    if (shoutNumber >= 0 && shoutNumber <= 8)
        std::cout << "Draugr (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:" << std::endl;
    switch (shoutNumber)
    {
    case 0:
        std::cout << "Qiilaan Us Dilon!" << std::endl;
        break;
    case 1:
        std::cout << "Bolog Aaz, Mal Lir!" << std::endl;
        break;
    case 2:
        std::cout << "Kren Sosaal!" << std::endl;
        break;
    case 3:
        std::cout << "Dir Volaan!" << std::endl;
        break;
    case 4:
        std::cout << "Aar Vin Ok!" << std::endl;
        break;
    case 5:
        std::cout << "Unslaad Krosis!" << std::endl;
        break;
    case 6:
        std::cout << "Faaz! Paak! Dinok!" << std::endl;
        break;
    case 7:
        std::cout << "Aav Dilon!" << std::endl;
        break;
    case 8:
        std::cout << "Sovngarde Saraan!" << std::endl;
        break;
    default:
        std::cout << "Invalid shoutNumber" << std::endl;
        break;
    }
}
