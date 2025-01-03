
/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on November 1, 2024, 4:55 PM
 */

#include <iostream>

using namespace std;


int buscarMaximo( int  *arr, int ini, int fin) {
    
    if(ini == fin) return arr[ini]; // o arr[fin]
    
    int medio = (ini + fin)/2;
    
    if(arr[medio] > arr[medio+1])
        return buscarMaximo(arr, ini, medio);
    else {
        return buscarMaximo(arr, medio+1, fin);
    }
    
    
}


int buscarMayorDesordenado( int  *arr, int ini, int fin) {
     
    if(ini == fin) return arr[ini];
    
    int medio = (ini + fin)/2;
    
    
    int maximoIzquierda = buscarMayorDesordenado(arr, ini, medio);
    int maximoDerecha = buscarMayorDesordenado(arr, medio + 1, fin);
    
    if(maximoIzquierda > maximoDerecha) return maximoIzquierda;
    else return maximoDerecha;    
}


int buscarElemento(int *arr, int ini, int fin, int elemento) {
    
    
    if(ini > fin) return -1;
    int medio = (ini + fin)/2;
    //RETORNO LA POSICION
    if(arr[medio] == elemento) return medio;// SI ESTA EN EL MEDIO
    else {
        if(arr[medio] > elemento) return buscarElemento(arr, ini, medio-1, elemento); // si pongo medio, me da bucle infinito
        else return buscarElemento(arr, medio + 1, fin, elemento);
    }   
}





int main(int argc, char** argv) {

    //int arr[] = {1,2, 5, 3, 2};
    //int arr[] = {200, 10};
//    int arr[] = {100, 5, 3, 10, 15, 80};
    int arr[] = {1, 3, 6, 7, 9, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
//    cout << buscarMaximo(arr, 0, n-1) << endl;
//    cout << buscarMayorDesordenado(arr, 0, n-1);
    
    cout << buscarElemento(arr, 0, n-1, 9);
    
    return 0;
}

