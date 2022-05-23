#include <iostream>

int sumaDivisores(int x){
  int y=2;
  int result = 0;
  while(y < x){
    if (x % y == 0){
      result = result + y;
    }
  y++;
  }
  return result;
}

int main(){
  std :: cout << "La suma de divisores es: " << sumaDivisores(10) << std :: endl;
  return 0;
}
