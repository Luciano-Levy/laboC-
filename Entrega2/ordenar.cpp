#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
	int i = l;
	int res = l;
	while(i<=r){
		if (v[i] <= v[res]){
			res = i;
		}
        i++;
	}
	return res;

}
void swap(int &a,int &b){
  int a_0 = a;

  a = b;
  b = a_0;
}
void ordenar1(vector<int>& v){
	int i = 0;
	int indiceMinimo;
	int cambio;
	while(i < v.size()){
		indiceMinimo = indiceMinSubsec(v,i,v.size()-1); 
		swap(v[i],v[indiceMinimo]);
		i++;
	}
}


int main() {
    /* No hace falta modificar el main */
    
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);
    
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    
    return 0;
}
