/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on September 23, 2024, 11:54 PM
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <ratio>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"



void pasarPila(Pila &pila1, Pila &pila2) {
    
    int valor, aux, n;
    
    while(!esPilaVacia(pila1)) {
        n = 0; //Cuando elementos me queda
        
        valor = desapilar(pila1);
        while(!esPilaVacia(pila1)) {
            apilar(pila2, valor);
            valor = desapilar(pila1);
            n++;
        }
        
        while(n > 0) { // Con esa cantidad de n, apilo las veces
            aux = desapilar(pila2);
            apilar(pila1, aux);
            n--;
        }
        apilar(pila2, valor); // El valor que tenia guardado en valor, lo apilo a la pila2 paara ponerlo
        // ahi ya tengon una iteracion        
    }
}







int main(int argc, char** argv) {

    
    Pila pila;
    Pila pila2;
    construir(pila);
    construir(pila2);
    
    apilar(pila, 6);
    apilar(pila, 8);
    apilar(pila, 10);
    apilar(pila, 12);
    
    cout << "----------------------------------------------" << endl;
    imprimir(pila);
    pasarPila(pila, pila2);
    
    cout << "----------------------------------------------" << endl;
    imprimir(pila2);

    
    
    
    
    return 0;
}

