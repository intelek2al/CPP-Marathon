#pragma once

#include <iostream>

class Draugr
{
public:
    Draugr();
    Draugr(double health);
    Draugr(double health, const int m_frostResist);
    Draugr(Draugr &other);
    Draugr(Draugr &&other);
    void shoutPhrase(int shoutNumber) const;
    void setName(const std::string &&name);

private:
    std::string m_name;
    double m_health;
    const int m_frostResist;
};
