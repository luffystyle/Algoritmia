/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 30 de noviembre de 2024, 09:06 AM
 */

#include <iostream>

using namespace std;
#include "ArbolB.h"
#include "funcionesAB.h"
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Pila.h"
#include "funcionesPila.h"

struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, int cantidad,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->cantidad = cantidad;
    return nuevo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento, int cantidad,
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, cantidad, derecha);
    raiz = nuevoNodo;
}

void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento, int cantidad){
    if(esNodoVacio(raiz))
        plantarArbolBinarioNew(raiz, nullptr, elemento, cantidad, nullptr);
    else
        if(raiz->elemento > elemento)
            insertarRecursivoNew(raiz->izquierda, elemento, cantidad);
        else
            if(raiz->elemento < elemento)
                insertarRecursivoNew(raiz->derecha, elemento, cantidad);
            else
                raiz->cantidad += cantidad;
}

void ingresa_lote(struct ArbolBinarioBusqueda & arbol, int anho, int cantidad) {
    insertarRecursivoNew(arbol.arbolBinario.raiz, anho, cantidad);
    
}

NodoArbol *buscarNodito(NodoArbol *nodo, int elemento){
    if(nodo == nullptr) return nullptr;
    if( nodo->elemento == elemento) return nodo;
    if(nodo->elemento < elemento){
        nodo = buscarNodito(nodo->derecha, elemento);
    }
    if(nodo->elemento > elemento){
        nodo = buscarNodito(nodo->izquierda, elemento);
    }
    return nodo;
}





void recorrerIterativo(ArbolBinarioBusqueda & arbol) {
    Pila pila;
    construir(pila);
    int alto;
    NodoArbol *nodo = arbol.arbolBinario.raiz;
    
    while(nodo != nullptr || !esPilaVacia(pila)) {
        
        while(nodo){
            apilar(pila, nodo->elemento, nodo->cantidad);
            nodo = nodo->derecha;
        }
        
        int alto = cima(pila);
        nodo = buscarNodito(arbol.arbolBinario.raiz, alto); // LOS AÑOS NO SE REPITEN, solo se acumulan
        desapilar(pila);
        imprimirNodo(nodo);
        
        nodo = nodo->izquierda;
    }
    
}


int main(int argc, char** argv) {

    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    
    ingresa_lote(abb, 2023, 200);
    ingresa_lote(abb, 2022, 50);
    ingresa_lote(abb, 2020, 75);
    ingresa_lote(abb, 2019, 125);
    ingresa_lote(abb, 2018, 100);
    ingresa_lote(abb, 2017, 25);
    ingresa_lote(abb, 2011, 300);
    ingresa_lote(abb, 2010, 175);
    
    // EJEMPLO DE ACUMULACION DE CANTIDAD
    ingresa_lote(abb, 2010, 25);
    //recorrerEnOrden(abb.arbolBinario);
    
    recorrerIterativo(abb);
    
    return 0;
}

