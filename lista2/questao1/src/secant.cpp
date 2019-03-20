#include <iostream>
#include <math.h>

double Function(double x){
     return pow(x,3) -1.7*pow(x,2) -12.78*x -10.08;
}

double func_secant(double p0, double p1){

    double root =  0;
    int i = 2;
    double q0 = Function(p0);
    double q1 = Function(p1);

    for(; i <= 10000; i++){
        root =  p1 - ((q1*( p1 - p0))/(q1 - q0));
        if(std::abs(root - p1) < 0.000001){
            std::cout << i << std::endl;
            return root;
        }
        p0 = p1; 
        q0 = q1;
        p1 = root;
        q1 = Function(root);
    }
    return -1;
}
int main(){
    double r1, r2, r3;
    r1 = func_secant(-4,-2);
    r2 = func_secant(0, 2);
    r3 = func_secant(3,5);
    
    if(r1 != -1){
        std::cout <<"Está é a raiz 1: " << r1 << std::endl;
    }else{
        std::cout << "Não foi encontrada uma raiz 1" << std::endl;
    }
    if(r2 != -1){
        std::cout <<"Está é a raiz 2: " << r2 << std::endl;
    }else{
        std::cout << "Não foi encontrada uma raiz 2" << std::endl;
    }

    if(r3 != -1){
        std::cout <<"Está é a raiz 3: " << r3 << std::endl;
    }else{
        std::cout << "Não foi encontrada uma raiz 3" << std::endl;
    }
}