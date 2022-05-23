#include <iostream>
#include <math.h>
using namespace std;

void valoresCirculo(float radio,float &diametro,float &perimetro,float &area){
  float pi = 3.14159f;
  diametro = radio * 2;
  perimetro =  2 * pi * radio;
  area = pi * (float)(pow(radio,2));

}

int main(){
  float radio;
  float diametro;
  float perimetro;
  float area;
  cout << "Ingrese el radio de la circunferencia" << endl;
  cin >> radio;
  valoresCirculo(radio,diametro,perimetro,area);
  cout << "El diametro es: " << diametro << endl; 
  cout << "El perimetro es: " << perimetro << endl;
  cout << "El area es: " << area << endl;
}
