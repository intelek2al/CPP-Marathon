#include <iostream>
#include <string>

void PrintUsage()
{
    std::cerr << "usage :./automaton [name] [level] [health] [stamina]" << std::endl;
}

template <typename To, typename Function>
To Converter(const std::string &str, Function func)
{
    To res;
    try
    {
        size_t ptr;
        res = func(str, &ptr);
        if (str[ptr] != '\0')
            throw std::invalid_argument("");
    }
    catch (std::exception &ex)
    {
        std::cerr << "Invalid argument: " << str << std::endl;
        exit(EXIT_FAILURE);
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        PrintUsage();
        return 1;
    }
    auto name = argv[1];
    auto level = Converter<int>(std::string(argv[2]), [](const std::string &str, size_t *ptr) { return stoi(str, ptr); });
    auto health = Converter<float>(std::string(argv[3]), [](const std::string &str, size_t *ptr) { return stof(str, ptr); });
    auto stamina = Converter<double>(std::string(argv[4]), [](const std::string &str, size_t *ptr) { return stod(str, ptr); });
    std::cout << "Name = " << name << "\nLevel = " << level << "\nHealth = " << health << "\nStamina = " << stamina << std::endl;
}
