#include "lecturaEscritura.h"

vector<int> leerVector(string nombreArchivo){
	vector<int> v;
	ifstream archivo;
	archivo.open(nombreArchivo, ios::in);

	if (archivo.is_open()){

		while (!archivo.eof()){
			int n = 0;
			archivo >> n;
			v.push_back(n);
			
		}
		archivo.close();
	}else{
		throw invalid_argument("Archivo no encontrado");
	}
	return v;
}

void guardarVector(vector<int> v, string nombreArchivo){

	int n; //Longitud del vector a rotar
	cin >> n;
	int i = 0;
	int x;
	vector<int> v;// En v leo el vector
	while (i<n){
		cin >> x;
		v.push_back(x);
		i++;
	}
	ofstream archivo;
	archivo.open(nombreArchivo,ios::out);
	for(int i = 0;i<v.size();i++){
		archivo << v[i] << " ";
	}
	archivo.close();
}

int elementoMedio(vector<int> v){
	int sumaTotal = 0;
	for(int k=0;k < v.size();k++){
		sumaTotal += v[k];
	}
	for(int i=0;i<v.size();i++){
		int sumaAnteriores = 0;

		// fijarse si la suma hasta ese numero es mayor a la mitad
		// de la suma total 
		for(int j=0;j<=i;j++){
			sumaAnteriores += v[j];	
		}
		if (sumaAnteriores > (sumaTotal/2)){
			return ; // una funcion de la std que me devuelva el parcial de un vector
		}
	}	
}

void cantidadAperaciones(string nombreArchivo){
	
	ifstream entrada;
	ofstream salida;

	entrada.open(nombreArchivo,ios::in);
	salida.open("archivos/out/cantidadOperaciones.out");
	

	while(!archivo.eof()){
		int x;
		int repeticiones=0;
		entrada >> x;
		while (!archivo.eof()){
			int y;
			entrada >> y;
			if (x == y){
				repeticiones++;
			}
		}
		salida << x << " " << repeticiones - 1<< endl; // para no contar dos veces el primero
	
	}
	entrada.close();
	salida.close();



}
int cantidadAparicionesDePalabra(string nombreArchivo,string palabra){
	ifstream archivo;
	archivo.open(nombreArchivo,,ios::in)
	int repeticiones = 0;
	
	while(!archivo.eof()){
		string palabraLeida;
		archivo >> palabraLeida;
		+
		
		if(palabraLeida == palabra){
			repeticiones++
		}
	}
	archivo.close()
	return repeticiones;
}


void promedio(string nombreArchivoIn1,string nombreArchivoIn2,string nombreArchivoOut){

	ifstream archivoIn1,archivoIn2;
	archivoIn1.open(nombreArchivoIn1,ios::in);
	archivoIn2.open(nombreArchivoIn2,ios::in);

	ofstream archivoOut;
	archivoOut.open(archivoOut,ios::out);

	while(!archivoIn1.eof() && !archivoIn1.eof()){
		int x,y;
		float promedioEntre;
		
		archivoIn1 >> x;
		archivoIn2 >> y;

		promedioEntre = (x+y)/2;

		archivoOut << promedioEntre << " ";
	}
	
	archivoIn1.close();
	archivoIn2.close();
	archivoOut.close();
}

void ordenarSequencias(string nombreArchivoIn1,string nombreArchivoIn2,string nombreArchivoOut){



	ifstream archivoIn1,archivoIn2;
	archivoIn1.open(nombreArchivoIn1,ios::in);
	archivoIn2.open(nombreArchivoIn2,ios::in);

	ofstream archivoOut;
	archivoOut.open(archivoOut,ios::out);

	// los dos arhivos tienen la misma longitud
	while(!archivoIn1.eof() && !archivoIn1.eof()){
		int x,y;
		
		archivoIn1 >> x;
		archivoIn2 >> y;

		while(x>y){
			archivoOut << y;
			archivoIn2 >> y;
		}
	}
	
	archivoIn1.close();
	archivoIn2.close();
	archivoOut.close();

}

vector<int> intersecion(){

	string nombreArchivoIn1;
	string nombreArchivoIn2;

	cout << "Calculemos la interseccion!" << endl;
	cout << "Ingrese dos archivos con enteros" << endl;
	cin >> nombreArchivoIn1;
	cin >> nombreArchivoIn2
	
	vector<int> v = leerVector(nombreArchivoIn1);
	vector<int> l = leerVector(nombreArchivoIn2);
	vector<int> result;

	for(int i=0;i<v.size();i++){
		for(int j=0;j<l.size();j++){
			if(v[i]==l[j]){
				result.push_back(v[i])
			}
		}
	}
	return result;
}

