/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 2, 2024, 12:06 AM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;



NodoArbol *buscarNodoArbolito(NodoArbol *nodo, int elemento) {
    
    if(esNodoVacio(nodo)) {
        return nullptr;
    }
    if(nodo->elemento == elemento) return nodo;
    if(nodo->elemento < elemento) 
        return buscarNodoArbolito(nodo->derecha, elemento);
    if(nodo->elemento > elemento)
        return buscarNodoArbolito(nodo->izquierda, elemento);
}



void breadth_first_seach_iterative(ArbolBinario &arbol) {
    
    if(esArbolVacio(arbol)) return;
    
    
    NodoArbol *nodo = arbol.raiz;
    Cola cola;
    construir(cola);
    
    encolar(cola, nodo->elemento);
    
    while( !esColaVacia(cola) ) {
        int valor = desencolar(cola);
        cout << valor << " ";
        nodo = buscarNodoArbolito(arbol.raiz, valor);        
        
        if(!esNodoVacio(nodo->izquierda)){
            encolar(cola, nodo->izquierda->elemento); // Esto es pa recorrer nada mas que eso
            
        } 
        if(!esNodoVacio(nodo->derecha)) {
            encolar(cola, nodo->derecha->elemento); // Esto es pa recorrer nada mas que eso 
            
        }  
    }
}

int posicionCandidatoEmocion( int emociones[][3], int peso) {
    
    for(int i = 0; i<9; i++) { 
        for(int k = 0; i<3; k++) {
            if(emociones[i][k] == peso) return i;
        }
    }
    return -1;
}




int validar_combinacion(NodoArbol *nodo, int emociones[][3], int combinaciones[][3]) {
    
    ArbolBinario arbolin;
    construir(arbolin);
    
    arbolin.raiz = nodo;
    
    if(altura(arbolin) >= 2) {
        for(int i = 0; i<9; i++) { 
            for(int k = 0; k<3; k++) {
                if(emociones[i][k] == nodo->elemento) {
                    if(nodo->elemento == combinaciones[0][0] && 
                            nodo->elemento == combinaciones[1][0] && 
                            nodo->elemento == combinaciones[2][0]) {
                        
                    }
                    
                }
            }
        }
    } 
    return 0;
}




void solucion(ArbolBinario &arbol, int emociones[][3], int combinaciones[][3]) {
    
    if(esArbolVacio(arbol)) return;
    
    
    NodoArbol *nodo = arbol.raiz;
    Cola cola;
    construir(cola);
    
    encolar(cola, nodo->elemento);
    
    int cantidad_total_combinacion = 0;
    
    while( !esColaVacia(cola) ) {
        int valor = desencolar(cola);
        //cout << valor << " ";
        nodo = buscarNodoArbolito(arbol.raiz, valor);        
        
        if(validar_combinacion(nodo, emociones, combinaciones)) {
            cantidad_total_combinacion++;
        }
        
        
        if(!esNodoVacio(nodo->izquierda)){
            encolar(cola, nodo->izquierda->elemento); // Esto es pa recorrer nada mas que eso
            
        } 
        if(!esNodoVacio(nodo->derecha)) {
            encolar(cola, nodo->derecha->elemento); // Esto es pa recorrer nada mas que eso 
            
        }  
    }
    
    
    cout << "La cantidad total de combinaciones es: " << cantidad_total_combinacion << endl;
    
}


void breadth_first_search_with_levels(ArbolBinario &arbol) {
    if (esArbolVacio(arbol)) return;

    NodoArbol *nodo = arbol.raiz;
    Cola cola;
    construir(cola);

    encolar(cola, nodo->elemento);
    encolar(cola, -1); // Marcador de fin de nivel

    int nivel = 1; // Nivel inicial
    cout << "Nivel " << nivel << ": ";

    while (!esColaVacia(cola)) {
        int valor = desencolar(cola);

        if (valor == -1) { // Fin del nivel actual
            cout << endl;
            if (!esColaVacia(cola)) {
                nivel++;
                cout << "Nivel " << nivel << ": ";
                encolar(cola, -1); // Agregar marcador para el siguiente nivel
            }
        } else {
            cout << valor << " ";
            nodo = buscarNodoArbolito(arbol.raiz, valor);

            if (!esNodoVacio(nodo->izquierda)) {
                encolar(cola, nodo->izquierda->elemento);
            }
            if (!esNodoVacio(nodo->derecha)) {
                encolar(cola, nodo->derecha->elemento);
            }
        }
    }
}

int main(int argc, char** argv) {

    
    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    insertar(abb, 180);
    insertar(abb, 120);
    insertar(abb, 250);
    insertar(abb, 100);
    insertar(abb, 150);
    insertar(abb, 230);
    insertar(abb, 280);
    insertar(abb, 80);
    insertar(abb, 140);
    insertar(abb, 160);
    insertar(abb, 200);
    insertar(abb, 240);
    insertar(abb, 260);
    insertar(abb, 90);

    //recorrerEnOrden(abb.arbolBinario);
    //breadth_first_seach_iterative(abb.arbolBinario);
    
    
    
    /*
        0 -> Alegria
        1 -> Tristeza
        2 -> Temor
        3 -> Furia
        4 -> Desagrado
        5 -> Ansiedad
        6 -> Envidia
        7 -> Verguenza
        8 -> Aburrimiento
    */
    
    int emociones[][3] = {{180, 200,  0}, 
                          {140, 230, 80}, 
                          {240, 100,  0}, 
                          {280,   0,  0}, 
                          {250,   0,  0}, 
                          {260, 120,  0}, 
                          {160, 240,  0}, 
                          {120,  80,  0}, 
                          {150, 230, 90} };
    
    int combinaciones[][3] = {{5, 8, 1}, 
                              {4, 1, 2}, 
                              {2, 7, 8} };    
    
    
    solucion(abb.arbolBinario, emociones, combinaciones);
    //breadth_first_search_with_levels(abb.arbolBinario);
    
    
//    
//    NodoArbol *noditito = buscarNodoArbolito(abb.arbolBinario.raiz, 150);
//    ArbolBinario arbolin;
//    construir(arbolin);
//    arbolin.raiz = noditito;
//    cout << altura(arbolin);
    
    return 0;
}

