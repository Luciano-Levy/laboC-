#include "generador.h"
#include "vectores.h"
#include "lecturaEscritura.h"


using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    //generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp
    
    // Leo las entradas
   // int n; //Longitud del vector a rotar
   // cin >> n;
   // int i = 0;
   // int x;
   // vector<int> v;// En v leo el vector
   // while (i<n){
   //     cin >> x;
   //     v.push_back(x);
   //     i++;
   // }


   // mostrarVector(v);
   vector<int> s = leerVector("archivos/leerVector.in");
   cout  << elementoMedio(s);
    return 0;
}
