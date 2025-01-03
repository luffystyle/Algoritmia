/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"

using namespace std;

void definirContrasenha(struct ArbolBinarioBusqueda & arbol){
    struct Elemento elemento;
    
    elemento.posicion = 4;
    elemento.caracter = 'P';
    insertar(arbol, elemento);
    
    elemento.posicion = 2;
    elemento.caracter = 'U';
    insertar(arbol, elemento);
    
    elemento.posicion = 6;
    elemento.caracter = '0';
    insertar(arbol, elemento);
    
    elemento.posicion = 1;
    elemento.caracter = 'P';
    insertar(arbol, elemento);
    
    elemento.posicion = 3;
    elemento.caracter = 'C';
    insertar(arbol, elemento);
    
    elemento.posicion = 5;
    elemento.caracter = '2';
    insertar(arbol, elemento);
    
    elemento.posicion = 7;
    elemento.caracter = '2';
    insertar(arbol, elemento);
    
    elemento.posicion = 8;
    elemento.caracter = '4';
    insertar(arbol, elemento);
}

int longitudContrasenha(const struct ArbolBinarioBusqueda & arbol){
    return numeroNodos(arbol.arbolBinario);
}

bool buscarCaracterIngresado(const struct ArbolBinarioBusqueda & arbol, char caracter, int posicion){
    struct Elemento elemento;
    elemento.caracter = caracter;
    elemento.posicion = posicion;
    return buscarCaracter(arbol, elemento);
}

bool buscarCaracter(const struct ArbolBinarioBusqueda & arbol, struct Elemento elemento){
    return buscarCaracterRecursivo(arbol.arbolBinario.raiz, elemento);
}

bool buscarCaracterRecursivo(struct NodoArbol * nodo, struct Elemento elemento){
    if(esNodoVacio(nodo))
        return false;
    if(comparaABB(nodo->elemento.posicion, elemento.posicion) == 0){
        if (nodo->elemento.caracter == elemento.caracter){
            return true;
        } else {
            return false;
        }
    }
    if(comparaABB(nodo->elemento.posicion, elemento.posicion) == 1)
        return buscarCaracterRecursivo(nodo->izquierda, elemento);
    else
        if(comparaABB(nodo->elemento.posicion, elemento.posicion) == -1)
            return buscarCaracterRecursivo(nodo->derecha, elemento);
}