#include <iostream>
#include <math.h>

double Function(double x){
    return pow(x,3) -1.7*pow(x,2) -12.78*x -10.08;
}

double func_Bissection(double a, double b){
    double fa, fb, root = 0;
    for(auto i(0); i < 1000; i++){
        fa = Function(a);
        root = (a + b)/2;
        fb = Function(root);

        if(fb == 0 or ((b-a)/2) < 0.000001){
            std::cout << i << std::endl;
            return root;
        } else {
            if(fa * fb > 0){
                a = root;
            } else {
                b = root;
            }
        }
    }
    return -1;
}

int main(){


    double r1 = func_Bissection(-4,-2);
    double r2 = func_Bissection(-2,0);
    double r3 = func_Bissection(3,5);

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