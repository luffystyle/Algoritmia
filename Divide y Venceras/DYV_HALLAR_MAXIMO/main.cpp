#include <iostream>
using namespace std;

int maximo( int arr[], int ini, int fin) {
    
    int medio;
    
    medio = (ini + fin)/2;
    
    if(ini == fin) return arr[ini];
    
    //esta condicion es cuando son dos elementos y siempre caeria en la condicion dos 
    // de la linea 25
    
    if( fin - ini == 1) {
        if( arr[fin] > arr[ini]) return arr[fin];
        else return arr[ini];
    }
    
    if(arr[medio] > arr[medio+1]) return maximo(arr, ini, medio); // la parte de la derecha ya no nos sirve
    else return maximo(arr, medio, fin);
    
    
}



int main(int argc, char** argv) {


    
    int arreglo[] = {8, 10, 20, 100, 50, 30, 6, 1};
    int n = 8;
    // le pasamos a la funcion maximo la posicion inicial 0 y la posicion final n-1    
    cout << "El maximo valor del arreglo es " << maximo(arreglo, 0, n-1);


    return 0;
}

