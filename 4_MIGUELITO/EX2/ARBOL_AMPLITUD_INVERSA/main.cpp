/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo> 20175525
 * Created on December 4, 2024, 7:04 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "funcionesLista.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;



NodoArbol *buscarNodito(NodoArbol *nodo, int elemento) {
    if(esNodoVacio(nodo)) return nullptr;
    if(nodo->elemento == elemento) return nodo;
    if(nodo->elemento > elemento) nodo = buscarNodito(nodo->izquierda, elemento);
    if(nodo->elemento < elemento) nodo = buscarNodito(nodo->derecha, elemento);
    return nodo;
}

void recorridoAmplitud(ArbolBinarioBusqueda &abb) {
    Cola cola;
    construir(cola);
    Pila pila;
    construir(pila);
    NodoArbol *nodo = abb.arbolBinario.raiz;
    encolar(cola, nodo->elemento);
    
    int i = 1;
    while(!esColaVacia(cola)) {
        int tamanoNivel = longitud(cola);  // Número de nodos en el nivel actual
        cout << "Nivel: ";
        
        for (int i = 0; i < tamanoNivel; i++) {
            int valor = desencolar(cola);
            apilar(pila, valor);
            
            nodo = buscarNodito(abb.arbolBinario.raiz, valor);  // Sacamos el nodo del frente de la cola
            cout << nodo->elemento << " ";  // Imprimimos el nodo del nivel actual

            // Encolamos los hijos de ese nodo}
            if (nodo->derecha != nullptr) {
                encolar(cola, nodo->derecha->elemento);
            }
            if (nodo->izquierda != nullptr) {
                encolar(cola, nodo->izquierda->elemento);
            }
            
        }
        cout << endl; 
    }
    
    
    while(!esPilaVacia(pila)) {
        cout << desapilar(pila) << " ";
    }
    
    
}


void recorridoAmplitudInverso(ArbolBinarioBusqueda &abb) {
    Pila pila;
    construir(pila);
    Cola cola;
    construir(cola);
    
    NodoArbol *nodo = abb.arbolBinario.raiz;
    encolar(cola, nodo->elemento);
    
    int i = 1;
    while(!esColaVacia(cola)) {
        int valor = desencolar(cola);
        apilar(pila, valor);
        //cout << valor << " ";
        nodo = buscarNodito(abb.arbolBinario.raiz, valor);

        if(!esNodoVacio(nodo->derecha)) {
            encolar(cola, nodo->derecha->elemento);
        }
        
        if(!esNodoVacio(nodo->izquierda)) {
            encolar(cola, nodo->izquierda->elemento);
        }   
        
    }
    imprimir(pila);
}


int main(int argc, char** argv) {

    ArbolBinarioBusqueda abb;
    construir(abb.arbolBinario);

    insertar(abb, 15);
    insertar(abb, 9);
    insertar(abb, 20);
    insertar(abb, 6);
    insertar(abb, 14);
    insertar(abb, 17);
    insertar(abb, 64);
    insertar(abb, 13);
    insertar(abb, 26);
    insertar(abb, 72);
    
    //recorridoAmplitudInverso(abb);
    recorridoAmplitud(abb);
//    recorrerEnOrden(abb.arbolBinario); cout << endl;
//    recorrerPreOrden(abb.arbolBinario); cout << endl;
//    recorrerPostOrden(abb.arbolBinario); cout << endl;
    
    return 0;
}

