/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on October 7, 2024, 11:12 AM
 */

#include <iostream>

using namespace std;

#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

void muestraMovimientos(char *instrucciones, int n) {
    
    Pila stack;
    construir(stack);
    for(int i =  0; i<=n; i++) { // i<=n es por el elemento final
        apilar(stack, i + 1);
        if(instrucciones[i] == 'S'){
            while(!esPilaVacia(stack)) {
                cout << desapilar(stack) << " ";
            }
        }
    }
     
    
}





int main(int argc, char** argv) {
    
    char instrucciones[] = {'B', 'B', 'S'};    
    int n = sizeof(instrucciones)/sizeof(instrucciones[0]);
    
    muestraMovimientos(instrucciones, n);
    
    
    return 0;
}

