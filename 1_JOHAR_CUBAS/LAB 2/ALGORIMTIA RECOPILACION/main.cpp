/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

void intercalarLista(struct Lista &lista1,struct Lista &lista2){
    struct Nodo * recorrido = lista1.cabeza;
    struct Nodo * siguiente = lista2.cabeza;
    //struct Nodo * nodoInsertado = nullptr;
    
    while(recorrido!=nullptr and siguiente!=nullptr){
        struct Nodo * nodoInsertado = new struct Nodo ;

        nodoInsertado->elemento = siguiente->elemento;
        nodoInsertado->siguiente = recorrido->siguiente;
        recorrido->siguiente = nodoInsertado;
        
        recorrido = nodoInsertado->siguiente;
        siguiente = siguiente->siguiente;

    }
    
}

void intercalarLista2(struct Lista &lista1,struct Lista &lista2){
    struct Nodo * recorrido = lista1.cabeza;
    struct Nodo * siguiente = lista2.cabeza;
        
    while(recorrido!=nullptr and siguiente!=nullptr){
        struct Nodo* recorridoSig = recorrido->siguiente;
        struct Nodo* recorrido2Sig = siguiente->siguiente;
        
        recorrido->siguiente = siguiente;
        siguiente->siguiente = recorridoSig;
        
        recorrido = recorridoSig;
        siguiente = recorrido2Sig;

    }
    
}
void ordenarListas(struct Lista &lista){
    struct Nodo* recorrido = lista.cabeza;    
    int menor,aux;
    while(recorrido!=nullptr){
        struct Nodo* siguiente = recorrido->siguiente;
        menor = recorrido->elemento;
        while(siguiente!=nullptr){
            aux= siguiente->elemento;
            if(menor>siguiente->elemento){
                siguiente->elemento= menor;
                recorrido->elemento=aux;
                menor = aux;
            }
            siguiente = siguiente->siguiente;
        }
        
        recorrido = recorrido->siguiente ;
    }
    
    
}
void ordenarDesLista(struct Lista &lista){
    struct Nodo* recorrido = lista.cabeza;    
    int mayor,aux;
    while(recorrido!=nullptr){
        struct Nodo* siguiente = recorrido->siguiente;
        mayor = recorrido->elemento;
        while(siguiente!=nullptr){
            aux= siguiente->elemento;
            if(mayor<aux){
                siguiente->elemento= mayor;
                recorrido->elemento=aux;
                mayor = aux;
            }
            siguiente = siguiente->siguiente;
        }
        
        recorrido = recorrido->siguiente ;
    }
    
}

void invertirLista(struct Lista &lista){
    struct Nodo * anterior = nullptr;
    struct Nodo * actual = lista.cabeza;
    struct Nodo * siguiente= nullptr;
    while(actual!=nullptr){
        siguiente = actual->siguiente;
        actual->siguiente = anterior  ;
        anterior = actual ;
        actual = siguiente;
    }
    lista.cabeza = anterior;
}

void intercalarPilas(struct Pila &pila1,struct Pila &pila2,int n,int n2){
    int valorPila1,valorPila2;
    if(esPilaVacia(pila1)or n==0) return;
    valorPila1 = desapilar(pila1);
    if(!esPilaVacia(pila2)){
        valorPila2= desapilar(pila2);
    }
    intercalarPilas(pila1,pila2,n-1,n2-1);
    apilar(pila1,valorPila1);
    if(n2!=0){
        apilar(pila1,valorPila2);
    }
    
    
    
}



int main(int argc, char** argv) {
    struct Lista lista1,lista2;
    construir(lista1);
    construir(lista2);
    
    insertarAlFinal(lista1,5);
    insertarAlFinal(lista1,20);
    insertarAlFinal(lista1,40);
    insertarAlFinal(lista1,60);
    insertarAlFinal(lista1,80);
    
    insertarAlFinal(lista2,10);
    insertarAlFinal(lista2,30);
    insertarAlFinal(lista2,50);
    insertarAlFinal(lista2,15);
    
    imprime(lista1);
    imprime(lista2);
    
    intercalarLista2(lista1,lista2);
    imprime(lista1);
    ordenarListas(lista1);
    imprime(lista1);
    ordenarDesLista(lista1);
    imprime(lista1);
    
    struct Pila pila1,pila2;
    construir(pila1);
    construir(pila2);
    
    apilar(pila1,20);
    apilar(pila1,10);
    apilar(pila1,40);
    apilar(pila1,30);
    
    apilar(pila2,50);
    apilar(pila2,60);
    apilar(pila2,70);
    imprimir(pila1);
    imprimir(pila2);
    intercalarPilas(pila1,pila2,longitud(pila1),longitud(pila2));
    imprimir(pila1);
    
    return 0;
}

