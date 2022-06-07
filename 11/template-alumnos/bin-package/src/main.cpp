#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void swap(vector<int> &arr,int i,int j){
    int i_0 = arr[i];
    int j_0 = arr[j];
    arr[j] = i_0;
    arr[i] = j_0;
}

void insert(vector<int> &arr,int i){
    for (int j = i; j > 0 && arr[j] < arr[j-1]; --j) {
        swap(arr,j,j-1);
    }
}

void insertionSort(vector< int > &arr){
    for (int i = 0; i < arr.size(); ++i) {
        insert(arr,i);
    }
}

void ordenar(vector<int> &items){
    insertionSort(items);
}

// |restos| = |items| = n
int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	} // O(n)
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
        // O(logn)
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);//O(1)
		restos.insert(restoAct);//O(logn)
	} // O(nlogn)
	return res;
}

int main(){
	int N, W, aux;

	//Se levantan los items y la capacidad del contenedor
	cout << "Se levantan los items y la capacidad del contenedor";
	ifstream bpp("BPP.in");
	bpp >> N >> W;
	vector<int> items;
	for(int i=0; i<N; ++i){
		bpp >> aux;
		items.push_back(aux);
	}
	bpp.close();
	//Se corre best-fit
	int cant1 = bestFit(W, items);
	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

	//Se ordenan los items
	ordenar(items);
	//Se corre best-fit-decreasing
	int cant2 = bestFit(W, items);
	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

	return 0;
}
