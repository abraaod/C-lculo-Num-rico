#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

class Sistema{

    using matriz = std::vector<std::vector<double>>;

     private:

        matriz sistema;
        std::vector<double> resultado;
        //matriz A;
        //std::vector<double> matriz_x;
        int size;

        void leituraMatriz(std::string filename){

	        std::ifstream file(filename); 
            
            if(file.is_open()){
                file >> size;
                
                double value;
                std::vector<double> aux;
                for(auto i(0); i < size; i++){
                    for(auto j(0); j <= size; j++){
                       file >> value;
                       aux.push_back(value);
                    }
                    sistema.push_back(aux);
                    aux.clear();
                }
            }
            file.close();	
        }

        void triangularizar(bool pivot){
            double fator;
            if(pivot){
                pivotagem();
            } 
            for(auto i(0); i < size; i++){
                if(sistema[i][i] == 0){
                    std::cout << "Não possui solução";
                    exit(0);
                }
                for(auto j = i + 1; j < size; j++){
                    fator = sistema[j][i]/sistema[i][i];
                    for(auto k = i; k <= size; k++){
                        sistema[j][k] = sistema[j][k] - (sistema[i][k]*fator);
                    }
                }
            }    

        }

        void Gauss(){
            for(int i = size - 1; i >= 0; i--){
		        double X = sistema[i][i]; 
	            double Y = 0;
 
                for(auto j = i + 1, k = 0; j < size + 1; j++, k++){

	                if(j < size){
		                Y = Y + resultado[k] * sistema[i][j];
                    } else {
                        Y = (sistema[i][j] - Y)/X;
                    }
		        }
		 
		        resultado.insert(resultado.begin(),Y);
	        }
        }

        void pivotagem(){
            std::vector<double> aux;
            int linha;
            double menor;

            for(auto i(0); i < size; i++){
                menor = sistema[0][i];
                linha = i;
                for(auto j(0); j < size; j++){
                    if(sistema[j][i] < menor){
                        menor = sistema[j][i];
                        linha = j;
                    }
                }
                aux = sistema[i];
                sistema[i] = sistema[linha];
                sistema[linha] = aux; 
            }
        }
    public:
    
        Sistema(std::string filename){
           leituraMatriz(filename);
        }
        ~Sistema() = default;
        std::vector<double> solucao;
        void imprimir(){
            for(auto i(0); i < size; i++){
                for(auto j(0); j <= size; j++){
                    std::cout << sistema[i][j] << " ";
                }
                std::cout << std::endl;
            } 
        }
        void solucionar(){
            triangularizar(true);
            Gauss();
        }

        void printresultados(){
            std::cout << "\nOs resultados são: \n";
            std::copy(resultado.begin(), resultado.end(), std::ostream_iterator<double>(std::cout, " "));
            std::cout << std::endl;
        }
    
};