/* 
 * File:   funcionesListaDoble.cpp
 * Author: ANA RONCAL
 * Created on 27 de agosto de 2023, 02:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Lista.h"
using namespace std;
#include "funcionesListaDoble.h"

void construir(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

bool esListaVacia(struct Lista tad){
    return tad.cabeza == nullptr;
}

struct Nodo *crearNuevoNodo(int elemento, struct Nodo * anterior, struct Nodo * siguiente){
    struct Nodo * nuevoNodo = new Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->anterior = anterior;   
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}

void insertarAlInicio(struct Lista & tad, int elemento){
    struct Nodo * nuevoNodo = crearNuevoNodo(elemento, nullptr, tad.cabeza);
    if (tad.cabeza != nullptr)
        tad.cabeza->anterior = nuevoNodo;
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

int longitud(struct Lista tad ){
    return tad.longitud;
}

struct Nodo * obtenerUltimoNodo(struct Lista tad){
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

/*imprime desde la cola de la lista */
void imprimeDesdeFinal(const struct Lista & tad){
    struct Nodo * recorrido = obtenerUltimoNodo(tad);
    int estaImprimiendoLaCola = 1;
    cout<<"[";
    
    while(recorrido != nullptr){
        if (!estaImprimiendoLaCola)
            cout<<", ";
        estaImprimiendoLaCola=0;
        cout<<recorrido->elemento;        
        recorrido = recorrido->anterior;
    }
    cout<<"]"<<endl;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/
/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad){
    cout<<fixed;   
    cout<<setprecision(2); 
    if (esListaVacia(tad)){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";

        while(recorrido != nullptr){
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            cout<<recorrido->elemento;        
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}