

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 14 de diciembre de 2024, 08:15 AM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

using namespace std;
// PREGUNTA A
#define M 7
#define N 4



struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, int cantidad,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->cantidad = cantidad;
            
    return nuevo;
}

NodoArbol *construirArbolito(int *arr, int *arrCantidad, int ini, int fin) {
    if(ini>fin) return nullptr;
    
    int med = (ini+fin)/2;
    NodoArbol *nodo = crearNuevoNodoNew(nullptr, arr[med], arrCantidad[med],nullptr);
    
    nodo->izquierda = construirArbolito(arr, arrCantidad, ini, med-1);
    nodo->derecha = construirArbolito(arr, arrCantidad, med+1, fin);
    return nodo;
}

void equilibrarArbol(ArbolBinarioBusqueda & abb, int *arr, int *arrCantidad,int ini, int fin) {
    
    destruirArbolBinario(abb.arbolBinario);
    abb.arbolBinario.raiz = construirArbolito(arr, arrCantidad, ini, fin);
}




void insertadiaturno(ArbolBinarioBusqueda & abb, int elemento, int *arr, int *arrCantidad, int h) {
    //destruirArbolBinario(abb.arbolBinario);
    equilibrarArbol(abb, arr, arrCantidad, 0, h-1); //  cada vez que ingresamos REORDENAMOS EL ARBOL
    // a traves del arreglo
}

//void recursionInsertar(NodoArbol *nodo, int elemento, int ini, int fin) {
//    if(ini == fin) return ;
//    if(elemento > nodo->elemento) {
//        recursionInsertar(nodo->derecha, elemento, ini, fin)
//    }
//    recursionInsertar(nodo->izquierda, )
//}
//
//
//void armarArbolito(ArbolBinarioBusqueda & arbol, int *arr, int cant) {
//    
//    int med = (cant+1)/2;
//    insertar(arbol, arr[med]);// la raiz el punto medio
//    
//}


int main(int argc, char** argv) {

    
    int matriz[][7] = {{100, 103, 100, 101, 100, 99, 100},
                   {100, 102, 102,  92,  99, 100,  98},
                   {100, 100, 102, 100, 100, 101, 100}, 
                   {98,   96,  93,  99, 100, 102,  95}};
    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    int arr[N*M]{},  h = 0;
    int arrCantidad[N*M]{};
    int arreglon[N*M]{};
    
    // EL numero 1 es Lunes, marte 2 ... viernes 4
    // Estoy recorriendo por filas porque me piden en ese orden dia y turno
    int variable = 0;
    for(int i = 0; i<7; i++) {
        for(int k = 0; k<4; k++) {
            int elemento = 10*(variable+1) + (k+1);
            arrCantidad[h] = matriz[k][i];
            //arreglon[h] = 10*(variable+1) + (k+1);
            arr[h] = elemento;
            h++;
            insertadiaturno(abb, elemento, arr, arrCantidad, h); // por cada vez creo un arbol ya equilibrado
            //cout << elemento << " " << cantidad <<endl;
            //variable++;
        }
        variable++;
    }
    if(esEquilibrado(abb.arbolBinario)) cout << "Es arbol equilibrado" << endl;
    
    
    //for(int i  = 0; i<N*M; i++) cout << arreglon[i] << " ";
    //cout << endl;
    //armarArbolito(abb, arreglon, h);
    
    recorrerEnOrden(abb.arbolBinario); cout << endl;
    recorrerPreOrden(abb.arbolBinario); //VERIFICAMOS QUE EL PRIMER NODO ES EL 27, entonces esta equilibrado
    
    
    return 0;
}

