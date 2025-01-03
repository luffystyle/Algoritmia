/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"
#define n 7

using namespace std;
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

int skynerd(int servidor[n][n]){
    //Creando una pila
    struct Pila pila;
    construir(pila);
    for(int i=0;i<n;i++){
         apilar(pila,i);
    }
//    imprimir(pila);
    //Descartando donde no puede estar skynerd
    int a,b;
    int sky;
    int valido=0;
    
    while(1){
        a=desapilar(pila);
        b=desapilar(pila);
        if(servidor[a][b]==0){//skynerd no se encuentra en el servidor a por lo que se descarta
            apilar(pila,b);
        }else if(servidor[a][b]!=0){
            apilar(pila,a);
        }
        if(longitud(pila)==1){
            sky=cima(pila);
            break;
        }        
    }
    //Comprobando si efectivamente skynerd esta en el servidor 5;
    for(int j=0;j<n;j++){
        if(servidor[j][sky]==0 and (servidor[sky][j]>0 || servidor[sky][sky]==0)){
            valido=1;
        }else{
            break;
        }
    }
    if(valido){
        return sky+1;
    }else{
        return 0;
    }
}

int main(int argc, char** argv) {
    
    
     int servidor[n][n]{{0,0,0,0,0,0,0},
                    {10,0,20,30,0,20,40},
                    {0,0,0,0,0,100,0},
                    {0,0,0,0,0,80,0},
                    {50,10,5,10,0,100,4},
                    {100,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}};
     
     
     if(skynerd(servidor)){
         cout<<"Skynerd se encuentra en el servidor: "<<skynerd(servidor);
     }else{
         cout<<"Skynerd no esta en la red.";
     }    
    return 0;
}

