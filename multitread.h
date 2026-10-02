    #pragma once  

    #include <SDL3/SDL.h>

    struct App{
        SDL_Window* window = nullptr; 
        SDL_Renderer* renderer = nullptr;
    };


    // Window.cpp
    void checkLoadInSDLLib ();
    void generateWindow();
    void paintSquare();
    void print();