
/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on November 26, 2024, 6:28 PM
 */

#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

// NodoArbol *&nodo esto va a asi porque aqui le vamos a dar memoria dinamica
void plantaArbolABBnuevo(NodoArbol *&nodo, NodoArbol *arbolIzquierdo, int numLote, int cantidad, NodoArbol *arbolDerecho) {
    NodoArbol *nuevoNodo = new NodoArbol;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    nuevoNodo->elemento = numLote;
    nuevoNodo->cantidad = cantidad;
    nodo = nuevoNodo;
}

void insertarNuevoRecursivo(NodoArbol *&nodo, int numLote, int cantidad) {
    if(nodo == nullptr) {
        plantaArbolABBnuevo(nodo, nullptr, numLote, cantidad, nullptr);
    } else {
        if(nodo->elemento < numLote) {
            insertarNuevoRecursivo(nodo->derecha, numLote, cantidad);
        } else {
            insertarNuevoRecursivo(nodo->izquierda, numLote, cantidad);
        }
    }
}

void insertaNuevo(ArbolBinarioBusqueda &abb,int numLote, int cantidad) {
    insertarNuevoRecursivo(abb.arbolBinario.raiz, numLote, cantidad);
}

NodoArbol *buscarNodoAntiguo(NodoArbol *nodo) {

    if(nodo->izquierda == nullptr) {
        return nodo;
    } else {
        return buscarNodoAntiguo(nodo->izquierda);
    }
}

NodoArbol *eliminarNodoRecurchivito(NodoArbol *nodo, int dato) {
    if(esNodoVacio(nodo)) return nodo;
    
    if(dato < nodo->elemento) {
        nodo->izquierda = eliminarNodoRecurchivito(nodo->izquierda, dato);
    } else if(dato > nodo->elemento) {
        nodo->derecha = eliminarNodoRecurchivito(nodo->derecha, dato);
    } else {
        if(esNodoVacio(nodo->izquierda)) {
            NodoArbol *hijo = nodo->derecha;
            delete nodo;
            return hijo;
        } else if(esNodoVacio(nodo->derecha)) {
            NodoArbol * hijo = nodo->izquierda;
            delete nodo;
            return hijo;
        } else {
            NodoArbol *minNodo = buscarNodoAntiguo(nodo->derecha);
            nodo->elemento = minNodo->elemento;
            nodo->derecha = eliminarNodoRecurchivito(nodo->derecha, minNodo->elemento);
        }
    }
    return nodo;    
}

void eliminarNodito(ArbolBinarioBusqueda &ab, int dato) {
    ab.arbolBinario.raiz = eliminarNodoRecurchivito(ab.arbolBinario.raiz, dato);
}

int main(int argc, char** argv) {

    ArbolBinarioBusqueda abb;
    construir(abb.arbolBinario);
    insertaNuevo(abb, 20180211, 20);
    insertaNuevo(abb, 20170810, 20);
    insertaNuevo(abb, 20170620, 20);    
    insertaNuevo(abb, 20180409, 10);
    
    int numPedidos = 35;
    
    while(numPedidos > 0) {
        NodoArbol *nodo_anticucho = buscarNodoAntiguo(abb.arbolBinario.raiz);
        if(nodo_anticucho->cantidad <= numPedidos) {
            numPedidos -= nodo_anticucho->cantidad;
            eliminarNodito(abb, nodo_anticucho->elemento);
        } else {
            nodo_anticucho->cantidad -= numPedidos;
            numPedidos = 0;
        }
    } 
    recorrerEnOrden(abb.arbolBinario);

    return 0;
}
