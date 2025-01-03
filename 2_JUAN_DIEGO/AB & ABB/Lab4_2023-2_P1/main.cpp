/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de mayo de 2025, 05:05 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "Lista.h"
#include "Cola.h"
using namespace std;
#include "funcionesABB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#include "Nodo.h"

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
 void plantarArbolBBnew(struct NodoArbol *& nodo, struct NodoArbol * arbolIzquierdo,
         int elemento, struct NodoArbol * arbolDerecha){
     
     struct NodoArbol * nuevoNodo = new struct NodoArbol;
     nuevoNodo->derecha = arbolDerecha;
     nuevoNodo->elemento = elemento;
     nuevoNodo->izquierda = arbolIzquierdo;
     nodo = nuevoNodo;
 }
 int buscaMayor(NodoArbol *&nodo){
     if(nodo->derecha==nullptr){
         return nodo->elemento;
     }
     buscaMayor(nodo->derecha);
 }
void insertarRecursivoNew(NodoArbol * &nodo, int elemento,ArbolBinarioBusqueda & arbol){
    if(buscaArbol(arbol,elemento)){
        int mayor=buscaMayor(arbol.arbolBinario.raiz);
        elemento+=mayor;
    }
    if(esNodoVacio(nodo))
         plantarArbolBBnew(nodo, nullptr, elemento, nullptr);
     else
         if(elemento > nodo->elemento)
             insertarRecursivoNew(nodo->derecha, elemento,arbol);
         else
             if(elemento < nodo->elemento)
                 insertarRecursivoNew(nodo->izquierda, elemento,arbol);
}

void insertarNew(ArbolBinarioBusqueda & arbol,int elemento){
    insertarRecursivoNew(arbol.arbolBinario.raiz, elemento,arbol);
}
void llenarEnOrden(NodoArbol * nodo,Cola & cola){
    if(not esNodoVacio(nodo)){
        llenarEnOrden(nodo->izquierda,cola);
        encolar(cola,nodo);
        llenarEnOrden(nodo->derecha,cola);
    }
}
NodoArbol * abbBalanced(Cola & cola,int n){
    if(n<=0)return nullptr;
    NodoArbol * izq = abbBalanced(cola,n/2);
    NodoArbol * raiz = cola.lista.cabeza->nodo;
    desencolar(cola);
    raiz->izquierda=izq;
    raiz->derecha=abbBalanced(cola,n-n/2-1);
    return raiz;
}

NodoArbol * balanceoABB(NodoArbol * raiz){
    if(raiz==nullptr)return nullptr;
    Cola cola;
    construir(cola);
    llenarEnOrden(raiz,cola);
    int cantNodos = numeroNodosRecursivo(raiz);
    return abbBalanced(cola,cantNodos);
}
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    insertarNew(arbol,3);
    insertarNew(arbol,5);
    insertarNew(arbol,2);
    insertarNew(arbol,1);
    insertarNew(arbol,3);
    insertarNew(arbol,5);
    insertarNew(arbol,4);
    insertarNew(arbol,5);
    enOrden(arbol);
    cout<<endl;
    recorrerPostOrden(arbol.arbolBinario);
    cout<<endl;
    if(esEquilibrado(arbol.arbolBinario)){
        cout<<"Es equilibrado."<<endl;
    }else{
        cout<<"No es equilibrado."<<endl;
    }
    //Balanceo
    arbol.arbolBinario.raiz=balanceoABB(arbol.arbolBinario.raiz);
    
    cout<<endl;
    if(esEquilibradoRecursivo(arbol.arbolBinario.raiz)){
        cout<<"Es equilibrado."<<endl;
    }else{
        cout<<"No es equilibrado."<<endl;
    }
    recorrerEnPreOrdenRecursivo(arbol.arbolBinario.raiz); 
    cout<<endl;
    recorrerPostOrden(arbol.arbolBinario);
    
    return 0;
}

//    struct ArbolBinarioBusqueda arbol;
//
//    construir(arbol);
//
//    insertar(arbol, 100);
//    insertar(arbol, 50);
//    insertar(arbol, 200);
//    insertar(arbol, 30);
//    insertar(arbol, 75);
//    insertar(arbol, 201);
//    insertar(arbol, 1500);
//    insertar(arbol, 150);
//    enOrden(arbol);
//    cout << endl;
//    cout <<"Se encuentra 201 en el árbol: "<<buscaArbol(arbol, 201)<<endl;
//    eliminarNodo(arbol, 100);
//    cout <<"Se encuentra 100 en el árbol: "<<buscaArbol(arbol, 100)<<endl;
//    enOrden(arbol);
//    
//    destruirArbolBB(arbol);