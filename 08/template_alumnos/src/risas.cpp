#include <string>
#include <vector>
#include "risas.h"
#include <iostream>
#include <fstream>

using namespace std;

/* Utiles */
vector<char> leerDatos(string s) {
    vector<char> vec;
    ifstream archivo;
    archivo.open(s,ios::in);
    if(archivo.is_open()){
        while (!archivo.eof()){
            char x;
            archivo >> x;
            vec.push_back(x);

        }
        archivo.close();
    }

    return vec;
}

int leerLargoReal(string filename){
    int val = -1;
    ifstream archivo;
    archivo.open(filename,ios::in);
    if(archivo.is_open()){
        while (!archivo.eof()){
            int x;
            archivo >> x;
            val = x;

        }
        archivo.close();
    }

    return val;
}
/* Utiles */

/* RESOLUCION ALUMNOS */
int risaMasLarga(vector<char> s)
{
    int largoTotal = 0;
    int largo = 0;
    char actual;
    int i =0;
    while(i<s.size()){
        if(s[i] == 'a' || s[i] == 'h'){
            actual = s[i];
            int j = i+1;
            while((s[j] == 'a' || s[j] == 'h') && s[j] != actual){
                bool a = s[j] != actual;
                actual = s[j];
                largo++;
                i=j;
                ++j;
            }
            if(largoTotal <= largo){
                largoTotal = largo;
            }
            largo=0;



        }
        i++;
    }
    return largoTotal+1;
}
/* RESOLUCION ALUMNOS */
