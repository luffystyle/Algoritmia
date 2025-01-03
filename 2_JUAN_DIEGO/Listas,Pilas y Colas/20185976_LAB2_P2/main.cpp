/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"
#include "Lista.h"

using namespace std;
#include "funcionesPila.h"
#include "funcionesLista.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
void hanoi(int n, Pila & A, Pila & B, Pila & C){//se realiza el algortimo de hanoi para reorganizar las pilas
    if(n==0)return;
    hanoi(n-1,A,C,B);
    apilar(C,desapilar(A));
    hanoi(n-1,B,A,C);
}
void robot(Lista & faja,int n){
    
    int elemento;//se utilizara como brazo del robot
    int j;
    int yaApilo;
    //Creamos las pilas 
    Pila pilaPrinc,pilaAux1,pilaAux2;
    construir(pilaPrinc);
    construir(pilaAux1);
    construir(pilaAux2);
    //Apilamos el primer elemento de la faja en la pila principal
    apilar(pilaPrinc,retornaCabeza(faja));
    eliminaCabeza(faja);
    //Apilamos los elementos restantes, respetando el peso de los objetos
    for(int i=0;i<n-1;i++){
        j=1;
        yaApilo=1;
       elemento=retornaCabeza(faja);
       eliminaCabeza(faja);
       if((elemento%1000)+(elemento/1000)<=pilaPrinc.lista.cabeza->elemento%1000+(pilaPrinc.lista.cabeza->elemento/1000)){
           apilar(pilaPrinc,elemento);
       }else{
           while((elemento%1000)+(elemento/1000)>pilaPrinc.lista.cabeza->elemento%1000+(pilaPrinc.lista.cabeza->elemento/1000)){
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
    cout<<"Pila principal organizada: "<<endl;
    imprimir(pilaPrinc);   
}
int main(int argc, char** argv) {
    
    int n=7;
    struct Lista faja;
    construir(faja);
    
    insertarAlFinal(faja,1050);
    insertarAlFinal(faja,2100);
    insertarAlFinal(faja,1200);
    insertarAlFinal(faja,1150);
    insertarAlFinal(faja,2050);
    insertarAlFinal(faja,2200);
    insertarAlFinal(faja,1100);
    
//    struct Pila A,B,C;
//    construir(A);
//    construir(B);
//    construir(C);
//    /*Apilamos elementos en la pila*/
//    apilar(A, 1);
//    apilar(A, 2);
//    apilar(A, 3);
//    apilar(A, 4);
//    imprimir(A);
//    hanoi(n,A,B,C);
//    imprimir(C);
    cout<<"Faja inicial: "<<endl;
    imprime(faja);
    robot(faja,n);
    cout<<"Faja despues de la operacion: "<<endl;
    imprime(faja);
    return 0;
}

