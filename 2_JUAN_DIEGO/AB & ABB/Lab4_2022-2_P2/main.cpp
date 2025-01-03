/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cmath>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "NodoArbol.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
void fusionarRecursivo(struct NodoArbol*nodo1,struct NodoArbol*nodo2){
    
    int valor,cantidad;
    struct NodoArbol*nodoAux;
    nodoAux=nodo2;
    
    if(nodoAux){
        fusionarRecursivo(nodo1,nodoAux->izquierda);
        fusionarRecursivo(nodo1,nodoAux->derecha);
        
        valor=nodoAux->elemento;
        cantidad=nodoAux->dato;
        delete nodoAux;
        
        struct NodoArbol * nodoExiste;
        nodoExiste = buscaArbolRecursivo(nodo1,valor);
        
        if(nodoExiste){
            nodoExiste->dato+=cantidad;
        }else{
            insertarRecursivo(nodo1,valor,cantidad);
        }
        nodo2=NULL;
    }    
}

void fusionarArboles(struct ArbolBinarioBusqueda *arbol1,struct ArbolBinarioBusqueda *arbol2){
    fusionarRecursivo(arbol1->arbolBinario.raiz,arbol2->arbolBinario.raiz);
    arbol2->arbolBinario.raiz=NULL;
    
}
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbolDest, arbolEm;
    
    construir(arbolDest);
    construir(arbolEm);
    
    /*Insertamos los elementos en el arbol destino*/
    cout<<"Arbol destino inicial: "<<endl;
    insertar(arbolDest,20170620,20);
    insertar(arbolDest,20170810,20);
    insertar(arbolDest,20180211,20);
    insertar(arbolDest,20180409,10);    
    enOrden(arbolDest);
    /*Insertamos los elementos en el arbol emisor*/
    cout<<endl<<"Arbol emisor: "<<endl;
    insertar(arbolEm,20170811,5);
    insertar(arbolEm,20180211,10);
    insertar(arbolEm,20180410,15);
    enOrden(arbolEm);
    

    cout<<endl<<"Arbol fusionado: "<<endl;
    fusionarArboles(&arbolDest,&arbolEm);
    enOrden(arbolDest);
    
    return 0;
}

//    struct ArbolBinarioBusqueda arbol;
//    int auxiliarElemento;
//    
//    construir(arbol);
//    insertar(arbol, 100);
//    insertar(arbol, 50);
//    insertar(arbol, 150);
//    insertar(arbol, 125);
//    insertar(arbol, 175);
//    insertar(arbol, 200);
//    insertar(arbol, 25);
//    insertar(arbol, 75);
//    
//   
//    preOrden(arbol); cout<<endl;
//    enOrden(arbol);  cout<<endl;
//    postOrden(arbol); cout<<endl;
//    cout<<"Se encuentra 125 en árbol: "<<buscaArbol(arbol, 125)<<endl;
//     
//    eliminarNodo(arbol, 125);
//    enOrden(arbol);   cout<<endl;
//      
//    auxiliarElemento = minimoNodoABB(arbol);
//    cout<<"Mínimo ABB: "<<auxiliarElemento<<endl;
//    //LISTO
//    auxiliarElemento = maximoNodoABB(arbol);
//    cout<<"Máximo ABB: "<<auxiliarElemento<<endl;
//        
//    cout<<"Sumar nodos: "<<sumarNodos(arbol)<<endl;
//    
//    destruirArbolBB(arbol);