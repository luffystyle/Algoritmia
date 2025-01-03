/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
//exam 1 2020.2
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

void intervaloIncremento(int n,int *arr,int *arrFinal){
    for(int i=0;i<n;i++) arrFinal[i]=0;
    Pila pila;
    construir(pila);
    int i=0;
    while(i<n){
        Nodo* cima1 = cima(pila);
        if(!esPilaVacia(pila) and arr[i] >=arr[cima1->elemento] ){
            struct Nodo* cim = desapilar(pila);
        }else{
            if(esPilaVacia(pila)){
                arrFinal[i]=i;
            }else{
                arrFinal[i] = i -cima1->elemento -1;
            }
            apilar(pila,i,1);
            i++;
        }        
    }
}



int main(int argc, char** argv) {
    int n = 8;
    int arr[8] = {10,20,15,10,12,10,13,18};
    int arrFinal[8];
    
    intervaloIncremento(n,arr,arrFinal);
    for(int i=0;i<n;i++) cout<<arrFinal[i]<<" ";
    
    return 0;
}

