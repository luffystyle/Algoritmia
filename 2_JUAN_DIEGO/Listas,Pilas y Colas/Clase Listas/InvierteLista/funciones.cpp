/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 4 de abril de 2024, 09:41 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Lista.h"
#include "funciones.h"
using namespace std;
void construir(struct Lista & lista){
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

bool esListaVacia(const struct Lista & lista){
    return lista.cabeza == nullptr;
}

void insertarAlInicio(struct Lista & lista, int elemento){
    
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = lista.cabeza;
    
    lista.cabeza = nuevoNodo;
    lista.longitud++;
    
}

void imprime(const struct Lista & lista){
    
    if(esListaVacia(lista)){
        cout<<"La lista está vacía no se puede imprimir";
    }
    else{
        struct Nodo * recorrido = new struct Nodo;
        recorrido = lista.cabeza;
        while(recorrido != nullptr){
            cout<<recorrido->elemento<<" ";
            recorrido = recorrido->siguiente; 
        }
        cout<<endl;
    }
}

struct Nodo * obtenerUltimoNodo(const  struct Lista & lista){
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = lista.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

struct Nodo * obtenerAnteriorNodo( const struct Lista & lista){
    struct Nodo * ultimo = nullptr;
    struct Nodo * anterior = nullptr;
    struct Nodo* recorrido = lista.cabeza;
    
    while(recorrido != nullptr){
        anterior = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

/*devuelve la longitud de la lista*/
int longitud( const struct Lista  & lista) {
    return lista.longitud;
}

void invierteLista(struct Lista & lista){
    struct Nodo * ultimo;
    struct Nodo * ultimoNodo = obtenerUltimoNodo(lista); //salvo el nodo
    struct Nodo * anteriorUltimo = obtenerAnteriorNodo(lista);
    
    while(true){
        ultimo = obtenerUltimoNodo(lista);
        anteriorUltimo = obtenerAnteriorNodo(lista);
        if(anteriorUltimo == nullptr) break;
        ultimo->siguiente =  anteriorUltimo;
        anteriorUltimo->siguiente = nullptr;
    }
    lista.cabeza = ultimoNodo;
}

void invierteListaRecursivo(struct Lista & lista, int n){
    struct Nodo * ultimo;
    struct Nodo * anteriorUltimo;
    
    if((n == 0) or (n == 1)){
        return;
    }
    else{
        ultimo = obtenerUltimoNodo(lista);
        anteriorUltimo = obtenerAnteriorNodo(lista);
        ultimo->siguiente =  anteriorUltimo;
        anteriorUltimo->siguiente = nullptr;
        invierteListaRecursivo(lista, n - 1);
    }
    lista.cabeza = ultimo;    
}

/*Elimina repetidos cuando son consecutivos*/
void eliminaRepetidos(struct Lista & lista){
    
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = lista.cabeza;
    
    anterior = lista.cabeza;
    recorrido = lista.cabeza->siguiente;
    
    while(recorrido != nullptr){
        while(anterior->elemento != recorrido->elemento){ /*son diferentes*/
            anterior = anterior->siguiente;
            recorrido = recorrido->siguiente;
            if(recorrido == nullptr) break;
        }
        
        if(recorrido != nullptr){
            anterior->siguiente = recorrido->siguiente; /*enlazo*/
            delete recorrido;                           /*borro*/
            recorrido = anterior->siguiente;
        }
    }
}

void completarLista(struct Lista & lista){
    
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido;
    struct Nodo * nuevoNodo;
    
    anterior = lista.cabeza;
    recorrido = lista.cabeza->siguiente;
    
    while(recorrido != nullptr){
        while(anterior->elemento + 1 ==  recorrido->elemento){
            anterior = anterior->siguiente;
            recorrido = recorrido->siguiente;
            if(recorrido == nullptr) return;
        }
        
        for(int i = anterior->elemento + 1; i < recorrido->elemento; i++){
            struct Nodo * nuevoNodo = new struct Nodo;
            nuevoNodo->elemento = i;
            nuevoNodo->siguiente = anterior->siguiente;
    
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = recorrido;
            anterior = nuevoNodo;
            recorrido = nuevoNodo->siguiente;
        }
    }
}