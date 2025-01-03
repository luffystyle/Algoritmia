/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"

using namespace std;

void insertaDiaTurno(struct ArbolBinarioBusqueda & arbol, int produccion[4][7], 
                     int numDias, int numTurnos){
    struct Elemento arr[28];
    int cantDatos = numDias*numTurnos;
    pasarMatrizArreglo(arr, produccion, numDias, numTurnos);
    balancearArbol(arbol, arr, 0, 27);
}

void pasarMatrizArreglo(struct Elemento * arr, int produccion[4][7], 
                        int numDias, int numTurnos){
    int k = 0;
    struct Elemento elemento;
    for(int i=0; i<numDias; i++){
        for(int j=0; j<numTurnos; j++){
            elemento.dia = i+1;
            elemento.turno = j+1;
            elemento.cantidad = produccion[j][i];
            arr[k] = elemento;
            k++;
        }
    }
}

void balancearArbol(struct ArbolBinarioBusqueda & arbol, struct Elemento * arr, 
                    int posInicio, int posFin){
    if (posInicio>posFin) return;
    int posMedio = (posInicio+posFin)/2;
    insertar(arbol, arr[posMedio]);
    balancearArbol(arbol, arr, posInicio, posMedio-1);
    balancearArbol(arbol, arr, posMedio+1, posFin);
}

int verificarEquilibrio(const struct ArbolBinarioBusqueda & arbol){
    return esEquilibrado(arbol.arbolBinario);
}