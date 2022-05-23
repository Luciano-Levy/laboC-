#include <iostream>
using namespace std;

void swap(int &a,int &b){
  int a_0 = a;
  int b_0 = b;

  a = b_0;
  b = a_0;
}

int main(){
  int a = 0;
  int b = 0;
  cout << "Ingrese los valores a intercambiar" << endl; 
  cin >> a;
  cin >> b;
  swap(a,b);
  cout << "Primero: " << a << endl;
  cout << "Segundo: " << b << endl;
  return 0;
}
