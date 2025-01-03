/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 4 de abril de 2024, 03:48 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Lista.h"
#include "funciones.h"
using namespace std;

void construir(struct Lista & lista) {
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

bool esListaVacia(const struct Lista & lista) {
    return lista.cabeza == nullptr;
}

void insertarAlInicio(struct Lista & lista, int elemento) {

    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = lista.cabeza;

    lista.cabeza = nuevoNodo;
    lista.longitud++;
}

void insertarAlFinal(struct Lista & lista, int elemento) {
    struct Nodo * ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = nullptr;

    if (ultimoNodo == nullptr)
        lista.cabeza = nuevoNodo;
    else
        ultimoNodo->siguiente = nuevoNodo;
    lista.longitud++;
}

void insertarEnOrden(struct Lista & lista, int elemento) {

    struct Nodo * nodoAnterior = obtenerNodoAnterior(lista, elemento);
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = nullptr;

    if (nodoAnterior == nullptr) {
        nuevoNodo->siguiente = lista.cabeza;
        lista.cabeza = nuevoNodo;
        lista.longitud++;
    } else {
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
        lista.longitud++;
    }
}

struct Nodo * obtenerUltimoNodo(const struct Lista & lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

struct Nodo * obtenerNodoAnterior(const struct Lista & lista, int elemento) {

    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = lista.cabeza;

    while ((recorrido != nullptr) and (recorrido->elemento <= elemento)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

void imprime(const struct Lista & lista) {
    if (esListaVacia(lista)) {
        cout << "La lista esta vacía no se puede imprimir";
    } else {
        struct Nodo * recorrido;
        recorrido = lista.cabeza;
        while (recorrido != nullptr) {
            cout << recorrido->elemento << " ";
            recorrido = recorrido->siguiente;
        }
        cout << endl;
    }
}