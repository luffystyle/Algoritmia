/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"


void recursivoOrden(struct Pila &pila,int n){
    if(esPilaVacia(pila) or n==1) return;
    int mayor = desapilar(pila),aux; 
    int i=1;
    Pila pila2;
    construir(pila2);
    while(i<n){
        aux = desapilar(pila);
        if(aux>mayor){
            apilar(pila2,mayor);
            mayor = aux;
        }else{
            apilar(pila2,aux);
        }
        i++;
    }
    apilar(pila,mayor);
    while(!esPilaVacia(pila2)){
        apilar(pila,desapilar(pila2));
    }
    destruirPila(pila2);
    recursivoOrden(pila,n-1);
}

int main(int argc, char** argv) {
    int arrIncre[8]={10,20,15,10,12,10,13,18};
    int dias[8];
    Pila pila;
    construir(pila);
    int i=0;
    while(i<8){
        int cimaAux = cima(pila); 
        if(!esPilaVacia(pila) and arrIncre[i] >= arrIncre[cimaAux]){
            int cim = desapilar(pila);
        }else{
            if(esPilaVacia(pila)){
                dias[i]=i;
            }else{
                dias[i]= i - cimaAux - 1;
            }
            apilar(pila,i);
            i++;
        }
        
        
    }
    
    for(int i=0;i<8;i++){
        cout<< dias[i]<<" ";
    }
    
    
    Pila pila2;
    construir(pila2);
    apilar(pila2,2);
    apilar(pila2,6);
    apilar(pila2,3);
    apilar(pila2,4);
    apilar(pila2,5);
    apilar(pila2,0);
    apilar(pila2,1);
    
    recursivoOrden(pila2,pila2.lista.longitud);
    imprimir(pila2);
    cout<<endl<<desapilar(pila2);
    return 0;
}


