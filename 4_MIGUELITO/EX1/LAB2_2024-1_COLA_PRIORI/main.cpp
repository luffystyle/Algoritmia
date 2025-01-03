
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 17, 2024, 10:47 PM
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"


int prioridad (int edad) {
    if(edad >= 80) {
        return 1;
    } else if( edad <= 10) {
        return 2;
    } else {
        return 3;
    }
}

int convertirEdad(int fecha) {
    
    int aa = fecha/10000;
    int mm = (fecha%10000)/100;
    int dd = fecha%100;
    
    
    int edad = 2024 - aa;
    if (6 < mm || (6 == mm && 15 < dd)) {
        edad--;
    }
    return edad;
}


void encolaConPrioridad(Cola &C1, Elemento elem) {
    
    int prioriNuevoNodo;
    int edadNuevo = convertirEdad(elem.fecha);
    //prioriNuevoNodo = prioridad(edadNuevo);
    
    Nodo *nuevoNodo = crearNodo(elem, nullptr);
    
    if(esColaVacia(C1)) {
        C1.lista.cabeza = nuevoNodo;
        C1.lista.cola = nuevoNodo;
    } else {
        Nodo *anterior =nullptr;
        Nodo *actual = C1.lista.cabeza;
        
        while(actual != nullptr) {
            int edadActual = convertirEdad(actual->elemento.fecha);
            if( prioridad(edadNuevo) > prioridad(edadActual) ) { 
                anterior = actual;
                actual = actual->siguiente;
            } 
            else if (prioridad(edadActual) == prioridad(edadNuevo)) {
                if (strcmp(elem.codigo, actual->elemento.codigo) < 0) {
                    anterior = actual;
                    actual = actual->siguiente;
                } else {
                    break;
                }
            }
            else {
                break;
            }
        }
        
        if(anterior == nullptr) { 
            nuevoNodo->siguiente = C1.lista.cabeza;
            C1.lista.cabeza = nuevoNodo;
        } else {
            nuevoNodo->siguiente = actual;
            anterior->siguiente = nuevoNodo;
        }
        
        if(actual == nullptr) C1.lista.cola = nuevoNodo;
    }
    
    C1.lista.longitud++;
}



int main(int argc, char** argv) {
    
    
    Cola C1;
    construir(C1);
    
    Elemento elem1 = {19430530, "BXQ778"};
    Elemento elem2 = {20140420, "HRP112"};
    Elemento elem3 = {19750626, "PRL625"};
    Elemento elem4 = {19491022, "MKP157"};
    Elemento elem5 = {20200513, "ARH749"};
    Elemento elem6 = {19300214, "HRQ931"};
    
    
    
    
    
    
    encolaConPrioridad(C1, elem1);
    encolaConPrioridad(C1, elem2);
    encolaConPrioridad(C1, elem3);
    encolaConPrioridad(C1, elem4);
    encolaConPrioridad(C1, elem5);
    encolaConPrioridad(C1, elem6);
    
    imprime(C1);

    
    return 0;
}

