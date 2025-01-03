/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesArbolesBB.h"
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"

struct NodoArbol * encuentraNodo(struct NodoArbol *raiz_destino,int dato){
    if(raiz_destino == nullptr) return nullptr;
    
    if(dato == raiz_destino->elemento){
        return raiz_destino;
    }else{
        if(dato<raiz_destino->elemento){
            return encuentraNodo(raiz_destino->izquierda,dato);
        }else{
            return encuentraNodo(raiz_destino->derecha,dato);
        }
    }
    
}

void fusionarABB(struct ArbolBinarioBusqueda &destino,struct NodoArbol *&raiz_emisor){
    if(raiz_emisor==nullptr){
        return;
    }
    fusionarABB(destino,raiz_emisor->izquierda);
    fusionarABB(destino,raiz_emisor->derecha);
    NodoArbol *parbol = encuentraNodo(destino.arbolBinario.raiz,raiz_emisor->elemento);
    if(parbol != nullptr){
        parbol->cantidad += raiz_emisor->cantidad;
    }else{
        insertar(destino,raiz_emisor->elemento,raiz_emisor->cantidad);
    }
    
}


int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda destino, emisor;
    construir(destino);
    construir(emisor);
    insertar(destino,52,2);
    insertar(destino,40,1);
    insertar(destino,25,3);
    insertar(destino,42,2);
    insertar(destino,60,1);
    recorrerPreOrden(destino.arbolBinario);
    cout<<endl;
    insertar(emisor,65,1);
    insertar(emisor,25,1);
    insertar(emisor,12,2);
    insertar(emisor,34,1);
    insertar(emisor,75,2);
    insertar(emisor,70,1);
    recorrerPreOrden(emisor.arbolBinario);
    
    fusionarABB(destino,emisor.arbolBinario.raiz);
    cout<<endl<<"ARBOL DESTINO EN PRE-ORDEN: ";
    recorrerPreOrden(destino.arbolBinario);
    cout<<endl<<"ARBOL BALANCEADO: "<<endl;
    //balancearArbol(destino.arbolBinario);
    recorrerPreOrden(destino.arbolBinario);
    return 0;
}

