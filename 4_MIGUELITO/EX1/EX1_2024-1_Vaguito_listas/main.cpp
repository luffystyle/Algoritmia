/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * CodigoÑ 20175525
 * Created on October 16, 2024, 1:43 PM
 */

#include <iostream>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "funcionesLista.h"




void combinarListas(Lista &L1, Lista &L2) {
    
    
    
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
            while(!esListaVacia(L1) && !esListaVacia(L2)) {
                if( L1.cabeza->elemento < L2.cabeza->elemento) { // COMPARO CABEZAS
                   if(ini == nullptr) {
                       ini = L1.cabeza;
                       fin = L1.cabeza;
                   } else {
                       fin->siguiente = L1.cabeza;
                       fin = L1.cabeza;
                   }
                   L1.cabeza = L1.cabeza->siguiente;
                } else {
                    if(ini == nullptr) {
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
                if(ini == nullptr) {
                    ini = L1.cabeza;
                    fin = L1.cabeza;
                } else {
                    fin->siguiente = L1.cabeza;
                    fin = L1.cabeza;
                }
                L1.cabeza = L1.cabeza->siguiente;
            }
            while(!esListaVacia(L2)) {
                if(ini == nullptr) {
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

//    ifstream arch("Datos.txt", ios::in);
//    if(!arch) {
//        cout << "El archivo Datos.txt no se pudo abrir" << endl;
//        exit(1);
//    }
//    
    
    Lista arrListas[];
    int cantTiposProd;
    
    cout << "Ingrese la cantidad de tipos de datos:" << endl;
    cin >> cantTiposProd;
   
    // CREANDO LAS LISTAS
    if( cantTiposProd > 1 && cantTiposProd <= 6) {
        for(int i = 0; i<cantTiposProd; i++) {
            construir(arrListas[i]);
            
        }
    } else {
        cout << "El valor ingresado no es el correcto." << endl;
    }
    
    
    
    Lista Lista;
    
    
    
    
    
    
//    Lista L1, L2, L3;
//    construir(L1);
//    construir(L2);
//    construir(L3);
//    
//    insertarAlFinal(L1, 182);
//    insertarAlFinal(L1, 240);
//    
//    insertarAlFinal(L2, 58);
//    insertarAlFinal(L2, 120);
//    insertarAlFinal(L2, 247);
//    
//    insertarAlFinal(L3, 128);
//    insertarAlFinal(L3, 354);
//
//    combinarListas(L1, L2);
//    combinarListas(L1, L3);
//    
//    imprime(L1);
//    imprime(L2);
//    imprime(L3);
    
    
    return 0;
}

