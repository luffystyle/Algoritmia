/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva 
 * Codigo: 20175525
 * Created on October 16, 2024, 10:30 AM
 */

#include <iostream>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"


void pasarOtraPila(Pila &P1, Pila &P2, int n){

    int valor;

    if(n == 0) return; 
    valor = desapilar(P1);
    pasarOtraPila(P1, P2, n-1);
    apilar(P2, valor);
    
}

void ordenandoPila(Pila &P1, int n) {
    
    Pila Paux;
    construir(Paux);
    
    int max, valor, k ;
    if(n == 0) return ;
    
    max = desapilar(P1);

    k = n-1;
    while(k>0) {
        valor = desapilar(P1);
        if(valor < max) {
            apilar(Paux, valor);                
        } else {
            apilar(Paux, max);
            max = valor;
        }
        k--;
    }
    apilar(P1, max);
    while(!esPilaVacia(Paux)) {
        apilar(P1, desapilar(Paux));
    }

    ordenandoPila(P1, n-1);
}


void pasarPilaUnica(Pila &P1, Pila &P2) {
     
    while(!esPilaVacia(P2)) {
        apilar(P1, desapilar(P2));
    }
}

int main(int argc, char** argv) {

    
    Pila P1; // ROBOT KUPA 1
    Pila P2; // ROBOT KUP2
    Pila P3; // MUNDO CHAMPINON
    construir(P1);
    construir(P2);
    construir(P3);
    
    
    apilar(P1,  27);
    apilar(P1,  30);
    apilar(P1,  56);
    apilar(P1,  15);
    apilar(P1,  85);
    
    apilar(P2, 20);
    apilar(P2, 68);
    apilar(P2, 22);
    apilar(P2, 45);
    
    imprimir(P1);
    imprimir(P2);
    
    // PASANDO A UNA SOLA PILA
    pasarPilaUnica(P1, P2);
    
    imprimir(P1);
    imprimir(P2);
    cout << P1.lista.longitud << endl;
    cout << P2.lista.longitud << endl;
    
    
    // ORDENANDO PILA
    ordenandoPila(P1, P1.lista.longitud);
    
    cout << "Imprimiendo Ordenado" << endl;
    imprimir(P1);
    
    pasarOtraPila(P1, P3, P1.lista.longitud);
    imprimir(P1);
    imprimir(P3);
    
    return 0;
}

