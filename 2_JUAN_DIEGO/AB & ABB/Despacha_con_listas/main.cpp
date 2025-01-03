/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Lista.h"
#include "funciones.h"
using namespace std;

/*para revisar Falta ABB*/
/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
void restaLista(Lista & lista,int n){
    Nodo * nodo = lista.cabeza;
    while(nodo!=nullptr){
        if(nodo->elemento-n<0){
            n=n-nodo->elemento;
            nodo->elemento=0;            
            nodo=nodo->siguiente;
        }
        if(nodo->elemento-n>0){
            nodo->elemento=(nodo->elemento)-n;
            nodo->siguiente=nullptr;
            nodo=nodo->siguiente;
        }
    }
}
void eliminaNodo(Lista & lista,int elem){
    Nodo * recorrido = lista.cabeza;
    Nodo * anterior;
    while(recorrido!=nullptr){
        //El elmento a eliminar es la cabeza
        if(recorrido==lista.cabeza && recorrido->elemento==elem){
            lista.cabeza=lista.cabeza->siguiente;
            delete recorrido;
            lista.longitud--;
            break;
        }
        //El elemento esta en medio o al final
        if(recorrido->elemento==elem ){
            anterior->siguiente=recorrido->siguiente;
            delete recorrido;
            lista.longitud--;
            break;
        }        
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
}
struct Nodo*crearNodoDoble(Nodo*anterior,int elemento,Nodo*siguiente){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->anterior=anterior;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}
void insertarAlFinalDoble(Lista & tad,int elemento){
    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo = crearNodoDoble(ultimoNodo,elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    tad.longitud++;
}
void imprimeInvertido(const struct Lista & tad){
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = obtenerUltimoNodo(tad);
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->anterior;
        }
        cout << "]" << endl;
    }
}
int main(int argc, char** argv) {

    struct Lista listaSimp;
    struct Lista listaDobl;
    /*Construimos la lista, la lista esta vacía*/
    construir(listaSimp);
    construir(listaDobl);
    int n=100;
    int cont=0;
    
    /*Listas doblemente enlazadas*/
    //Para manejar una listas doble debemos tener una parametro anterior en el nodo
    
    insertarAlFinalDoble(listaDobl,10);
    insertarAlFinalDoble(listaDobl,20);
    insertarAlFinalDoble(listaDobl,30);
    insertarAlFinalDoble(listaDobl,40);
    insertarAlFinalDoble(listaDobl,50);
    
    imprime(listaDobl);
    imprimeInvertido(listaDobl);
    /*Listas simplemente enlazadas*/       
    /*Inserta datos comenzando desde el inicio de la lista*/
    insertarAlFinal(listaSimp,50);
    insertarAlFinal(listaSimp,30);
    insertarAlFinal(listaSimp,40);
    insertarAlFinal(listaSimp,30);
    insertarAlFinal(listaSimp,80);
//    imprime(listaSimp);
    
    eliminaNodo(listaSimp,30);
    eliminaNodo(listaSimp,50);
    eliminaNodo(listaSimp,80);
    eliminaNodo(listaSimp,40);
    eliminaNodo(listaSimp,30);
//    restaLista(lista,n);  
    
//    imprime(listaSimp);    

    return 0;
}

