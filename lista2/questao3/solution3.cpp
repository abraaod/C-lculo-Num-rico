#include <iostream>
#include <math.h>

double Function(double x){

    double A = 8;
    double x1 = 20;
    double x2 = 30;

    return (A/sqrt(pow(x1,2) - pow(x,2)) + A/sqrt(pow(x2,2) - pow(x,2)));
}

double func_Bissection(double a, double b, double (*Function) (double)){
    double fa, fb, root = 0;
    for(auto i(0); i < 1000; i++){
        fa = Function(a);
        root = (a + b)/2;
        fb = Function(root);

        if(fb == 1 or ((b-a)/2) < 0.000001){
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

    double root = func_Bissection(0,1000, Function);
    if(root != -1){
        std::cout <<"Está é a largura aproximada: " << root << std::endl;
    }else{
        std::cout << "Não foi encontrada uma raiz" << std::endl;
    }
}