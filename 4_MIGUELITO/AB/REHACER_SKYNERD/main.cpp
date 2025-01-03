
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 24, 2024, 4:38 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "NodoArbol.h"
#include "ArbolB.h"
#include "funcionesAB.h"
#include "funcionesLista.h"
#include "Cola.h"
#include "funcionesCola.h"





int buscarSkynerd(ArbolBinario &arbol) {
    
    Cola cola;
    construir(cola);
    encolaNew(cola, arbol.raiz); // le paso nodoArbol, pero esta vez es la raiz
    while(!esColaVacia(cola)) {
        NodoArbol *nodoArbol = desencolarNew(cola); // desencolo para evaluar CADA NODOARBOL
        if(nodoArbol->elemento.velocidad == 200) {
            if(!esNodoVacio(nodoArbol->izquierda)) {
                if(nodoArbol->izquierda->elemento.tipo == 'S' && nodoArbol->izquierda->elemento.velocidad == 200) {
//                    cout << "El padre: ";
//                    imprimirNodo(nodoArbol);
//                    cout << endl;
//                    cout << "Skynerd es :";
//                    imprimirNodo(nodoArbol->izquierda);
//                    cout << endl;
                    return 1;
                }
                    
                else
                    encolaNew(cola, nodoArbol->izquierda);
            }
            if(!esNodoVacio(nodoArbol->derecha)) {
                if(nodoArbol->derecha->elemento.tipo == 'S' && nodoArbol->derecha->elemento.velocidad == 200) {
//                    cout << "El padre: ";
//                    imprimirNodo(nodoArbol);
//                    cout << endl;
//                    cout << "Skynerd es :";
//                    imprimirNodo(nodoArbol->derecha);
//                    cout << endl;
                    return 1;
                }                    
                else 
                    encolaNew(cola, nodoArbol->derecha);
            }
        }
        
        
        // ESTOS DOS IF SIGUEINTES, SE EVALUA LA MISMO NIVEL
        if(!esNodoVacio(nodoArbol->izquierda)) { //AQui evaluamos al hijo, pero si no es NO LLEGO AL NIVEL 4 y cumple con la condicion del problema
            //imprimirNodo(nodoArbol->izquierda);
            cout << setw(5) << nodoArbol->izquierda->elemento.tipo << "-" << nodoArbol->izquierda->elemento.velocidad << " ";
            cout << endl;
            encolaNew(cola, nodoArbol->izquierda);  
        }
            
        
        if(!esNodoVacio(nodoArbol->derecha)) { //AQui evaluamos al hijo, pero si no es NO LLEGO AL NIVEL 4 y cumple con la condicion del problema
            //imprimirNodo(nodoArbol->derecha);
            cout << setw(5) << nodoArbol->derecha->elemento.tipo << "-" <<  nodoArbol->derecha->elemento.velocidad << " ";
            cout << endl;
            encolaNew(cola, nodoArbol->derecha);
        }
            
        
    }
}


int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    
    //RAIZ
    Elemento elem = {'Z', 100}; // Este elemento es una estructura
    // arbol.raiz es un puntero NodoArbol o simplemente es un NodoArbol
    plantarArbolBinario(arbol.raiz, nullptr, elem, nullptr);
            
    // 1er Nivel
    elem = {'Z', 50};
    plantarArbolBinario(arbol.raiz->izquierda, nullptr, elem, nullptr);
    elem = {'E', 200};
    plantarArbolBinario(arbol.raiz->derecha, nullptr, elem, nullptr);
    
    // 2do Nivel
    elem = {'E', 100};
    plantarArbolBinario(arbol.raiz->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'S', 50};
    plantarArbolBinario(arbol.raiz->izquierda->derecha, nullptr, elem, nullptr);
    elem = {'S', 200};
    plantarArbolBinario(arbol.raiz->derecha->izquierda, nullptr, elem, nullptr);
    elem = {'S', 150};
    plantarArbolBinario(arbol.raiz->derecha->derecha, nullptr, elem, nullptr);
    
    // 3er Nivel
    elem = {'S', 50};
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'Z', 200};
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->derecha, nullptr, elem, nullptr);
    elem = {'S', 100};
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'E', 200};
    plantarArbolBinario(arbol.raiz->derecha->izquierda->derecha, nullptr, elem, nullptr);
    
    // 4to Nivel
    elem = {'E', 50};
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->izquierda->izquierda, nullptr, elem, nullptr);
    elem = {'E', 100};
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->derecha->izquierda, nullptr, elem, nullptr);
    
    
//    recorrerEnOrden(arbol);
//    cout << endl;
    
    cout << "Skynerd está o no: "  << buscarSkynerd(arbol) << endl;
    
    return 0;
}

