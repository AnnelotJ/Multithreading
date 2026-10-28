#include "multitread.h"

std::vector<Sqaure> makeSqaures (){ 
    // x,y,size,r,g,b
    std::vector<Sqaure> sqaures;

    Sqaure sqaure0 = {0,0,300,40,0,40};
    Sqaure sqaure1 = {300,0,300,0,40,40};
    Sqaure sqaure2 = {0,300,300,0,80,40};
    Sqaure sqaure3 = {300,300,300,80,0,40};

    sqaures.push_back(sqaure0); 
    sqaures.push_back(sqaure1); 
    sqaures.push_back(sqaure2); 
    sqaures.push_back(sqaure3);

    std::cout<<"Sqaures have been made";

    return sqaures;
}

void changeColor (std::vector<Sqaure>& sqaure, int i){ 
    int x = randomNum(0,255); 
    sqaure[i].r = randomNum(0,255);
    sqaure[i].g = randomNum(0,255); 
    sqaure[i].b = randomNum(0,255);
}

int randomNum(int min, int max){ 
    static std::random_device seed; 
    static std::mt19937 generator(seed()); 
    std::uniform_int_distribution<int> range(min,max); 
    return range(generator);

}


int main () { 
    checkLoadInSDLLib();
    std::vector<Sqaure> sqaures = makeSqaures();
    generateWindow(sqaures);

}

