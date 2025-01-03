/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "LoteNodo.h"
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesPila.h"
#include "Pila.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

struct NodoArbol* buscaNodo(struct NodoArbol *destino, int dato){
    if(esNodoVacio(destino)){
        return nullptr;
    } 
    
    if(comparaABB(destino->elemento->codigo, dato) == 0)
        return destino;
    if(comparaABB(destino->elemento->codigo, dato) == 1)
        return buscaNodo(destino->izquierda, dato);
    else
        if(comparaABB(destino->elemento->codigo, dato) == -1) 
            return buscaNodo(destino->derecha, dato);
    
}

void insertarOactualizarStockRecursivo(struct NodoArbol *&destino,struct NodoArbol *emisor){
    if(esNodoVacio(destino)){
//        emisor->izquierda =nullptr;
//        emisor->derecha = nullptr;
//        destino = emisor;
        insertarRecursivo(destino,emisor->elemento);
        return; 
    }

    if(buscaArbolRecursivo(destino,emisor->elemento->codigo)){
        struct NodoArbol *pArbol = buscaNodo(destino,emisor->elemento->codigo);
        
        pArbol->elemento->cantidad += emisor->elemento->cantidad; 
    }else if(destino->elemento->codigo > emisor->elemento->codigo){
        insertarOactualizarStockRecursivo(destino->izquierda,emisor);
    }else if(destino->elemento->codigo < emisor->elemento->codigo){
        insertarOactualizarStockRecursivo(destino->derecha,emisor);
    }
    
}
//para isnertar recursivamente 
void insertarOactualizarStock(struct ArbolBinario &arbol,struct NodoArbol *raiz){
    if(!esArbolVacio(arbol)){
        insertarOactualizarStockRecursivo(arbol.raiz,raiz);
    }

}


void fuisonarArbolesRecursivo(struct ArbolBinarioBusqueda &destino,struct NodoArbol *raiz){
    if(esNodoVacio(raiz)){
        return;
    }

    if(raiz->izquierda !=nullptr){
        fuisonarArbolesRecursivo(destino,raiz->izquierda);
    }
    if(raiz->derecha != nullptr){
        fuisonarArbolesRecursivo(destino,raiz->derecha);
    }    
    
    insertarOactualizarStock(destino.arbolBinario,raiz);
    //raiz = nullptr;
    
}


void fusionarArboles(struct ArbolBinarioBusqueda &destino,struct ArbolBinarioBusqueda &emisor){

    if(!esArbolVacio(emisor)){
        fuisonarArbolesRecursivo(destino,emisor.arbolBinario.raiz);
    }

}


int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda destino,emisor;
    construir(destino);
    construir(emisor);
    struct Lote lote1,lote2,lote3,lote4,lote5,lote6,lote7;
    lote1.cantidad = 10;
    lote1.codigo = 20180211;
    lote2.cantidad= 5;
    lote2.codigo= 20170811;
    lote3.cantidad= 15;
    lote3.codigo= 20180410;
    insertar(emisor,&lote1);
    insertar(emisor,&lote2);
    insertar(emisor,&lote3);
    
    
    lote4.cantidad = 10;
    lote4.codigo = 20180409;
    lote5.cantidad= 20;
    lote5.codigo= 20170810;
    lote6.cantidad= 20;
    lote6.codigo= 20170620;
    lote7.cantidad= 20;
    lote7.codigo= 20180211;
    
    insertar(destino,&lote4);
    insertar(destino,&lote5);
    insertar(destino,&lote6);
    insertar(destino,&lote7);
    cout<<"---En orden"<<endl<<endl;
    cout<<"Emisor: ";
    enOrden(emisor);
    cout<<endl;
    cout<<"Destino: ";
    enOrden(destino);
    cout<<endl;
    cout<<"---En pre orden"<<endl<<endl;
    cout<<"Emisor: ";
    preOrden(emisor);
    cout<<endl;
    cout<<"Destino: ";
    preOrden(destino);
    
    cout<<endl<<endl<<"Fusionar los Arboles"<<endl;
    if(numeroNodos(destino.arbolBinario)>numeroNodos(emisor.arbolBinario) ){
        fusionarArboles(destino,emisor);
    }else{
        fusionarArboles(emisor,destino);
    }
    //fusionarArboles(destino,emisor);
    cout<<endl<<"Resultado: "<<endl;
    cout<<"Pre-orden: ";preOrden(destino);
    cout<<endl<<"En-Orden: ";enOrden(destino);
    
    
    return 0;
}

