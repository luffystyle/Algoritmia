
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 13, 2024, 9:34 PM
 */

#include <iostream>
#include <iomanip> // Para setw
#include <queue> 
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

using namespace std;
#define N 10


void recorrerYLlenaArreglo(NodoArbol *nodo, int *arr, int &n){ 
    
    if(esNodoVacio(nodo)) return;
    
    recorrerYLlenaArreglo(nodo->izquierda, arr, n);
    arr[n] = nodo->elemento;
    n++;
    recorrerYLlenaArreglo(nodo->derecha, arr, n);
}

NodoArbol *construirArbolBalanceado(int *arr, int ini, int fin) {
    if(ini>fin) return nullptr;
    
    int med = (ini+fin)/2;
    NodoArbol *nodel = crearNuevoNodo(nullptr, arr[med], nullptr);
    
    nodel->izquierda = construirArbolBalanceado(arr, ini, med-1);
    nodel->derecha = construirArbolBalanceado(arr, med + 1, fin);
    
    return nodel;
}


void equilibrarArbol(ArbolBinarioBusqueda &abb) {
    
    int n = 0;
    int cant = numeroNodos(abb.arbolBinario);
    int arr[cant];
    recorrerYLlenaArreglo(abb.arbolBinario.raiz, arr, n);
    //for(int i = 0; i<cant; i++) cout << arr[i] << " ";
    destruirArbolBinario(abb.arbolBinario);
    abb.arbolBinario.raiz = construirArbolBalanceado(arr, 0, cant-1);
}



//void recorrrerEnAmplitudRecursivo(NodoArbol*raiz){
//    if(not esNodoVacio(raiz)){ //la impresion de los hijos se hace recursivo
//        if(not esNodoVacio(raiz->izquierda)){
//            imprimirNodo(raiz->izquierda);
//        }
//        if(not esNodoVacio(raiz->derecha)){
//            imprimirNodo(raiz->derecha);
//        }
//        recorrrerEnAmplitudRecursivo(raiz->izquierda);
//        recorrrerEnAmplitudRecursivo(raiz->derecha);
//    }
//}
//
//void recorrrerEnAmplitud(const ArbolBinario &arbol){
//    if(not esArbolVacio(arbol)){
//        imprimirNodo(arbol.raiz);
//        recorrrerEnAmplitudRecursivo(arbol.raiz);
//    }
//}


void imprimirPorNiveles(NodoArbol *raiz) {
    if (raiz == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    // Cola para realizar el recorrido por niveles
    queue<NodoArbol *> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        int nivelTam = cola.size(); // Número de nodos en el nivel actual

        // Imprimir todos los nodos de este nivel
        for (int i = 0; i < nivelTam; i++) {
            NodoArbol *nodo = cola.front();
            cola.pop();

            // Imprimir el nodo actual
            if (nodo != nullptr) {
                cout << nodo->elemento << " ";

                // Encolar los hijos del nodo actual
                if (nodo->izquierda)
                    cola.push(nodo->izquierda);
                if (nodo->derecha)
                    cola.push(nodo->derecha);
            }
        }
        cout << endl; // Salto de línea al finalizar el nivel
    }
}

void imprimirNivel(struct NodoArbol *nodo, int nivel) {
    if (esNodoVacio(nodo)) return;

    if (nivel == 1) {
        imprimirNodo(nodo); // Imprime el nodo si está en el nivel actual
    } else if (nivel > 1) {
        imprimirNivel(nodo->izquierda, nivel - 1); // Recurre al subárbol izquierdo
        imprimirNivel(nodo->derecha, nivel - 1);  // Recurre al subárbol derecho
    }
}

void recorrerPorAmplitud(const struct ArbolBinario &arbol) {
    int h = altura(arbol); // Calculamos la altura del árbol
    for (int nivel = 1; nivel <= h + 1; ++nivel) {
        cout << "Nivel " << nivel << ":";
        imprimirNivel(arbol.raiz, nivel);
        cout << endl;
    }
}


int main(int argc, char** argv) {

    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    insertar(abb, 100);
    insertar(abb,  50);
    insertar(abb, 150);
    insertar(abb,  25);
    insertar(abb, 75);
    insertar(abb, 125);
    insertar(abb, 175);
    insertar(abb, 40);
    insertar(abb, 200);
    insertar(abb, 300);
    
    
    
//    insertar(abb,  50);
//    insertar(abb,  25);
//    insertar(abb, 75);
//    insertar(abb, 300);
//    insertar(abb, 125);
//    insertar(abb, 175);
//    insertar(abb, 150);
//    insertar(abb, 40);
//    insertar(abb, 200);
//    insertar(abb, 100);
    
    
    //recorrerEnOrden(abb.arbolBinario);cout << endl;
    //imprimirPorNiveles(abb.arbolBinario.raiz); cout << endl;
    recorrerPorAmplitud(abb.arbolBinario); cout << endl << endl;
    equilibrarArbol(abb);
    //recorrerPreOrden(abb.arbolBinario);
    recorrerPreOrden(abb.arbolBinario); cout << endl << endl;
    recorrerPorAmplitud(abb.arbolBinario); cout << endl << endl;
    //imprimirPorNiveles(abb.arbolBinario.raiz);
    

    
    
    return 0;
}

