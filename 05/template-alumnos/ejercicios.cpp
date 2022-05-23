#include "ejercicios.h"

// Ejercicio 1
bool existePico(vector<int> v){
	int i = 1;
	while(i < v.size()-1){
		if(v[i] > v[i-1] && v[i] > v[i+1]){
			return true;
		}
		i++;
	}
	return false;
}

// Ejercicio 2
int mcd(int m, int n){
	int mayor;
	int b;
    int menor = b;
    if (m >= n){
        mayor = m;
        menor = n;
	}else{
        mayor = n;
        menor = m;
	}

	while(mayor % menor != 0){
        if(mayor < menor){
            int cambio = menor;
            menor =mayor;
            mayor=cambio;
        }
        mayor = mayor - menor;
	}

	return menor;

}

// Ejercicio 3
int indiceMinSubsecDes(vector<int> v, int l, int r){
	int i = r;
	int res = r;
	while(i>=l){
		if (v[i] <= v[res]){
			res = i;
		}
        --i;
	}
	return res;

}

int indiceMinSubsecAsc(vector<int> v, int l, int r){
    int i = l;
    int res = l;
    while(i <=r){
        if (v[i] <= v[res]){
            res = i;
        }
        ++i;
    }
    return res;

}

// Ejercicio 4
void ordenar1(vector<int>& v){
	int i = 0;
	int indiceMinimo;
	int cambio;
	while(i < v.size()){
		indiceMinimo = indiceMinSubsecDes(v,i,v.size()-1);
		swap(v[i],v[indiceMinimo]);
		i++;
	}

}

void swap(int &a,int &b){
  int a_0 = a;

  a = b;
  b = a_0;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
	int i=0;
	int j=0;
	int k=v.size()-1;
    if (v.size() <= 1){
        j = k;
    }
    while(k != j-1){
		swap(v[i],v[indiceMinSubsecDes(v,i,j)]);
		swap(v[j],v[indiceMinSubsecAsc(v,j,k)]);
		if(v[i+1] == 0){
			i++;
		}
		if(v[k] == 2 && v[k-1]==2){
			k--;
		}
		j++;

        
	}
}
// Ejercicio 6
tuple<int,int> division(int n, int d){
	int r = n;
	int q = 0;

	while(q <= n){
		r = n % d;
		q = (n-r)/d;
        break;
	}


	return make_tuple(q,r);
}
