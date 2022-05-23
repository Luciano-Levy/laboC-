#include <iostream>

int factorial(int x){
  int y=1;
  int result = 1;
  for(int i = 1; i <= x;i++){
    result *= i;
  }
  return result;
}

int combinatorio(int n ,int k){
  return (factorial(n)) / (factorial(k)*factorial(n-k));
}


int main(){
  std :: cout << "El numero combinatorio es: " << combinatorio(6,3) << std :: endl;
  return 0;
}
