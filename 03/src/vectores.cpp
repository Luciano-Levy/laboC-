#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio
bool divide(vector<int> v, int a){
	// Dados un vector v y un int a, decide si a divide a todos los numeros de v.
	for(int i=0;i<v.size();i++){
		if(v[i] % a != 0){
			return false;
		}
	}
	return true;
}

//Ejercicio
int mayor(vector<int> v){
	// Dado un vector v, devuelve el valor maximo encontrado.
	int masGrande=0;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(v[i] >= v[j]){
				masGrande++;
			}
		}
		if (masGrande == v.size()){
		    return v[i];
		}else{
		    masGrande = 0;
		}
		
	}
}

//Ejercicio
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
	
    for(int i=0; i < v.size();i++){
        int elemento = v[0];
        v.erase(v.begin());
        v.push_back(elemento);
    
    }
    return v;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
	
    for(int i=0; i < k;i++){
        int elemento = v[0];
        v.erase(v.begin());
        v.push_back(elemento);
    
    }
    return v;
}

//Ejercicio

bool esPrimo(int x){
	for(int i=2;i<x;i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo
	vector<int> v;
	for(int i=2;i<n;i++){
		if(n % i == 0 && esPrimo(i)){
			v.push_back(i);
		}
	}
	return v;
}

//Ejercicio
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
	cout << "[";
	for(int i=0;i<v.size();i++){
		if (i == v.size()-1){
			cout << v[i];
			continue;
		}

		cout << v[i] << ",";
	}
	cout << "]" << endl;

}
