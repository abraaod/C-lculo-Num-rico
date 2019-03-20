#include <iostream>
#include <math.h>

double func_Bissection(double a, double b, double (*Function) (double)){
    double fa, fb, root = 0;
    for(auto i(0); i < 1000; i++){
        fa = Function(a);
        root = (a + b)/2;
        fb = Function(root);

        if(fb == 0 or ((b-a)/2) < 0.000001){
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

double function_q2(double t){
    double g  = 32.17;
    double s0 = 300;
    double m = 0.25;
    double k = 0.1;

    return s0 - ((m*g)/k) * t + ((pow(m, 2)*g)/pow(k,2)) * (1 - pow(M_E,((-1*k)*t)/m));
}

int main(){

    double root = (func_Bissection(0, 8, function_q2));
    if(root != -1){
        std::cout << "Está é a raiz: " << root << std::endl;
    }else {
        std::cout << "Não foi encontrada raíz" << std::endl;
    }

}