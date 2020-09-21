#pragma once

#include <set>
#include <fstream>

class leaderboard
{
public:
    std::set<int> w_retcodes;
    leaderboard();
    void setnewrecord(int rec);
};
