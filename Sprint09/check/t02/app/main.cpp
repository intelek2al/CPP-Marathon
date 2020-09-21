#include <iostream>
#include "src/Worker.h"
#include "src/MultithreadedFileHandler.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);
    if (!file1.is_open() || !file2.is_open())
    {
        std::cerr << "error" << std::endl;
        return EXIT_FAILURE;
    }

    MultithreadedFileHandler mtfh;
    Worker worker;
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &mtfh, argv[1]);
    worker.startNewThread(&MultithreadedFileHandler::processFile, &mtfh);
    worker.joinAllThreads();
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &mtfh, argv[2]);
    worker.startNewThread(&MultithreadedFileHandler::processFile, &mtfh);
    worker.joinAllThreads();
}