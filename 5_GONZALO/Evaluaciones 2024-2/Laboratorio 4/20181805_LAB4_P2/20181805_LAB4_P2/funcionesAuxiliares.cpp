/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "ArbolBB.h"
#include "funcionesPila.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"

using namespace std;

void ingresarLote(struct ArbolBinarioBusqueda & arbol, int anioLote, int cantidadLote){
    struct Lote lote;
    lote.anio = anioLote;
    lote.cantidad = cantidadLote;
    ingresarLoteRecursivo(arbol.arbolBinario.raiz, lote);
}

void ingresarLoteRecursivo(struct NodoArbol * nodo, struct Lote lote){
    if (not buscarRecursivo(nodo, lote.anio)){
        insertarRecursivo(nodo, lote);
    } else {
        struct NodoArbol * nodoLote = buscarLote(nodo, lote);
        nodoLote->elemento.cantidad += lote.cantidad;
    }
}

struct NodoArbol * buscarLote(struct NodoArbol * nodo, struct Lote lote){
    if (nodo->elemento.anio==lote.anio){
        return nodo;
    } else if (nodo->elemento.anio>lote.anio){
        return buscarLote(nodo->izquierda, lote);
    } else {
        return buscarLote(nodo->derecha, lote);
    }
}

void reporteStock(const struct ArbolBinarioBusqueda & arbol){
    struct Pila pila;
    construir(pila);
    int fin = 0;
    struct NodoArbol * nodo = arbol.arbolBinario.raiz;
    do {
        while (not esNodoVacio(nodo)){
            apilar(pila, nodo->elemento);
            nodo = nodo->derecha;
        }
        if (esPilaVacia(pila)) fin = 1;
        else {
            struct Lote elemento = desapilar(pila);
            //struct NodoArbol * nodoLote = buscarIterativo(arbol, lote);
            //nodo = nodo->izquierda;
        }
    } while (fin == 0);
    destruirPila(pila);
}