/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "Pila.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesPila.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
void fusionarRecursivo(NodoArbol * nodoR,NodoArbol * nodoE){
    int valor,cantidad;
    NodoArbol * nodoAux = nodoE;
    if(nodoE==nullptr)return;
    if(nodoAux){
        fusionarRecursivo(nodoR,nodoAux->izquierda);
        fusionarRecursivo(nodoR,nodoAux->derecha);
        valor=nodoAux->elemento/10;
        cantidad=nodoAux->elemento%10;
        delete nodoAux;
        NodoArbol * nodoExiste=buscaArbolRecursivo(nodoR,valor);
        if(nodoExiste){
            nodoExiste->elemento+=cantidad;
        }else{
            insertarRecursivo(nodoR,(valor*10)+cantidad);
        }
        nodoE=nullptr;
    }    
}

void fusionEjercitos(ArbolBinarioBusqueda & peach,ArbolBinarioBusqueda & donkey){
    fusionarRecursivo(peach.arbolBinario.raiz,donkey.arbolBinario.raiz);
    donkey.arbolBinario.raiz=nullptr;
}
void preOrdenItertivo(ArbolBinario & arbol){
    struct Pila pila;
    construir(pila);
    if(!esArbolVacio(arbol)){
        apilar(pila,arbol.raiz);
        while(!esPilaVacia(pila)){
            NodoArbol * nodo = desapilar(pila);
            imprimeNodo(nodo);
            if(nodo->derecha!=nullptr){
                apilar(pila,nodo->derecha);
            }
            if(nodo->izquierda!=nullptr){
                apilar(pila,nodo->izquierda);
            }
        }
    }
    cout<<endl;
    destruirPila(pila);
}
int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda peach,donkey;    
    construir(peach);
    construir(donkey);
    
    insertar(peach,522);
    insertar(peach,401);
    insertar(peach,601);
    insertar(peach,253);
    insertar(peach,422);
    cout<<"Ejercito de peach: "<<endl;    
    enOrden(peach);
    cout<<endl;
    insertar(donkey,651);
    insertar(donkey,251);
    insertar(donkey,752);
    insertar(donkey,122);
    insertar(donkey,341);    
    insertar(donkey,701); 
    cout<<"Ejercito de donkey: "<<endl; 
    enOrden(donkey);
    cout<<endl;
    
    fusionEjercitos(peach,donkey);
    cout<<"Ejercitos fusionados: "<<endl; 
    enOrden(peach);
    cout<<endl;
    cout<<"PreOrden iterattivo: "<<endl;
    preOrdenItertivo(peach.arbolBinario);
    return 0;
}

//struct ArbolBinarioBusqueda arbol;
//    int auxiliarElemento;
//    
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