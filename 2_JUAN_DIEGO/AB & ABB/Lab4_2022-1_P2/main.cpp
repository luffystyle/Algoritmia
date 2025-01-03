/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <climits>
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
void actualizacionEnOrdenRecursivo(struct NodoArbol * nodo,Cola & cola){
    if(not esNodoVacio(nodo)){
        actualizacionEnOrdenRecursivo(nodo->izquierda,cola);
        encolar(cola,nodo->elemento);
        actualizacionEnOrdenRecursivo(nodo->derecha,cola);
    }
}
int operaCola(Cola & cola,int despacho){
    int nodoMin;
    int difr;
    int n=longitud(cola);
    int eliminar=0;
    int actualizar;
    while(!esColaVacia(cola)){
        nodoMin = desencolar(cola);
        difr=(nodoMin%100)-despacho;
        if(difr>0){
            encolar(cola,nodoMin-despacho);    
            actualizar=nodoMin-despacho;
            break;
        }else if(difr==0){
            encolar(cola,nodoMin);
            eliminar++;
            break;
        }else if(difr<0){
            encolar(cola,nodoMin);
            eliminar++;
            despacho=difr*(-1);
        }
    }
    if(eliminar==0){
        for(int i=0;i<n-1;i++){
            encolar(cola,desencolar(cola));
        }
        return actualizar;
    }else{
        for(int j=0;j<n-eliminar-1;j++){
            desencolar(cola);
        }
        return actualizar;
    }    
}
bool actualizaArbolRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo)){
        return false;
    } 
    if(comparaABB(nodo->elemento/100, dato/100) == 0){
        nodo->elemento=dato;
        return true;
    }        
    if(comparaABB(nodo->elemento/100, dato/100) == 1)
        return actualizaArbolRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento/100, dato/100) == -1) 
            return actualizaArbolRecursivo(nodo->derecha, dato);
}

bool actualizaArbol( struct ArbolBinario & arbol ,int dato){
    return actualizaArbolRecursivo(arbol.raiz, dato);
}
bool eliminaArbolRecursivo(ArbolBinarioBusqueda & arbol,struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo)){
        return false;
    } 
    if(comparaABB(nodo->elemento, dato) == 0){
        eliminarNodo(arbol,dato);
        return true;
    }        
    if(comparaABB(nodo->elemento, dato) == 1)
        return eliminaArbolRecursivo(arbol,nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento, dato) == -1) 
            return eliminaArbolRecursivo(arbol,nodo->derecha, dato);
}

bool eliminaArbol( struct ArbolBinarioBusqueda & arbol ,int dato){
    return eliminaArbolRecursivo(arbol,arbol.arbolBinario.raiz, dato);
}
void actualizacion(ArbolBinarioBusqueda & arbol, int despacho){
    struct Cola cola;
    construir(cola);
    int num;
    int longi;
    if (not esArbolVacio(arbol)){
        actualizacionEnOrdenRecursivo(arbol.arbolBinario.raiz,cola);
    }
    longi=longitud(cola);
    num=operaCola(cola,despacho);
    cout<<endl;
//    imprime(cola);
    if(longi==longitud(cola)){
        actualizaArbol(arbol.arbolBinario,num);
    }else{
        while(longitud(cola)!=1){
            eliminaArbol(arbol,desencolar(cola));
        }
        actualizaArbol(arbol.arbolBinario,num);
    }      
    destruirCola(cola);
}

int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    insertar(arbol,2022081540);
    insertar(arbol,2022071050);
    insertar(arbol,2022093030);
    insertar(arbol,2022063050);
    insertar(arbol,2022072050);
    insertar(arbol,2022062440);
    insertar(arbol,2022061540);
    insertar(arbol,2022061840);
    
    recorrerPreOrden(arbol.arbolBinario);
//    eliminarNodo(arbol,2022061540);
    int despacho=20;    
    actualizacion(arbol,despacho);
    cout<<endl;
    cout<<"La representación, en preorden, del árbol de lotes de productos luego del despacho 1 es: "<<endl;
    recorrerPreOrden(arbol.arbolBinario);
    despacho=40;
    actualizacion(arbol,despacho);
    cout<<endl;
    cout<<"La representación, en preorden, del árbol de lotes de productos luego del despacho 2 es: "<<endl;
    recorrerPreOrden(arbol.arbolBinario); 
    despacho=200;    
    actualizacion(arbol,despacho);
    cout<<endl;
    cout<<"La representación, en preorden, del árbol de lotes de productos luego del despacho 3 es: "<<endl;
    recorrerPreOrden(arbol.arbolBinario);
    
    return 0;
}

