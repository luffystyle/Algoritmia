/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"

using namespace std;
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
/*
 * IMPLEMENTACIÓN DE UNA COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
void encolar_prioridad(Cola & cola,int codigo,int prioridad){
    struct Nodo*nodo;
    struct Nodo*sig;
    nodo->codigo=codigo;
    nodo->prioridad=prioridad;
    
    Nodo*nuevoNodo=crearNodo(codigo,prioridad,sig);
    
    if(esColaVacia(cola) || prioridad<cola.lista.cabeza->prioridad){
        nuevoNodo->siguiente=cola.lista.cabeza;
        cola.lista.cabeza=nuevoNodo;
        if(esColaVacia(cola)){
            cola.lista.cola=nuevoNodo;
        }
        cola.lista.longitud++;
        return;
    }
    
    Nodo*ptraux=cola.lista.cabeza;
    while(ptraux->siguiente!=NULL && ptraux->siguiente->prioridad<=prioridad){
        ptraux=ptraux->siguiente;
    }
    
    nuevoNodo->siguiente=ptraux->siguiente;
    ptraux->siguiente=nuevoNodo;
    
    if(nuevoNodo->siguiente==NULL){
        cola.lista.cola=nuevoNodo;
    }
    cola.lista.longitud++;
}

int main(int argc, char** argv) {
    ////////////
    /*Parte A*/
    ///////////
    Cola cola;
    
    int n=7;
    construir(cola);
    
    encolar_prioridad(cola,1,2);
    encolar_prioridad(cola,2,1);
    encolar_prioridad(cola,3,1);
    encolar_prioridad(cola,4,3);
    encolar_prioridad(cola,5,2);
    encolar_prioridad(cola,6,3);
    encolar_prioridad(cola,7,1);
    imprime(cola); 

    
    
    
    return 0;
}

