/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"

using namespace std;

void ordenarMezcla(int *arr, int inicio, int fin){
    if (inicio==fin) return;
    int medio = (inicio+fin)/2;
    ordenarMezcla(arr, inicio, medio);
    ordenarMezcla(arr, medio+1, fin);
    mezclar(arr, inicio, medio, fin);
}

void mezclar(int *arr, int inicio, int medio, int fin){
    int longitud1 = medio-inicio+1;
    int longitud2 = fin-medio;
    int aux1[longitud1+1];
    int aux2[longitud2+1];
    aux1[longitud1] = 9999;
    aux2[longitud2] = 9999;
    for(int i=inicio; i<=medio; i++){
        aux1[i-inicio] = arr[i];
    }
    for(int i=medio+1; i<=fin; i++){
        aux2[i-medio-1] = arr[i];
    }
    int p = 0, q = 0;
    for(int i=inicio; i<=fin; i++){
        if (aux1[p]>aux2[q]){
            arr[i] = aux2[q];
            q++;
        } else {
            arr[i] = aux1[p];
            p++;
        }
    }
}

int buscarSolitario(int *arr, int inicio, int fin){
    if (inicio==fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    if ((medio%2)==0){
        if (arr[medio]==arr[medio+1])
            return buscarSolitario(arr, medio+2, fin);
        else return buscarSolitario(arr, inicio, medio);
    } else {
        if (arr[medio-1]==arr[medio])
            return buscarSolitario(arr, medio+1, fin);
        else return buscarSolitario(arr, inicio, medio-1);
    }
}