#ifndef LECTURAESCRITURA_H
#define LECTURAESCRITURA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<int> leerVector(string nombreArchivo);

void guardarVector(vector<int> v, string nombreArchivo);

int elementoMedio(vector<int> v);

void cantidadAperaciones(string nombreArchivo);

void promedio(string nombreArchivoIn1,string nombreArchivoIn2,string nombreArchivoOut);


void ordenarSequencias(string nombreArchivoIn1,string nombreArchivoIn2,string nombreArchivoOut);

vector<int> intersecion();

#endif	
