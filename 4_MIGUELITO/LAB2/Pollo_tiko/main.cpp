
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 8, 2024, 8:53 PM
 */

#include <iostream>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "funcionesLista.h"


void ordenarPedidos(Lista &list1, Lista &list2) {
    
    
    if(list1.cola->elemento < list2.cabeza->elemento) { 
        list1.cola->siguiente = list2.cabeza;
        list1.cola = list2.cola;
        //list1.longitud += list2.longitud;
    } else {
        if(list2.cola->elemento < list1.cabeza->elemento) {
            list2.cola->siguiente = list1.cabeza;
            list1.cabeza = list2.cabeza;
            //list1.longitud += list2.longitud;
        } else {
            Nodo *pIni, *pFin;
            pIni = nullptr;
            pFin = nullptr;
            
            while(!esListaVacia(list1) && !esListaVacia(list2)) { //VOY A RECORRER LAS LISTAS
                //COMPARO LAS DOS CABEZAS xq ya comparé anterior mente las combinaciones más faciles
                if(list1.cabeza->elemento <= list2.cabeza->elemento) { 
                    if( pIni == nullptr) { // la primera VEZ
                        pIni = list1.cabeza;
                        pFin = list1.cabeza;
                    } else { // pIni es diferente de nullptr
                        pFin->siguiente = list1.cabeza;
                        pFin = list1.cabeza;
                    }
                    list1.cabeza = list1.cabeza->siguiente;
                    
                } else { // lo contrario, la cabeza de las L2 es menor que la cabeza de L1
                    if(pIni == nullptr) {
                        pIni = list2.cabeza; // una vez determinado el ini ya no lo cambio. Solo cambiamo el fin
                        pFin = list2.cabeza;
                    } else {
                        pFin->siguiente = list2.cabeza;
                        pFin = list2.cabeza;
                    }
                    list2.cabeza = list2.cabeza->siguiente;
                }
            }
            
            while(!esListaVacia(list1)) {
                if( pIni == nullptr) { // la primera VEZ
                    pIni = list1.cabeza;
                    pFin = list1.cabeza;
                } else { // pIni es diferente de nullptr
                    pFin->siguiente = list1.cabeza;
                    pFin = list1.cabeza;
                }
                list1.cabeza = list1.cabeza->siguiente;
            }
            
            while(!esListaVacia(list2)) {
                if(pIni == nullptr) {
                    pIni = list2.cabeza;
                    pFin = list2.cabeza;
                } else {
                    pFin->siguiente = list2.cabeza;
                    pFin = list2.cabeza;
                }
                list2.cabeza = list2.cabeza->siguiente;
            }
            
            list1.cabeza = pIni;
            list2.cola = pFin;
            
        }
    }
    
    
    
}



int main(int argc, char** argv) {

    
    Lista lunes, martes, miercoles, jueves, viernes;
    
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);

    
    
    insertarencola(lunes,  8);
    insertarencola(lunes, 10);
    insertarencola(lunes, 12);
    
    insertarencola(martes,  9);
    insertarencola(martes, 11);
    
    insertarencola(miercoles,  8);
    insertarencola(miercoles,  9);
    insertarencola(miercoles, 10);
    
    insertarencola(jueves, 14);
    insertarencola(jueves, 15);
    insertarencola(jueves, 16);
    
    insertarencola(viernes, 17);
    insertarencola(viernes, 18);
    insertarencola(viernes, 19);
    
    imprime(lunes);
    
    ordenarPedidos(lunes, martes);
    ordenarPedidos(lunes, miercoles);
    ordenarPedidos(lunes, jueves);
    ordenarPedidos(lunes, viernes);
    
    imprime(lunes);
    
    
    return 0;
}

