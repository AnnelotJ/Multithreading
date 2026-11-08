#include "multitread.h"
 
void checkLoadInSDLLib(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
    SDL_Log("Init failed %s", SDL_GetError());
    std::abort(); 
    }
}

void generateWindow(const std::vector<Sqaure>& sqaures, ThreadController& threadController){ 
    App app;
    SDL_Event e;
    int isrunning = 1; 
    int frame = 0; 

    app.window = SDL_CreateWindow("Annelot's window",600,600, 0);
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

        frame++; 

        if (frame % 30 == 0 ){ 
            threadController.addJob(randomNum(0,3));
        }
        
        // x,y,size,r,g,b
        for (const Sqaure& sqaure : sqaures ){
            paintSqaure(app.renderer, sqaure);
        }
        
    
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

