/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 10, 2024, 8:47 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Pila.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

using namespace std;


struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int binario, int elemento, struct NodoArbol * derecha) {
    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->binario = binario;
    return nuevo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, struct NodoArbol * izquierda, int binario, int elemento,  struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, binario, elemento, derecha);
    raiz = nuevoNodo;
}

NodoArbol* buscarNodito(NodoArbol *nodo, int elemento) {
    
    while(!esNodoVacio(nodo)) {
        if(nodo->elemento == elemento) return nodo;
        if(nodo->elemento > elemento) nodo = nodo->izquierda;
        if(nodo->elemento < elemento) nodo = nodo->derecha;
    }
    return nodo;
}

void recorridoDiagonalNormalin(ArbolBinarioBusqueda &abb) {
    if(esArbolVacio(abb.arbolBinario)) return;
    
    Cola cola;
    construir(cola);
    NodoArbol *nodo = abb.arbolBinario.raiz;
    
    encolar(cola, nodo->elemento);
    while(!esColaVacia(cola)) {       
        int valor = desencolar(cola);
        nodo = buscarNodito(abb.arbolBinario.raiz, valor);
        while(!esNodoVacio(nodo)) {
            imprimirNodo(nodo);
            if(!esNodoVacio(nodo->izquierda))
                encolar(cola, nodo->izquierda->elemento);
            nodo = nodo->derecha;
        }            
    }
}


void recorridoDiagonalInversa(ArbolBinarioBusqueda &abb) {
    
    if(esArbolVacio(abb.arbolBinario)) return;
    
    Cola cola;
    construir(cola);
    Pila pila;
    construir(pila);
    NodoArbol *nodo = abb.arbolBinario.raiz;
    
    encolar(cola, nodo->elemento);
    while(!esColaVacia(cola)) {       
        int valor = desencolar(cola);
        nodo = buscarNodito(abb.arbolBinario.raiz, valor);
        while (!esNodoVacio(nodo)) {
            apilar(pila, nodo->elemento);  // Almacenar en la pila para invertir el orden
            if (!esNodoVacio(nodo->izquierda)) {
                encolar(cola, nodo->izquierda->elemento);  // Encolar el subárbol izquierdo
            }
            nodo = nodo->derecha;  // Avanzar al nodo derecho en la misma diagonal
        }
    }
    while (!esPilaVacia(pila)) {
        int valor =  desapilar(pila);
        NodoArbol *nodito = buscarNodito(abb.arbolBinario.raiz, valor);
        imprimirNodo(nodito);   
    }
}



int main(int argc, char** argv) {
    
    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    // RAIZ
    plantarArbolBinarioNew(abb.arbolBinario.raiz, nullptr, 0, 100, nullptr);
    
    // NIVEL 2
    plantarArbolBinarioNew(abb.arbolBinario.raiz->izquierda, nullptr, 0, 50, nullptr);
    plantarArbolBinarioNew(abb.arbolBinario.raiz->derecha, nullptr, 0, 150, nullptr);
    
    // NIVEL 3
    plantarArbolBinarioNew(abb.arbolBinario.raiz->izquierda->izquierda, nullptr, 0, 25, nullptr);
    plantarArbolBinarioNew(abb.arbolBinario.raiz->izquierda->derecha, nullptr, 0, 75, nullptr);
    plantarArbolBinarioNew(abb.arbolBinario.raiz->derecha->izquierda, nullptr, 1, 125, nullptr);
    plantarArbolBinarioNew(abb.arbolBinario.raiz->derecha->derecha, nullptr, 0, 175, nullptr);
    
    // NIVEL 4
    plantarArbolBinarioNew(abb.arbolBinario.raiz->izquierda->izquierda->derecha, nullptr, 0, 40, nullptr);
    plantarArbolBinarioNew(abb.arbolBinario.raiz->derecha->derecha->derecha, nullptr, 0, 200, nullptr);
    
    //recorrerEnOrden(abb.arbolBinario); cout << endl;
    recorridoDiagonalNormalin(abb); cout << endl;

    recorridoDiagonalInversa(abb);
    
    return 0;    
}

