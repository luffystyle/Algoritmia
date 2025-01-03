/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */

struct NodoArbol * crearNuevoNodoArbolNuevo(struct NodoArbol * izquierdo, 
                               int elemento,int dato, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->dato=dato;
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->derecha = derecho;
    return nuevoNodo;
}

void plantarArbolBinarioNuevo(struct ArbolBinario & arbol, struct NodoArbol * izquierdo,
                         int elemento,int dato, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNuevo(izquierdo, elemento,dato, derecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinarioNuevo(struct NodoArbol * &raiz, struct NodoArbol * izquierdo,
                         int elemento,int dato, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNuevo(izquierdo, elemento,dato, derecho);
    raiz = nuevoNodo;
}

void insertarValorArbolRecursivo(struct NodoArbol * &raiz, int elemento,int dato){
    if(raiz==nullptr){
        plantarArbolBinarioNuevo(raiz,nullptr,elemento,dato,nullptr);
        return ;
    }
    insertarValorArbolRecursivo(raiz->izquierda,0,dato);
    insertarValorArbolRecursivo(raiz->derecha,1,dato);
}

void insertarValorArbol(struct ArbolBinario & arbol,int dato){
    insertarValorArbolRecursivo(arbol.raiz,0,dato);
}
/*============================================================================*/
//Amplitud
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
/*============================================================================*/
int cantCombinacionesRecursivo(NodoArbol * raiz,int peso,int pesoParcial){
    pesoParcial+=raiz->elemento*raiz->dato;
    if(raiz->izquierda==nullptr and raiz->derecha==nullptr){
        if(pesoParcial==peso)
            return 1;
        return 0;
    }
    return cantCombinacionesRecursivo(raiz->izquierda,peso,pesoParcial)+cantCombinacionesRecursivo(raiz->derecha,peso,pesoParcial);
}

int cantCombinaciones(ArbolBinario cromosoma,int peso){
    int pesoParcial=0;
    return cantCombinacionesRecursivo(cromosoma.raiz,peso,pesoParcial);
}


int main(int argc, char** argv) {

    int cantidad=5;
    int arr[cantidad]={10,50,20,30,40};
    
    struct ArbolBinario cromosoma;
    construir(cromosoma);
    
    //pantar la raiz del cromosoma
    
    plantarArbolBinarioNuevo(cromosoma,nullptr,0,0,nullptr);
    for(int i=0;i<cantidad;i++){
        insertarValorArbol(cromosoma,arr[i]);
    }
    recorreAmplitud(cromosoma);
    int peso = 70;
    cout<<endl<<"Cantidad de combinaciones: "<<cantCombinaciones(cromosoma,peso);
    
    return 0;
}

