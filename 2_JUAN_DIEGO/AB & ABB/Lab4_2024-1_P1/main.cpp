/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "Cola.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}
struct NodoArbol * crearNuevoNodoArbolNuevo(struct NodoArbol * izquierdo, 
                               int elemento, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->derecha = derecho;
    return nuevoNodo;
}
void plantarArbolBinarioNuevo(struct ArbolBinario & arbol, struct NodoArbol * izquierdo,
                         int elemento, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNuevo(izquierdo, elemento, derecho);
    arbol.raiz = nuevoNodo;
}
void plantarArbolBinarioNuevo(NodoArbol*&raiz,NodoArbol*izquierdo,int elemento,NodoArbol*derecho){
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNuevo(izquierdo, elemento, derecho);
    raiz = nuevoNodo;
}
void resultadoRecursivo(NodoArbol *&raiz,int newElemento,int temp){
    if(raiz==nullptr){
        plantarArbolBinarioNuevo(raiz,nullptr,newElemento,nullptr);
        return;
    }
    if(temp%2!=0)
        resultadoRecursivo(raiz->izquierda,newElemento,temp);
    else
        resultadoRecursivo(raiz->derecha,newElemento,temp);
}
void insertarResultado(struct ArbolBinario & arbol,int newElemento,int temp){
    resultadoRecursivo(arbol.raiz,newElemento,temp);
}

void aplicar_arbol(ArbolBinario & arbol1, ArbolBinario & arbol2,ArbolBinario & arbol3){
    // se utilizan dos colas para poder obtener ir recorriendo tanto el AB como el ABB
    struct Cola cola1,cola2;    
    construir(cola1);
    construir(cola2);
    int newElemento;
    int i=0;
    if(!esArbolVacio(arbol1)){
        encolar(cola1,arbol1.raiz);
        encolar(cola2,arbol2.raiz);
        while(!esColaVacia(cola1)){
            //Aqui se operan los nodos al sumar al nodo paquetes, el nodo sistema
            NodoArbol* nodo1 = desencolar(cola1);
            NodoArbol* nodo2 = desencolar(cola2);
            newElemento=numeroNodosRecursivo(nodo2) - numeroHojasRecursivo(nodo2)+nodo1->elemento;
            if(i==0){
                plantarArbolBinarioNuevo(arbol3,nullptr,newElemento,nullptr);
            }else{
                insertarResultado(arbol3,newElemento,i); 
            }            
//            nodo1->elemento += numeroNodosRecursivo(nodo2) - numeroHojasRecursivo(nodo2);
//            imprimeNodo(nodo);
            if(nodo1->izquierda!=nullptr)
                encolar(cola1,nodo1->izquierda);
                encolar(cola2,nodo2->izquierda);
            if(nodo1->derecha!=nullptr)
                encolar(cola1,nodo1->derecha);
                encolar(cola2,nodo2->derecha);
                i++;
        }
    }
    cout<<endl;
}
int verificarABB(NodoArbol*raiz){
    
    //Determina que los nodos de la izquierda sean simepre menores que los de la derecha
    if(raiz->izquierda==nullptr || raiz->derecha==nullptr)return 1;
    NodoArbol * actual = raiz;
    //Verifica si los elementos de la izquierda son menores
    if(actual->elemento > actual->izquierda->elemento){
        return verificarABB(raiz->izquierda);
    }else{
        return 0;
    }
    //verifica si los elementos de la derecha son mayores
    if(actual->elemento<actual->derecha->elemento){
        return verificarABB(raiz->derecha);
    }else{
        return 0;
    }
}
int determinar_anomalia(ArbolBinario & arbol){
    int valido=verificarABB(arbol.raiz);
    int resultado=sumarNodos(arbol);
//    cout<<resultado;
    if(valido!=0 && resultado%2==0){
        return 1;
    }else{
        return 0;
    }    
}
int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda arbol_paquetes;
    construir(arbol_paquetes);
    //construyendo el ABB
    insertar(arbol_paquetes,5);
    insertar(arbol_paquetes,3);
    insertar(arbol_paquetes,9); 
    cout<<endl<<"Arbol paquetes: "<<endl;
    recorrerPreOrden(arbol_paquetes.arbolBinario);
//    recorreAmplitud(arbol_paquetes.arbolBinario);
    struct ArbolBinario arbol_sistema;
    construir(arbol_sistema);
    
    cout<<endl;
    //Construyendo el ab
    ArbolBinario arbol1,arbol2,arbol3,arbol4;
    
    plantarArbolBinario(arbol1,nullptr,2,nullptr);
    plantarArbolBinario(arbol2,nullptr,3,nullptr);
    plantarArbolBinario(arbol3,arbol1,7,arbol2);
    plantarArbolBinario(arbol4,nullptr,8,nullptr);
    plantarArbolBinario(arbol_sistema,arbol3,1,arbol4);
    cout<<endl<<"Arbol sistema: "<<endl;
    recorrerPreOrden(arbol_sistema);
    
    //Construyendo el arbol resultado
    struct ArbolBinario arbol_resultado;
    construir(arbol_resultado);
    
    aplicar_arbol(arbol_paquetes.arbolBinario,arbol_sistema,arbol_resultado);
    cout<<endl<<"Arbol resultado en preOrden"<<endl;
    recorrerEnOrden(arbol_resultado);
    cout<<endl;
    int valido=determinar_anomalia(arbol_resultado);
    if(valido){
        cout<<endl<<"Sin eventos sospechosos"<<endl;
    }else{
        cout<<"Anomalia detectada"<<endl;
    }
    
      
    return 0;
}

