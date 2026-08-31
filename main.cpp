#include <iostream>
#include "multitread.h"
#include <thread>

// clang++ -std=c++17 main.cpp window.cpp -o main $(pkg-config --cflags --libs sdl3)


int main () { 
    int amountOfThreads; 
    
    std::cout<<"How many threads would you like?\n";
    std::cin>>amountOfThreads;

    checkLoadInSDLLib();
    generateWindow();

    
}