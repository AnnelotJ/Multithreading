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


    void checkLoadInSDLLib ();
    void generateWindow(const std::vector<Sqaure> sqaures);
    void paintSqaure(SDL_Renderer*, const Sqaure&);
    std::vector<Sqaure> makeSqaures (); 
    void changeColor(std::vector<Sqaure>,std::mutex,std::atomic<bool>,int);