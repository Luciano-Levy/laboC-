#include "ejercicios.h"

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
	//COMPLETAR
	vector<vector<int> > res;
    int i = 0;
    while (i<u.size()){
        int j = 0;
        vector<int> tmp = {};
        while(j<v.size()){
            tmp.push_back(u[i] * v[j]);
            j++;
        }
        res.push_back(tmp);
        i++;
    }
	return res;
}

bool esCuadrada(vector<vector<int>> m){
    int i =0;
    while(i<m.size()){
        if(m[i].size() != m[0].size()){
            return false;
        }
        i++;
    }
    return true;
}


void trasponer(vector<vector<int> > &m) {
	if(!esCuadrada(m)){
        return;
    }
    vector<vector<int>> m_0 = m;
    int i = 0;
    while(i<m.size()){
        int j = 0;
        while(j<m[0].size()){
            m[i][j] = m_0[j][i];
            j++;
        }
        i++;
    }
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	if(m1[0].size() != m2.size()|| m1.empty() || m2.empty() || m2[0].empty()) {
        throw invalid_argument("La multiplicacion no esta definida para estas matrices");
    }
	vector<vector<int> > res(m1.size(),vector<int>(m2[0].size(), 0));

    int i = 0;
    while(i<m1.size()){
        int j = 0;
        while(j<m2[0].size()){
            int k=0;
            while(k<m2.size()){
                res[i][j] += m1[i][k]*m2[k][j];
                k++;
            }
            j++;

        }
        i++;
    }

    // que O() tiene esto
	return res;
}
vector<int> conseguirVecinos(vector<vector<int> > m, int i,int j){
    vector<int> res;
    int i_0 = i-1;
    while(i_0 <= i + 1){
        int j_0 = j-1;
        if(i_0 >= 0 && i_0 < m.size()) {
            while (j_0 <= j + 1) {

                if (j_0 >= 0 && j_0 < m[0].size()) {
                    res.push_back(m[i_0][j_0]);
                }
                ++j_0;
            }

        }
        ++i_0;
    }

    return res;
}

int sumaVec(vector<int> v){
    int res = 0;
    int i = 0;
    while(i<v.size()){
        res += v[i];
        i++;
    }
    return res;
}


vector<vector<int> > promediar(vector<vector<int> > m){

	vector<vector<int> > res(m.size(),vector<int>(m[0].size()));
    int i = 0;
    while(i < m.size()){
        int j = 0;
        while(j < m[0].size()){
            vector<int> vecinos = conseguirVecinos(m,i,j);
            res[i][j] = (sumaVec(vecinos)) / vecinos.size();
            ++j;
        }
        ++i;
    }

	return res;
}

int mayorVec(vector<int> v){
    int res = v[0];
    int k = 1;
    while(k < v.size()){
        if(res < v[k]){
            res = v[k];
        }
        k++;
    }
    return res;
}

int apariciones(vector<int> v, int x){
    int res = 0;
    int i = 0;
    while(i<v.size()){
        if(x == v[i]){
            res += 1;
        }
        i++;
    }
    return res;
}


int contarPicos(vector<vector<int> > m){
    int res = 0;
    int i = 0;
    while(i < m.size()){
        int j = 0;
        while(j < m[0].size()){
            vector<int> vecinos = conseguirVecinos(m,i,j);
            int mayor = mayorVec(vecinos);
            if( m[i][j] == mayor && apariciones(vecinos,mayor) == 1 ){
                res += 1;
            }
            ++j;
        }
        ++i;
    }
	return res;
}

bool Tinferior(vector<vector<int>> m) {
    int j = 0;
    while(j < m[0].size()){
        int i = j+1;
        while(i < m.size()){
            if(m[i][j] != 0){
                return false;
            }
            i++;
        }
        j++;
    }
    return true;

}

bool Tsuperior(vector<vector<int>> m){
    int j = m[0].size();
    while(j <= 0){
        int i = 0;
        while(i < j){
            if(m[i][j] != 0){
                return false;
            }
            i++;
        }
        j--;
    }
    return true;
}


bool esTriangular(vector<vector<int> > m){

    if(Tsuperior(m) || Tinferior(m)){
        return true;
    }
    return false;



}

vector<vector<int>> reinas(vector<vector<int>> m){

    vector<vector<int>> res;
    int i = 0;
    while(i<m.size()){
        int j = 0;
        while(j<m[0].size()){
            if(m[i][j] == 1){
                vector<int> reina;
                reina.push_back(i);
                reina.push_back(j);
                res.push_back(reina);
            }
            j++;
        }
        i++;
    }
    return res;
}

bool hayAmenaza(vector<vector<int> > m){
    vector<vector<int>> reinasT = reinas(m);
    int i = 0;
    while(i < reinasT.size()){
        int j = i+1;
        while(j<reinasT.size()){
            if( reinasT[i][0] == reinasT[j][0] || reinasT[i][1] == reinasT[j][1] ||
                    abs(reinasT[i][0] - reinasT[j][0]) == abs(reinasT[i][1] - reinasT[j][1])){
                return true;
            }
            j++;
        }
        i++;
    }


	return false;
}

int diagonalInicial(vector<vector<int>> m){
    int i =0;
    int sum = 0;
    while(i < m.size()){
        sum += m[i][i];
        i++;
    }
    return sum;
}
int diagonalFinal(vector<vector<int>> m){
    int i =m.size()-1;
    int j = 0;
    int sum = 0;
    while(i >= 0 && j < m.size()){
        sum += m[i][j];
        i--;
        j++;
    }
    return sum;
}
int diferenciaDiagonales(vector<vector<int> > m) {

    return abs(diagonalInicial(m)- diagonalFinal(m));
}