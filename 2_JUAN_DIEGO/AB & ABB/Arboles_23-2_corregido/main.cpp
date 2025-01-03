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
#define MAX 10

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
int recorrido[MAX]={};
int i=0;

struct NodoArbol* ancestroComun(int p,int q,NodoArbol * raiz){
    if(!raiz)return nullptr;    
    //si los nodos se encuntran a la derecha del nodo actual
    if(raiz->elemento < p and raiz->elemento < q){
        recorrido[i]=1;
        i++;
        return ancestroComun(p,q,raiz->derecha);
    }
    //si los nodos se encuentran a la izquierda del nodo actual
    if(raiz->elemento>p and raiz->elemento>q){
        recorrido[i]=0;
        i++;
        return ancestroComun(p,q,raiz->izquierda);
    }
    //si uno de los nodos esta a la derecha y el otro hacia la isquierda solo retornamos
    return raiz;
}
NodoArbol * encontNodo(NodoArbol*raiz){
    for(int j=0;j<i;j++){
        if(recorrido[j]==0){
            raiz=raiz->izquierda;
        }else{
            raiz=raiz->derecha;
        }
    }
    return raiz;
}

void sumaNodos(NodoArbol*nodo1,NodoArbol*nodo2){
    //el nodo 2 se sumara al nodo 1
    if(nodo2==nullptr)return;
    nodo1->elemento=nodo1->elemento+nodo2->elemento;
    sumaNodos(nodo1->izquierda,nodo2->izquierda);
    sumaNodos(nodo1->derecha,nodo2->derecha);    
}
int valido(NodoArbol * raiz){
    if(raiz==nullptr){
        return 1;
    }
    if(raiz->izquierda!=nullptr and raiz->izquierda->elemento > raiz->elemento){
        return 0;
    }
    if(raiz->derecha!=nullptr and raiz->derecha->elemento < raiz->elemento){
        return 0;
    }    
    return valido(raiz->izquierda) && valido(raiz->derecha);
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

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda token;
    construir(token);
    
    insertar(token,5);
    insertar(token,2);
    insertar(token,12);
    insertar(token,1);
    insertar(token,18);
    insertar(token,3);
    insertar(token,8);
    insertar(token,4);
    
    recorrerPreOrden(token.arbolBinario);
    
    int p=1,q=4;    
    
    NodoArbol * ancestro = ancestroComun(p,q,token.arbolBinario.raiz);
    cout<<endl;
    recorrerEnOrdenRecursivo(ancestro);
    cout<<endl<<"El primer ancestro comun de "<<p <<" y "<<q<<" sera: "<<ancestro->elemento<<endl;
    for(int j=0;j<i;j++){
        cout<<recorrido[j];
    }
    cout<<endl;
    
    /*===========================================*/
    /*Plantamos el arbol sistema puede ser un AB*/
    /*===========================================*/
    struct ArbolBinario sistema1,sistema2;
    construir(sistema1);
    construir(sistema2);    
    
    //Arbol sistema 1
    ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5,arbol6;
    plantarArbolBinario(arbol1,nullptr,2,nullptr);
    plantarArbolBinario(arbol2,nullptr,1,arbol1);
    plantarArbolBinario(arbol3,nullptr,7,nullptr);
    plantarArbolBinario(arbol4,nullptr,6,arbol3);
    plantarArbolBinario(arbol5,nullptr,4,nullptr);
    plantarArbolBinario(arbol6,arbol5,5,arbol4);
    plantarArbolBinario(sistema1,arbol2,3,arbol6);    
    recorrerEnOrden(sistema1);
    cout<<endl;
    recorreAmplitud(sistema1);
    cout<<endl;
    //Arbol sistema 2
    ArbolBinario ab1,ab2,ab3,ab4,ab5,ab6,ab7;
    plantarArbolBinario(ab1,nullptr,-3,nullptr);
    plantarArbolBinario(ab2,nullptr,0,nullptr);
    plantarArbolBinario(ab3,nullptr,-1,ab2);
    plantarArbolBinario(ab4,ab1,-2,ab3);
    plantarArbolBinario(ab5,nullptr,5,nullptr);
    plantarArbolBinario(ab6,nullptr,7,nullptr);
    plantarArbolBinario(ab7,ab5,6,ab6);
    plantarArbolBinario(sistema2,ab4,4,ab7);
    recorrerEnOrden(sistema2);
    NodoArbol * node1=encontNodo(sistema1.raiz);
    cout<<endl;
    NodoArbol * node2=encontNodo(sistema2.raiz);
    cout<<endl;
    recorrerEnOrdenRecursivo(node1);
    cout<<endl;
    recorrerEnOrdenRecursivo(node2);
    cout<<endl;
    //sumamos los nodos///
    sumaNodos(ancestro,node1);
    cout<<endl;    
    recorrerEnOrdenRecursivo(ancestro);
    cout<<endl;
    recorrerEnOrden(token.arbolBinario);
    cout<<endl;
    if(valido(token.arbolBinario.raiz)){
        cout<<"Verdadero."<<endl;
    }else{
        cout<<"Falso."<<endl;
    }

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
   