

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 28, 2024, 3:29 PM
 */

#include <iostream>

using namespace std;

int busquedaBinaria(int *arr, int ini, int fin , int elementoAbuscar) {
    
    if(ini > fin) return -1; // No encontramos
    
    int med = (ini + fin)/2;
    if(arr[med] == elementoAbuscar) return med;
    else {
        if(arr[med] > elementoAbuscar)
            busquedaBinaria(arr, ini, med-1, elementoAbuscar);
        else // arr[med] < elementoAbuscar 
            busquedaBinaria(arr, med+1, fin, elementoAbuscar);
    }
}

int main(int argc, char** argv) {

    int arr[] = {2, 3, 4, 5, 6, 7, 10, 11};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout << n << endl;
    int elementoAbuscar = 10;
    int ini = 0, fin = n -1;
    int posicion = busquedaBinaria(arr, ini, fin , elementoAbuscar);
    cout << posicion << endl;
    
    return 0;
}
