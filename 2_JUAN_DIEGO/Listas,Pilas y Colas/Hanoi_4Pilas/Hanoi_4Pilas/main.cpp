/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
using namespace std;

void hanoi(int n, Pila & A, Pila & B, Pila & C){//se realiza el algortimo de hanoi para reorganizar las pilas
    if(n==0)return;
    hanoi(n-1,A,C,B);
    apilar(C,desapilar(A));
    hanoi(n-1,B,A,C);
}

void hanoi4(Cola & cola,int n){
    struct Pila PilaMain,PilaAux1,PilaAux2,PilaAux3;
    int yaApilo=0;
    construir(PilaMain);
    construir(PilaAux1);
    construir(PilaAux2);
    construir(PilaAux3);
    //Desencolamos y apilamos el primer elemento
    apilar(PilaMain,desencolar(cola));
    //imprimir(PilaMain);
    while(!esColaVacia(cola)){
        if(esPilaVacia(PilaMain)){
            apilar(PilaMain,desencolar(cola));
            hanoi(PilaAux3.lista.longitud,PilaAux3,PilaAux2,PilaMain);
            continue;
        }
        if(cola.lista.cabeza->elemento<PilaMain.lista.cabeza->elemento){
            apilar(PilaMain,desencolar(cola));
            yaApilo=1;
            if(yaApilo && !esPilaVacia(PilaAux3)){
                hanoi(PilaAux3.lista.longitud,PilaAux3,PilaAux2,PilaMain);
            }
        }else{
            apilar(PilaAux1,desapilar(PilaMain));
            while(!esPilaVacia(PilaAux3)){
                 hanoi(PilaAux3.lista.longitud,PilaAux3,PilaAux2,PilaAux1);
            };
            hanoi(PilaAux1.lista.longitud,PilaAux1,PilaAux2,PilaAux3);
        }
    }
    imprimir(PilaMain);
}


int main(int argc, char** argv) {
    struct Cola cola;
    
    construir(cola);
    
    int n;
    
    encolar(cola, 50);
    encolar(cola, 100);
    encolar(cola, 200);
    encolar(cola, 150);
    encolar(cola, 50);
    encolar(cola, 200);
    encolar(cola, 100);
    imprime(cola);
    n=cola.lista.longitud;
    cout<<n<<endl;
    hanoi4(cola,n);
    
    return 0;
}

