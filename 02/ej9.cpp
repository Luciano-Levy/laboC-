#include <iostream>
using namespace std;


void division(int dividendo, int divisor, int &cociente, int &resto){
	// Modificar el pasaje de parametros de ser necesario para que calcule el cociente y resto. Deben se por copia o referencia??
    

    if (divisor <= 0 || dividendo < 0){
    
        throw invalid_argument("No cumple la precondicion");
    }else if (divisor > dividendo){
        cociente = 0;
        resto = dividendo;
    }else{        
        cociente = 1;
        while ( divisor*cociente < dividendo ){
            cociente++;
        }
        resto = dividendo - (divisor*cociente);
    }
    
}

using namespace std;
int main() {
    /* No hace falta modificar el main */
    //Leo la entrada
    int divisor,dividendo,cociente,resto;
    cin >> dividendo>>divisor;
    
    //Calculo la division
    division(dividendo,divisor,cociente,resto);
    
    //Salida
    cout << cociente << " " << resto;
    
    return 0;
}
