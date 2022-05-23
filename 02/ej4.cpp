#include <iostream>
#include <math.h>
using namespace std;

int binarioadecimal(int binario){
  int decimal = 0;
  for(int i=0;binario % (int)pow(10,i) != binario; i++){    
    decimal += (binario % (int)pow(10,(i+1)) / (int)pow(10,i)) * (int)pow(2,i);
  }
  return decimal;
}

int main(){
  int x;
  cout << "Ingrese un numero en formato binario" << endl;
  cin >> x;
  cout << "El numero en formato decimal es: " << binarioadecimal(x) << endl;
}
