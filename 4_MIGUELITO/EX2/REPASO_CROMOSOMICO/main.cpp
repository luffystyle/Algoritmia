/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 6, 2024, 11:12 AM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "Pila.h"
#include "Cola.h"

using namespace std;


struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, int binario, 
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->binario = binario;
    return nuevo;
}


void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento, int binario,
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, binario, derecha);
    raiz = nuevoNodo;
}

void insertarRecursivoNew(NodoArbol *&nodo, int valor, int binario) {
    if(esNodoVacio(nodo)) {
        plantarArbolBinarioNew(nodo, nullptr, valor, binario, nullptr);
        return ;
    }

    insertarRecursivoNew(nodo->izquierda, valor, 0);
    insertarRecursivoNew(nodo->derecha, valor, 1);

}

void insertarValor(NodoArbol *nodo, int valor) {
    
    insertarRecursivoNew(nodo, valor, 0);
}
    
void construirArbol(ArbolBinario &arbol, int n, int *arr) {
    
    plantarArbolBinarioNew(arbol.raiz, nullptr, 0, 0, nullptr);

    for(int i = 0; i<n; i++) {
        insertarValor(arbol.raiz, arr[i]); // por cada nivel
    }   
}



int recorrerHoja(NodoArbol *nodo, int pesoMaximo, int pesoParcial) {
    if(esNodoVacio(nodo)) return 0;
    
    pesoParcial += nodo->elemento*nodo->binario;
    if(nodo->izquierda == nullptr && nodo->derecha == nullptr){
        if(pesoParcial == pesoMaximo) {
            return 1;
        } 
        //imprimirNodo(nodo);
        
    }
    return recorrerHoja(nodo->izquierda, pesoMaximo,pesoParcial) 
            + recorrerHoja(nodo->derecha, pesoMaximo,pesoParcial);
}


void hallarCombinaciones(ArbolBinario &arbol, int n, int *arr) {
    
    int pesoMaximo = 60;
    int pesoParcial = 0;
    
    cout << recorrerHoja(arbol.raiz, pesoMaximo, pesoParcial);
    
    
    
    
}

