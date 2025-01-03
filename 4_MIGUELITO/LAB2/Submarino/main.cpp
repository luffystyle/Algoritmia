
/* 
 * File:   main.cpp
 * Author: Miguelito Torres
 *
 * Created on October 11, 2024, 11:08 PM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"


void imprimeSolucion(char *ordenes, int longitud) {
    int i = 1;
    Pila P1;
    construir(P1);
    
    for(int i = 0; i<longitud; i++) {
        if(ordenes[i] == 'S') {
            apilar(P1, i+1);
            while(!esPilaVacia(P1)) {
                cout << desapilar(P1) << " ";
            }
        } else {
            apilar(P1, i+1);
        }
        
    }
    while(!esPilaVacia(P1)) {
        cout << desapilar(P1) << " ";
    }
}



int main(int argc, char** argv) {

    
    //char ordenes[] = { 'S', 'B', 'S', 'B', 'B', 'S', 'S'};   
    //char ordenes[] = { 'B', 'B', 'S'};   
    char ordenes[] = { 'S', 'S', 'S', 'B', 'S'};   
    int n = 5;
    
    imprimeSolucion(ordenes, n);
    
    
    return 0;
}

