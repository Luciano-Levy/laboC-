#include <iostream>
using namespace std;

void collatz(int n, int &cantPasos){
  while (n !=1 && n > 0){
    if (n % 2 == 0){
      n = n / 2;
    }else {
      n = n*3 + 1;
    }

    cout << n << endl;
    cantPasos += 1;
  }
}





int main(){
  int cantPasos = 1;
  int n = 0;
  cout << "Ingrese numero para collatz: " << endl;
  cin >> n;
  collatz(n,cantPasos);
  cout << "Realizado en " << cantPasos << " pasos" << endl;
}
