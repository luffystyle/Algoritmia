/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"

using namespace std;
#include "funcionesLista.h"
#include "funcionesCola.h"

/*Construye la Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

/*Verifica si la cola estÃ¡ vacÃ­a*/
bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

/*Devuelve la longitud de la cola*/
int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

/*AÃ±ade un elemento a la cola*/
void encolar(struct Cola & cola, int elemento){
    insertarAlFinal(cola.lista, elemento);
    //cout<<"Encolando: "<<elemento<<endl;
}

/*Elimina un elemento de la cola*/
int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola estÃ¡ vacÃ­a no se puede desencolar"<<endl;
        return -1; //Cero o algÃºn elemento que no estÃ© en la cola
    }
    else{
        int elemento = retornaCabeza(cola.lista);
        eliminaCabeza(cola.lista);
        return elemento;
    }
    
}

/*Muestra los elementos de la cola*/
void imprimeCola(const struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola estÃ¡ vacÃ­a no se puede mostrar"<<endl;
    }
    else
        imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}

