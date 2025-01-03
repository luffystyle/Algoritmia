
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 29, 2024, 10:41 AM
 */

#include <iostream>
#include <cstring>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
using namespace std;


//NodoArbol* buscarNodo(NodoArbol *nodo, Elemento elemento) {
//    if(esNodoVacio(nodo)) {
//        return nullptr;
//    } 
//    if(nodo->elemento.cantidad == elemento) return nodo;
//    else {
//        if(nodo->elemento.cantidad < elemento.cantidad) {
//            nodo = buscarNodo(nodo->derecha, elemento);
//        } 
//        if( nodo->elemento.cantidad > elemento.cantidad) {
//            nodo = buscarNodo(nodo->izquierda, elemento.cantidad);
//        }
//        return buscarNodo(nodo, elemento.cantidad);
//    }
//}


//void postOrderIterative(ArbolBinarioBusqueda arbol) {
//    Pila pila;
//    int valor = 0;
//    int alto;
//    construir(pila);
//    NodoArbol *nodo;
//    
//    nodo = arbol.arbolBinario.raiz;
//    if(esArbolVacio(arbol.arbolBinario)) {
//        return;
//    }
//    
//    while(true) {
//        while(nodo) {
//            apilar(pila, nodo->elemento);
//            nodo = nodo->izquierda;
//        }
//        
//        alto = cima(pila); // Esto es para solo obtener el valor y luego buscarlo
//        // ME POSICIONO EN LA UBICACION DEL ULTIMO NODO
//        // Por eso, lo busco
//        nodo = buscarNodo(arbol.arbolBinario.raiz, alto);
//        if(nodo->derecha != nullptr && nodo->derecha->elemento != valor) { // HAY MAS POR DESCUBRIR
//            nodo = nodo->derecha;
//        } else { // YA NO HAY MAS, no tiene hijitos e imprimo
//            valor = desapilar(pila);
//            cout << valor << " ";
//            nodo = nullptr; // PARA NO ENTRAR AL WHILE DE LA IZQUIERDA AL REGRESAR            
//        }        
//        if(esPilaVacia(pila)) break;
//    }   
//    
//}


//void InOrderIterative(ArbolBinarioBusqueda arbol) {
//    Pila pila;
//    int valor = 0;
//    int alto;
//    construir(pila);
//    NodoArbol *nodo;
//    
//    nodo = arbol.arbolBinario.raiz;
//    if(esArbolVacio(arbol.arbolBinario)) {
//        return;
//    } 
//    
//    while(true) {
//        while(nodo) {
//            apilar(pila, nodo->elemento);
//            nodo = nodo->izquierda;
//        }
//        int alto = cima(pila);
//        nodo = buscarNodo(arbol.arbolBinario.raiz, alto);
//        desapilar(pila);
//        cout << alto << " ";
//        nodo = nodo->derecha;
//        if(esPilaVacia(pila) && nodo == nullptr) break;
//    }
//    
//}






NodoArbol *buscarcitoRecursivo(NodoArbol *nodo, int valor) {
    
    if(esNodoVacio(nodo)) return nullptr;
    if(nodo->elemento.cantidad == valor) return nodo;
    if(nodo->elemento.cantidad < valor) nodo = buscarcitoRecursivo(nodo->derecha, valor);
    if(nodo->elemento.cantidad > valor) nodo = buscarcitoRecursivo(nodo->izquierda, valor);
    return nodo;
}



bool buscarcito(ArbolBinario &arbolito, int valor) {
    
    if(buscarcitoRecursivo(arbolito.raiz, valor)) return true;
    return false;
    
}




void postOrder(ArbolBinario &abb) {
	
    
    Pila pila;
    construir(pila.lista);
    NodoArbol *nodoArbol = abb.raiz;
    Elemento alto, valor;
    valor.cantidad = 0;
    strcpy(valor.codigo, "GAAAAAAA");
    
    if(esArbolVacio(abb)) return;

    while(true){
        while(nodoArbol) {
            apilar(pila, nodoArbol->elemento);
            nodoArbol = nodoArbol->izquierda;
        }
        
        alto = cima(pila);
        
        nodoArbol = buscarcitoRecursivo(abb.raiz, alto.cantidad);
        
        if( nodoArbol->derecha != nullptr && nodoArbol->derecha->elemento.cantidad != valor.cantidad ) {
            nodoArbol = nodoArbol->derecha;
        } else {
            valor = desapilar(pila);
            imprimirNodo(nodoArbol);
            nodoArbol = nullptr;
        }
        if(esPilaVacia(pila)) break;
    }
}




