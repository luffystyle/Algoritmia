#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"
#include "masFunciones.h"

void invertirLista(struct Lista &l1){
    struct Nodo *siguiente=nullptr;
    struct Nodo *actual = l1.cabeza;
    struct Nodo *anterior = nullptr;
    
    while ((actual != nullptr)) {
        siguiente = actual->siguiente;
        actual->siguiente= anterior ;
        
        anterior = actual;
        actual = siguiente;
    }
    l1.cabeza=anterior;
    
}

void rotarNodoIzquierdaFila(struct Lista &l1){
    struct Nodo* ultimo = obtenerUltimoNodo(l1);
    struct Nodo* recorrido =l1.cabeza->siguiente ;
    l1.cabeza->siguiente=nullptr;
    ultimo->siguiente=l1.cabeza;
    l1.cabeza=recorrido;
}


void intercambiarElementos(struct Lista &l1){
    struct Nodo* recorrido = l1.cabeza;
    if(esListaVacia(l1) || l1.longitud ==1){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    
    while(recorrido != nullptr and recorrido->siguiente !=nullptr){
        int aux= recorrido->elemento;
        recorrido->elemento = recorrido->siguiente->elemento;
        recorrido->siguiente->elemento=aux;
        
        recorrido = recorrido->siguiente;
    }

    
}

void eliminarRepetidos(struct Lista &l1){
    struct Nodo * recorrido = l1.cabeza;
    
    if(esListaVacia(l1) || l1.longitud==1){
        return;
    }
    while( recorrido!=nullptr){
        struct Nodo *anterior = recorrido; 
        struct Nodo * siguiente= recorrido->siguiente;
        
        while(siguiente!=nullptr){
            int element= siguiente->elemento;
            if(recorrido->elemento == element){
                anterior->siguiente =siguiente->siguiente;
                delete siguiente;
                siguiente = anterior->siguiente;
                l1.longitud--;
            }else{
                anterior = siguiente;
                siguiente = siguiente->siguiente;
            }
        }
        
        recorrido = recorrido->siguiente;
    }
    
    
    
}