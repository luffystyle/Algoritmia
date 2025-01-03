
#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>

#include "Lista.h"
using namespace std;
#include "funcionesLista.h"
#include "masFuncionesLista.h"


void invertirLista(struct Lista &lista) {
    struct Nodo * anterior = nullptr;
    struct Nodo * actual = lista.cabeza;
    struct Nodo * siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente; // Guarda el siguiente nodo
        actual->siguiente = anterior; // Enlaza el nodo actual al nodo anterior

        // Mueve los punteros al siguiente nodo para la siguiente iteración
        anterior = actual;
        actual = siguiente;
    }

    // Al salir del bucle, 'anterior' apuntará al último nodo de la lista original,
    // así que actualizamos la cabeza de la lista para que apunte a este nodo.
    lista.cabeza = anterior;
}
void rotarListaIzquierda(struct Lista &lista) {
    if (esListaVacia(lista) || lista.longitud == 1) {
        // No hay nada que rotar
        return;
    }

    struct Nodo *ultimo = obtenerUltimoNodo(lista);
    struct Nodo *nuevaCabeza = lista.cabeza->siguiente; // el segundo nodo se convierte en la nueva cabeza

    lista.cabeza->siguiente = nullptr; // "desconecta" el enlace del primer nodo

    ultimo->siguiente = lista.cabeza; // el último nodo apunta al primer nodo original
    lista.cabeza = nuevaCabeza; // la nueva cabeza de la lista
}
void intercambiarPares(struct Lista &lista) {
    if (esListaVacia(lista) || lista.longitud == 1) {
        // No hay nada que intercambiar
        return;
    }

    struct Nodo *actual = lista.cabeza;

    // Iterar sobre la lista en pasos de dos nodos
    while (actual != nullptr && actual->siguiente != nullptr) {
        // Intercambiar elementos entre el nodo actual y el siguiente nodo
        int temp = actual->elemento;
        actual->elemento = actual->siguiente->elemento;
        actual->siguiente->elemento = temp;

        // Mover al siguiente par de nodos
        actual = actual->siguiente->siguiente;
    }
}

void eliminarRepetidos(Lista& lista) {
    if (lista.cabeza == nullptr || lista.longitud == 1) {
        // Lista vacía o con un solo elemento, no hay nada que hacer
        return;
    }

    Nodo* actual = lista.cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        Nodo* anterior = actual;
        
        while (siguiente != nullptr) {
            if (siguiente->elemento == actual->elemento) {
                // Eliminar el nodo repetido
                anterior->siguiente = siguiente->siguiente;
                delete siguiente;
                siguiente = anterior->siguiente;
                lista.longitud--;
            } else {
                anterior = siguiente;
                siguiente = siguiente->siguiente;
            }
        }
        actual = actual->siguiente;
    }
}
