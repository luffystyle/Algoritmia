/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
void pasaPila(Pila & p1,Pila & p2){
    int valor,n;
    while(!esPilaVacia(p1)){
        valor=desapilar(p1);
        n=0;
        while(!esPilaVacia(p1)){
            apilar(p2,valor);
            valor=desapilar(p1);
            n++;
        }
        while(!esPilaVacia(p2) && n>0){
            apilar(p1,desapilar(p2));
            n--;
        }
        apilar(p2,valor);
    }
}
void pasaPilaRecursivo(Pila & pila,Pila & pila2){
    if(esPilaVacia(pila))return;
    int valor;
    valor=desapilar(pila);
    pasaPilaRecursivo(pila,pila2);
    apilar(pila2,valor);    
}
int main(int argc, char** argv) {

    struct Pila pila;
    construir(pila);
    /*Apilamos elementos en la pila*/
    apilar(pila, 1);
    apilar(pila, 2);
    apilar(pila, 3);
    apilar(pila, 4);
    apilar(pila, 5);
    apilar(pila, 6);
    imprimir(pila);
    
    struct Pila pila2;
    construir(pila2);
//    pasaPila(pila,pila2);
    pasaPilaRecursivo(pila,pila2);
    imprimir(pila2);
    
    return 0;
}

