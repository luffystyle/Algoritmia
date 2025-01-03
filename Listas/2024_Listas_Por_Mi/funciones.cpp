

#include <iostream> 
using namespace std;
#include "funciones.h"
#include "Nodo.h"
#include "Lista.h"


//Inicializo la lista
void construir(struct Lista &tad) {
    tad.cabeza = nullptr;
    tad.longitud = 0;
}


const bool esListaVacia(const struct Lista &tad) {
    if(tad.cabeza == nullptr) return true;
    else return false;
}

int longitud( struct Lista &tad) {
    return tad.longitud;
}

void insertarAlInicio (struct Lista &tad, int elemento) {
    // el *nuevoNodo es un puntero; por eso, en la línea lista.cabeza le asignamos
    struct Nodo *nuevoNodo = new struct Nodo; // creamos un nuevo nodo de manera dinámica
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = tad.cabeza;// se la doy antes de cambiarselo
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

struct Nodo* obtenerUltimoNodo(const struct Lista &tad) {
    struct Nodo *nuevoNodo = new struct Nodo;
    
    nuevoNodo = tad.cabeza;
    while( true ){
        if(nuevoNodo->siguiente == nullptr) return nuevoNodo;
        nuevoNodo = nuevoNodo->siguiente;
    }       
    return nuevoNodo;
}


void insertarAlFinal(struct Lista &tad, int elemento) {
    
    struct Nodo *nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = nullptr;
    
    if(esListaVacia(tad)) {
        tad.cabeza = nuevoNodo;
    } else {
        struct Nodo *ultimoNodo = obtenerUltimoNodo(tad);
        ultimoNodo->siguiente = nuevoNodo;
    }    
    tad.longitud++;
}

struct Nodo* obtenerNodoAnterior(const struct Lista &tad, int elemento) {
    
    struct Nodo *nodo = new struct Nodo;
    struct Nodo *nodoAnterior = new struct Nodo;
    
    if(esListaVacia(tad)) {
        cout << "No existe nodo anterior" << endl;
    } else { // voy a recorrer todo la lista
        nodo = tad.cabeza;
        nodoAnterior = nullptr;
        while(nodo != nullptr) {
            if(nodo->elemento == elemento) return nodoAnterior;
            nodoAnterior = nodo;
            nodo = nodo->siguiente;
        }
        return nullptr;
    }
}

void destruir(struct Lista &tad) {
    
    struct Nodo *nodo = new struct Nodo;
    
    nodo = tad.cabeza;
    while(nodo != nullptr) { // sea diferente de lista Vacia
        struct Nodo *auxNodo = nodo;
        nodo = nodo->siguiente;
        delete auxNodo;
    }
    tad.cabeza = nullptr;
    tad.longitud = 0; 
}



void eliminaNodo(struct Lista &tad, int elemento){

    struct Nodo *nodo = new struct Nodo;
    struct Nodo *nodoAnterior = new struct Nodo;
    
    if(esListaVacia(tad)) {
        cout << "La lista está vacía. No se puede eliminar." << endl;
    } else {
        nodo = tad.cabeza;
        nodoAnterior = obtenerNodoAnterior(tad, elemento);
        while(nodo != nullptr) {
            if(nodo->elemento == elemento){
                nodoAnterior->siguiente = nodo->siguiente;
                delete nodo; 
                break;
            }   
            nodoAnterior = nodo;
            nodo = nodo->siguiente;
        }
        tad.longitud--;
    }  
}




void eliminaCabeza(struct Lista &tad) {
    struct Nodo *nodo = tad.cabeza;
    
    if(nodo != nullptr) { // si tuviera estuviera vacío, el nodo sería nullptr; por eso, no entraría al if
        tad.cabeza = nodo->siguiente;
        delete nodo;
        tad.longitud--;
    }
    
}


void imprime(const struct Lista &tad) {
    struct Nodo *nodo; // en realidad, no un nodo en sí, sino un puntero para ir recorriendo la lista
    if(esListaVacia(tad)) {
        cout << "La lista está vacía " << endl;
    } else {
        nodo = tad.cabeza;
        //no solemos usar un for porque no avanzamos por número, sino avanzamos por p.siguiente
        while( nodo != nullptr) {
            cout << "Elemento: " << nodo->elemento << " ";
            nodo = nodo->siguiente;
        }
        cout << endl;
    }
}
 



