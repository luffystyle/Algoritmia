
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 10, 2024, 9:31 PM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "funcionesLista.h"


void ordenarPorPedidos(Lista &L1, Lista &L2) {
    
    if(L1.cola->elemento < L2.cabeza->elemento) {
        L1.cola->siguiente = L2.cabeza;
        L1.cola = L2.cola;
        L1.longitud += L2.longitud;
    } else {
        if(L2.cola->elemento < L1.cabeza->elemento) {
            L2.cola->siguiente = L1.cabeza;
            L1.cabeza = L2.cabeza;
            L1.longitud += L2.longitud;
        } else {
            Nodo *ini, *fin;
            ini = nullptr;
            fin = nullptr;
            while( !esListaVacia(L1) && !esListaVacia(L2)) {
                if(L1.cabeza->elemento <= L2.cabeza->elemento) {
                    if(ini == nullptr) { //  la primera vez
                        ini = L1.cabeza;
                        fin = L1.cabeza;
                    } else {
                        fin->siguiente = L1.cabeza;
                        fin = L1.cabeza;                        
                    }
                    L1.cabeza = L1.cabeza->siguiente;
                } else {
                    if(ini == nullptr) { //  la primera vez
                        ini = L2.cabeza;
                        fin = L2.cabeza;
                    } else {
                        fin->siguiente = L2.cabeza;
                        fin = L2.cabeza;                        
                    }
                    L2.cabeza = L2.cabeza->siguiente;
                }             
            }
            
            while(!esListaVacia(L1)) {
                if(ini == nullptr) { //  la primera vez
                    ini = L1.cabeza;
                    fin = L1.cabeza;
                } else {
                    fin->siguiente = L1.cabeza;
                    fin = L1.cabeza;
                }
                L1.cabeza = L1.cabeza->siguiente;
            }
            while(!esListaVacia(L2)) {
                if(ini == nullptr) { //  la primera vez
                    ini = L2.cabeza;
                    fin = L2.cabeza;
                } else {
                    fin->siguiente = L2.cabeza;
                    fin = L2.cabeza;
                }
                L2.cabeza = L2.cabeza->siguiente;
            }
            L1.cabeza = ini;
            L1.cola = fin;
            L1.longitud += L2.longitud;
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
    
    insertarencola(lunes, 8);
    insertarencola(lunes, 10);
    insertarencola(lunes, 14);
    
    insertarencola(martes, 9);
    insertarencola(martes, 11);
    
    insertarencola(miercoles, 8);
    insertarencola(miercoles, 9);
    insertarencola(miercoles, 10);
    
    insertarencola(jueves, 14);
    insertarencola(jueves, 15);
    insertarencola(jueves, 16);
    
    insertarencola(viernes, 17);
    insertarencola(viernes, 18);
    insertarencola(viernes, 19);
    
    imprime(lunes);
    
    ordenarPorPedidos(lunes, martes);
    ordenarPorPedidos(lunes, miercoles);
    ordenarPorPedidos(lunes, jueves);
    ordenarPorPedidos(lunes, viernes);
    
    cout << lunes.longitud << endl;
    imprime(lunes);
    
    
    return 0;
}

