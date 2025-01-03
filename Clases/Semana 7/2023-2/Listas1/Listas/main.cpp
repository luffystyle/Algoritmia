/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de septiembre de 2023, 10:49 AM
 */
#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"

using namespace std;

Nodo* inviertereal(Nodo *lista){
    Nodo *ptrini;
    
    if(lista==NULL) return NULL;
    if(lista->siguiente==NULL) return lista;
    ptrini = inviertereal(lista->siguiente);
    lista->siguiente->siguiente = lista;
    lista->siguiente = NULL;
    
    return ptrini;
}


void invierterec(Lista &lista){
    Nodo* ptrini,*ptrfin;    
    
    ptrfin= lista.cabeza;
    ptrini= inviertereal(lista.cabeza);
    lista.cabeza = ptrini;
    lista.cola = ptrfin;
}


int main(int argc, char** argv) {
    
    Lista lista1;
    construir(lista1);
    insertarAlFinal(lista1,13);
    insertarAlFinal(lista1,34);
    insertarAlFinal(lista1,25);
    insertarAlFinal(lista1,55);
    
    imprime(lista1);
    invierterec(lista1);
     imprime(lista1);   
    
    return 0;
}

