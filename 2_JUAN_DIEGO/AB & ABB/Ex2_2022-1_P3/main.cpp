/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 1 de julio de 2024, 02:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
/*
 * 
 */
void leerRecursivo(ArbolBinarioBusqueda & arbol,int n){
    int index;
    char let;
    if(n==0){
        return;
    }
    cin>>index;
    cin>>let;
    insertar(arbol,index,let);
    leerRecursivo(arbol,n-1);
}
int posCorrecta(NodoArbol*nodo,char letra,int pos){    
    if(nodo!=nullptr){
        if(nodo->letra==letra){
            return nodo->elemento==pos;
        }else if(pos<nodo->elemento){
            return posCorrecta(nodo->izquierda,letra,pos);
        }else{
            return posCorrecta(nodo->derecha,letra,pos);
        }
    }
    return 0;
}
int buscaArbolLetra(NodoArbol*nodo,char letra){
    if(nodo!=nullptr){
        if(nodo->letra==letra)return 1;
        if(nodo->izquierda==nullptr)return 0;
        int izq=buscaArbolLetra(nodo->izquierda,letra);
        if(nodo->derecha==nullptr)return 0;
        int der=buscaArbolLetra(nodo->derecha,letra);
        return izq + der;
    }    
}
int coincide(ArbolBinarioBusqueda & arbol,char*palabra,int cantLet,int i,int cent){
    if(i==cantLet){
        return cent;
    }
    if(buscaArbolLetra(arbol.arbolBinario.raiz,palabra[i])){
        if(posCorrecta(arbol.arbolBinario.raiz,palabra[i],i+1)){
            cout<<palabra[i]<<" ";
        }else{
            cout<<palabra[i]<<"(X)";
            cent=0;
        }
    }else{
        cout<<"_ ";
        cent=0;
    }
    
    return coincide(arbol,palabra,cantLet,i+1,cent);
}
void balword(ArbolBinarioBusqueda & arbol,int cantLet){
    char palabra[10];
    int seResolvio=0;
    cout<<"BIENVENIDO AL JUEGO DEL BALWORD"<<endl;
    cout<<"Descubre la palbra de "<<cantLet<<" letras. Tiene maximo "<<cantLet<< " intentos."<<endl;
    cout<<" _ _ _ _ _ "<<endl;
    for(int i=0;i<cantLet;i++){
        cout<<endl<<"Intento "<<i+1<<": ";
        cin>>palabra;
        if(cantLet==strlen(palabra)){
            if(coincide(arbol,palabra,cantLet,0,1)){
                cout<<endl<<"Felicitaciones por haber resulto el reto."<<endl;
                seResolvio=1;
                break;
            }
        }else{
            cout<<"La longitud de la palabra no es la correcta.";
            i--;
        }
    }
    if(seResolvio==0){
        cout<<endl<<"Lo siento se agotaron los intentos."<<endl;
    }
}

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    int cantLet;
    cout<<"Cantidad de letras: ";
    cin>>cantLet;
    leerRecursivo(arbol,cantLet);
    
//    postOrden(arbol);    
    balword(arbol,cantLet);    
//    
    
    
//    char palabra[10];
//    cin>>palabra;
//    cout<<strlen(palabra)<<endl; 

    return 0;
}

