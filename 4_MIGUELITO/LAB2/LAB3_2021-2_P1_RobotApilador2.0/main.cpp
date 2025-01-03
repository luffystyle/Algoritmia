/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 1, 2024, 7:55 AM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

void hanoi(int n, Pila &A, Pila &B, Pila &C) {
    if(n == 0) return;
    hanoi(n-1, A, C, B);
    apilar(C, desapilar(A));
    hanoi(n-1, B, A, C);
}


void robotApilador(Cola &cola, int n) {
    
    Pila pPrincipal, pAux1, pAux2;
    
    construir(pPrincipal);
    construir(pAux1);
    construir(pAux2);
    
    
    //Quitamos un primer elemento y lo apilamos
    apilar(pPrincipal, desencolar(cola));
    
    //Variables
    int elemento;
    int yaApilo;
    int k;
    
    
    //Recorremos
    for(int i = 0; i < n-1; i++) { // Porque ya saqué uno
        yaApilo = 1; //Esto es un bandera
        k = 1;
        elemento = desencolar(cola);
        if(elemento <= pPrincipal.lista.cabeza->elemento) { //Si son iguales, igual apilo 
            apilar(pPrincipal, elemento);
        } else {
            while(elemento > pPrincipal.lista.cabeza->elemento) { // Cuando el elemento es mayor a la cabeza de la pila
                
                //Cuando k = 0, no hace nada. No entra a niguna funcion
                if(!esPilaVacia(pAux2)) { // pasar de la aux2 a la principal, cuando k>0
                    hanoi(pAux2.lista.longitud, pAux2, pAux1, pPrincipal);
                }
                hanoi(k, pPrincipal, pAux1, pAux2); // pasa principal a tercera pila.Se queda vacio pilaPrincipal
                if(esPilaVacia(pPrincipal)) {
                    apilar(pPrincipal, elemento);
                    yaApilo = 0;
                }
                k++;
            }
            
            if(yaApilo) {
                apilar(pPrincipal, elemento);
            }
            hanoi(pAux2.lista.longitud, pAux2, pAux1, pPrincipal); // Aqui ya ordeno todo la pila en la principal
        } 
    }
    
    imprimir(pPrincipal);
}




int main(int argc, char** argv) {

    
    Pila pila;
    Cola cola;
    int n = 6;
    
    construir(cola);
    
    
    encolar(cola, 2);
    encolar(cola, 8);
    encolar(cola, 10);
    encolar(cola, 8);
    encolar(cola, 5);
    encolar(cola, 3);
    
    imprime(cola);
    
    
    robotApilador(cola, n);
    destruirCola(cola);
    
    
//    Pila pPrincipal, pAux1, pAux2;
//    
//    construir(pPrincipal);
//    construir(pAux1);
//    construir(pAux2);
//    
//    apilar(pPrincipal, 10);
//    apilar(pPrincipal, 5);
//    apilar(pPrincipal, 3);
//    
//    hanoi(3, pPrincipal, pAux1, pAux2);
//    
//    imprimir(pAux2);
//    
    return 0;
}

