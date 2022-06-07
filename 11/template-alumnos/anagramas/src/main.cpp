#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "anagramas.h"
using namespace std;

int main(){
    string palabra, palabra2;
    cout << "Ingrese una palabra en ingles con letras en minuscula:" << endl;
    cin >> palabra;

    ifstream dicci ("ingles.dic");
    vector<string> listaPalabras;
    string word;
    while(getline(dicci, word)){
        listaPalabras.push_back(word);
    }
    int cantidadAnagrama = 0;
    for (int i = 0; i < listaPalabras.size(); ++i)
    {
        string x = listaPalabras[i];
        x.pop_back();
        if (x != palabra && esAnagrama(x,palabra)) {
            cout << "Son anagramas: " << x << " y " << palabra << endl;
            cantidadAnagrama++;
        }
    }
    cout << "La cantidad de anagramas es: " << cantidadAnagrama << endl;

    return 0;
} // O(M*n) M = |dict|, n = palabra

// por ejemplo en palabra la longitud de cual la mas larga? porque estamos en
// el peor caso?


bool esAnagrama(string p1, string p2){
    // CAMBIAR AQUI QUE IMPLEMENTACION USAR
    return esAnagrama1(p1,p2);
}

bool esAnagrama1(string p1, string p2){
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa ordenar
    ordenarString(p1);
    ordenarString(p2);
    return p1 == p2;
} // O(n)

bool esAnagrama2(string p1, string p2){
    //COMPLETAR
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa el mapeo de letras a números primos. Utilizar charToPrimo()
    if(p1.size() == p2.size()){
        int multp1 = 1;int multp2 = 1;
        for (int i = 0; i < p1.size(); ++i) {
            multp1 *= charToPrimo(p1[i]);
            multp2 *= charToPrimo(p2[i]);
        }
        return multp1 == multp2;
    }else {
        return false;
    } // O(n), si usara un metodo iterativo para encontrar primos se iria a
    // O(n^2) o O(n^3)

}

void ordenarString(string &palabra){
    //counting sort, del 97 al 122 son las letras minusculas
    vector<int> apariciones(255,0); // si lo hago menor a 255 se rompe todo.
    // PORQUE
    for (int i = 0; i < palabra.size(); ++i) {
        apariciones[posicionEnAlfabeto(palabra[i])]++;
    }
    palabra.clear();
    for (int i = 0; i < apariciones.size(); ++i) {
        for (int j = 1; j <= apariciones[i]; ++j) {
            palabra.push_back((i+97));
        }
    }//O(1*n)
}

int charToPrimo(char c){
    //COMPLETAR
    //Dado una letra minuscula de a-z (sin enie) devolver el numero primo correspondiente.
    vector<int> primeros24primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
                                    37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
	return primeros24primos[posicionEnAlfabeto(c)];
} // O(1)

int posicionEnAlfabeto(char c){
    return c - 'a';
}
