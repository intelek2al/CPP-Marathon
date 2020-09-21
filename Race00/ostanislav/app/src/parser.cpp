#include <iostream>

void ender(char str) {
    if (str != 0)
        throw 1;
}

void parce_func(int argc, char **argv, int &width, int &height) {
    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]\n";
        exit(1);
    } else {
        try {
            auto pointer = 4ul;
            width = std::stoi(argv[1], &pointer, 10);
            ender(argv[1][pointer]);
            height = std::stoi(argv[2], &pointer);
            ender(argv[2][pointer]);
        } 
        catch (...) {
            std::cerr << "error\n";
            exit(1);
        }
        if ((width <= 0 || height <= 0)) {
            std::cerr << "error\n";
            exit(1);
        }
    }
}

// int main(int argc, char **argv) {
//     int width;
//     int height;

//     parce_func(argc, argv, width, height);
//     std::cout << width << " " << height << "\n";
// }
