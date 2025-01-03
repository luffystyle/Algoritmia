/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"

void obtenerMaxPureza(int terreno[10][10], int filaInicio, int filaFin, 
                      int numCol, int &maxPureza){
    int filaMedio, maxPurezaCol;
    if (filaInicio==filaFin){
        maxPurezaCol = maximo(terreno[filaInicio], numCol);
        if (maxPurezaCol>maxPureza){
            maxPureza = maxPurezaCol;
        }
        return;
    }
    filaMedio = (filaInicio+filaFin)/2;
    obtenerMaxPureza(terreno, filaInicio, filaMedio, numCol, maxPureza);
    obtenerMaxPureza(terreno, filaMedio+1, filaFin, numCol, maxPureza);
}

int maximo(int *arr, int n){
    int max = 0;
    for(int i=0; i<n; i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void obtenerMuestrasMaxNiveles(int terreno[10][10], int idFila, int filaFin, 
                               int numCol, int *muestrasMaxNiveles, 
                               int &cantMuestras, int &maxCantMuestras){
    if (idFila>filaFin) return;
    int cant;
    if (terreno[idFila][0]==0){
        cant = cuentaMuestras1(terreno[idFila], 0, numCol-1);
    } else {
        cant = cuentaMuestras2(terreno[idFila], 0, numCol-1);
    }
    if (cant>=maxCantMuestras){
        if (cant>maxCantMuestras){
            maxCantMuestras = cant;
            cantMuestras = 0;
        }
        muestrasMaxNiveles[cantMuestras] = idFila+1;
        cantMuestras++;
    }
    obtenerMuestrasMaxNiveles(terreno, idFila+1, filaFin, numCol, 
            muestrasMaxNiveles, cantMuestras, maxCantMuestras);
}

int cuentaMuestras1(int *arr, int inicio, int fin){
    int contador;
    if (inicio==fin){
        if (arr[inicio]!=0){
            contador = 1;
        } else {
            contador = 0;
        }
        return contador;
    }
    int medio = (inicio+fin)/2;
    if (arr[medio]==0){
        contador = 0;
        return contador + cuentaMuestras1(arr, medio+1, fin);
    } else {
        contador = fin-medio+1;
        return contador + cuentaMuestras1(arr, inicio, medio-1);
    }
}

int cuentaMuestras2(int *arr, int inicio, int fin){
    int contador;
    if (inicio>fin) return 0;
    if (inicio==fin){
        if (arr[inicio]!=0){
            contador = 1;
        } else {
            contador = 0;
        }
        return contador;
    }
    int medio = (inicio+fin)/2;
    if (arr[medio]==0){
        contador = 0;
        return contador + cuentaMuestras2(arr, inicio, medio-1);
    } else {
        contador = medio-inicio+1;
        return contador + cuentaMuestras2(arr, medio+1, fin);
    }
}