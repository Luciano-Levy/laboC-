#include "ejercicios.h"

using namespace std;

void mostrar_vector(vector<int>& v){
    string vector = "[";
    if(v.size() > 0){
        for(int i=0; i < v.size()-1; i++){
            vector = vector + to_string(v[i]) + ", ";
        }
    }

    if(v.size() != 0){
        vector = vector + to_string(v[v.size()-1]) + "]";
    }else{
        vector = vector + "]";
    }

    cout << vector << endl;
}

vector<int> construir_vector(int n, string disposicion){

    vector<int> res;
    srand (time(NULL));
    int numero;

    if (disposicion == "asc"){
        for(int i=0; i < n; i++){
            res.push_back(i);
        }
    }else if(disposicion == "desc"){
        for(int i=n-1; i >= 0; i--){
            res.push_back(i);
        }

    }else if(disposicion == "azar"){
        for(int i=0; i < n; i++){
            numero = rand() % 100;
            res.push_back(numero);
        }
    }else if(disposicion == "iguales"){
        numero = rand() % 100;
        for(int i=0; i < n; i++){
            res.push_back(numero);
        }
    }else{
        cout << "Dispocisión no válida" << endl;
    }

    return res;
}

bool hayDuplicados (vector<int>& v){
    bool res = false ; int i = 0; int j = 0;

    while ( i < v . size ()){
        j = 0;
        while ( j < v . size ()){
            if ( i != j && v [ i ] == v [ j ]){
                res = true ;
            }
            j ++;
        }
        i ++;
    }

    return res;
}


bool busqueda_binaria(vector<int> &s, int x) {
    int low = 0;
    int high = s.size() -1;
    while( low+1 < high ) {
        int mid = (low+high) / 2;
        if( s[mid] <= x ) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return s[low] == x;
}




// Dado un vector de enteros, devuelve verdadero si
// existe un subconjunto tal que la suma sea igual a sum
bool algunSubconjSuma(vector<int>& vec, int sum)
{
    return aux(vec, vec.size() - 1, sum);
}

bool aux(vector<int>& vec, int i, int sum)
{
    if (sum == 0) return true;
    if (i < 0 || sum < 0) return false;
    bool prueba1 = aux(vec, i - 1, sum - vec[i]);
    bool prueba2 = aux(vec, i - 1, sum);
    return prueba1 || prueba2;
}

double tiempoHayDuplicados(vector<int> v){
    double t0 = clock();
    bool b = hayDuplicados(v);
    double t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    return tiempo;
}

double aproximarC(int n){
    double total = 0;

    for (int i = 0; i <= n; ++i) {
        int vectorSize = rand() % 100; // Arbitrario
        vector<int> v = construir_vector(vectorSize,"azar");
        double tiempo = tiempoHayDuplicados(v);
        total += (tiempo/pow(vectorSize,2));

    }
    return (total/n);
}

void generarDataEj2(){
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej2.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= 1000; i += 499) {
            vector<int> v = construir_vector(i, "azar");
            double tiempo = tiempoHayDuplicados(v);
            fout << i << "\t" << tiempo << endl;
        }
    }
    fout.close();
}

int bigO_1(vector<int> v){
    return v[0] - v[v.size()-1]; // los accesos al vector son O constantes
}


int bigO_n(vector<int> v){
    int menor=v[0];
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] <= menor){
            menor = v[i];
        }
    }
    return menor;
}


int bigO_n3(vector<int> s){
    int r = 0;
    for (int i = 0; i < s.size(); ++i) {
        int chiquito = bigO_n(s);
        for (int j = 0; j < s.size(); ++j) {
            if(s[i]-s[j] >= 10){
                r += 1;
                break;
            }
        }
    }
    return r;
}



int bigO_nlogn(vector<int> s){
    int multiplicados = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(busqueda_binaria(s,s[i]*2)){
            multiplicados += 1;
        }
    }
    return multiplicados;
}



double tiempo_O(vector<int> v,int (*func)(vector<int>)){
    double t0 = clock();
    bool b = func(v);
    double t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    return tiempo;
}

void generarDataEj4(){
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej4.csv");
    if(fout.is_open()) {
        fout << "n\t" << "O(1)" << "\t" << "O(n)" << "\t" << "O(n^3)" << "\t" << "O(nlog(n))" << endl;
        for (int i = 100; i <= 100000; i *= 10) {
            vector<int> v = construir_vector(i, "azar");
            double tiempoO_1 = tiempo_O(v,bigO_1);
            fout << i << "\t" << tiempoO_1 << "\t";
            double tiempoO_n = tiempo_O(v,bigO_n);
            fout << tiempoO_n << "\t";
            double tiempoO_n3 = tiempo_O(v,bigO_n3);
            fout <<tiempoO_n3 << "\t";
            double tiempoO_nlogn = tiempo_O(v,bigO_nlogn);
            fout << tiempoO_nlogn << endl;

        }
    }
    fout.close();
}

double aproximarComplejidadEj5_1(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_1.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<int> v = construir_vector(i, "azar");
            //
            double t0 = clock();
            int b = v.size();
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t"<< tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}


double aproximarComplejidadEj5_2(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_2.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<int> v = construir_vector(i, "azar");
            //
            double t0 = clock();
            v.push_back(0); // tien saltos por realocalizacion
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}


double aproximarComplejidadEj5_3(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_3.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<int> v = construir_vector(i, "azar");
            //
            double t0 = clock();
            v.pop_back();
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}

double aproximarComplejidadEj5_4(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_4.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<int> v = construir_vector(i, "azar");
            //
            double t0 = clock();
            int x = v[i];
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}


double aproximarComplejidadEj5_5(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_5.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<int> v = construir_vector(i, "azar");
            //
            double t0 = clock();
            v[i] = 0;
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}

double aproximarComplejidadEj5_6(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_6.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<bool> v(i,0);
            //
            double t0 = clock();
            v.flip();
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}

double aproximarComplejidadEj5_7(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej5_7.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {

            vector<bool> v(i,0);
            //
            double t0 = clock();
            v.clear();
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}

void generarDataEj5(){
    int n = 1000; // simulaciones
    aproximarComplejidadEj5_1( n);
    aproximarComplejidadEj5_2( n);
    aproximarComplejidadEj5_3( n);
    aproximarComplejidadEj5_4( n);
    aproximarComplejidadEj5_5( n);
    aproximarComplejidadEj5_6( n);
    aproximarComplejidadEj5_7( n);
}

double aproximarComplejidadEj6(int n){
    double total = 0;
    ofstream fout;
    fout.open("/home/lucio/FCEN/Algo1/laboC++/09/Ejercicios/data/ej6.csv");
    if(fout.is_open()) {
        fout << "n\t" << "tiempo" << endl;
        for (int i = 1; i <= n; i++) {
            int sum = rand()%100;
            vector<int> v = construir_vector(i,"azar");
            //
            double t0 = clock();
            bool r = algunSubconjSuma(v,sum);
            double t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            //
            fout << i << "\t" << tiempo << endl;
            total += tiempo;

        }
    }
    fout.close();
    return (total/n);
}

void generarDataEj6(){
    aproximarComplejidadEj6(2000);
}
