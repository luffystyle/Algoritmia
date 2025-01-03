//  PRUEBA
#include <iostream>
#include <iomanip>
#include <cmath>
#define N 4

using namespace std;



int main(int argc, char** argv) {
    int digitos[] = {2, 5, 5, 2, 5, 6, 1, 1, 1, 6, 9};
    int aux = 0, contador = 4, i = 4;
    
    for(int j = contador - 1; j>=0; j--) {
        aux = aux + digitos[ i - (j+1)]*pow(10, j);
        //cout << "El aux es " << aux << endl;
    }
    cout << "Aux final " << aux << endl;
    
    return 0;
}



