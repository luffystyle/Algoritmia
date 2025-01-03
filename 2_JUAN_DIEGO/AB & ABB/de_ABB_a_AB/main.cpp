/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de mayo de 2025, 05:05 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
using namespace std;
#include "funcionesABB.h"
#include "funcionesArbolesBinarios.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
void imprimeAmplitudRecursivo(NodoArbol * nodo ){
    if(!esNodoVacio(nodo)){
        if(!esNodoVacio(nodo->izquierda))
            imprimeNodo(nodo->izquierda);
        if(!esNodoVacio(nodo->derecha))
            imprimeNodo(nodo->derecha);
        imprimeAmplitudRecursivo(nodo->izquierda);
        imprimeAmplitudRecursivo(nodo->derecha);
    }   
}

void recorreAmplitud(struct ArbolBinario & arbol){
    if(!esArbolVacio(arbol)){
        imprimeNodo(arbol.raiz);
        imprimeAmplitudRecursivo(arbol.raiz);
    }
}

struct NodoArbol*deABB_AB(NodoArbol * raiz){
    if(raiz==nullptr){
        return nullptr;
    }
    NodoArbol * izq = deABB_AB(raiz->izquierda);
    NodoArbol * der= deABB_AB(raiz->derecha);
    
    NodoArbol * nodo = new NodoArbol;
    nodo->elemento=raiz->elemento;
    nodo->izquierda=izq;
    nodo->derecha=der;
    
    return nodo;
}

int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda abb;
    construir(abb);
    
    insertar(abb,4);
    insertar(abb,2);
    insertar(abb,5);
    insertar(abb,1);
    insertar(abb,3);
    insertar(abb,6);
    
    recorrerPreOrden(abb.arbolBinario);
    
    struct ArbolBinario ab;
    construir(ab);
    
    NodoArbol * nodoAB = deABB_AB(abb.arbolBinario.raiz);
    
    ab.raiz=nodoAB;
    cout<<endl;
    recorrerPreOrden(ab);
    return 0;
}

