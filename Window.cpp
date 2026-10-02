#include <iostream>
#include <SDL3/SDL.h>
#include "multitread.h"

// COMPILE FOR MAC: clang++ -std=c++17 main.cpp window.cpp -o main $(pkg-config --cflags --libs sdl3)
 
void checkLoadInSDLLib(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
    SDL_Log("Init failed %s", SDL_GetError());
    std::abort(); 
    }
}

void generateWindow(){ 
    SDL_Window* window = nullptr; 
    SDL_Event e;
    int isrunning = 1; 

    window = SDL_CreateWindow("Mr Teddy Bear",460,460, 0);

    while(isrunning) { 
        while(SDL_PollEvent(&e) != 0){
            if (e.type == SDL_EVENT_QUIT){ 
                isrunning = 0; 
            }
        }
    }  
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}

void print (){
    std::cout<<"hello";
}