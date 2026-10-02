    #pragma once  

    #include <SDL3/SDL.h>

    struct App{
        SDL_Window* window = nullptr; 
        SDL_Renderer* renderer = nullptr;
    };

    struct Sqaure { 
        float x; 
        float y; 
        float size; 
        // color 
        Uint8 r; 
        Uint8 g; 
        Uint8 b; 
    };


    // Window.cpp
    void checkLoadInSDLLib ();
    void generateWindow();
    void paintSqaure(SDL_Renderer*, const Sqaure&);
    