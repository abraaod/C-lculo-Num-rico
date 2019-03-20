#include <math.h>


/*bool func_Bissection(double a, double b, double (*Function) (double), double *root){
    double fa, fb;
    for(auto i(0); i < 1000; i++){
        fa = Function(a);
        *root = (a + b)/2;
        fb = Function(*root);

        if(fb == 0 or ((b-a)/2) < 0.0000001){
            return true;
        } else {
            if(fa * fb > 0){
                a = *root;
            } else {
                b = *root;
            }
        }
    }
    return true;
}*/