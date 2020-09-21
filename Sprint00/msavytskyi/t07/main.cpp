#include "src/inventory.h"

void PrintHelp()
{
    cout << "Available commands:\n1. insert<itemType>\n2.remove<itemType>\n3.show inventory\n4.help\n5.exit " << endl;
}

int main()
{
    Inventory inv;

    while (true)
    {
        try
        {
            string command;
            cout << "Enter command:> ";
            cin >> command;
            if (command == "help")
            {
                if (cin.peek() != '\n')
                {
                    cin.ignore(INT_MAX, '\n');
                    throw invalid_argument("Invalid command.");
                }
                PrintHelp();
            }
            else if (command == "insert")
            {
                string item;
                cin >> item;
                if (cin.peek() != '\n')
                {
                    cin.ignore(INT_MAX, '\n');
                    throw invalid_argument("Invalid command.");
                }
                inv.Insert(item);
                cout << item << " was inserted." << endl;
            }
            else if (command == "remove")
            {
                string item;
                cin >> item;
                if (cin.peek() != '\n')
                {
                    cin.ignore(INT_MAX, '\n');
                    throw invalid_argument("Invalid command.");
                }
                inv.Remove(item);
            }
            else if (command == "show")
            {
                if (cin.peek() != '\n')
                {
                    cin.ignore(INT_MAX, '\n');
                    throw invalid_argument("Invalid command.");
                }
                inv.Show();
            }
            else if (command == "exit")
            {
                if (cin.peek() != '\n')
                {
                    cin.ignore(INT_MAX, '\n');
                    throw invalid_argument("Invalid command.");
                }
                break;
            }
            else
                throw invalid_argument("Invalid command.");
        }
        catch (invalid_argument &ex)
        {
            cerr << ex.what() << endl;
        }
    }
    cout << "Bye." << endl;
}
