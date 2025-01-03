/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
using namespace std;

void hanoi(int n,Pila &A,Pila &B,Pila &C){
   if(n==0) return; 
   hanoi(n-1,A,C,B);
   apilar(C,desapilar(A));
   hanoi(n-1,B,A,C); 
    
}
void robot(Cola & cola,int n){
    Pila pilaPrinc,pilaAux1,pilaAux2; 
    construir(pilaPrinc);
    construir(pilaAux1);
    construir(pilaAux2);
    //Desencolamos y apilamos el primer elementos
    apilar(pilaPrinc,desencolar(cola));
    int elemento;
    int yaApilo;
    int j;
    //Desencolamos el siguiente elemento
    for(int i=0;i<n-1;i++){
        yaApilo=1;
        j=1;
        elemento=desencolar(cola);
        if(elemento<=pilaPrinc.lista.cabeza->elemento){
            apilar(pilaPrinc,elemento);
        }else{
            while(elemento>pilaPrinc.lista.cabeza->elemento){
                while(!esPilaVacia(pilaAux2)){
                    hanoi(pilaAux2.lista.longitud,pilaAux2,pilaAux1,pilaPrinc);
                }
                hanoi(j,pilaPrinc,pilaAux1,pilaAux2);
                if(esPilaVacia(pilaPrinc)){
                    apilar(pilaPrinc,elemento);
                    yaApilo=0;
                }
                j++;
            }
            if(yaApilo){
              apilar(pilaPrinc,elemento);   
            } 
            hanoi(pilaAux2.lista.longitud,pilaAux2,pilaAux1,pilaPrinc);
        }
    }
    imprimir(pilaPrinc);
}

int main(int argc, char** argv) {
    
    struct Cola cola;
    int n=6;
    
    construir(cola);    
    encolar(cola,2);
    encolar(cola,8);
    encolar(cola,10);
    encolar(cola,8);
    encolar(cola,5);
    encolar(cola,3);
    imprime(cola);
    robot(cola,n);   
    destruirCola(cola);

    return 0;
}

