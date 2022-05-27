#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
    // Completar aca
    string res = s;
    for(int i=0;i<s.size();i++){
        int k = (i+j)%(s.size());
        res[k] = s[i];
    }
	return res;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
