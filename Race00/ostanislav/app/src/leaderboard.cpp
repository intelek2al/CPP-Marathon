#include "leaderboard.h"

leaderboard::leaderboard(/* args */)
{
    std::ifstream fin(".leaderboard.txt");
    std::string str;
    int score;

    if (fin.is_open())
    {
        while (getline(fin, str, '\n'))
        {
            score = std::stoi(str);
            w_retcodes.insert(score);
        }
    }
}

void leaderboard::setnewrecord(int rec)
{
    std::ofstream out(".leaderboard.txt", std::ios::app);
    if (out.is_open())
    {
        out << rec << std::endl;
    }
    out.close();
    w_retcodes.insert(rec);
}
