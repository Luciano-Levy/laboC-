#include "ejercicios.h"

using namespace std;

void ej1(){
    int n;
    cout << "Cantidad de simulaciones" << endl;
    cin >> n;
    double c = aproximarC(n);
    cout << "El valor de C es:  " << c << endl;
    cout << "Segundos utilizando todos los usuarios de facebook:  " << (c*( pow(2200000000,2))) << endl;
}


int main() {

    //ej1();
    //generarDataEj2();
    //generarDataEj4();
    generarDataEj5();
    generarDataEj6();
    return 0;
}