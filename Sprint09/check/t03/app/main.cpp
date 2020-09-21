#include <iostream>
#include "src/Worker.h"
#include "src/ClassWithAtomic.h"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "usage: classWithAtomic [add] [subtract] [size]" << std::endl;
        return EXIT_FAILURE;
    }
    int pushSize;
    int addValue;
    int subtractValue;

    try
    {
        size_t f, s, t;
        pushSize = std::stoi(argv[3], &f);
        subtractValue = std::stoi(argv[2], &s);
        addValue = std::stoi(argv[1], &t);
        if (f != std::strlen(argv[3]) || s != std::strlen(argv[2]) || t != std::strlen(argv[1]))
            throw std::invalid_argument("");
    }
    catch (...)
    {
        std::cerr << "Incorrect values" << std::endl;
        return EXIT_FAILURE;
    }

    Worker worker;
    ClassWithAtomic obj;
    worker.startNewThread(&ClassWithAtomic::addToInt, &obj, addValue);
    worker.startNewThread(&ClassWithAtomic::subtractFromInt, &obj, subtractValue);
    for (auto i = 0; i < pushSize; ++i)
    {
        worker.startNewThread(&ClassWithAtomic::pushToVector, &obj, i);
    }
    for (auto i = 1; i <= pushSize; ++i)
    {
        if (i % 2 == 0)
        {
            worker.startNewThread(&ClassWithAtomic::eraseFromVector, &obj, i);
        }
    }
    worker.joinAllThreads();
    std::cout << "Result: " << obj.getInt() << std::endl;
    auto vec = obj.getVector();
    std::cout << "Size of vector: " << vec.size() << std::endl;
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << std::endl;
        }
    }
}