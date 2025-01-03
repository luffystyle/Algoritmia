
/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on November 1, 2024, 11:32 PM
 */

#include <iostream>

using namespace std;



int cuentaCeros(int *arr, int ini, int fin, int contador) {
    
    if(ini > fin) {
        return contador;
    }

    int med = (ini + fin)/2;
    if(arr[med] == 0 ) { // me voy  a la izquierda
        return cuentaCeros(arr, ini, med-1, contador + (fin - med + 1));
    } else {
        return cuentaCeros(arr, med + 1, fin, contador);
    }
    
}


int contarNumeros(int *arr, int *arr2,int ini, int fin, int contador, int numero) {
    if(ini > fin) return 0;
    if(ini == fin) {
        if(arr[ini] == numero) {
            contador += arr2[ini];
        }
        return contador;
    }
    
    int med = (ini + fin)/2;
    
    int contIzq = contarNumeros(arr, arr2, ini, med, contador, numero);
    int contDer = contarNumeros(arr, arr2, med+1, fin, contador, numero);
    return contador + contIzq + contDer;
    
}



int main(int argc, char** argv) {
    int arr[]={1, 1, 1, 1, 0, 0, 0, 0};//Dato de entrada
    
//    int arr[] = {2, 2, 2, 1, 1, 1, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23};
//    int arr2[] = {2, 1, 3, 2, 2, 3, 3, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    int contador = 0;
    
    cout << cuentaCeros(arr, 0, n-1, contador);
//    int numero = 2;
//    
//    cout << contarNumeros(arr, arr2, 0, n-1, contador, numero);   
    
    
    return 0;
}

