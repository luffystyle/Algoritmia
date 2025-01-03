
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 18, 2024, 4:24 PM
 */
 // REPLICA DE ALLASI
#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "NodoArbol.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"




// ESTO YA ESTÁ IMPLEMENTANDO 
//NodoArbol *crearNuevoNodoNew(NodoArbol *arbolIzquierdo, Elemento elem, NodoArbol *arbolDerecho) {
//    NodoArbol *nuevoNodo = new NodoArbol;
//    nuevoNodo->elemento = elem;
//    nuevoNodo->izquierda = arbolIzquierdo;
//    nuevoNodo->derecha = arbolDerecho;
//}
//
//void plantarArbolBinarioNew(NodoArbol *&raiz, NodoArbol *arbolIzquierda, Elemento elem, NodoArbol *arbolDerecha) {
//    NodoArbol *nuevoNodo = crearNuevoNodoNew(arbolIzquierda, elem, arbolDerecha);
//    raiz = nuevoNodo;
//}


int buscarSkyNerd(ArbolBinario &arbol) {
    Cola cola;
    construir(cola);
    encolarNew(cola, arbol.raiz);
    while(!esColaVacia(cola)) {
        NodoArbol *nodo = desencolarNew(cola);
        if(nodo->elemento.valor == 200) { //EL PADRE
            if(!esNodoVacio(nodo->izquierda)) {
                if(nodo->izquierda->elemento.tipo == 'S' && nodo->izquierda->elemento.valor == 200)
                    return 1;
                else
                    encolarNew(cola, nodo->izquierda);
            }
            if(!esNodoVacio(nodo->derecha)) {
                if(nodo->derecha->elemento.tipo == 'S' && nodo->derecha->elemento.valor == 200)
                    return 1;
                else 
                    encolarNew(cola, nodo->derecha);
            }
        }
        if(!esNodoVacio(nodo->izquierda))
            encolarNew(cola, nodo->izquierda);
        if(!esNodoVacio(nodo->derecha))
            encolarNew(cola, nodo->derecha);
    }    
    return -1;
}


int main(int argc, char** argv) {

    
       
    ArbolBinario arbolPrincipal;
    construir(arbolPrincipal);
    Elemento elem = {'Z', 100};
    plantarArbolBinario(arbolPrincipal.raiz, nullptr, elem, nullptr);
    
    //Estoy llenando por niveles
    //NIVEL 1
    elem = {'Z', 50};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda, nullptr, elem, nullptr);
    elem = {'E', 200};
    plantarArbolBinario(arbolPrincipal.raiz->derecha, nullptr, elem, nullptr);
//     
//    //NIVEL 2
    elem = {'E', 100};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'S', 50};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda->derecha, nullptr, elem, nullptr);
    elem = {'S', 200};
    plantarArbolBinario(arbolPrincipal.raiz->derecha->izquierda, nullptr, elem, nullptr);
    elem = {'S', 150};
    plantarArbolBinario(arbolPrincipal.raiz->derecha->derecha, nullptr, elem, nullptr);
    
//    //NIVEL 3
    elem = {'S', 50};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'Z', 200};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda->izquierda->derecha, nullptr, elem, nullptr);
    elem = {'S', 100};
    plantarArbolBinario(arbolPrincipal.raiz->derecha->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'E', 200};
    plantarArbolBinario(arbolPrincipal.raiz->derecha->izquierda->derecha, nullptr, elem, nullptr);

//    //NIVEL 4
    elem = {'E', 50};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda->izquierda->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'E', 100};
    plantarArbolBinario(arbolPrincipal.raiz->izquierda->izquierda->derecha->izquierda, nullptr, elem, nullptr);
    
    //recorrerEnOrden(arbolPrincipal);
    
    
    cout << buscarSkyNerd(arbolPrincipal);
    
    
    return 0;
}

