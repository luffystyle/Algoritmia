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
#include "Lista.h"
#include "Pila.h"
#include "funcionesPila.h"

struct NodoArbol *buscar(struct NodoArbol *nodo,int dato){
    if(esNodoVacio(nodo)){
        return nullptr;
    } 
    if(comparaABB(nodo->elemento, dato) == 0)
        return nodo;
    if(comparaABB(nodo->elemento, dato) == 1)
        return buscar(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento, dato) == -1) 
            return buscar(nodo->derecha, dato);
    
    
}


void ingresarHojas(struct NodoArbol *&raizDestino,struct NodoArbol *raizEmisor){
    if(esNodoVacio(raizDestino)){
        insertarRecursivo(raizDestino,raizEmisor->elemento,raizEmisor->cantidad);
        return;
    }
    
    if(buscaArbolRecursivo(raizDestino,raizEmisor->elemento)){
        struct NodoArbol * pArbol = buscar(raizDestino,raizEmisor->elemento);
        pArbol->cantidad += raizEmisor->cantidad;
    }else if(raizDestino->elemento > raizEmisor->elemento){
        ingresarHojas(raizDestino->izquierda,raizEmisor);
        //insertarRecursivo(raizDestino,raizEmisor->elemento,raizEmisor->cantidad);
    }else if(raizDestino->elemento < raizEmisor->elemento){
        ingresarHojas(raizDestino->derecha,raizEmisor);
        //insertarRecursivo(raizDestino,raizEmisor->elemento,raizEmisor->cantidad);
    }
    
}
//esta sirve al parecer
//aca se esta recorriendo de forma desde el inicio de preorden el emisor 
void fusionarArbolesIterativo23(struct NodoArbol *&raizDestino, struct NodoArbol *raizEmisor) {
    if (esNodoVacio(raizEmisor)) return;

    struct Pila pilaEmisor;
    construir(pilaEmisor);
    apilar(pilaEmisor, raizEmisor);

    while (!esPilaVacia(pilaEmisor)) {
        struct NodoArbol *nodoEmisor = desapilar(pilaEmisor);
        ingresarHojas(raizDestino, nodoEmisor);

        if (nodoEmisor->derecha != nullptr) {
            apilar(pilaEmisor, nodoEmisor->derecha);
        }
        if (nodoEmisor->izquierda != nullptr) {
            apilar(pilaEmisor, nodoEmisor->izquierda);
        }
    }
}

//esto recorre desde el ultimo raiz del pre-ordem
 void fusionarRecursivo(struct NodoArbol * nodo1, struct NodoArbol * nodo2){
	int valor, cantidad;
	struct NodoArbol * nodoAux;
	nodoAux=nodo2;
	if (nodo2==NULL) return; //CASO BASE
	if (nodoAux){
		fusionarRecursivo(nodo1, nodoAux->izquierda);
		fusionarRecursivo(nodo1, nodoAux->derecha);
		valor = nodoAux->elemento;//"guardamos" el nro de lote
		cantidad = nodoAux->cantidad;//"guardamos" la cantidad del lote
		delete nodoAux;//Liberamos la memoria que ocupa el nodo
		struct NodoArbol * nodoPresente;
		nodoPresente=buscar(nodo1,valor);
		//Si se encontr  el nodo que tiene el mismo n mero de lote, aumentamos la cantidad de productos de ese lote
		if (nodoPresente)
			nodoPresente->cantidad+=cantidad;
		else//Sino, insertamos el nuevo nodo a la ra z 1	
			insertarRecursivo(nodo1,valor,cantidad);//insertamos con confianza en el  rbol destino.
		nodo2=NULL;//Al puntero le asignamos NULL como  ltima acci n de su eliminaci n.
	}
}

//esto recorre desde el ultimo raiz del post-ordem
void fusionarArboles(struct NodoArbol *&raizDestino,struct NodoArbol *raizEmisor){
    if(esNodoVacio(raizEmisor)) return ;
    if(raizEmisor->izquierda !=nullptr){
        fusionarArboles(raizDestino,raizEmisor->izquierda);
    }
    if(raizEmisor->derecha != nullptr){
        fusionarArboles(raizDestino,raizEmisor->derecha);
    }
    
    ingresarHojas(raizDestino,raizEmisor);
    raizEmisor = nullptr;
    
}

void preOrdenIterativo(struct NodoArbol *raiz){
    //if (raiz == nullptr) return;
    struct Pila pila;
    struct NodoArbol *nodo;
    construir(pila);
    apilar(pila,raiz);
    while(!esPilaVacia(pila)){
        nodo = desapilar(pila);
        imprimeNodo(nodo);
        
        if(nodo->derecha !=nullptr){
            apilar(pila,nodo->derecha);
        }
        if(nodo->izquierda !=nullptr){
            apilar(pila,nodo->izquierda);
        }
    }
    
}


int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda destino,emisor;
    construir(destino);
    construir(emisor);
    insertar(destino,52,2);
    insertar(destino,40,1);
    insertar(destino,60,1);
    insertar(destino,25,3);
    insertar(destino,42,2);
    
    preOrden(destino);
    insertar(emisor,65,1);
    insertar(emisor,25,1);
    insertar(emisor,12,2);
    insertar(emisor,34,1);
    insertar(emisor,75,2);
    insertar(emisor,70,1);
   
    cout<<endl;
    preOrden(emisor);
    
    int cantEmisor=numeroNodos(emisor.arbolBinario);
    int cantDestino=numeroNodos(destino.arbolBinario);
    cout<<endl<<cantEmisor<<"-"<<cantDestino<<endl;
    
    //fusionarArboles(destino.arbolBinario.raiz,emisor.arbolBinario.raiz);
    //preOrden(destino);cout<<endl;
    fusionarArbolesIterativo23(destino.arbolBinario.raiz,emisor.arbolBinario.raiz);cout<<endl;
    preOrden(destino);
    //preOrdenIterativo(destino.arbolBinario.raiz);
    return 0;
}

