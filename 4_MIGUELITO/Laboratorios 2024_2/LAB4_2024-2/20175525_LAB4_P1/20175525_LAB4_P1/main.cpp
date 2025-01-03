
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 30 de noviembre de 2024, 08:08 AM
 */

#include <iostream>

#include "ArbolB.h"
#include "funcionesAB.h"
#include "Lista.h"
#include "funciones.h"

using namespace std;

struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, char elemento,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    return nuevo;
}

void plantarArbolBinarioNew(struct ArbolBinario & arbol, struct NodoArbol * izquierda, 
                         int elemento, struct NodoArbol * derecha) {
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, derecha);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, char elemento, 
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, derecha);
    raiz = nuevoNodo;
}

void pasarLaMatrizAlaLista(char *matriz, int n, Lista &lista){
    for(int i = 0; i<n ; i++) {
        insertarAlFinal(lista, matriz[i]);
    }
}

int correctoLetra(Lista &lista, int n, char *matriz, char letrita) {
    for(int i = 0; i<n; i++) {
        if(matriz[i] == letrita){
            eliminaNodo(lista, letrita);
            return 1;
        }
    }
    return 0;
}

void verificarPalabraRecursivo(NodoArbol *nodoArbol, char *matriz, int n, Lista &lista, int &valido) {
    
    if(nodoArbol == nullptr){
        if(esListaVacia(lista)){
            valido = 1;
        }
    } else {
        if(correctoLetra(lista, n, matriz,nodoArbol->elemento)) {
            verificarPalabraRecursivo(nodoArbol->izquierda, matriz, n, lista, valido);
            verificarPalabraRecursivo(nodoArbol->derecha, matriz, n, lista, valido);
        }
    }
}

int verificarPalabra(ArbolBinario &arbol, char *matriz, int n){
    Lista lista;
    construir(lista);
    pasarLaMatrizAlaLista(matriz, n, lista);
    //imprime(lista);
    
    int valido = 0;
    NodoArbol *nodoArbol = arbol.raiz;
    
    verificarPalabraRecursivo(nodoArbol, matriz, n, lista, valido);
    
    return valido;
}

void imprimirMatriz(char *matriz, int n) {
    for(int i = 0; i<n; i++) {
        cout << matriz[i];
    }
    cout << endl;
}

 void imprimeNewRecursivo(NodoArbol *raiz, NodoArbol *nodo, Lista &lista) {
     
    if(nodo == nullptr) return;
    if(nodo->izquierda == nullptr && nodo->derecha == nullptr) { // CUANDO ES HOJA IMPRIMO LA LISTA
        
        insertarAlFinal(lista, nodo->elemento);
        nodo = raiz;
        imprime(lista);
        destruir(lista);
        Lista lista;
        construir(lista);

        nodo = nodo->derecha; // pa que se vaya a la derecha
        raiz = raiz->derecha;
        return;
    } 
    insertarAlFinal(lista, nodo->elemento);
    if(nodo->izquierda != nullptr) {
        imprimeNewRecursivo(raiz, nodo->izquierda, lista);
    }

    if(nodo->derecha != nullptr) {
        imprimeNewRecursivo(raiz, nodo->derecha, lista);
    }

 }

void imprimeNew(ArbolBinario &arbol) {
    NodoArbol *nodo = arbol.raiz;
    Lista lista;
    construir(lista);
    imprimeNewRecursivo(nodo, nodo, lista);
    
}


int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
    // NIVEL 1
    plantarArbolBinarioNew(arbol, nullptr, 'B', nullptr);
    // NIVEL 2
    plantarArbolBinarioNew(arbol.raiz->izquierda, nullptr, 'I', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha, nullptr, 'U', nullptr);
    
    // NIVEl 3
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda, nullptr, 'E', nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha, nullptr, 'L', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda, nullptr, 'E', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha, nullptr, 'R', nullptr);
    
    // NIVEL 4
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda, nullptr, 'N', nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda, nullptr, 'B', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda, nullptr, 'N', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->derecha, nullptr, 'R', nullptr);
    
    // NIVEL 5
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda->izquierda, nullptr, 'A', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->izquierda, nullptr, 'A', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->derecha, nullptr, 'O', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->derecha->izquierda, nullptr, 'A', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->derecha->derecha, nullptr, 'O', nullptr);
    
    //NIVEL 6
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda->izquierda->izquierda, nullptr, 'O', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->derecha->derecha, nullptr, 'S', nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->derecha->derecha->derecha, nullptr, 'S', nullptr);
    
//    recorrerEnOrden(arbol);
    
    
    
//    char matriz[][7] = {{'B', 'I', 'E', 'N', '-'}, 
//                       {'B', 'I', 'L', 'B', 'A', 'O', '-'}, 
//                       {'B', 'U', 'E', 'N', 'A', 'S', '-'}, 
//                       {'B', 'U', 'E', 'N', 'O', '-'}, 
//                       {'B', 'U', 'R', 'R', 'A', '-'}, 
//                       {'B', 'U', 'R', 'R', 'O', 'Z', '-'}};
    
    
    
//    for(int i = 0; i<6; i++) {
//        int n = 0;
//        for(int k = 0; k<7; k++) {
//            if(matriz[i][k] == '-') break;
//            n++;
//            
//        }
//        if(verificarPalabra(arbol, matriz[i], n)) {
//            imprimirMatriz( matriz[i], n);
//        }
//    }
    imprimeNew(arbol);
    
    return 0;
}


