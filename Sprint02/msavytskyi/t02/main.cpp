#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define cerr std::cerr
#define string std::string
#define invalid_argument std::invalid_argument

class Database
{
public:
    void AddBook(const string &book)
    {
        string content;
        std::ifstream file("./library/" + book);
        if (!file || file.eof())
        {
            throw invalid_argument("invalid book");
        }
        for (string line; getline(file, line);)
        {
            content += move(line);
            content += '\n';
        }
        if (content.size() == 0)
        {
            throw invalid_argument("invalid book");
        }
        library[book] = move(content);
    }

    void DeleteBook(const string &book)
    {
        if (library.count(book) == 0)
        {
            throw invalid_argument("invalid book");
        }
        library.erase(book);
    }
    string ReadBook(const string &book) const
    {
        if (library.count(book) == 0)
        {
            throw invalid_argument("invalid book");
        }
        return library.at(book);
    }

    std::set<string> GetListBook() const
    {
        std::set<string> catalog;
        for (const auto &[book, content] : library)
        {
            catalog.insert(book);
        }
        return catalog;
    }

private:
    std::map<string, string> library;
};

void CheckNextInput(std::istream &ss)
{
    if (!ss.eof())
    {
        // ss.ignore(INT_MAX, '\n');
        throw invalid_argument("invalid command");
    }
}

std::ostream &operator<<(std::ostream &ss, const std::set<string> list)
{
    for (const auto &book : list)
    {
        ss << book << endl;
    }
    return ss;
}

int main()
{
    Database db;

    while (true)
    {
        try
        {
            string command;
            string ln;
            cout << "enter command:> ";
            getline(cin, ln);
            std::stringstream line(ln);
            line >> command;
            if (command == "read")
            {
                if (line.eof())
                    throw invalid_argument("invalid command");
                string item;
                line >> item;
                CheckNextInput(line);
                cout << db.ReadBook(item);
            }
            else if (command == "add")
            {
                if (line.eof())
                    throw invalid_argument("invalid command");
                string item;
                line >> item;
                CheckNextInput(line);
                db.AddBook(item);
                cout << item << " added" << endl;
            }
            else if (command == "delete")
            {
                if (line.eof())
                    throw invalid_argument("invalid command");
                string item;
                line >> item;
                CheckNextInput(line);
                db.DeleteBook(item);
                cout << item << " deleted" << endl;
            }
            else if (command == "list")
            {
                CheckNextInput(line);
                cout << db.GetListBook();
            }
            else if (command == "quit")
            {
                CheckNextInput(line);
                break;
            }
            else
                throw invalid_argument("invalid command");
        }
        catch (invalid_argument &ex)
        {
            cerr << ex.what() << endl;
        }
    }
    cout << "bye" << endl;
    return 0;
}
