/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
#include "FuncionesAuxiliares.h"
#define MAX_COMPUTADORAS 6


using namespace std;

void agregarConexion(int idCompOrigen, int idCompDestino, 
                     struct Lista *computadoras, int cantComputadoras){
    int indiceCompOrigen, indiceCompDestino;
    indiceCompOrigen = idCompOrigen-1;
    indiceCompDestino = idCompDestino-1;
    insertarEnOrden(computadoras[indiceCompOrigen], indiceCompDestino);
    cout<<"Se conecto la computadora "<<idCompOrigen<<" con la computadora "
            <<idCompDestino<<endl;
}

void eliminarConexion(int idCompOrigen, int idCompDestino, 
                      struct Lista *computadoras, int cantComputadoras){
    int indiceCompOrigen, indiceCompDestino;
    indiceCompOrigen = idCompOrigen-1;
    indiceCompDestino = idCompDestino-1;
    eliminaNodo(computadoras[indiceCompOrigen], indiceCompDestino);
    cout<<"Se desconecto la computadora "<<idCompOrigen<<" con la computadora "
            <<idCompDestino<<endl;
}

void hayEscaladaPrivilegios(int idCompOrigen, int idCompDestino, 
                            struct Lista *computadoras, int cantComputadoras){
    int indiceCompOrigen, indiceCompDestino;
    indiceCompOrigen = idCompOrigen-1;
    indiceCompDestino = idCompDestino-1;
    cout<<"VERIFICACION: de computadora "<<idCompOrigen<<" a "<<idCompDestino<<endl;
    cout<<"RESULTADO: ";
    struct Nodo *ptComp = computadoras[idCompOrigen].cabeza;
    struct Nodo *ptAux = ptComp;
    struct Nodo *ptUltimo = nullptr;
    int cambioComputadora = 0;
    int existe = 0;
    while (ptAux != nullptr){
        if (ptAux->elemento==indiceCompDestino){
            existe = 1;
            break;
        } else {
            ptUltimo = ptAux;
            ptAux = computadoras[ptAux->elemento].cabeza;
        }
    }
    if (existe){
        cout <<"Si hay escalada de privilegios";
    } else {
        cout << "No hay escalada de privilegios";
    }
    cout <<endl;
}

void imprimirRed(struct Lista *computadoras, int cantComputadoras){
    for(int i=0; i<cantComputadoras; i++){
        cout<<"Computadora "<<i+1<<": ";
        if (not esListaVacia(computadoras[i])) imprime(computadoras[i]);
        else cout << endl;
    }
}