/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 07:21 PM
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "Cola.h"
using namespace std;
#include "funcionesCola.h"


void ordenarec(Cola &cola1,int n){
    int min,aux,i=1;
    
    if(esColaVacia(cola1)) return;
    min = desencolar(cola1);
    while(i<n){
        aux = desencolar(cola1);
        if(min>aux){
            encolar(cola1,min);
            min = aux;
        }else
            encolar(cola1,aux);
        i++;
    }
    ordenarec(cola1,n-1);
    encolar(cola1,min);
    
}



int main(int argc, char** argv) {
    
    Cola cola;
    construir(cola);
    cout<<"La cola está vacía: "<<esColaVacia(cola)<<endl;
    encolar(cola, 8);
    encolar(cola, 21);
    encolar(cola, 10);
    encolar(cola, 15);
    encolar(cola, 7);
    imprime(cola);
    ordenarec(cola,cola.lista.longitud);
    imprime(cola);   

    return 0;
}

