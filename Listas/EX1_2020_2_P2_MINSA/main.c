/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Adrian Masashiri Fujiki Escobar
 * Code: 20203646
 * Created on 14 de octubre de 2022, 01:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void hallar_val_crec(Pila *pilaAux,int val_crec[],int arr_dias[],int n){
    ElementoPila aux; //la pila solo sirve como una mano
    int i=n;//i es el contador que recorrera todo el arreglo
    int indice=i;//indice refiere al primer elemento a analizarse
    int max=arr_dias[i];//almacena el elemento del indice
    
    while(1){
        if(i == 0 && indice == 0){ //si el indice y el contador es 0 se acaba el while
            val_crec[indice] = 0; //ademas al ser el primero, su intervalo es 0
            break; 
        }
        if(i<0){ //si el indice es menor que 0 es decir, si ya se acabo de analizar el maximo con los anteriores
            aux = pop(pilaAux);  //se hace pop de la pila que habia almacenado aquellos datos/aquel dato de la respuesta
            val_crec[indice] = aux; //el elemento pila que es un entero se almacena en el arreglo de val_crec/respuestas
            i = indice;//el i procede a tomar el valor del indice y luego será restado en -1 saliendo de esta condicional, asi los dos marcaran el mismo inicio
            indice = indice - 1; //el indice retrocedera en uno para marcar el nuevo inicio
            max = arr_dias[indice]; //el maximo se actualiza para realizar las siguientes comparaciones
        }else{
            if(i == indice){ //si el indice es igual que i
                push(pilaAux, 0);  //se coloca 0 en la pila
            }else{ //sino se analizan dos casos
                if(arr_dias[i] < max){ //cuando el valor maximo o primero es mayor que el elemento del arreglo
                    aux = pop(pilaAux);  //se hace pop al elemento de la pila
                    push(pilaAux, aux + 1); //se hace push del elemento de la pila +1, ya que se acumula un incremento
                }else{ //cuando el valor maximo es menor que el elemento del arreglo
                    aux = pop(pilaAux); //se hace pop del elemento de la pila, es decir hasta donde llego en acumulaciones
                    val_crec[indice] = aux; //se coloca como respuesta aquel valor
                    i = indice;  //se resetean las variables
                    indice = indice - 1;  //se resetean las variables
                    max = arr_dias[indice];  //se resetean las variables
                }
            } 
        }
        i--; 
    }
}

int main(int argc, char** argv) {
    Pila pilaAux;
    Pila arrPilas[5];
    int arr_dias[8]={10,20,15,10,12,10,13,18};
    int val_crec[8];
    construir_pila(&pilaAux);
    hallar_val_crec(&pilaAux,val_crec,arr_dias,7);
    for(int i=0;i<8;i++){
        printf(" %d ",val_crec[i]);
    }
    return (EXIT_SUCCESS);
}

