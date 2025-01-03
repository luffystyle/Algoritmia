/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "Lote.h"
#include "Funciones.h"

using namespace std;

int encontrarLoteInicial(int cantProductos, struct Lote * arrLotes, int posInicio, int posFin){
    if (posInicio > posFin) return -1;
    if (posInicio == posFin){
        if (arrLotes[posInicio].cantidad == cantProductos){
            return arrLotes[posInicio].codigo;
        } else {
            return -1;
        }
    }
    int posMedio = (posInicio + posFin)/2;
    if (arrLotes[posMedio].cantidad == cantProductos){
        return encontrarLoteInicial(cantProductos, arrLotes, posInicio, posMedio);
    } else if (arrLotes[posMedio].cantidad > cantProductos){
        return encontrarLoteInicial(cantProductos, arrLotes, posInicio, posMedio-1);
    } else {
        return encontrarLoteInicial(cantProductos, arrLotes, posMedio+1, posFin);
    }
}

int encontrarLoteFinal(int cantProductos, struct Lote * arrLotes, int posInicio, int posFin){
    if (posInicio > posFin) return -1;
    if (posInicio == posFin){
        if (arrLotes[posInicio].cantidad == cantProductos){
            return arrLotes[posInicio].codigo;
        } else {
            return -1;
        }
    }
    if ((posFin-posInicio)==1){
        if (arrLotes[posFin].cantidad == cantProductos) return arrLotes[posFin].codigo;
        if (arrLotes[posFin].cantidad < cantProductos) return -1;
        if (arrLotes[posFin].cantidad > cantProductos){
            return encontrarLoteFinal(cantProductos, arrLotes, posInicio, posInicio);
        }
    }
    int posMedio = (posInicio + posFin)/2;
    if (arrLotes[posMedio].cantidad == cantProductos){
        return encontrarLoteFinal(cantProductos, arrLotes, posMedio, posFin);
    } else if (arrLotes[posMedio].cantidad > cantProductos){
        return encontrarLoteFinal(cantProductos, arrLotes, posInicio, posMedio-1);
    } else {
        return encontrarLoteFinal(cantProductos, arrLotes, posMedio+1, posFin);
    }
}