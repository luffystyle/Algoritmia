

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 18, 2024, 8:18 PM
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

void encolarPrioridad( Cola &C1, Elemento elem) {
    
    Nodo *nuevoNodo = crearNodo(elem, nullptr);
    
    
    if(esColaVacia(C1)) {
        C1.lista.cabeza = nuevoNodo;
        C1.lista.cola = nuevoNodo;
        if(strcmp(elem.prioridad, "VIP") == 0) C1.lista.vip = nuevoNodo;
    } else {
        if(strcmp(elem.prioridad, "VIP") == 0) {
            if(C1.lista.vip == nullptr) { // hay puros N's
                nuevoNodo->siguiente = C1.lista.cabeza;
                C1.lista.cabeza = nuevoNodo;                
            }else {
                if(C1.lista.vip->siguiente ==  nullptr) C1.lista.cola = nuevoNodo;
                nuevoNodo->siguiente = C1.lista.vip->siguiente;
                C1.lista.vip->siguiente = nuevoNodo;
                C1.lista.vip = nuevoNodo;
            }               
        } else {
            C1.lista.cola->siguiente = nuevoNodo;
            C1.lista.cola = nuevoNodo;
        }
    }
    C1.lista.longitud++;
}

int main(int argc, char** argv) {

    Cola C1;
    construir(C1);
    
    Elemento elem1 = {"VIP", 3};
    Elemento elem2 = {"VIP", 5};
    Elemento elem3 = {"NON", 1};
    Elemento elem4 = {"NON", 10};
    
    
    encolarPrioridad(C1, elem1);   
    encolarPrioridad(C1, elem2);   
    encolarPrioridad(C1, elem3);   
    encolarPrioridad(C1, elem4);   
    imprime(C1);
    
    return 0;
}

