
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 29, 2024, 10:39 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "funcionesLista.h"
#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"


struct NodoArbol * crearNuevoNodoNew(NodoArbol * izquierda, Elemento elemento, NodoArbol * derecha) {
    NodoArbol * nuevo = new NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    return nuevo;
}

void plantarArbolBinarioNew(NodoArbol *& raiz, NodoArbol * izquierda, Elemento elemento, NodoArbol * derecha){
    NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, derecha);
    raiz = nuevoNodo;
}

void recorrerEnOrdenRecursivoNew(NodoArbol * nodo){
    if (not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivoNew(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivoNew(nodo->derecha);
    }
}

void recorrerEnOrdenNew(const ArbolBinario & arbol){
    recorrerEnOrdenRecursivoNew(arbol.raiz);
}

NodoArbol* buscarNodito(NodoArbol *nodoArbol, Elemento elem) {
    
    if(esNodoVacio(nodoArbol)) {
        return nullptr;
    }
    
    if(nodoArbol->elemento.valor == elem.valor && nodoArbol->elemento.codigo == elem.codigo) {
        return nodoArbol;
    }
    
    
    NodoArbol* encontrado = buscarNodito(nodoArbol->izquierda, elem);
    if (encontrado != nullptr) {
        return encontrado; // Si lo encontró en el izquierdo, retornar el nodo encontrado
    }

    // Si no se encontró en el subárbol izquierdo, buscar en el derecho
    return buscarNodito(nodoArbol->derecha, elem);
}



int buscarSkyNerd(ArbolBinario & arbol) {
    
    Cola cola;
    construir(cola);
    
    
    encolar(cola, arbol.raiz->elemento);
    
    while(true) {
        Elemento elem = desencolar(cola);
        NodoArbol *nodoArbol = buscarNodito(arbol.raiz, elem);
        if(elem.codigo == 'E' && elem.valor ==200) { // padre
            
            if(!esNodoVacio(nodoArbol->izquierda)) {
                if(nodoArbol->izquierda->elemento.codigo == 'S' && nodoArbol->izquierda->elemento.valor == 200){
                    imprimirNodo(nodoArbol->izquierda);
                    return 1;
                } else {
                    encolar(cola, nodoArbol->izquierda->elemento);
                }
                
            }
            if(!esNodoVacio(nodoArbol->derecha)) {
                if(nodoArbol->derecha->elemento.codigo == 'S' && nodoArbol->derecha->elemento.valor == 200){
                    imprimirNodo(nodoArbol->derecha);
                    return 1;
                } else {
                    encolar(cola, nodoArbol->derecha->elemento);
                }
            } 
        }
        
        if(!esNodoVacio(nodoArbol->izquierda)) {
            encolar(cola, nodoArbol->izquierda->elemento);
        }
        if(!esNodoVacio(nodoArbol->izquierda)) {
            encolar(cola, nodoArbol->derecha->elemento);
        } 
    }  
}

void postOrderIratative(ArbolBinarioBusqueda &abb) {
//    if(esArbolVacio(abb.arbolBinario)) return;
//    
//    NodoArbol *nodoArbol = abb.arbolBinario.raiz;
//    
//    while(true) {
//        while(nodoArbol) {
//            
//            nodoArbol = nodoArbol->izquierda;
//        }
//        
//    }
}




int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
    // Nivel 1
    Elemento elem = {'Z', 100};
    plantarArbolBinarioNew(arbol.raiz, nullptr, elem, nullptr);
    
    // Nivel 2
    elem = {'Z', 50};
    plantarArbolBinarioNew(arbol.raiz->izquierda, nullptr, elem, nullptr);
    elem = {'E', 200};
    plantarArbolBinarioNew(arbol.raiz->derecha, nullptr, elem, nullptr);
    
    // Nivel 3
    elem = {'E', 100};
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'S', 50};
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha, nullptr, elem, nullptr);
    elem = {'S', 200};
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda, nullptr, elem, nullptr);
    elem = {'S', 150};
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha, nullptr, elem, nullptr);
    
    // Nivel 4
    elem = {'S', 50};
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'Z', 200};
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->derecha, nullptr, elem, nullptr);
    elem = {'S', 100};
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'E', 200};
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->derecha, nullptr, elem, nullptr);
    
    
    // Nivel 5
    elem = {'E', 50};
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'E', 100};
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->derecha->izquierda, nullptr, elem, nullptr);


    
    //recorrerEnOrdenNew(arbol);
//    elem = {'Z', 200};
//    NodoArbol *novita = buscarNodito(arbol.raiz, elem);
//    imprimirNodo(novita);
    //cout << buscarSkyNerd(arbol);
//    Cola c1;
//    construir(c1.lista);
//    elem = {'S', 50};   
//    encolar(c1, elem);
//    elem = {'Z', 200};
//    encolar(c1, elem);
//    elem = {'S', 100};
//    encolar(c1, elem);
//    elem = {'E', 200};
//    encolar(c1, elem);
//    elem = {'Z', 50};    
//    encolar(c1, elem);
//    elem = {'E', 200};
//    encolar(c1, elem);
//    imprime(c1.lista);
    
    return 0;
}

