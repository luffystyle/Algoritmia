
/* 
 * File:   main.cpp
 * Author: Miguel ANgel Torre Villanueva
 * Codigo : 20175525
 * Created on 7 de diciembre de 2024, 09:52 AM
 */

#include <iostream>

#include "ArbolB.h"
#include "funcionesAB.h"

using namespace std;
// PROBLEMA 2a


struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, bool valido,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->valido = valido;
    return nuevo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento, bool valido, 
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, valido, derecha );
    raiz = nuevoNodo;
}


void recorrerPorAmplitudRecursivo(NodoArbol *nodo) {
    if(esNodoVacio(nodo)) return;
    
    recorrerPorAmplitudRecursivo(nodo->izquierda);
    recorrerPorAmplitudRecursivo(nodo->derecha);
    imprimirNodo(nodo);
}

void recorrerPorAmplitud(ArbolBinario &arbol) {
    recorrerPorAmplitudRecursivo(arbol.raiz);
}


void cargaBin(int *arr, int n, int numero){
    int i;
    for(i = 0; i<n; i++) arr[i] = 0;
    i=0;
    while(numero>0) {
        arr[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

int buscarNumeroRecursivo(int valor, int n, int numero, NodoArbol *nodo) {
    if(esNodoVacio(nodo)) return -1;
    if(nodo->valido == true) return 1; // tengo que ver que si es valido
    
    if(nodo->derecha == nullptr && nodo->izquierda == nullptr) { //hoja
        if(nodo->valido == true) return 1;
    }
    
    //ME VOY POR TODOS
    return buscarNumeroRecursivo(valor, n, numero, nodo->izquierda) + buscarNumeroRecursivo(valor, n, numero, nodo->derecha);

    
}

int buscarNumero(int *arr, int n, int numero, ArbolBinario &arbol){
    int contadorverdaderos =0;
    for(int i = n; i>= 0; i++) { //recorro de atras hacia delante ene l arreglo
        if(buscarNumeroRecursivo(i, n, numero, arbol.raiz)){
            //SE ENCONTRÓ en todos los casos
            contadorverdaderos++;
        }
    }
    if(contadorverdaderos == n)
            return 1;
    return -1;
}

int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
    plantarArbolBinarioNew(arbol.raiz, nullptr, 0, false, nullptr);
    //NIVEL 2
    plantarArbolBinarioNew(arbol.raiz->izquierda, nullptr, 1, true, nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha, nullptr, 0, true, nullptr);
    //NIVEL 3
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda, nullptr, 1, true, nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha, nullptr, 0, false, nullptr);
    //NIVEL 3
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda, nullptr, 1, false, nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda, nullptr, 1, true, nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha, nullptr, 0, false, nullptr);
    
    //NIVEL 4
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda->izquierda->derecha, nullptr, 0, true, nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha->izquierda, nullptr, 1, true, nullptr);
    
    //recorrerEnOrden(arbol);
    recorrerPorAmplitud(arbol); cout << endl;
    
    
    int numero = 14;
    int n = 4;
    int arreglo[n];
    cargaBin(arreglo, n, numero);
    
    for(int i = 0; i<n; i++) 
        cout << arreglo[i] << " "; 
    cout << endl; 
    
    if(buscarNumero(arreglo, n, numero, arbol)) {
        cout << "El numero se encontró" << endl;
    } else {
        cout << "El numero NOO se encontró" << endl;
    }
    
    return 0;
}

