#include <iostream>

using namespace std;

void swap(int& a, int& b){
    
    int a_0 = a;
    int b_0 = b;

    a = b_0;
    b = a_0;
}

int main() {
    /* No hace falta modificar el main */
    int a,b;
    //Leo a
    cin >> a >> b;
    
    swap(a,b);
    
    //Devuelvo despues del swap
    cout << a << " " << b;
    return 0;
}
