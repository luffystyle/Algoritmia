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
#include "Nodo.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "Cola.h"
#include "funcionesCola.h"


void hanoi(int n,struct Pila &pilaA,struct Pila &pilaB,struct Pila &pilaC, int valor){
    if(n==1){
        if(cima(pilaA)<valor){
            apilar(pilaB,desapilar(pilaA));
        }
        return;
    }
    hanoi(n-1,pilaA,pilaC,pilaB,valor);
    if(cima(pilaA)<valor and cima(pilaA)!=-1){
        apilar(pilaB,desapilar(pilaA));
    }
    hanoi(n-1,pilaC,pilaB,pilaA,valor);
}

void contruirPila(struct Cola &faja,struct Pila &pila){
    struct Pila pilaB,pilaC;
    construir(pilaC);
    construir(pilaB);
    int longit,aux1,aux2;
    while(!esColaVacia(faja)){
        longit = longitud(pila); 
        if(esPilaVacia(pila)){
            apilar(pila,desencolar(faja));
        }else if(longit==1){
            aux1=desapilar(pila);
            aux2 = desencolar(faja);
            if(aux1<aux2){
                apilar(pila,aux2);
                apilar(pila,aux1);
            }else{
                apilar(pila,aux1);
                apilar(pila,aux2);
            }
        }else{
            aux1=desencolar(faja);
            aux2=cima(pila);
            if(aux1<aux2){
                apilar(pila,aux1);
            }else{
                apilar(pilaB,aux1);// lo guardo en una pila auxiliar
                //ahora saco de la pila principal hasta que el disco que siga sea mayor al aux1
                hanoi(longitud(pila),pila,pilaB,pilaC,aux1);
                apilar(pila,aux1);
                hanoi(longitud(pilaB),pilaB,pila,pilaC,aux1);
//                while(!esPilaVacia(pilaC)){
//                    apilar(pila,desapilar(pilaC));
//                }
            }
        }
        
    }
    imprimir(pila);
    
}

int main(int argc, char** argv) {
    
    struct Cola faja;
    construir(faja);
    encolar(faja,2);
    encolar(faja,8);
    encolar(faja,10);
    encolar(faja,8);
    encolar(faja,5);
    encolar(faja,3);
    encolar(faja,3);
    encolar(faja,9);
    
    struct Pila pila;
    construir(pila);
    contruirPila(faja,pila);
    
    
    return 0;
}





















