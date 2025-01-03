/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "Cola.h"


struct NodoArbol*encontrarMiniNodo(struct NodoArbol *nodo){
    while(nodo->izquierda !=nullptr){
        nodo = nodo->izquierda;
    }
    return nodo;
}


void despachar(struct NodoArbol* raiz,int cant){
    if (cant == 0 )return;
    if(esNodoVacio(raiz)) return;
    NodoArbol *parbol ;
    parbol = encontrarMiniNodo(raiz);
    if(parbol->elemento.cantidad <= cant){
        int falta = cant - parbol->elemento.cantidad;
        raiz = eliminarNodoRecursivo(raiz,parbol->elemento.codigo);
        despachar(raiz,falta);
    }else{
        parbol->elemento.cantidad -=cant;
    }
    
    
}

void recorrePorAmplitud(struct ArbolBinario arbol){
//    if(raiz==nullptr){
//        return;
//    }
    struct Cola cola;
    construir(cola);
    encolar(cola,arbol.raiz);
    NodoArbol *parbol;
    while(!esColaVacia(cola)){
        parbol = desencolar(cola);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->izquierda)){
            encolar(cola,parbol->izquierda);
        }
        if(!esNodoVacio(parbol->derecha)){
            encolar(cola,parbol->derecha);
        }
        
    }
    
    
}


int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    insertar(arbol,{20180211,20});
    //imprimeNodo(arbol.arbolBinario.raiz);
    insertar(arbol,{20170810,20});
    insertar(arbol,{20170620,20});
    insertar(arbol,{20180409,10});
    preOrden(arbol);
    cout<<endl;recorrePorAmplitud(arbol.arbolBinario);
    despachar(arbol.arbolBinario.raiz,35);
    cout<<endl;preOrden(arbol);
    
    struct ArbolBinario arbol2;
    construir(arbol2);
    
    
    
    
    return 0;
}

