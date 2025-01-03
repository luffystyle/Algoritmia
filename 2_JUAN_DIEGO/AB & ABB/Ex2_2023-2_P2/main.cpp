/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolBinario.h"
#include "Lista.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funciones.h"
#define M 10
/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
int aux=0;
/*============================================================================*/
//Amplitud
void imprimeAmplitudRecursivo(NodoArbol * nodo ){
    if(!esNodoVacio(nodo)){
        if(!esNodoVacio(nodo->izquierda))
            imprimeNodo(nodo->izquierda);
        if(!esNodoVacio(nodo->derecha))
            imprimeNodo(nodo->derecha);
        imprimeAmplitudRecursivo(nodo->izquierda);
        imprimeAmplitudRecursivo(nodo->derecha);
    }   
}

void recorreAmplitud(struct ArbolBinario & arbol){
    if(!esArbolVacio(arbol)){
        imprimeNodo(arbol.raiz);
        imprimeAmplitudRecursivo(arbol.raiz);
    }
}
/*============================================================================*/
void llenarLista(char*palabra,Lista & lista,int cantLet){
    for(int i=0;i<cantLet;i++){
        insertarAlFinal(lista,palabra[i]);
    }
}
int buscaPalabraRecursivo(NodoArbol*nodo,Lista & lista){
    if(lista.longitud==0){
        return 1;
    } 
    Nodo*recorre=lista.cabeza;
    Nodo*ultimo;
    int temp=0;    
    
    for(int j=0;j<longitud(lista);j++){
        if(nodo->letra==recorre->elemento or lista.longitud==1){   
            if(nodo->letra==lista.cabeza->elemento){
                lista.cabeza=lista.cabeza->siguiente;
            }
            ultimo->siguiente=recorre->siguiente;
            delete recorre;
            lista.longitud--;
            temp=1;
            break;
        }else{
            ultimo=recorre;
            recorre=recorre->siguiente;
        }
    }
    if(temp==0){
        return 0;
    }    
    buscaPalabraRecursivo(nodo->izquierda,lista);
    buscaPalabraRecursivo(nodo->derecha,lista);
}
int buscaPalabra(NodoArbol*nodo,char * palabra,int cantLet){
    struct Lista lista;     
    construir(lista);
    llenarLista(palabra,lista,cantLet);
    return buscaPalabraRecursivo(nodo,lista);    
}


int main(int argc, char** argv) {
    
    int n,m;
    char palabra[M][M];
//    char palabra[n]={'C','I','C','L','O'};
    
    /*construimos el arbol*/
    //Es un arbol binario asi que plantaremos los nodos
    
    struct ArbolBinario arbol;
    construir(arbol);
    
    ArbolBinario ab1,ab2,ab3,ab4,ab5,ab6,ab7,ab8,ab9,ab10,ab11,ab12,ab13,ab14;
    
    plantarArbolBinario(ab1,nullptr,'E',nullptr);
    plantarArbolBinario(ab2,nullptr,'R',nullptr);
    plantarArbolBinario(ab3,nullptr,'T',nullptr);
    plantarArbolBinario(ab4,nullptr,'O',nullptr);
    plantarArbolBinario(ab5,nullptr,'F',nullptr);
    plantarArbolBinario(ab6,nullptr,'T',nullptr);
    plantarArbolBinario(ab7,ab3,'G',nullptr);
    plantarArbolBinario(ab8,ab4,'C',nullptr);
    plantarArbolBinario(ab9,ab5,'A',ab6);
    plantarArbolBinario(ab10,ab2,'E',ab7);
    plantarArbolBinario(ab11,ab8,'C',nullptr);
    plantarArbolBinario(ab12,ab9,'N',nullptr);
    plantarArbolBinario(ab13,ab1,'D',ab10);
    plantarArbolBinario(ab14,ab11,'I',ab12);
    plantarArbolBinario(arbol,ab13,'L',ab14);
    
//    recorreAmplitud(arbol);
//    cout<<endl;
//    recorrerPreOrden(arbol);
//    cout<<endl;
//    recorrerPostOrden(arbol);
//    cout<<endl;   
    
    cout<<"Ingrese el numero de palabras :";
    cin>>n;
    char letra;
    int cantLet[M];
    for(int j=0;j<n;j++){
        cout<<"Ingrese la cantidad de caracteres de la palabra "<<j+1<<": ";
        cin>>cantLet[j];
        cout<<"Palabra: ";
        for(int i=0;i<cantLet[j];i++){
            cin>>palabra[j][i];
        }                
    }
    
//    for(int i=0;i<n;i++){
//        for(int j=0;j<strlen(palabra[i]);j++){
//            cout<<palabra[i][j];
//        }
//        cout<<" ";
//    }
//    cout<<endl;
    cout<<"Mensaje oculto: ";
    int existe=0;
    for(int j=0;j<n;j++){
        int seEncuentra=buscaPalabra(arbol.raiz,palabra[j],cantLet[j]);
        if(seEncuentra){
            for(int k=0;k<cantLet[j];k++){
                cout<<palabra[j][k];
            }
            cout<<" ";
            existe++;
        }else if(j==n-1 && existe==0){
            cout<<"No se encontro ninguna palabra";
        }
    }
    cout<<endl;
    
    
//    for(int i=0;i<n;i++){
//        construir(lista);
//        cout<<"Numero de letras de la palabra "<<i+1<<": ";
//        cin>>m;
//        cout<<"Ingrese la palabra: ";
//        for(int k=0;k<m;k++){
//            cin>>palabra[k];
//        }
//        
//        for(int j=0;j<m;j++){
////            cout<<palabra[j];
//            insertarAlFinal(lista,palabra[j]);
//        }
//        int seEncuentra=buscaPalabra(arbol.raiz,lista);
//    
//        if(seEncuentra){
//            cout<<setw(40);
//            for(int k=0;k<m;k++){
//                cout<<palabra[k];
//            }
//            cout<<" "<<endl;;
//        }else{
//            cout<<"La palabra no se encuentra"<<endl;
//        }
//        destruir(lista);
//    }       
//    cout<<lista.longitud<<endl;    
//    imprime(lista);       
    return 0;
}



//     char palabras[6][10]={{'H','I','J','O'},
//                          {'F','I','N','A','L'},
//                          {'M','U','N','D','O'},
//                          {'D','E','L'},
//                          {'D','I','A'},
//                          {'C','I','C','L','O'}};