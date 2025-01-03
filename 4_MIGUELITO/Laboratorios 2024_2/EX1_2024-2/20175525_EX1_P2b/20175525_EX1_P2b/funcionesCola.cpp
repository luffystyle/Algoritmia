/* 
 * File:   funcionesCola.cpp
 * Author: Ana Roncal
 * 
 * Created on 1 de setiembre de 2024, 23:02
 */

#include <iostream>
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
using namespace std;

/*constructor de Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, struct Cliente elemento){
 
    insertarAlFinal(cola.lista, elemento);
}

struct Cliente desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    struct Cliente elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

void imprime(const struct Cola & cola){
    if(esColaVacia(cola))
        cout << "La cola está vacía no se puede desencolar" <<endl;
    else
        imprime(cola.lista);
}

int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}

void encolarConPrioridad(struct Cola & cola, const struct Cliente & cliente){
    insertarConPrioridad(cola.lista, cliente);
}

struct Cliente retornaCabeza(struct Cola & cola){
    return retornaCabeza(cola.lista);
}