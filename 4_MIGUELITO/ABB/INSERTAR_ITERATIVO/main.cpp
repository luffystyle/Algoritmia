
/* 
 * File:   main.cpp
 * Author: Miguel ANgel Torres Villanueva
 * Codigo: 20175525
 * Created on November 29, 2024, 8:51 PM
 */

#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"


void insertarIterativamenteUnAbb(ArbolBinarioBusqueda &abb, int dato) {
    
    NodoArbol *nodoArbol = abb.arbolBinario.raiz;
    NodoArbol *padre = nullptr;
    
    if(esNodoVacio(nodoArbol)) {
        plantarArbolBinario(abb.arbolBinario.raiz, nullptr, dato, nullptr);
        return;
    }
    
    while(true) {
        if(nodoArbol == nullptr) break; 
        // SOlamente es pa recorrer y posicionarse
        padre = nodoArbol;
        if(nodoArbol->elemento < dato) {
            nodoArbol = nodoArbol->derecha;
        } else if(nodoArbol->elemento > dato) {
            nodoArbol = nodoArbol->izquierda;
        }
        else if(nodoArbol->elemento == dato)  {
            cout << "Ya se enccuentra" << endl;
            return ;            
        }
    }
    
    if(padre->elemento < dato) {
        plantarArbolBinario(padre->derecha, nullptr, dato, nullptr);
    } else if(padre->elemento > dato) {
        plantarArbolBinario(padre->izquierda, nullptr, dato, nullptr);
    }
}



int main(int argc, char** argv) {

    
    ArbolBinarioBusqueda abb;
    construir(abb);
    
    
//    insertar(abb, 15);
//    insertar(abb, 9);
//    insertar(abb, 20);
//    insertar(abb, 6);
//    insertar(abb, 14);
//    insertar(abb, 17);
//    insertar(abb, 64);
//    insertar(abb, 7);
//    insertar(abb, 13);
//    insertar(abb, 16);
//    insertar(abb, 19);
//    insertar(abb, 26);
//    insertar(abb, 72);
    
    
    
    insertarIterativamenteUnAbb(abb, 15);
    insertarIterativamenteUnAbb(abb, 9);
    insertarIterativamenteUnAbb(abb, 20);    
    insertarIterativamenteUnAbb(abb, 6);
    
    insertarIterativamenteUnAbb(abb, 14);
    insertarIterativamenteUnAbb(abb, 17);
    insertarIterativamenteUnAbb(abb, 64);
    insertarIterativamenteUnAbb(abb, 7);
    insertarIterativamenteUnAbb(abb, 13);
    insertarIterativamenteUnAbb(abb, 16);
    insertarIterativamenteUnAbb(abb, 19);
    insertarIterativamenteUnAbb(abb, 26);
    insertarIterativamenteUnAbb(abb, 72);
    recorrerEnOrden(abb.arbolBinario);
//    
//    
//    
//    recorrerEnOrden(abb.arbolBinario);
    
    
    
    return 0;
}

