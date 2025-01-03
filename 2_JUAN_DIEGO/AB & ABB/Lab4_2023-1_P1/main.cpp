/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Lista.h"
#include "Cola.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
int nivel=0;

int obtenerNivel(NodoArbol * nodo,int servidor,int velocidad,int nivelActual){
    if(nodo==nullptr){
        return -1;
    }
    if(nodo->servidor==servidor && nodo->velocidad==velocidad){
        return nivelActual;
    }
    
    int nivelIzq = obtenerNivel(nodo->izquierda,servidor,velocidad,nivelActual+1);
    if(nivelIzq!=-1){
        return nivelIzq;
    }
    return obtenerNivel(nodo->derecha,servidor,velocidad,nivelActual+1);
}

struct NodoArbol * buscaSkynerd(struct ArbolBinario & arbol){
    struct Cola cola;
    construir(cola);
    if(!esArbolVacio(arbol)){
        encolar(cola,arbol.raiz);
        while(!esColaVacia(cola)){
            struct NodoArbol*nodo = desencolar(cola);
//            imprimeNodo(nodo);
            if(nodo->velocidad==200){
                //Verificamos el hijo izquierdo
                if(nodo->izquierda->servidor=='S'){
                    if(nodo->izquierda->velocidad==200){
                        nivel=obtenerNivel(arbol.raiz,nodo->izquierda->servidor,nodo->izquierda->velocidad,0);
                        return nodo->izquierda;
                    }else{
                        return nullptr;
                    }
                }
                //Verificamos el hijo derecho
                else if(nodo->derecha->servidor=='S'){
                    if(nodo->derecha->velocidad==200){
                        nivel=obtenerNivel(arbol.raiz,nodo->derecha->servidor,nodo->derecha->velocidad,0);
                        return nodo->derecha;
                    }else{
                        return nullptr;
                    }
                }
            }
            if(!esNodoVacio(nodo->izquierda))
                encolar(cola,nodo->izquierda);
            if(!esNodoVacio(nodo->derecha))
                encolar(cola,nodo->derecha);
        }
    }
    destruirCola(cola);
}

int main(int argc, char** argv) {
    
    struct ArbolBinario arbol;
    construir(arbol);
    
//    plantarArbolBinario(arbol,nullptr,'Z',100,nullptr);
    
    struct ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,arbol7,arbol8,arbol9,arbol0;
    struct ArbolBinario arbol11,arbol12;
    
    plantarArbolBinario(arbol1,nullptr,'E',50,nullptr);    
    plantarArbolBinario(arbol2,arbol1,'S',50,nullptr);
    plantarArbolBinario(arbol3,nullptr,'E',100,nullptr);   
    plantarArbolBinario(arbol4,arbol3,'Z',200,nullptr);   
    plantarArbolBinario(arbol5,arbol2,'E',100,arbol4);   
    plantarArbolBinario(arbol6,nullptr,'S',50,nullptr);   
    plantarArbolBinario(arbol7,arbol5,'Z',50,arbol6); 
    plantarArbolBinario(arbol8,nullptr,'S',100,nullptr);
    plantarArbolBinario(arbol9,nullptr,'E',200,nullptr);
    plantarArbolBinario(arbol0,arbol8,'S',200,arbol9);
    plantarArbolBinario(arbol11,nullptr,'S',150,nullptr);
    plantarArbolBinario(arbol12,arbol0,'E',200,arbol11);  
    plantarArbolBinario(arbol,arbol7,'Z',100,arbol12);
    
    cout<<"En orden: "<<endl;
    recorrerEnOrden(arbol);
    cout<<endl<<"Niveles: "<<alturaRecursivo(arbol.raiz)+1<<endl;
    struct NodoArbol * skynerd = buscaSkynerd(arbol);
    if(skynerd){
        cout<<"Skynerd esta en el AB."<<endl;
    }
    if(nivel){
        cout<<"esta en el nivel: "<<nivel+1<<endl;
    }
//    cout<<endl<<"Niveles: "<<alturaRecursivo(skynerd)+1<<endl;
    
    return 0;
}

//    struct ArbolBinario arbol;
//    construir(arbol);
//    
//    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
//    plantarArbolBinario(arbol, nullptr, 100, nullptr);
//    imprimeRaiz(arbol); cout<<endl;
//    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
//    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
//    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
//    plantarArbolBinario(arbol3, arbol1, 50, arbol2);
//    plantarArbolBinario(arbol4, nullptr, 150, nullptr);
//    plantarArbolBinario(arbol, arbol3, 100, arbol4);
//    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
//    
//    cout<<"Recorrer en pre orden: "<<endl;
//    recorrerPreOrden(arbol); cout<<endl;
//    cout<<"Recorrer en orden: "<<endl;
//    recorrerEnOrden(arbol); cout<<endl;
//    cout<<"Recorrer en post orden: "<<endl;
//    recorrerPostOrden(arbol); cout<<endl;
//    
//    cout<<"ALTURA árbol: "<<altura(arbol)<<endl;
//    cout<<"NúMERO DE HOJAS: "<<numeroHojas(arbol)<<endl;
//    cout<<"NúMERO DE NODOS: "<<numeroNodos(arbol)<<endl;
//    cout<<"ES EQUILIBRADO: "<<esEquilibrado(arbol)<<endl;
//    
//    destruirArbolBinario(arbol);
//    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;