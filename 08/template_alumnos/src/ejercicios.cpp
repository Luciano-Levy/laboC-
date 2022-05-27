#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
    string word;
    for(int i = 0;i<s.size();i++){
        if(s[i] == delim && word.size() > 0){
            v.push_back(word);
            word.clear();
        }
        else if(s[i] != delim){
            if(i == s.size()-1){
                word.push_back(s[i]);
                v.push_back(word);
            }else{
                word.push_back(s[i]);
            }
        }

    }
	return v;
}


string darVueltaPalabra(string s){
	string res;
    vector<string> separadas = split(s,' ');// hacer una funcion que haga las dos cosas?
    for(int i=separadas.size()-1;i>=0;i--){
        for(int j =0;j<=separadas[i].size();j++){
            if(j != separadas[i].size()){
                res.push_back(separadas[i][j]);

            }else if(i==0){
                break;
            }
            else{
                res.push_back(' ');
            }
        }
    }
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
	int i = 0;
    int indice = 0;
    while(i < s1.size()){
        int j = indice;
        while(j<s2.size() && s2[j] != s1[i]){
            j++;
        }
        if(j==s2.size())return false;
        indice = j+1;
        i++;
    }
    return true;
}

bool subsecuenciaSinOrden(string s1, string s2) {
    int i = 0;

    while(i < s1.size()){
        int j = 0;
        while(j<s2.size() && s2[j] != s1[i]){
            j++;
        }
        if(j==s2.size())return false;

        i++;
    }
    return true;
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
    for(int i=0;i<v.size();i++){
        if(!v[i].empty()){ // es como user v.size() != 0
            vector<string> anagramas;
            anagramas.push_back(v[i]);
            for(int j=i+1;j<v.size();j++){
                if(v[j].size() == v[i].size() && subsecuenciaSinOrden(v[j],v[i])){
                    anagramas.push_back(v[j]);
                    v[j].clear();
                }
            }
            res.push_back(anagramas);
        }
    }
	return res;
}

bool esPalindromo(string s){
	int i = 0;
    while(i<s.size() && s[i] == s[s.size()-1-i]){
        i++;
    }
	return i == s.size();
}

bool tieneRepetidos(string s){
	for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i] == s[j]){
                return true;
            }
        }
    }
    return false;

    // Hay una manera que no sea n^2
}

string rotar(string s, int j){
	string res = s;
    for(int i=0;i<s.size();i++){
        int k = (i+j)%(s.size());
        res[k] = s[i];
    }
	return res;
}
void swap(char &a,char &b){
    char a_0 = a;
    char b_0 = b;

    a = b_0;
    b = a_0;
}

// no se puede usar substring
string darVueltaK(string s, int k){

    string res;
    int final;
    int i = 0;
    while(i<s.size()){
        int r =i+ k - 1;
        if(r>=s.size()){
            r=r-1;
        }
        for(int j=i;j<=(r+i)/2;j++) {

            swap(s[j], s[r]);
            r--;
            final = j;
        }
        i=final+k;
        }

	return s;
}

string abueloLaino(string s){
    string res;
    res.push_back('S');
    int i =0;
    while(i < s.size()){
        if(s[i] == 'i'){
            res.clear();
            res.push_back('N');
        }
        i++;
    }
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){


}

int middleOut(string s, string t){
    int i =0;
    int cambios =-1;
    while(i<s.size()){
        if(t[i] == s[0]){
            swap(s[i],s[0]);
            cambios++;
        }else if(t[i] == s[s.size()-1]){
            swap(s[i],s[s.size()-1]);
            cambios++;
        }
        i++;
    }
    return cambios;
}
