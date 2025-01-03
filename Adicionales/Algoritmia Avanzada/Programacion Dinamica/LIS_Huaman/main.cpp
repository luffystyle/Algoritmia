// LONGEST INCREASING SUBSEQUENCE (LIS)

#include <iostream>
using namespace std;

int solveLIS(int X[], int n) {
    //aqui creamos el LIS
    int LIS[n];
    int i, j, maxLis = 1;
    // el i es para recorrer el arreglo y el j es para recorrer el mismo pero desde el i hacía atras
    for(i = 0; i < n; i++) {
        LIS[i] = 1;// esto es el LIS inicial de cualquier numero, ya sea -7 o 10 o 9 etc
        for(j = 0; j < i; j++) {
            if( (X[i] > X[j]) && (LIS[j] + 1 > LIS[i]) ) LIS[i] = LIS[j] + 1;            
        }
        if(LIS[i] > maxLis) maxLis = LIS[i];      // solo estoy guardando el mayor de las longitudes  
    }
    return maxLis;
}

int main(int argc, char** argv) {

    int X[] = {-7, 10, 9, 2, 3, 8, 8, 1};
    int n = 8;
   
    cout << "La secuencia más larga de número consecutivos es : " << solveLIS(X, n);

    return 0;
}