void InOrderIrative(ArbolBinario &abb) {
    Pila pila;
    construir(pila.lista);
    NodoArbol *nodoArbol = abb.raiz;
    Elemento alto, valor;
    valor.cantidad = 0;
    strcpy(valor.codigo, "GAAAAAAA");
    
    if(esArbolVacio(abb)) return;

    while(nodoArbol || !esPilaVacia(pila)){
        while(nodoArbol) {
            apilar(pila, nodoArbol->elemento);
            nodoArbol = nodoArbol->izquierda;
        }
        
        alto = cima(pila);        
        nodoArbol = buscarcitoRecursivo(abb.raiz, alto.cantidad);
        desapilar(pila);     
        imprimirNodo(nodoArbol);
        nodoArbol = nodoArbol->derecha;
    }
}



void preOrderIterative(ArbolBinario &abb) {
    Pila pila;
    construir(pila.lista);
    NodoArbol *nodoArbol = abb.raiz;
    
    if (esArbolVacio(abb)) return;
    int valor = 0;
    apilar(pila, nodoArbol->elemento);

    while (!esPilaVacia(pila)) {
        valor = desapilar(pila);
        nodoArbol = buscarcitoRecursivo(abb.raiz, valor);

        imprimirNodo(nodoArbol);

        if(nodoArbol->derecha) {
            apilar(pila, nodoArbol->derecha->elemento);
        }
        if(nodoArbol->izquierda) {
            apilar(pila, nodoArbol->izquierda->elemento);
        }
    }
}



void breadthFirstSearch(ArbolBinario &abb) {
    Cola cola;
    construir(cola.lista);
    NodoArbol *nodoArbol = abb.raiz;

    if (esArbolVacio(abb)) return;

    encolar(cola, nodoArbol->elemento);

    while (!esColaVacia(cola)) {
        Elemento actual = desencolar(cola);
        nodoArbol = buscarcitoRecursivo(abb.raiz, actual.cantidad);

        imprimirNodo(nodoArbol);

        // Encolar primero el hijo izquierdo, luego el derecho
        if (nodoArbol->izquierda) {
            encolar(cola, nodoArbol->izquierda->elemento);
        }
        if (nodoArbol->derecha) {
            encolar(cola, nodoArbol->derecha->elemento);
        }
    }
}


int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda abb;
    construir(abb.arbolBinario);
    Elemento elem ;
    
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 15;
//    elem.cantidad = 15;
//    strcpy(elem.codigo, "20175525");
    plantarArbolBinario(abb.arbolBinario, nullptr, elem, nullptr);
    
    // NIVEL 1
    strcpy(elem.codigo, "20172147");
    elem.cantidad = 9;
    plantarArbolBinario(abb.arbolBinario.raiz->izquierda, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 20;
    plantarArbolBinario(abb.arbolBinario.raiz->derecha, nullptr, elem, nullptr);
//    
//    // NIVEL 2
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 6;
    plantarArbolBinario(abb.arbolBinario.raiz->izquierda->izquierda, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 14;
    plantarArbolBinario(abb.arbolBinario.raiz->izquierda->derecha, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20172147");
    elem.cantidad = 17;
    plantarArbolBinario(abb.arbolBinario.raiz->derecha->izquierda, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 64;
    plantarArbolBinario(abb.arbolBinario.raiz->derecha->derecha, nullptr, elem, nullptr);
//    
//    
//    // NIVEL 3
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 7;
    plantarArbolBinario(abb.arbolBinario.raiz->izquierda->izquierda->derecha, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20175525");
    elem.cantidad = 13;
    plantarArbolBinario(abb.arbolBinario.raiz->izquierda->derecha->izquierda, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20172147");
    elem.cantidad = 26;
    plantarArbolBinario(abb.arbolBinario.raiz->derecha->derecha->izquierda, nullptr, elem, nullptr);
    strcpy(elem.codigo, "20172147");
    elem.cantidad = 72;
    plantarArbolBinario(abb.arbolBinario.raiz->derecha->derecha->derecha, nullptr, elem, nullptr);
    
    //recorrerEnOrden(abb.arbolBinario);
//    postOrder(abb.arbolBinario);
//    cout << endl << endl;
//    InOrderIrative(abb.arbolBinario);
    preOrderIterative(abb.arbolBinario);
    cout << endl << endl;
    //breadthFirstSearch(abb.arbolBinario);
//    recorrerPostOrden(abb.arbolBinario);
//    cout << endl << endl;
//    postOrderIterative(abb);
//    cout << endl << endl;
//    recorrerPostOrden(abb.arbolBinario);
    //InOrderIterative(abb);
    
    
//    ArbolBinario arbolito, arb, arboligrande;
//    construir(arbolito);
//    construir(arb);
//    construir(arboligrande);
//    plantarArbolBinario(arbolito, arb, 8, arb);
//    plantarArbolBinario(arboligrande, arb, 7, arbolito);
    
    
    


    
    
    
    return 0;
}

