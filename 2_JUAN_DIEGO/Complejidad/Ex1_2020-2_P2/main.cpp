/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

/*============================================================================*/
/*===============================Real solution================================*/
/*============================================================================*/

void contagios(int dias,int*cifras,int*intervalos){
    struct Pila pila;
    construir(pila);
    int i = 0;
    int n=1;
    
    while(i<dias){//el 
        if(esPilaVacia(pila)){
            apilar(pila,cifras[i],n);
            Nodo*nodo = cima(pila);
            intervalos[i]=nodo->incremento;
            i++;
            n=1;
        }else{
            if(cifras[i]>cima(pila)->elemento){
                int increase=pila.lista.cabeza->incremento;
                desapilar(pila);
                n+=increase;
            }else{
                if(cifras[i]<cima(pila)->elemento){
                    apilar(pila,cifras[i],n);
                    Nodo*nodo = cima(pila);
                    intervalos[i]=nodo->incremento;
                    n=1;
                }
                i++;
            }
        }
    }
    cout<<"Los incrementos son: {";
    for(int j=0;j<dias;j++){
        cout<<intervalos[j]-1;
        if(j<7)cout<<",";
    }
    cout<<"}";
}

int main(int argc, char** argv) {
    
    int dias=8;
    int cifras[dias]={10,20,15,10,12,10,13,18};
    int intervalos[8];
    
    contagios(dias,cifras,intervalos);

    return 0;
}

/*============================================================================*/
/*============================Alternative solution============================*/
/*============================================================================*/
//void contagios(int dias,int*cifras,int*intervalos){
//    struct Pila pila;
//    construir(pila);
//    int max_cont=0,max=0;
//    int mayor_cont=0,mayor=0;
//    int n=0;
//    int i=0,cent,flag=0;
//    
//    while(1){
//        cent=1;
//        apilar(pila,cifras[i]);
//        if(cifras[i-1]<cima(pila)){
//            n=1;
//            if(cima(pila)>max){
//                max=cifras[i+1];
//            }
//            if(max_cont>0 && mayor_cont>0){
//                if(cima(pila)<mayor){
//                    n=mayor_cont-2;
//                }else{
//                    n=max_cont-2;
//                    mayor_cont=0;
//                }
//            }
//            if(cent){                
//                max_cont++;
//                cent=0;
//            }            
//        }else{
//            n=0;                  
//        }
//        if(cent){
//            max_cont++;
//        }
//        if(max_cont>1){
//            if(cima(pila)>mayor){
//                mayor=cifras[i+1];
//            }
//            mayor_cont++;
//        }        
//        intervalos[i]=n;
//        cout<<intervalos[i]<<" ";
//        desapilar(pila);
//        i++;
//        if(i==dias)break;
//    }
//}
//
//int main(int argc, char** argv) {
//    
//    int dias=8;
//    int cifras[dias]={10,20,15,10,12,10,13,18};
//    int intervalos[8];
//    
//    contagios(dias,cifras,intervalos);
//    
//
//    return 0;
//}

/*============================================================================*/
/*============================================================================*/
/*============================================================================*/