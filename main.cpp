#include <iostream>
#include "multitread.h"
#include <thread>

// clang++ -std=c++17 main.cpp window.cpp -o main $(pkg-config --cflags --libs sdl3)
// g++ -std=c++17 main.cpp window.cpp -o main.exe $(pkg-config --cflags --libs sdl3)

int main () { 

    checkLoadInSDLLib();
    generateWindow();

    std::thread t (print);
    t.join();
}

