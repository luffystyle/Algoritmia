
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 27, 2024, 6:06 PM
 */

#include <iostream>

using namespace std;
#include "NodoArbol.h"
#include "ArbolB.h"
#include "funcionesAB.h"
#include "Lista.h"
#include "funciones.h"

int correctorLetra(char letra, Lista &lista, char *palabra, int cantLetras) {
    for(int i = 0; i<cantLetras; i++) {
        if(palabra[i] == letra ) {
            eliminaNodo(lista, palabra[i]);
            return 1;
        }
    }
    return 0;
}

void buscarPalabraRecursivo(NodoArbol *nodoArbol, Lista &lista, char *palabra, int cantLetras, int &valido) {


    if(esNodoVacio(nodoArbol)) {
        if(esListaVacia(lista)) 
            valido = 1;
    } else{
        if(correctorLetra(nodoArbol->elemento, lista, palabra, cantLetras)) {
            buscarPalabraRecursivo(nodoArbol->izquierda, lista, palabra, cantLetras, valido);
            buscarPalabraRecursivo(nodoArbol->derecha, lista, palabra, cantLetras, valido);
        }   
    }
    
}

void llenarListaConArreglo(Lista &lista, char *palabra, int cantLetras) {
    for(int i = 0; i<cantLetras; i++) {
        insertarAlFinal(lista, palabra[i]);
    }
}


int buscarPalabra(ArbolBinario &arbol, char *palabra, int cantLetras) {
    
    int contador = 0;
    Lista lista;
    construir(lista);
    int valido = 0;
    llenarListaConArreglo(lista, palabra, cantLetras);
    buscarPalabraRecursivo(arbol.raiz, lista, palabra, cantLetras, valido);
    //imprime(lista);
    destruir(lista);
    return valido;
    
}


void imprimirMatriz(char *matriz) {
    
    for(int k = 0; k<6; k++) {
        if(matriz[k]!='-') cout << matriz[k];
        else break;
    }
    cout << "  ";
    
}



int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
    // PLANTAR LA RAIZ
    plantarArbolBinario(arbol, nullptr, 'L', nullptr);
    
    // NIVEL 1
    plantarArbolBinario(arbol.raiz->izquierda, nullptr, 'D', nullptr);
    plantarArbolBinario(arbol.raiz->derecha, nullptr, 'I', nullptr);
    
    // NIVEL 2
    plantarArbolBinario(arbol.raiz->izquierda->izquierda, nullptr,'E', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha, nullptr,'E', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda, nullptr,'C', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha, nullptr,'N', nullptr);
    
    // NIVEL 3
    plantarArbolBinario(arbol.raiz->izquierda->derecha->izquierda, nullptr,'R', nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha->derecha, nullptr,'G', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda, nullptr,'C', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->izquierda, nullptr,'A', nullptr);
   
    // NIVEL 4
    plantarArbolBinario(arbol.raiz->izquierda->derecha->derecha->izquierda, nullptr,'T', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda->izquierda, nullptr,'O', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->izquierda->izquierda, nullptr,'F', nullptr);
    plantarArbolBinario(arbol.raiz->derecha->derecha->izquierda->derecha, nullptr,'T', nullptr);
    
    
//    recorrerEnOrden(arbol);
//    cout << endl;
    
    //char palabra[] = {'F', 'I', 'N', 'A', 'L'};
    //char palabra[] = {'C', 'I', 'C', 'L', 'O'};
    //char palabra[] = {'D', 'E', 'L'};
    
    //int n = sizeof(palabra)/sizeof(palabra[0]);
    
    
    
//    int verdadero = buscarPalabra(arbol, palabra, n);    
//    cout << verdadero << endl;
    
    
    
    char matriz[][6] = {{'H', 'I', 'J', 'O', '-'}, 
                      {'F', 'I', 'N', 'A', 'L', '-'}, 
                      {'M', 'U', 'N', 'D', 'O', '-'}, 
                      {'D', 'E', 'L', '-'}, 
                      {'D', 'I', 'A', '-' }, 
                      {'C', 'I', 'C', 'L', 'O', '-'}  };
    
    for(int i = 0; i<6; i++) {
        int n = 0;
        for(int k = 0; k<6; k++) {
            if(matriz[i][k] != '-') {
                n++;
            } else {
                break;
            }   
        }
        if( buscarPalabra(arbol, matriz[i], n) ) 
            imprimirMatriz(matriz[i]);
                //cout << matriz[i] << endl;
    }    
    
    
    
    return 0;
}

