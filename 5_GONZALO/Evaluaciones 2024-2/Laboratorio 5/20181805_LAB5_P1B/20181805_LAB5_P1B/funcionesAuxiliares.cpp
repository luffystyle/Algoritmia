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

void insertaCantidad(struct ArbolBinarioBusqueda & arbol, int produccion[4][7], 
                     int numDias, int numTurnos){
    struct Elemento arr[28];
    int cantDatos = numDias*numTurnos;
    pasarMatrizArreglo(arr, produccion, numDias, numTurnos);
    ordenarMezcla(arr, 0, cantDatos-1);
//    imprimir(arr);
    balancearArbol(arbol, arr, 0, cantDatos-1);
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

void ordenarMezcla(struct Elemento * arr, int posInicio, int posFin){
    if (posInicio == posFin) return;
    int posMedio = (posInicio+posFin)/2;
    ordenarMezcla(arr, posInicio, posMedio);
    ordenarMezcla(arr, posMedio+1, posFin);
    mezclar(arr, posInicio, posMedio, posFin);
}

void mezclar(struct Elemento * arr, int posInicio, int posMedio, int posFin){
    int longitud1 = posMedio-posInicio+1;
    int longitud2 = posFin - posMedio;
    struct Elemento arr1[longitud1+1];
    struct Elemento arr2[longitud2+1];
    arr1[longitud1].cantidad = 99999;
    arr1[longitud1].dia = 0;
    arr1[longitud1].turno = 0;
    arr2[longitud2].cantidad = 99999;
    arr2[longitud2].dia = 0;
    arr2[longitud2].turno = 0;
    for(int i=posInicio; i<=posMedio; i++){
        arr1[i-posInicio] = arr[i];
    }
    for(int i=posMedio+1; i<=posFin; i++){
        arr2[i-posMedio-1] = arr[i];
    }
    int p = 0, q = 0;
    for(int i=posInicio; i<=posFin; i++){
        if (arr1[p].cantidad>arr2[q].cantidad){
            arr[i] = arr2[q];
            q++;
        } else if (arr1[p].cantidad<arr2[q].cantidad){
            arr[i] = arr1[p];
            p++;
        } else { // Si ambos tienen la misma cantidad
            if (arr1[p].dia>arr2[q].dia){
                arr[i] = arr2[q];
                q++;
            } else if (arr1[p].dia<arr2[q].dia){
                arr[i] = arr1[p];
                p++;
            } else { // Si ambos fueron producidos el mismo dia
                if (arr1[p].turno>arr2[q].turno){
                    arr[i] = arr2[q];
                    q++;
                } else if (arr1[p].turno<arr2[q].turno){
                    arr[i] = arr1[p];
                    p++;
                }
            }
        }
    }
}

void imprimir(struct Elemento * arr){
    for(int i=0; i<28; i++){
        cout << arr[i].cantidad << "-" << arr[i].dia << "-" << arr[i].turno << " ";
    }
    cout << endl;
}