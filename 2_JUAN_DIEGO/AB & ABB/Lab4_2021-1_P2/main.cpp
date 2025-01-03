/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
int i=0;

void verificarplantarArbolBB(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, long long fecha,int dni,int cant,int total,char estado, 
                    struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->fecha= fecha;
    nuevoNodo->dni= dni;
    nuevoNodo->numAcciones = cant;
    nuevoNodo->total = total;
    nuevoNodo->estado = estado;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

void verificarRecursivo(struct NodoArbol *& raiz,long long fecha,int dni,int cant,int total,char estado){
    if(esNodoVacio(raiz))
        verificarplantarArbolBB(raiz, nullptr, fecha,dni,cant,total,estado, nullptr);
    else
        if (raiz->total > total){
            if(!buscaArbolRecursivo(raiz, dni)){
                verificarRecursivo(raiz->izquierda, fecha,dni,cant,total,estado);
            }
        }            
        else
            if(raiz->total< total){
                if(!buscaArbolRecursivo(raiz, dni)){
                verificarRecursivo(raiz->derecha, fecha,dni,cant,total,estado);
                }
            }                
            else
                cout<<endl<<"El elemento "<< total <<" ya se encuentra en el árbol"<< endl;
}

void verificar(struct ArbolBinarioBusqueda & arbol, long long fecha,int dni,int cant,int total,char estado){
    verificarRecursivo(arbol.arbolBinario.raiz, fecha,dni,cant,total,estado);
}

void consolidadoEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        nodo->estado='p';
        consolidadoEnPreOrdenRecursivo(nodo->izquierda);
        consolidadoEnPreOrdenRecursivo(nodo->derecha);
    }
}

void  consolidado(struct ArbolBinario & arbol){
    if (not esArbolVacio(arbol)){
        consolidadoEnPreOrdenRecursivo(arbol.raiz);
    }
}
void rankingEnOrdenRecursivo(struct NodoArbol * nodo,NodoArbol ** arrNodo){
    if(not esNodoVacio(nodo)){
        rankingEnOrdenRecursivo(nodo->izquierda,arrNodo);
        arrNodo[i++]=nodo;
        rankingEnOrdenRecursivo(nodo->derecha,arrNodo);
    }
}
void ranking(struct ArbolBinario & arbol){
    NodoArbol * arrNodo[5];
    if (not esArbolVacio(arbol)){
        rankingEnOrdenRecursivo(arbol.raiz,arrNodo);
    }
    for(int i=4;i>=0;i--){
        imprimeNodo(arrNodo[i]);
    }
}

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda arbol;   
    construir(arbol);
    
    verificar(arbol,20240624185511,40582060,50,2000,'r');    
    verificar(arbol,20240624135411,98347060,50,3000,'r');
    verificar(arbol,20240624153311,37562060,50,2500,'r');    
    verificar(arbol,20240624153311,29596060,50,1700,'r');    
    verificar(arbol,20240624153311,72904060,50,4000,'r');    
    
    recorrerPreOrden(arbol.arbolBinario);
    consolidado(arbol.arbolBinario);
    cout<<endl<<"Despues del consolidado: "<<endl;
    recorrerPreOrden(arbol.arbolBinario);    
    cout<<endl<<"Ranking: "<<endl;
    ranking(arbol.arbolBinario);
    
   
      
    return 0;
}

//    struct ArbolBinarioBusqueda arbol;
//    int auxiliarElemento;
    
//    construir(arbol);
//    insertar(arbol, 100);
//    insertar(arbol, 50);
//    insertar(arbol, 150);
//    insertar(arbol, 125);
//    insertar(arbol, 175);
//    insertar(arbol, 200);
//    insertar(arbol, 25);
//    insertar(arbol, 75);
//    
//   
//    preOrden(arbol); cout<<endl;
//    enOrden(arbol);  cout<<endl;
//    postOrden(arbol); cout<<endl;
//    cout<<"Se encuentra 125 en árbol: "<<buscaArbol(arbol, 125)<<endl;
//     
//    eliminarNodo(arbol, 125);
//    enOrden(arbol);   cout<<endl;
//      
//    auxiliarElemento = minimoNodoABB(arbol);
//    cout<<"Mínimo ABB: "<<auxiliarElemento<<endl;
//    //LISTO
//    auxiliarElemento = maximoNodoABB(arbol);
//    cout<<"Máximo ABB: "<<auxiliarElemento<<endl;
//        
//    cout<<"Sumar nodos: "<<sumarNodos(arbol)<<endl;
//    
//    destruirArbolBB(arbol);