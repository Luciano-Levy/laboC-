#include <iostream>

int sumaImpares(int x){
  int y=1;
  int result = 0;
  while(y < x){
    if (y % 2 != 0){
      result = result + y;
    }
  y++;
  }
  return result;
}

int main(){
  std :: cout << "La suma de impares es: " << sumaImpares(10) << std :: endl;
  return 0;
}
