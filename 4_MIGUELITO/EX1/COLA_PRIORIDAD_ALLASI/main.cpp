
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 17, 2024, 9:53 PM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

void encolarConPrioridad(Cola &C1, Elemento elem) {
    
    Nodo *nuevoNodo = crearNodo(elem, nullptr);
    
    if(esColaVacia(C1)) {
        C1.lista.cabeza = nuevoNodo;
        C1.lista.cola = nuevoNodo;
    } else {
        Nodo *anterior = nullptr;
        Nodo *actual = C1.lista.cabeza;
        while( actual != nullptr) {
            if(actual->elemento.prioridad > elem.prioridad) {
                anterior = actual;
                actual = actual->siguiente;
            } else if( actual->elemento.prioridad == elem.prioridad) {
                if(actual->elemento.numero < elem.numero) {
                    anterior = actual;
                    actual = actual->siguiente;
                } else {
                    break;
                }
            } else {
                break;
            }         
        }
        if(anterior == nullptr) { //Prrimera vez
            nuevoNodo->siguiente = C1.lista.cabeza;
            C1.lista.cabeza = nuevoNodo;
        } else {
            nuevoNodo->siguiente = actual;
            anterior->siguiente = nuevoNodo;
        }
        if( actual == nullptr) C1.lista.cola = nuevoNodo;
    }
    C1.lista.longitud++;
}


//V antes que N
// [(3,V) , (5,V) , (1,N) , (10,N) ]
// Prioridad es el V
int main(int argc, char** argv) {

    
    Cola C1;
    construir(C1);

    Elemento elem1 = {3, 'V'};
    Elemento elem2 = {5, 'V'};
    Elemento elem3 = {1, 'N'};
    Elemento elem4 = {10, 'N'};
    
    encolarConPrioridad(C1, elem1);
    encolarConPrioridad(C1, elem2);
    encolarConPrioridad(C1, elem3);
    encolarConPrioridad(C1, elem4);
    
    imprime(C1);
    
    return 0;
}

