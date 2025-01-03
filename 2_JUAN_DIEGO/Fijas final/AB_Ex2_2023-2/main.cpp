/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstring>
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "Lista.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funciones.h"

#define M 10
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
int temp=0;
void leerPalabra(char palabra[][M],int n){      
    for(int i=0;i<n;i++){
        cin>>palabra[i];
    }      
}
void llenarLista(Lista & lista,char*palabra){
    int cantLetras;
    cantLetras=strlen(palabra);
    for(int i=0;i<cantLetras;i++){
        insertarAlFinal(lista,palabra[i]);
    }
}
void eliminaNodoLista(Lista & lista,char letra){
    Nodo * recorre = lista.cabeza;
    Nodo * anterior;
    while(recorre!=nullptr){
        if(recorre==lista.cabeza && recorre->elemento==letra){
            lista.cabeza=lista.cabeza->siguiente;
            delete recorre;
            lista.longitud--;
            break;
        }else if(recorre->elemento==letra){
            anterior->siguiente=recorre->siguiente;
            delete recorre;
            lista.longitud--;
            break;
        }
        anterior=recorre;
        recorre=recorre->siguiente;        
    }
}
int buscaLista(Nodo*nodo, char letra){
    if(nodo==nullptr)return 0;
    if(nodo->elemento==letra){
        return 1;
    }else{
        return buscaLista(nodo->siguiente,letra);
    }    
}
int buscaPalabraRecursivo(NodoArbol * nodo,Lista & lista){
    if(esListaVacia(lista)){
        return 1;
    }
    if(nodo!=nullptr and temp==0){
        if(buscaLista(lista.cabeza,nodo->elemento)){
            //Eliminamos el nodo
            eliminaNodoLista(lista,nodo->elemento);        
        }else{
            return 0;
        }
    }else{
        temp=1;
        return 0;
    }    
    buscaPalabraRecursivo(nodo->izquierda,lista);
    buscaPalabraRecursivo(nodo->derecha,lista);
}
int buscaPlabra(ArbolBinario & arbol,char*palabra){
    //nos apoyamos de una lista para comparar las letras de la palabra
    struct Lista lista;
    construir(lista);
    llenarLista(lista,palabra);    
//    imprime(lista);
    return buscaPalabraRecursivo(arbol.raiz,lista);
}
int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    construir(arbol);
    
    ArbolBinario ab1,ab2,ab3,ab4,ab5,ab6,ab7,ab8,ab9,ab10,ab11,ab12,ab13,ab14;
    
    plantarArbolBinario(ab1,nullptr,'T',nullptr);
    plantarArbolBinario(ab2,ab1,'G',nullptr);
    plantarArbolBinario(ab3,nullptr,'R',nullptr);
    plantarArbolBinario(ab4,ab3,'E',ab2);
    plantarArbolBinario(ab5,nullptr,'E',nullptr);
    plantarArbolBinario(ab6,ab5,'D',ab4);
    
    plantarArbolBinario(ab7,nullptr,'O',nullptr);
    plantarArbolBinario(ab8,ab7,'C',nullptr);
    plantarArbolBinario(ab9,ab8,'C',nullptr);
    plantarArbolBinario(ab10,nullptr,'F',nullptr);
    plantarArbolBinario(ab11,nullptr,'T',nullptr);
    plantarArbolBinario(ab12,ab10,'A',ab11);
    plantarArbolBinario(ab13,ab12,'N',nullptr);
    plantarArbolBinario(ab14,ab9,'I',ab13);
    
    plantarArbolBinario(arbol,ab6,'L',ab14);
    
//    recorrerPreOrden(arbol);
//    cout<<endl;
    char palabra[M][M];
    int cantPalabras; 
    cout<<"Ingrese la cantidad de palabras: ";//HIJO FINAL MUNDO DEL DIA CICLO   
    cin>>cantPalabras;
    cout<<"Palabras: ";
    leerPalabra(palabra,cantPalabras);
    int encuentra;
    cout<<"Mensaje oculto: ";
    for(int j=0;j<cantPalabras;j++){
        encuentra=buscaPlabra(arbol,palabra[j]);
        if(encuentra){
            cout<<palabra[j]<<" ";
        }
    }
    cout<<endl;
    
//    for(int i=0;i<cantPalabras;i++){
//        cout<<strlen(palabra[i])<<" ";
//    }
//    cout<<endl;
    
      
    return 0;
}

