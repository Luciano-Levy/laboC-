#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s, string t) {
    int i = 0;
    int indice = 0;
    while(i < s.size()){
        int j = indice;
        while(j<t.size() && t[j] != s[i]){
            j++;
        }
        if(j==t.size())return false;
        indice = j+1;
        i++;
    }
    return true;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

