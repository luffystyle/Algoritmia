
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 29, 2024, 7:28 PM
 */

#include <iostream>

using namespace std;

int buscarMayor(int *arr, int ini, int fin) {
    
    if(ini == fin) return arr[fin];
    
    int med = (ini+fin)/2;
    
    int maxIzquierda = buscarMayor(arr, ini, med);
    int maxDerecha = buscarMayor(arr, med+1, fin);
    
    if(maxDerecha > maxIzquierda) return maxDerecha;
    else return maxIzquierda;
    
}


//Este halla el maximo si está como una montaña que suba y luego baje
// Esta funcion descarta, no recorre todo el arreglo como el anteiror de buscar maximo
int buscamax(int *arr,int ini,int fin){
    if(ini==fin)return arr[ini];
    
    int med=(ini+fin)/2;
    
    if(arr[med]>arr[med+1])
        return buscamax(arr,ini,med);
    else
        return buscamax(arr,med+1,fin);
}

int main(int argc, char** argv) {

    
    int productos[] = {10, 15, 20, 80, 1000, 200, 100, 50, 20, 10};
//    int arr[] = {200, 5, 6, 1, 25, 2, 103, 70, 23, 150};
    int stocks[] = {20, 20, 30, 10, 10, 10, 20, 20, 20, 10};
    int n = sizeof(productos)/ sizeof(productos[0]);
    
    int codProducto = 20;
    
    cout << buscarMayor(productos, 0, n-1) << endl;
//    cout << buscamax(arr, 0, sizeof(arr)/ sizeof(arr[0]));
    
    return 0;
}

