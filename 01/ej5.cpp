#include <iostream>

int fibonacci(int x){
  int y = 1;
  int z = 0;
  for(int i = 0; i < x;i++){
	
    z = y + z;
    y = z - y;
  }
  return z;
}

int main(){
  std :: cout << "El resultado es: " << fibonacci(6) << std :: endl;
  return 0;
}
