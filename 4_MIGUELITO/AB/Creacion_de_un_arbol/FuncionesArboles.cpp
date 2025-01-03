/* 
 * File:   FuncionesArboles.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 13, 2024, 10:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesArboles.h"
#include "ArbolBinario.h"


void construir(ArbolBinario &arbol) { // CONSTRUYENDO
    arbol.raiz = nullptr;
}

bool esNodoVacio(NodoArbol *nodo) {
    //if(nodo.izquierda == nullptr && nodo.derecha == nullptr) return true;
    //return false;
    return nodo == nullptr; // Si es cierto, devuelve true. Es decir, sí está vacío
}

bool esArbolVacio(ArbolBinario &arbol) {
    return esNodoVacio(arbol.raiz);
}

// creamos una funcion de crear nuevo arbol
NodoArbol *crearNuevoNodoArbol(NodoArbol *arbolIzquierdo, int elemento, NodoArbol *arbolDerecho) {
    NodoArbol *nuevoNodo = new NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierdo = arbolIzquierdo;
    nuevoNodo->derecho = arbolDerecho;
    return nuevoNodo;
}


void plantarArbolBinario(ArbolBinario &arbol, NodoArbol *arbolIzquierdo, int elemento, 
                            NodoArbol *arbolDerecho) {
    
    NodoArbol *nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    arbol.raiz = nuevoNodo;// crear por primera vez un arbol
}

void plantarArbolBinario(ArbolBinario &arbol, ArbolBinario arbolIzquierdo, int elemento, 
                            ArbolBinario arbolDerecho) {
    
    NodoArbol *nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;// crear por primera vez un arbol
}

int raiz(NodoArbol *nodo) { // EL ARBOL ESTÁ VACÍO
    if(esNodoVacio(nodo)) {
        cout << "No se puede obtener raíz de un árbol vacío" << endl;
        exit(1);
    }
    return nodo->elemento;
}


NodoArbol *hijoIzquierdo(ArbolBinario &arbol) {
    if(esArbolVacio(arbol)) {
        cout << "No se puede obtener raíz de un árbol vacío." << endl;
        exit(1);
    }
    return arbol.raiz->izquierdo;
}

void imprimirRaiz(ArbolBinario &arbol) {
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(NodoArbol *nodo) {
    cout << setw(5) << nodo->elemento << " ";
}

void recorrerEnOrdenRecursivo(NodoArbol *nodo) {
    if(!esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierdo);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecho);
    }
}

void recorrerEnOrden(ArbolBinario &arbol) {
    if(!esArbolVacio(arbol)) 
        recorrerEnOrdenRecursivo(arbol.raiz);
}

void recorrerEnPreOrdenRecursivo(NodoArbol *nodo) {
    if(! esNodoVacio(nodo)) {
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierdo);
        recorrerEnPreOrdenRecursivo(nodo->derecho);
    }
}

void recorrerEnPreOrden(ArbolBinario &arbol) {
    if(!esArbolVacio(arbol))
        recorrerEnPreOrdenRecursivo(arbol.raiz);
}


void recorrerPostOrdenRecursivo(NodoArbol *nodo) {
    if(!esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierdo);
        recorrerPostOrdenRecursivo(nodo->derecho);
        imprimeNodo(nodo);
    }
}
void recorrerPostOrden(ArbolBinario &arbol) {
    if(!esArbolVacio(arbol))
        recorrerPostOrdenRecursivo(arbol.raiz);
}