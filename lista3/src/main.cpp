#include <../include/sistema.hpp>
int main(int argc, char const *argv[]){

    Sistema sistema(argv[1]);
    sistema.solucionar();
    std::cout << "A matriz triangularizada: \n";
    sistema.imprimir();
    sistema.printresultados();
    
}
