/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"

using namespace std;
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
/*
 * IMPLEMENTACIÓN DE UNA COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

void reorganizar(struct Cola & cola,int n){
    struct Pila pilaAux;
    construir(pilaAux);
    pilaAux.lista.cabeza->turno;
    //Intercalamos los elementos de la cola utilizando una pila auxiliar
    int tipo=cola.lista.cabeza->deteccion;
    while(!esColaVacia(cola)){
        if(esPilaVacia(pilaAux)){            
            apilar(pilaAux,cola.lista.cabeza->deteccion,cola.lista.cabeza->turno);
            desencolar(cola);
        }else{
            if(tipo!=cola.lista.cabeza->deteccion){
                apilar(pilaAux,cola.lista.cabeza->deteccion,cola.lista.cabeza->turno);
                tipo=cola.lista.cabeza->deteccion;
                desencolar(cola);
            }else{
                encolar(cola,cola.lista.cabeza->deteccion,cola.lista.cabeza->turno);
                desencolar(cola);
            }            
        }
    } 
    cout<<"\nPila: "<<endl;
    imprimir(pilaAux);
    //Devolvemos los elementos apilados a la cola
    while(!esPilaVacia(pilaAux)){
        encolar(cola,pilaAux.lista.cabeza->deteccion,pilaAux.lista.cabeza->turno);
        desapilar(pilaAux);
    }    
    cout<<"\nCola2: "<<endl;
    imprime(cola);
    //Volveremos a desencolar/apilar y desapilar/desencolar una vez mas
    while(!esColaVacia(cola)){
        apilar(pilaAux,cola.lista.cabeza->deteccion,cola.lista.cabeza->turno);
        desencolar(cola);
    }
    while(!esPilaVacia(pilaAux)){
        encolar(cola,pilaAux.lista.cabeza->deteccion,pilaAux.lista.cabeza->turno);
        desapilar(pilaAux);
    }
    cout<<"\nCola Definitiva: "<<endl;
    imprime(cola);
}

int main(int argc, char** argv) {
    
    Cola cola;
    
    int n=5;
    construir(cola);
    
    encolar(cola,1,1);
    encolar(cola,1,2);
    encolar(cola,1,3);
    encolar(cola,1,4);
    encolar(cola,1,5);
    encolar(cola,2,6);
    encolar(cola,2,7);
    encolar(cola,2,8);
    encolar(cola,2,9);
    encolar(cola,2,10);
    cout<<"Cola: "<<endl;
    imprime(cola);
    
    reorganizar(cola,n);    
    
    return 0;
}

