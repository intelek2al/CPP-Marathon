#include <iostream>
#include <regex>
#include <algorithm>
#include "src/dwemerCalculator.h"

int main(int argc, char *argv[])
{
    Calculator cl;

    while (true)
    {
        cout << ":> ";
        string line;
        getline(cin, line);
        auto quit = line.find("quit");
        if (quit == 0 && line.size() == 4)
            break;
        try
        {
            cl.SetLine(line);
            cout << cl.GetResoult() << endl;
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl;
        }
    }
    return 0;
}
