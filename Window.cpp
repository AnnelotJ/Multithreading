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
    App app;
    SDL_Event e;
    int isrunning = 1; 

    app.window = SDL_CreateWindow("Mr Teddy Bear",460,460, 0);
    app.renderer = SDL_CreateRenderer(app.window, nullptr); 
    SDL_SetRenderVSync(app.renderer,1);

    while(isrunning) { 
        while(SDL_PollEvent(&e) != 0){
            if (e.type == SDL_EVENT_QUIT){ 
                isrunning = 0; 
            }
        }

        SDL_SetRenderDrawColor(app.renderer,4,255,255,255);
        SDL_RenderClear(app.renderer); 
        
        // x,y,size,r,g,b
        Sqaure Sqaure = {0,100,50,40,0,40};
        paintSqaure(app.renderer, Sqaure);
        SDL_RenderPresent(app.renderer);
    }

    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
    
}
void paintSqaure(SDL_Renderer* renderer, const Sqaure& sqaure){
    
    SDL_SetRenderDrawColor(renderer, sqaure.r, sqaure.b, sqaure.b, 255);
    SDL_FRect rect = {sqaure.x, sqaure.y, sqaure.size, sqaure.size}; 
    SDL_RenderFillRect(renderer, &rect);
    
}

