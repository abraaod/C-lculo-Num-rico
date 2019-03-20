#include <iostream>
#include <math.h>

double Function(double x){
    return pow(x,3) -1.7*pow(x,2) -12.78*x -10.08;
}

double FunctionDerivative(double x){
    return 3*pow(x,2) -3.4*x - 12.78;
}

double func_newton_raphson(double a){
    double root = 0;
    for(int i= 0; i < 1000; i++){
        root = a - Function(root)/FunctionDerivative(root);
        if(std::abs(root - a) < 0.000001){
            std::cout << i << std::endl;
            return root;
        }
        a = root;
    }
    return -1;
}

int main(){


    double r1, r2, r3;
    r1 = func_newton_raphson(-4.1);
    r2 = func_newton_raphson(1);
    r3 = func_newton_raphson(6.8);
    
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