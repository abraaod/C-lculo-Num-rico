#include <iostream>
#include <math.h>

int main(){
    /*float variation = -0.5, x = 0, y = 0;
    for(; x >= -6.0; x+= variation){
        y += (cos(x) - x * sin(x)) * variation;
        std::cout << x << " " << y << std::endl;
    }

    variation = 0.5, x = 0.5, y = 0;
    for(; x <= 6.0; x+= variation){
        y += (cos(x) - x * sin(x)) * variation;
        std::cout << x << " " << y << std::endl;
    }*/
    float variation = 0.5;
    for(auto x = -6.0, y = -5.9671; x <= 6; x += variation){
        std::cout << x << " " << y << std::endl;
        y += (cos(x) - x * sin(x)) * variation;
    }
}