void cargaBin(int *arreglito, int n, int numero) {
    int i = 0;
    //for(i = 0; i<n; i++) arreglito[i] = 0;
    
    while(numero>0) {
        arreglito[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

NodoArbol* buscarNodoIterativo(NodoArbol *nodo, int elemento) {

    
    while(!esNodoVacio(nodo)) {
        if(nodo->elemento == elemento) return nodo;
        if(nodo->elemento > elemento) nodo = nodo->izquierda;
        if(nodo->elemento < elemento) nodo = nodo->derecha;
        
    }
    return nodo;
    //return nullptr;

}



//void recorridoPosOrdeniterativo(ArbolBinarioBusqueda &abb) {
//    Pila pila;
//    construir(pila);
//    NodoArbol *nodo = abb.arbolBinario.raiz;
//    
//    
//    
//    int valor = 0, alto;
//    
//    while(true) {
//        while(nodo) {
//            apilar(pila, nodo->elemento);
//            nodo = nodo->izquierda;
//        }
//        alto = cima(pila);
//        nodo = buscarNodoIterativo(abb.arbolBinario.raiz, alto);
//        
//        if(nodo->derecha != nullptr && nodo->derecha->elemento != valor) {
//            nodo = nodo->derecha;
//        } else {
//            valor = desapilar(pila);
//            cout << valor << " ";
//            nodo = nullptr;
//        }
//        
//        if(esPilaVacia(pila)) break;
//    }
//    
//}
//
//void recorridoInOrderIterativo(ArbolBinarioBusqueda &abb){
//    Pila pila;
//    construir(pila);
//    NodoArbol *nodo = abb.arbolBinario.raiz;
//    int valor = 0, alto;
//    
//    while( !esPilaVacia(pila) || !esNodoVacio(nodo)) {
//        while(nodo) {
//            apilar(pila, nodo->elemento);
//            cout << nodo->elemento << " ";
//            nodo = nodo->izquierda;
//        }
//        
//        
//        int alto = cima(pila);
//        nodo = buscarNodoIterativo(abb.arbolBinario.raiz, alto);
//        desapilar(pila);
//        //cout << nodo->elemento << " " ;
//        nodo = nodo->derecha;
//    }
//    
//}


void recorridoPosOrdeniterativo(ArbolBinarioBusqueda &abb) {
    Pila pila;
    construir(pila);
    NodoArbol *nodo = abb.arbolBinario.raiz;
    int alto, valor = 0;
    
    
    while(true) {
        while(nodo) {
            apilar(pila, nodo->elemento);
            nodo = nodo->izquierda;
        }
        alto = cima(pila);
        nodo = buscarNodoIterativo(abb.arbolBinario.raiz, alto);
        
        if(nodo->derecha != nullptr && nodo->derecha->elemento != valor)
            nodo = nodo->derecha;
        else {
            valor = desapilar(pila);
            cout << valor << " ";
            nodo = nullptr;
        }        
        if(esPilaVacia(pila)) break;
    }
    
}

void recorridoInOrderIterativo(ArbolBinarioBusqueda &abb){
    
    Pila pila;
    construir(pila);
    NodoArbol *nodo = abb.arbolBinario.raiz;
    int alto, valor = 0;
    
    
    while(!esPilaVacia(pila) || !esNodoVacio(nodo)) {
        while(nodo) {
            apilar(pila, nodo->elemento);
            //cout << nodo->elemento << " ";
            nodo = nodo->izquierda;
        }
        alto = cima(pila);
        nodo = buscarNodoIterativo(abb.arbolBinario.raiz, alto);
        
        valor = desapilar(pila);
        //cout << valor << " ";
        nodo = nodo->derecha;
    }
}


void recorridoAmpli(ArbolBinarioBusqueda &abb) {
    Cola cola;
    construir(cola);
    Pila pila;
    construir(pila);
    
    NodoArbol *nodo = abb.arbolBinario.raiz;
    encolar(cola, nodo->elemento);
    int valor;
    
    
    while(!esColaVacia(cola)) {
        valor = desencolar(cola);
        apilar(pila, valor);
        //cout << valor << " ";
        nodo = buscarNodoIterativo(abb.arbolBinario.raiz, valor);
        
        if(!esNodoVacio(nodo->derecha)) 
            encolar(cola, nodo->derecha->elemento);
        if(!esNodoVacio(nodo->izquierda)) 
            encolar(cola, nodo->izquierda->elemento);
    }
    
    
    while(!esPilaVacia(pila)) cout << desapilar(pila) << " ";
}



int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
     int arr[] = {10,50};
    //int arr[] = {14, 16, 19};
    //int arr[] = {10,50,20,30,40};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    construirArbol(arbol, n, arr);
    
    int i = 0;
    //recorrerEnOrden(arbol, i); cout << endl;
    //cout << i << endl;
    
//    hallarCombinaciones(arbol, n, arr);
    
    int m = 6;
    int arreglito[m]{};
    int numero = 3;
    cargaBin(arreglito, 4, numero);
//    for(int i = 0; i<m; i++) cout << arreglito[i] << " ";
//    cout << endl;
    
    
    //CREANDO UN ABB
    ArbolBinarioBusqueda abb;
    construir(abb);
    
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
    
    
    //recorrerEnOrden(abb.arbolBinario, i);
    
    recorridoPosOrdeniterativo(abb); cout << endl;
    recorridoInOrderIterativo(abb); cout << endl;
    recorridoAmpli(abb); cout << endl;
    //recorrerPostOrden(abb.arbolBinario); cout << endl;
//    recorrerEnOrden(abb.arbolBinario, i); cout << endl;
//    recorridoInOrderIterativo(abb); cout << endl;
//    recorrerPreOrden(abb.arbolBinario);
    
    
    return 0;
}

