#include <iostream>
using namespace std;


int triplicarPorValor(int valor){
  return valor*3;
}

void triplicarPorReferencia(int &valor){
  valor *= 3;
}


int main(){

  int valor =0;
  cout << "Ingrese el valor que desea triplicar" << endl;
  cin >> valor;
  cout << "El resultado es: " << triplicarPorValor(valor) << endl;
  triplicarPorReferencia(valor);
  cout << "El resultado por referencia es: " << valor << endl;
  return 0;
}
