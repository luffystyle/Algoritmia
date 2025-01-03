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
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "Cola.h"

void plantarArbolBinarioNew(struct NodoArbol *&raiz,struct NodoArbol *arbIzq,char tipo,int velocidad,struct NodoArbol*arbDer){
    
    struct NodoArbol *nodoNuevo = crearNuevoNodoArbol(arbIzq,tipo,velocidad,arbDer);
    raiz = nodoNuevo;
}

void insertarArbol(struct NodoArbol *&raiz,char tipo,int velocidad){
//    if(raiz == nullptr){
        plantarArbolBinarioNew(raiz,nullptr,tipo,velocidad,nullptr);
//    }else{      
//    }
}


void encontrarSkinerd(struct NodoArbol *raiz,int velocidad,char tipo){
    struct Cola faja;
    construir(faja);
    encolar(faja,raiz);
    int altura = alturaRecursivo(raiz);
//    cout<<endl;
//    imprime(faja);
    while(!esColaVacia(faja)){
        struct NodoArbol *nodoNuevo = desencolar(faja);
        if(nodoNuevo->elemento == velocidad){
            if(nodoNuevo->izquierda->tipo == tipo and nodoNuevo->izquierda->elemento ==velocidad){
                cout << "SkyNerd se encuentra en el nivel: " <<altura-alturaRecursivo(nodoNuevo->izquierda);
                cout<<endl;
                imprimeNodo(nodoNuevo->izquierda);
                break;
            }
            if(nodoNuevo->derecha->tipo==tipo and nodoNuevo->derecha->elemento == velocidad){
                cout << "SkyNerd se encuentra en el nivel: " <<altura-alturaRecursivo(nodoNuevo->derecha);
                cout<<endl;
                imprimeNodo(nodoNuevo->derecha);
                break;
            }
            
        }
        if(nodoNuevo->izquierda!= nullptr){
            encolar(faja,nodoNuevo->izquierda);
        }
        if(nodoNuevo->derecha!= nullptr){
            encolar(faja,nodoNuevo->derecha);
        }
    }
    destruirCola(faja);
}


int main(int argc, char** argv) {
    
    struct ArbolBinario arbol;
    construir(arbol);
    insertarArbol(arbol.raiz,'Z',100);
    insertarArbol(arbol.raiz->izquierda,'Z',50);
    insertarArbol(arbol.raiz->derecha,'E',200);
    insertarArbol(arbol.raiz->izquierda->izquierda,'E',100);
    insertarArbol(arbol.raiz->izquierda->derecha,'S',50);
    insertarArbol(arbol.raiz->izquierda->izquierda->izquierda,'S',50);
    insertarArbol(arbol.raiz->izquierda->izquierda->izquierda->izquierda,'E',50);
    insertarArbol(arbol.raiz->izquierda->izquierda->derecha,'Z',200);
    insertarArbol(arbol.raiz->izquierda->izquierda->derecha->izquierda,'E',100);
    insertarArbol(arbol.raiz->derecha->izquierda,'S',200);
    insertarArbol(arbol.raiz->derecha->izquierda->izquierda,'S',100);
    insertarArbol(arbol.raiz->derecha->izquierda->derecha,'E',200);
    insertarArbol(arbol.raiz->derecha->derecha,'S',150);
    recorrerEnPreOrdenRecursivo(arbol.raiz);
    cout<<endl<<"Altura: "<<altura(arbol);
    cout<<endl<<"Altura del Nodo: "<<alturaRecursivo(arbol.raiz);
    cout<<endl;
    encontrarSkinerd(arbol.raiz,200,'S');
    
    return 0;
}

