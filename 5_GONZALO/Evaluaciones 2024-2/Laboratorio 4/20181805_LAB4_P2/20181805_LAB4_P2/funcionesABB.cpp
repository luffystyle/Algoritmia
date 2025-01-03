/* 
 * File:   funcionesABB.cpp
 * Author: ANA RONCAL
 * 
 * Created on 13 de noviembre de 2024, 13:50
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

using namespace std;

void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
}

void insertar(struct ArbolBinarioBusqueda & arbol, struct Lote elemento){
    insertarRecursivo(arbol.arbolBinario.raiz, elemento);
}

void insertarRecursivo(struct NodoArbol *& raiz, struct Lote elemento){
    if(esNodoVacio(raiz))
        plantarArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.anio > elemento.anio)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.anio < elemento.anio)
                insertarRecursivo(raiz->derecha, elemento);
            else
                cout << "El elemento " << elemento.anio << "Ya se encuentra en el arbol" << endl;
}

void enOrden(const struct ArbolBinarioBusqueda & arbol){
    recorrerEnOrden(arbol.arbolBinario);
}

bool buscar(const struct ArbolBinarioBusqueda & arbol, int dato){
    return buscarRecursivo(arbol.arbolBinario.raiz, dato);
}

bool buscarRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo))
        return false;
    if(comparaABB(nodo->elemento.anio, dato) == 0)
        return true;
    if(comparaABB(nodo->elemento.anio, dato) == 1)
        return buscarRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento.anio, dato) == -1)
            return buscarRecursivo(nodo->derecha, dato);
}

int comparaABB(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if(elementoA > elementoB) return 1;
}

void eliminar(struct ArbolBinarioBusqueda & arbol, int dato){
    arbol.arbolBinario.raiz = eliminarRecursivo(arbol.arbolBinario.raiz, dato);
}

struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, int elemento){
    if(esNodoVacio(nodo))
        return nodo;
    //buscamos el nodo a eliminar
    if(nodo->elemento.anio > elemento)
        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
    else
        if(nodo->elemento.anio < elemento)
            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
        else
            /*encontró el elemento*/
            if(esNodoVacio(nodo->izquierda)){
                struct NodoArbol * hijo = nodo->derecha;
                delete nodo;
                return hijo;
            }
            else
                if(esNodoVacio(nodo->derecha)){
                    struct NodoArbol * hijo = nodo->izquierda;
                    delete nodo;
                    return hijo;
                }
                else{
                    /* dos hijos*/
                    struct NodoArbol * minNodo = minimoArbol(nodo->derecha);
                    nodo->elemento = minNodo->elemento;
                    nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento.anio);
                }
                    
    return nodo;           
    
}

struct NodoArbol * minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}