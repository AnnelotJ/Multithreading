    #pragma once  

    // clang++ -std=c++17 main.cpp window.cpp -o main $(pkg-config --cflags --libs sdl3)

    #include <SDL3/SDL.h>
    #include <thread>
    #include <iostream>
    #include "multitread.h"
    #include <atomic>
    #include <unistd.h>
    #include <random>
    

    struct Sqaure { 
        float x; 
        float y; 
        float size; 
        // color 
        Uint8 r; 
        Uint8 g; 
        Uint8 b; 
    };


    struct ThreadController{ 
        std::vector<std::thread> threads;
        std::atomic<bool> running {true};

        void makeThreads (int amountOfThreads, std::vector<Sqaure>& sqaures) { 
            for (int  i=0; i<amountOfThreads; i++){
                threads.emplace_back(, std::ref(sqaures), std::ref(running), i);
            }  
        }

        void startThread (){ 
            
        }

        void stopThread(){ 

        }
            
    
    };

       struct App{
        SDL_Window* window = nullptr; 
        SDL_Renderer* renderer = nullptr;
        std::vector<Sqaure> sqaures; 
        ThreadController threadController; 


        
    };


    void checkLoadInSDLLib ();
    void generateWindow(const std::vector<Sqaure> sqaures);
    void paintSqaure(SDL_Renderer*, const Sqaure&);
    std::vector<Sqaure> makeSqaures (); 
    void changeColor (std::vector<Sqaure>& sqaure, int i);
    int randomNum(int, int);
