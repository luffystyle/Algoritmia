

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 14 de diciembre de 2024, 08:15 AM
 */

#include <iostream>

#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

using namespace std;
// PREGUNTA B
#define M 7
#define N 4

struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, int diaturno,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->diaTurno = diaturno;
            
    return nuevo;
}
// FUNCION RECURSIVA
NodoArbol *construirArbolito(int *arr, int *arrCantidad, int ini, int fin) {
    if(ini>fin) return nullptr;
    
    int med = (ini+fin)/2;
    NodoArbol *nodo = crearNuevoNodoNew(nullptr, arr[med], arrCantidad[med],nullptr);
    
    nodo->izquierda = construirArbolito(arr, arrCantidad, ini, med-1);
    nodo->derecha = construirArbolito(arr, arrCantidad, med+1, fin);
    return nodo;
}

void equilibrarArbol(ArbolBinarioBusqueda & abb, int *arr, int *arrdiaTurno,int ini, int fin) {
    
    destruirArbolBinario(abb.arbolBinario);
    abb.arbolBinario.raiz = construirArbolito(arr, arrdiaTurno, ini, fin);
}

void insertarcantidad(ArbolBinarioBusqueda & abb, int elemento, int *arr, int *arrdiaTurno, int cantidad){
    destruirArbolBinario(abb.arbolBinario);
    equilibrarArbol(abb, arr, arrdiaTurno, 0, cantidad - 1);
}

int main(int argc, char** argv) {

    
    int matriz[][7] = {{100, 103, 100, 101, 100, 99, 100},
                       {100, 102, 102,  92,  99, 100,  98},
                       {100, 100, 102, 100, 100, 101, 100}, 
                       {98,   96,  93,  99, 100, 102,  95}};
    
    int arreglo[N*M]{}; // arreglo de cantidad
    int arrDiaTurno[N*M]{}; // arreglo de dia y turno
    int cantidad = 0;
    ArbolBinarioBusqueda abb;
    construir(abb);
    for(int i = 0; i<N; i++) {
        for(int k = 0; k<M; k++) {
            arreglo[cantidad] = matriz[i][k];
            arrDiaTurno[cantidad] = 10*(1+i) + (k+1); //  elturno es 1 y el dia es 1
            // van 11 12 13 14 15 16 17 , esto es para el turno 1 y aasi sucesimente hasta el turno 4
            cantidad++;
            insertarcantidad(abb, arreglo[cantidad], arreglo, arrDiaTurno, cantidad);
        }
    }
    if(esEquilibrado(abb.arbolBinario)) 
        cout << "Es arbol equilibrado" << endl;
    
    
    //Por ejemplo 24
    // el turno es el 2 y el dia es 4 que seria jueves
    recorrerEnOrden(abb.arbolBinario);
    //armarArbolito(abb, arreglo);
    
    return 0;
}

