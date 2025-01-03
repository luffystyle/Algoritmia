/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de mayo de 2025, 05:05 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "Pila.h"
using namespace std;
#include "funcionesABB.h"
#include "funcionesPila.h"
#include "funcionesArbolesBinarios.h"

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */

void despacha(ArbolBinarioBusqueda & almacen,int num,Pila & pila){    
    NodoArbol * nodo = almacen.arbolBinario.raiz;
    while(longitud(pila)!=num){
        nodo = almacen.arbolBinario.raiz;
        while(!esHoja(nodo) && nodo->izquierda!=nullptr){
            nodo=nodo->izquierda;
            if(nodo->izquierda==nullptr and nodo->derecha!=nullptr){
                nodo=nodo->derecha;
            }                        
        }        
        apilar(pila,nodo->elemento);
        eliminarNodo(almacen,nodo->elemento);
    }
    cout<<"Los lotes a despachar seran: ";
    imprimir(pila);
}


int main(int argc, char** argv) {
    struct Pila pila;
    construir(pila);
    int numLotes;
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    insertar(arbol,1008);
    insertar(arbol,910);
    insertar(arbol,1520);
    insertar(arbol,610);
    insertar(arbol,1210);
    insertar(arbol,1810);
    insertar(arbol,520);
    insertar(arbol,820);
    
    recorrerPreOrden(arbol.arbolBinario);
    
    cout<<endl<<"Ingrese la cantidad de lotes a despachar: ";
    cin>>numLotes;
    
    despacha(arbol,numLotes,pila);
    cout<<"El almacen quedara de la siguiente forma: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    cout<<"En caso no proceda el despacho, se devolveran los lotes"<<endl;
    for(int i=0;i<numLotes;i++){
        insertar(arbol,desapilar(pila));
    }
    cout<<"El almacen cuando los lotes hayan sido devueltos: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;   
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