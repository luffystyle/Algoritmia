
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 17, 2024, 6:43 PM
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"


void encolarConPrioridad(Cola &C1, Elemento elem) {
    
    Nodo *nuevoNodo = crearNodo(elem, nullptr);
    
    if( esColaVacia(C1)) {
        C1.lista.cabeza = nuevoNodo;
        C1.lista.cola = nuevoNodo;
    } else {
        Nodo *anterior = nullptr;
        Nodo *actual = C1.lista.cabeza;
        
        while(actual != nullptr) {
            if(actual->elemento.prioridad < elem.prioridad) {
                anterior = actual;
                actual = actual->siguiente;
            } else if(actual->elemento.prioridad == elem.prioridad) {
                if(strcmp(elem.codigo, actual->elemento.codigo) > 0) {
                    anterior = actual;
                    actual = actual->siguiente;
                } else {
                    break;
                }                
            } else {
                break;
            } 
        }
        if(anterior == nullptr) {
            nuevoNodo->siguiente = C1.lista.cabeza;
            C1.lista.cabeza = nuevoNodo;
        } else { // Al medio o final
            nuevoNodo->siguiente = actual;
            anterior->siguiente = nuevoNodo;
        }
        if(actual == nullptr)
            C1.lista.cola = nuevoNodo;
        
    }
    C1.lista.longitud++;
}


int main(int argc, char** argv) {

    Cola C1;
    construir(C1);
    
    Elemento elem1 = {"ISI001", 2};
    Elemento elem2 = {"ISI002", 1};
    Elemento elem3 = {"ISI003", 1};
    Elemento elem4 = {"ISI004", 3};
    Elemento elem5 = {"ISI005", 2};
    Elemento elem6 = {"ISI006", 3};
    Elemento elem7 = {"ISI007", 1};
    
    encolarConPrioridad(C1, elem1);
    encolarConPrioridad(C1, elem2);
    encolarConPrioridad(C1, elem3);
    encolarConPrioridad(C1, elem4);
    encolarConPrioridad(C1, elem5);
    encolarConPrioridad(C1, elem6);
    encolarConPrioridad(C1, elem7);
    
    imprime(C1);
    
    return 0;
}

