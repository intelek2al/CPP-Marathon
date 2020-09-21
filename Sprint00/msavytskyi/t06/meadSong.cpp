#include "meadSong.h"

void sing()
{
    for (int i = 99; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j != 2)
            {
                std::string t = j == 3 ? BOTTLES_OF_MEAD(i - 1, j) : BOTTLES_OF_MEAD(i, j);
                std::cout << t;
                if (j + 1 == 2)
                    std::cout << ".";
            }
            if (j == 0 || j == 3)
            {
                std::string tmp = (j == 0 ? ", " : ".");
                std::cout << " on the wall" << tmp;
            }
            else if (j == 2)
            {
                std::string s = TAKE((i - 1));
                std::string t1 = (i != 0) ? "\nTake " + s + " down and pass it around, " : "\nGo to the store and buy some more, ";
                std::cout << t1;
            }
        }
        std::cout << std::endl
                  << std::endl;
    }
}