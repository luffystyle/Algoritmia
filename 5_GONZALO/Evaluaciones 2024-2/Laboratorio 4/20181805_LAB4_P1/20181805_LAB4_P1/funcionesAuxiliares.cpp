/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "ArbolB.h"
#include "funciones.h"
#include "funcionesAB.h"
#include "funcionesAuxiliares.h"

using namespace std;

void generarArbol(struct ArbolBinario & arbol){
    plantarArbolBinario(arbol.raiz, nullptr, 'B', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda, nullptr, 'I', nullptr);
    plantarArbolBinario(arbol.raiz->derecha, nullptr, 'U', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->izquierda, nullptr, 'E', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha, nullptr, 'L', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda, nullptr, 'E', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha, nullptr, 'R', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->izquierda, nullptr, 'N', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha->izquierda, nullptr, 'B', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda, nullptr, 'N', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->derecha, nullptr, 'R', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha->izquierda->izquierda, nullptr, 'A', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda->izquierda, nullptr, 'A', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda->derecha, nullptr, 'O', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->derecha->izquierda, nullptr, 'A', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->derecha->derecha, nullptr, 'O', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha->izquierda->izquierda->izquierda, nullptr, 'O', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda->derecha->derecha, nullptr, 'S', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->derecha->derecha->derecha, nullptr, 'S', nullptr);
}

void imprimirArbol(const struct ArbolBinario & arbol){
    struct Lista lista;
    construir(lista);
    imprimirArbolRecursivo(arbol.raiz, lista);
    destruir(lista);
}

void imprimirArbolRecursivo(struct NodoArbol * nodo, struct Lista & lista){
    if (not esNodoVacio(nodo)){
        insertarAlFinal(lista, nodo->elemento);
        if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha)){
            imprime(lista);
            cout << endl;
            eliminaCola(lista);
            return;
        }
        imprimirArbolRecursivo(nodo->izquierda, lista);
        imprimirArbolRecursivo(nodo->derecha, lista);
        eliminaCola(lista);
    }
}