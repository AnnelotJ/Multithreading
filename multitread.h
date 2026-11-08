    #pragma once  

    // clang++ -std=c++17 main.cpp window.cpp -o main $(pkg-config --cflags --libs sdl3)

    // g++ -std=c++17 main.cpp window.cpp -o main $(pkg-config --cflags --libs sdl3) g --cflags --libs sdl3) 

    #include <SDL3/SDL.h>
    #include <thread>
    #include <iostream>
    #include "multitread.h"
    #include <atomic>
    #include <unistd.h>
    #include <random>
    #include <condition_variable>
    #include <mutex> 
    #include <queue>
    

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
    void changeColor (std::vector<Sqaure>& sqaure, int i);
    int randomNum(int, int);

    struct ThreadController{ 
        std::vector<std::thread> threads;
        std::queue<int> job; 
        std::mutex lock; 
        std::condition_variable wakeUp; 
        bool running = true; 

        void makeThreads (int amountOfThreads, std::vector<Sqaure> &sqaures) { 
            for (int i=0; i<amountOfThreads; i++){
                threads.emplace_back([this, &sqaures]{waitForJobs(sqaures);});
            }  
            
            for (const auto& thread : threads){
                std::cout << thread.get_id() << std::endl;
            }

        }

        void waitForJobs (std::vector<Sqaure>& sqaures){ 
            std::cout << "thread started " << std::endl; 

            while (true){
                int sqaureNumber; 
                {
                    std::unique_lock<std::mutex> guard (lock); 
                    std::cout<< "Thread going to sleep" << std::endl; 
                    wakeUp.wait (guard, [this] {return !job.empty() || !running; }); 
                    std::cout << "thread wake up" << std:: endl; 
                    if (!running && job.empty()) return; 
                    sqaureNumber = job.front(); 
                    job.pop(); 
                }
                changeColor(sqaures, sqaureNumber);
            }
        }



        void stopThread(){ 
            {
                std::lock_guard<std::mutex> guard(lock); 
                running = false; 

                wakeUp.notify_all(); 
                for (std::thread& t : threads){
                    t.join();
                }
            }

        }
            
    
    };

       struct App{
        SDL_Window* window = nullptr; 
        SDL_Renderer* renderer = nullptr;
        std::vector<Sqaure> sqaures; 
        ThreadController threadController; 


        
    };



