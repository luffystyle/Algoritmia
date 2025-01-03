
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 13, 2024, 3:31 PM
 */

#include <iostream>

#include "NodoArbol.h"
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

using namespace std;

struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int binario, int elemento, 
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->binario = binario;
    return nuevo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int binario, int elemento, 
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, binario, elemento, derecha);
    raiz = nuevoNodo;
}

void insertarRecursivoNew(struct NodoArbol *& raiz, int binario, int elemento){
    if(esNodoVacio(raiz))
        plantarArbolBinarioNew(raiz, nullptr, binario, elemento, nullptr);
    else
        if(raiz->elemento > elemento)
            insertarRecursivoNew(raiz->izquierda, binario, elemento);
        else
            if(raiz->elemento < elemento)
                insertarRecursivoNew(raiz->derecha, binario, elemento);
            else
                cout << "El elemento " << elemento << "Ya se encuentra en el árbol" << endl;
}


void insertarNew(struct ArbolBinarioBusqueda & arbol, int binario, int elemento){
    insertarRecursivoNew(arbol.arbolBinario.raiz, binario, elemento);
}


void procesarDiagonal(NodoArbol* nodo) {
    while (nodo != nullptr) {
        cout << nodo->binario << "-" << nodo->elemento << " ";
        nodo = nodo->derecha; // Avanzar hacia la derecha en la misma diagonal
    }
}

void recorrerEnDiagonalRecursivo(NodoArbol* nodo, NodoArbol *&skynerd, int bandera) {
    if (nodo == nullptr) {
        return;
    }

    if(!esNodoVacio(nodo->izquierda)) {
        if(nodo->izquierda->binario == 1) {
            //skynerd = new NodoArbol;
            skynerd = nodo->izquierda;
        }
    }
    
    
    if(nodo->binario != 1) {
        imprimirNodo(nodo);
    }
    
    if(nodo->elemento == 75) 
        imprimirNodo(skynerd);
    recorrerEnDiagonalRecursivo(nodo->derecha, skynerd, bandera);
    // Luego, mueve la recursión hacia la siguiente diagonal (subárbol izquierdo)
    recorrerEnDiagonalRecursivo(nodo->izquierda, skynerd, bandera);
    
}

// Función principal para el recorrido diagonal
void recorrerEnDiagonal(NodoArbol* raiz) {
    if (raiz == nullptr) {
        return;
    }

    cout << "Recorrido en diagonal:" << endl;
    NodoArbol *skynerd = new NodoArbol;
    recorrerEnDiagonalRecursivo(raiz, skynerd, 0);
    cout << endl;
}

int main(int argc, char** argv) {

    ArbolBinarioBusqueda abb;
    construir(abb);
    insertarNew(abb, 0, 100);
    insertarNew(abb, 0, 50);
    insertarNew(abb, 0, 150);
    insertarNew(abb, 0, 25);
    insertarNew(abb, 0, 75);
    insertarNew(abb, 1, 125);
    insertarNew(abb, 0, 175);
    insertarNew(abb, 0, 40);
    insertarNew(abb, 0, 200);
    
    //recorrerEnOrden(abb.arbolBinario); cout << endl;
    recorrerEnDiagonal(abb.arbolBinario.raiz);
    
    return 0;
}

