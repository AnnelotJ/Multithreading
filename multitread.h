    #pragma once  

    #include <SDL3/SDL.h>
    #include <thread>
    #include <iostream>
    #include "multitread.h"
    #include <atomic>
    #include <unistd.h>
    #include <random>

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

    struct ThreadController{ 
        std::vector<std::thread> threads;

        void makeThreads (int amountOfThreads) { 
            for (int  i=0; i<amountOfThreads; i++){
                threads.emplace_back();
            }  
            for (const auto& thread : threads){ 
                std::cout<<"Thread: "<<thread.get_id() << std::endl;
            } 
        }
            
    
    };


    void checkLoadInSDLLib ();
    void generateWindow(const std::vector<Sqaure> sqaures);
    void paintSqaure(SDL_Renderer*, const Sqaure&);
    std::vector<Sqaure> makeSqaures (); 
    // void changeColor(std::vector<Sqaure>,std::mutex,std::atomic<bool>,int);
    void changeColor (std::vector<Sqaure>& sqaure, int i);
    int randomNum(int, int);
