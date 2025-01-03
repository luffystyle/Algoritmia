/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cmath>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "Cola.h"
#include "Lista.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
void recorreAmplitud(ArbolBinario & arbol){
    struct Cola cola;
    construir (cola);
    if(!esArbolVacio(arbol)){
        encolar(cola,arbol.raiz);
        while(!esColaVacia(cola)){
            NodoArbol * nodo = desencolar(cola);
            imprimeNodo(nodo);
            if(nodo->izquierda!=nullptr){
                encolar(cola,nodo->izquierda);
            }
            if(nodo->derecha!=nullptr){
                encolar(cola,nodo->derecha);
            }
        }
    }
    cout<<endl;
    destruirCola(cola);
}


int validar(ArbolBinario & arbol,int grupo){
    struct Cola cola;
    int cont=0;
    int maxNodos=pow(2,grupo-1);
    construir (cola);
    if(!esArbolVacio(arbol)){
        encolar(cola,arbol.raiz);
        while(!esColaVacia(cola)){
            NodoArbol * nodo = desencolar(cola);
            int g = nodo->elemento/10000;
            if(g==grupo){
                cont++;
            }
            if(nodo->izquierda!=nullptr){
                encolar(cola,nodo->izquierda);
            }
            if(nodo->derecha!=nullptr){
                encolar(cola,nodo->derecha);
            }
        }
    }
    if(cont<maxNodos){
        return 1;
    }else{
        return 0;
    }
    cout<<endl;
    destruirCola(cola);    
}
int validarABB(NodoArbol * raiz){
    if(raiz==nullptr){
        return 1;        
    }
    if(raiz->izquierda!=nullptr && raiz->izquierda->elemento%100 > raiz->elemento%100){
        return 0;
    }
    if(raiz->derecha!=nullptr && raiz->derecha->elemento%100 < raiz->elemento%100){
        return 0;
    }
    return validarABB(raiz->izquierda) && validarABB(raiz->derecha);
    
}
int actualizar(NodoArbol*&raiz,int codigo,int codigoUpdt){
    NodoArbol * nodo = raiz;
    if(raiz==nullptr)return 0;
    if(nodo->elemento%100 == codigo){
        nodo->elemento=(nodo->elemento-codigo)+codigoUpdt;
        if(validarABB(raiz)){
            return 1;
        }else{
            return 0;
        }
    }else if(nodo->elemento%100 > codigo){
       return actualizar(nodo->izquierda,codigo,codigoUpdt);
    }else{
       return actualizar(nodo->derecha,codigo,codigoUpdt);
    }
}
int main(int argc, char** argv) {    

    struct ArbolBinarioBusqueda arbol;    
    construir(arbol);
    
    insertar(arbol,10010);
    insertar(arbol,20005);
    insertar(arbol,20020);
    insertar(arbol,30002);
    insertar(arbol,30006);    
    insertar(arbol,30021);
    
//    recorreAmplitud(arbol.arbolBinario);
    recorrerEnOrden(arbol.arbolBinario);
    //Validar Si se pueden ingresar un grupo de productos
    int grupo=3;
    int valido=validar(arbol.arbolBinario,grupo);//La funcion levara el arbol y 
                                                 // el grupo que se desea insertar
    if(valido){
        cout<<endl<<"Si es posible insertar.";
    }else{
        cout<<endl<<"No es posible insertar.";
    }
    int codigo=5;//10
    int codigoUpdt=7;//17
    if(actualizar(arbol.arbolBinario.raiz,codigo,codigoUpdt)){
        cout<<endl<<"Si es posible actualizar.";
    }else{
        cout<<endl<<"No es posible actualizar.";
    }
      
    return 0;
}

