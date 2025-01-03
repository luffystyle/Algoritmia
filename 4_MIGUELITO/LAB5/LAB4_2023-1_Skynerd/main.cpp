/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 12, 2024, 12:32 PM
 */

#include <iostream>

#include "NodoArbol.h"
#include "ArbolB.h"
#include "funcionesAB.h"
#include "funcionesCola.h"
#include "Cola.h"
#include "funcionesLista.h"
using namespace std;


struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, char letra,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->letra = letra;
    return nuevo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento, char letra,
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, letra, derecha);
    raiz = nuevoNodo;
}


NodoArbol* buscarNoditoRecursivo(NodoArbol *nodo, int elemento, char letra) {
    if(esNodoVacio(nodo)) 
        return nullptr;
    
    if(nodo->elemento == elemento && nodo->letra == letra) 
        return nodo;

    NodoArbol* encontrado = buscarNoditoRecursivo(nodo->izquierda, elemento, letra);
    if (encontrado != nullptr) 
        return encontrado; // Si encontramos el nodo, lo devolvemos inmediatamente

    // Buscar en el subárbol derecho
    return buscarNoditoRecursivo(nodo->derecha, elemento, letra);
}


NodoArbol* buscarNodito(ArbolBinario &arbol, int elemento, char letra) {
    
    NodoArbol *nofififto = buscarNoditoRecursivo(arbol.raiz, elemento, letra);
    return nofififto;
}

struct Nodo * crearNodoColaNew(NodoArbol *nodoArbol, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodoArbol;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}



void insertarNew(struct Lista & lista, NodoArbol *nodo ) {
    struct Nodo * ultimoNodo = lista.cola;
    struct Nodo * nuevoNodo = crearNodoColaNew(nodo, nullptr);

    if (ultimoNodo==nullptr) {
        lista.cabeza = nuevoNodo; 
        lista.cola = nuevoNodo;
    } else {
        lista.cola->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;
    }
    lista.longitud++;
}

void encolarNew(struct Cola & cola,  NodoArbol *nodo){
    insertarNew(cola.lista, nodo);
}


NodoArbol *desencolaNew(Cola cola) {
    if(esColaVacia(cola)) {
        return nullptr;
    } else {
        
        NodoArbol *nodo = cola.lista.cabeza->nodo;
        eliminaCabeza(cola.lista);
        if(esColaVacia(cola))   
            cola.lista.cola = nullptr;
        
        return nodo;
    }
}


int buscarSkynerd(ArbolBinario &arbol) {
    
    if(esArbolVacio(arbol)) return -1;
    Cola cola;
    construir(cola);
    
    NodoArbol *nodo = arbol.raiz;
    
    encolarNew(cola, nodo);
    while(!esColaVacia(cola)) {
        nodo = desencolaNew(cola);
        
        if(nodo->elemento == 200) {
            if(!esNodoVacio(nodo->izquierda)) {
                if(nodo->izquierda->letra == 'S' && nodo->izquierda->elemento == 200){
                    imprimirNodo(nodo);
                    return 1;
                } else
                    encolarNew(cola, nodo->izquierda);
            }
            if(!esNodoVacio(nodo->derecha)) {
                if(nodo->izquierda->letra == 'S' && nodo->izquierda->elemento == 200){
                    imprimirNodo(nodo);
                    return 1;
                } else
                    encolarNew(cola, nodo->derecha);
            }
                
        }
        
        if(!esNodoVacio(nodo->izquierda)) 
            encolarNew(cola, nodo->izquierda);
        if(!esNodoVacio(nodo->derecha)) 
            encolarNew(cola, nodo->derecha);
    }
    
    
}






int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
    // RAIZ
    plantarArbolBinarioNew(arbol.raiz, nullptr, 100, 'Z', nullptr);
    // NIVEL 2
    plantarArbolBinarioNew(arbol.raiz->izquierda, nullptr, 50, 'Z', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha, nullptr, 200, 'E', nullptr);
    // NIVEL 3
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda, nullptr, 100, 'E', nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha, nullptr, 50, 'S', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda, nullptr, 200, 'S', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha, nullptr, 150, 'S', nullptr);
    // NIVEL 4
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda, nullptr, 50, 'S', nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->derecha, nullptr, 200, 'Z', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda, nullptr, 100, 'S', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->derecha, nullptr, 200, 'E', nullptr);
    // NIVEL 5
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda->izquierda, nullptr, 50, 'E', nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->derecha->izquierda, nullptr, 100, 'E', nullptr);
    
    
//    recorrerEnOrden(arbol);
    
    cout << buscarSkynerd(arbol);
    
    return 0;
}

