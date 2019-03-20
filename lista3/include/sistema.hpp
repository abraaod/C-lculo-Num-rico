#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Sistema{

    using matriz = std::vector<std::vector<double>>;

     private:

        matriz sistema;
        std::vector<double> resultado;
        std::vector<double> matriz_x;
        unsigned int size;

        void leituraMatriz(std::string filename){

	        std::ifstream file(filename); 
            
            if(file.is_open()){
                file >> size;
                
                double value;
                std::vector<double> aux;
                for(auto i(0u); i < size; i++){
                    for(auto j(0u); j < size; j++){
                       file >> value;
                       aux.push_back(value);
                    }
                    file >> value;
                    matriz_x.push_back(value);
                    sistema.push_back(aux);
                    aux.clear();
                }
            }
            file.close();	
        }

        void triangularizar(matriz sistema, bool pivot){
            if(pivot){

            } else {
                for(auto k(0u); k < size; k++){
                    if(sistema[k][k] == 0){
                        std::cout << "Não possui solução";
                        exit(0);
                    }
                }
            }

        }
        void Gauss(matriz sistema);

    public:
    
        Sistema(std::string filename){
           leituraMatriz(filename);

        }
        ~Sistema() = default;
        std::vector<double> solucao;
        void imprimir(){
            for(auto i(0u); i < size; i++){
                for(auto j(0u); j < size; j++){
                    std::cout << sistema[i][j] << " ";
                }
                std::cout << "   " << matriz_x[i] << std::endl;
            } 
        }
    
};