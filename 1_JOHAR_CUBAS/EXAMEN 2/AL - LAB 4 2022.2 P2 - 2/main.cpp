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


struct NodoArbol *NodoEliminar(struct NodoArbol *raiz , int dato){
    
    
    
}

struct NodoArbol *eliminarNoditos(struct NodoArbol *raiz, int dato) {
    if (raiz == nullptr) {
        return nullptr;
    }
    if (dato < raiz->elemento) {
        raiz->izquierda = eliminarNoditos(raiz->izquierda, dato);
    } else if (dato > raiz->elemento) {
        raiz->derecha = eliminarNoditos(raiz->derecha, dato);
    } else {
        if (raiz->izquierda == nullptr) {
            NodoArbol *hijo = raiz->derecha;
            delete raiz;
            return hijo;
        } else if (raiz->derecha == nullptr) {
            NodoArbol *hijo = raiz->izquierda;
            delete raiz;
            return hijo;
        } else {
            NodoArbol *nodo = minimoArbol(raiz->derecha);
            raiz->elemento = nodo->elemento;
            raiz->cantidad = nodo->cantidad;
            raiz->derecha = eliminarNoditos(raiz->derecha, nodo->elemento);
        }
    }
    return raiz;
}

struct NodoArbol* encuentraArbol(struct NodoArbol *nodo,int dato){
    if(esNodoVacio(nodo)){
        return nullptr;
    }else{
        if(dato == nodo->elemento){
            return nodo;
        }else{
            if(dato < nodo->elemento){
                nodo = nodo->izquierda;
            }else{
                nodo = nodo->derecha;
            }
            return encuentraArbol(nodo,dato);
        }
        
    }
    
}

//                                                          //SI QUIERO ELIMINAR UN NODO MIENTRAS RECORRRO TENGO QUE PONER UN "&"
void fusionarAlmacenes(struct ArbolBinarioBusqueda &destino,struct NodoArbol *&raiz_emisor){
    if(esNodoVacio(raiz_emisor)){
        return;
    }
    fusionarAlmacenes(destino,raiz_emisor->izquierda);
    
    fusionarAlmacenes(destino,raiz_emisor->derecha);
    NodoArbol *parbol = encuentraArbol(destino.arbolBinario.raiz,raiz_emisor->elemento);
    
    if(parbol != nullptr){
        parbol->cantidad += raiz_emisor->cantidad; 
    }else{
        insertar(destino,raiz_emisor->elemento,raiz_emisor->cantidad);
    }
    int elemento = raiz_emisor->elemento;
    raiz_emisor = eliminarNoditos(raiz_emisor, elemento);
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda destino;
    struct ArbolBinarioBusqueda emisor;
    construir(destino);
    construir(emisor);
    insertar(destino,20180211,20);
    insertar(destino,20170810,20);
    insertar(destino,20170620,20);
    insertar(destino,20180409,10);
    
    insertar(emisor,20180211,10);
    insertar(emisor,20170811,5);
    insertar(emisor,20180410,15);
    
    //recorrerEnOrden(emisor.arbolBinario);
    //recorrerEnOrden(destino.arbolBinario);
    int cantNodDest= numeroNodos(destino.arbolBinario);
    int cantNodEmis= numeroNodos(emisor.arbolBinario);
    
    if(cantNodDest>=cantNodEmis){
        fusionarAlmacenes(destino,emisor.arbolBinario.raiz);
        recorrerPreOrden(destino.arbolBinario);
        cout<<endl;
        recorrerEnOrden(destino.arbolBinario);
        cout<<endl<<"EMIRSOr:";
        recorrerPreOrden(emisor.arbolBinario);
    }else{
        fusionarAlmacenes(emisor,destino.arbolBinario.raiz);
        recorrerPreOrden(emisor.arbolBinario);
        cout<<endl;
        recorrerEnOrden(emisor.arbolBinario);
    }
    
    return 0;
}

