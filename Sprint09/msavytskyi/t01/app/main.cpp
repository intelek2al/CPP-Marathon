#include <iostream>
#include "src/Worker.h"
#include "src/MultithreadedClass.h"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]" << std::endl;
        return EXIT_FAILURE;
    }
    int count;
    int addValue;
    int subtractValue;

    try
    {
        size_t f, s, t;
        count = std::stoi(argv[3], &f);
        subtractValue = std::stoi(argv[2], &s);
        addValue = std::stoi(argv[1], &t);
        if (count > 10 || count < 5 || subtractValue > 2000 || subtractValue < -2000 || addValue > 2000 || addValue < -2000 || f != std::strlen(argv[3]) || s != std::strlen(argv[2]) || t != std::strlen(argv[1]))
            throw std::invalid_argument("");
    }
    catch (...)
    {
        std::cerr << "Incorrect values" << std::endl;
        return EXIT_FAILURE;
    }

    MultithreadedClass obj;
    Worker worker;
    for (auto i = 0; i < count; ++i)
    {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }
    for (auto i = 0; i < count; ++i)
    {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }
    worker.joinAllThreads();
    std::cout << obj.getInt() << std::endl;
}