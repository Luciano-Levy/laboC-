#include <iostream>
#include <vector>

using namespace std;

bool estaOrdenado(vector<int> v){
    
    int decrecientes = 0;
    int crecientes = 0;
    
    // size - 1 para que nunca se indefina al ver v[i+1] 
    for(int i = 0;i < v.size()-1;i++){
        if(v[i] >= v[i+1]){
            decrecientes++;
        }else if (v[i] <= v[i+1]){
            crecientes++;
        }
    }
    
    if (crecientes == v.size()-1 || decrecientes == v.size()-1){
        return true;
    }else{
        return false;
    }
}
int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; 
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    // Evaluo si el vector v esta ordenado
    bool res = estaOrdenado(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}
