#include <math.h>
#include <iostream>

double Function(double x){

    return (pow(x,3) - 1.7*pow(x,2) - 10.08)/12.78;
}

double func_fixedPoint(double p){
    
    for(auto i(0); i < 1000; i++){
        
        double root = Function(p);
        if(std::abs(root - p) < 0.000001){
            std::cout << i << std::endl;
            return root;
        }
        p = root;
    }
    return -1;
}
int main(){
    double p1 = -3, p2 = -2, p3 = 5;

    
    double r1 = func_fixedPoint(p1);
    double r2 = func_fixedPoint(p2);
    double r3 = func_fixedPoint(p3);
  
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