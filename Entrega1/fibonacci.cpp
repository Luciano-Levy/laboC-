#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino
int fibonacci(int n){
    int y = 1;
    int z = 0;
    for(int i = 0; i < n;i++){
	
    z = y + z;
    y = z - y;
  }
  return z;
}
int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}
