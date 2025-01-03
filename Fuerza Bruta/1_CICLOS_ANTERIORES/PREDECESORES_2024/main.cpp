

#include <iostream>
#include <cmath>
using namespace std;




void cargaBinaria(int *arr, int numero, int n) {
    int i;
    for( i = 0; i<n; i++) arr[i] = 0;
    i = 0;
    while(numero>0) {
        arr[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

void mostrarCromosoma(int *arr, int n) {
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}


int main(int argc, char** argv) {

    int n = 8, p = 100;
    int combinaciones = pow(2, n);
    int cromosoma[n];
    
    int arrControles[][3]={ {32,  0,  60},
                            { 8,  0,  32},
                            {40, 12, 120},
                            {40,  0,  60},
                            {20,  0,  32},
                            { 4,  2,  20},
                            {16,  6,  48},
                            {16,  6,  60}   };
    
    for(int i = 0; i<combinaciones; i++){
        cargaBinaria(cromosoma, i, n);
        //mostrarCromosoma(cromosoma, n);
        for( int j = 0; j<n; j++) {
            if(cromosoma[i] == 1) {
                
            }
        }
    }
    
    
    
    return 0;
}

