
#include <iostream>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"

#include "funcionesCola.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "funcionesAuxiliares.h"

void reinicia_cola(struct Cola &cola, struct Pila &pila1, struct Pila &pila2, int cantCola) {
    
    //primero voy a encolar y desencolar
    int cantPila1 = pila1.lista.longitud;
    int elemento, cantPila2 = pila2.lista.longitud;
    for(int i = 0; i<cantPila2; i++) {
        elemento = desapilar(pila2);
        apilar(pila1, elemento);    
    }

    ordenarPila(pila1, pila2);
    
    int longPila1 = pila1.lista.longitud;
    // desencolo y encolo (longCola - longitud Pila 1)
    for(int i = 0; i<cantCola-longPila1; i++) encolar(cola, desencolar(cola));
    for(int i = 0; i<longPila1; i++) apilar(pila2, desencolar(cola));
    for(int i = 0; i<longPila1; i++) encolar(cola, desapilar(pila1));
    for(int i = 0; i<cantCola-longPila1; i++) encolar(cola , desencolar(cola));
}

void ordenarPila(struct Pila &pila1, struct Pila &pila2) {
    
    int aux;
    while(!esPilaVacia(pila1)){
        apilar(pila2, desapilar(pila1));
    }
    
    while(!esPilaVacia(pila2)) {
        aux = desapilar(pila2);
        while(!esPilaVacia(pila1) and aux%100 > cima(pila1)%100) { 
            apilar(pila2, desapilar(pila1));
        }
        apilar(pila1, aux);
    } 
    
}

void reclasifica_pilas(struct Pila &pila1, struct Pila &pila2) {    
    
    struct Cola colaAuxiliar;
    construir(colaAuxiliar);
    int longPila = pila2.lista.longitud, auxiliar;
    
    for(int i = 0 ; i< longPila; i++) encolar(colaAuxiliar, desapilar(pila2));
    for(int i = 0; i<longPila; i++) {
        auxiliar = desencolar(colaAuxiliar);
        if(auxiliar/100 == 1) apilar(pila2, auxiliar);
        else apilar(pila1, auxiliar);
    }
    
}

void imprimirResultados(const struct Cola &cola, const struct Pila &pila1, const struct Pila &pila2) {
    cout << "Cola: ";
    imprime(cola);
    cout << "Pila 1: ";
    imprime(pila1.lista);
    cout << "Pila 2: ";
    imprime(pila2.lista);
    cout << endl;
}