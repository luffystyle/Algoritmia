/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 5, 2024, 1:20 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

using namespace std;

int valorMaximoRecursivo(NodoArbol *nodo ) {
    if(esNodoVacio(nodo)) return 0;
    if(nodo->izquierda == nullptr && nodo->derecha == nullptr)
        return nodo->elemento;
    if(!esNodoVacio(nodo->derecha)) 
        valorMaximoRecursivo(nodo->derecha );
}

int valorMaximoArbol(ArbolBinarioBusqueda &abb) {
    return valorMaximoRecursivo(abb.arbolBinario.raiz->derecha );
}

void insertarABBnew(ArbolBinarioBusqueda &abb, int elemento) {
    bool seEncuentra = buscar(abb, elemento);
    if(seEncuentra != false) { // Se encuentra
        elemento += valorMaximoArbol(abb);
    } 
    insertarRecursivo(abb.arbolBinario.raiz, elemento);
}

int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    insertarABBnew(abb, 2);
    insertarABBnew(abb, 5);
    insertarABBnew(abb, 2);
    insertarABBnew(abb, 1);
    insertarABBnew(abb, 5);
    insertarABBnew(abb, 6);
    insertarABBnew(abb, 3);
    insertarABBnew(abb, 4);
    
    recorrerEnOrden(abb.arbolBinario); cout << endl;

    return 0;
}

