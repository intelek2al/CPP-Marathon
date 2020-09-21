#pragma once

#include <iostream>

class Draugr
{
public:
    Draugr();
    Draugr(int frostResist);
    Draugr(double health, const int m_frostResist = 50);
    void shoutPhrase(int shoutNumber) const;

private:
    double m_health;
    const int m_frostResist;
};
