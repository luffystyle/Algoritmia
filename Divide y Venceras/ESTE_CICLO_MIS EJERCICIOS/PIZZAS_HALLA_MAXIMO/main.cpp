/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on November 1, 2024, 8:18 PM
 */

#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;



int buscarMaximo(int *arr, int ini, int fin) {
    if( ini == fin) return arr[ini];
    
    int med = (ini + fin)/2;
    
    int maximoIzq = buscarMaximo(arr, ini, med);
    int maximoDer = buscarMaximo(arr, med+1, fin);
    if(maximoIzq > maximoDer) return maximoIzq;
    else return maximoDer;
}


int mayorCantProduccion(int *arr,int ini,int fin){ //Complejidad O(n);
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    
    if(arr[med]<arr[med+1]){
        int a =mayorCantProduccion(arr,med+1,fin);
        int b= mayorCantProduccion(arr,ini,med-1);
        if(a>b) return a;
        else
            return b;
    }else{
        int a =mayorCantProduccion(arr,med+1,fin);
        int b= mayorCantProduccion(arr,ini,med-1);
        if(a>b) return a;
        else
            return b;
    }
    
}

int mayorCantidadProduccion( int *arr, int ini, int fin) {
    
    int maximo = buscarMaximo(arr, ini, fin);
    int cantidad = 0;
    for(int i = 0; i<fin+1; i++) {
        if(arr[i] == maximo) 
            cantidad++;
    }
    cout << cantidad << endl;
    return cantidad;

}




int main(int argc, char** argv) {

    
    int empresa1[] = {15, 12, 10, 17, 15, 18, 18, 18, 12, 16};
    int empresa2[] = {14, 17, 17, 17, 17, 12, 14, 14, 12, 12};
    int empresa3[] = {16, 18, 20, 20, 15, 18, 16, 18, 18, 16};
    
    
    int cantProd1, cantProd2, cantProd3;
    
//    cantProd1 = mayorCantidadProduccion(empresa1, 0, 9);
//    cantProd2 = mayorCantidadProduccion(empresa2, 0, 9);
//    cantProd3 = mayorCantidadProduccion(empresa3, 0, 9);
    
    cantProd1 = buscarMaximo(empresa1, 0, 9);
    cantProd2 = buscarMaximo(empresa2, 0, 9);
    cantProd3 = buscarMaximo(empresa3, 0, 9);
    
    cout << cantProd1 << setw(3) << cantProd2 << setw(3) << cantProd3 << endl;
    
//    int minimo = INT_MAX;
//    cout << minimo << endl;
    cout << max(max(cantProd1, cantProd2), cantProd3);
    
    return 0;
}

