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
int frecmax=0;
int durmax=0;

int badSuny(int n,int*frecuencias){
    struct Pila pila;
    construir(pila);    
    int i=0;
    int timefrec,timedur;
    int temp;
    int areaCima;
    int areamax=0;
    while(i<n){
        if(esPilaVacia(pila) || frecuencias[i]>=frecuencias[cima(pila)]){
            apilar(pila,i);
            i++;
        }else{
           temp=desapilar(pila);
           if(esPilaVacia(pila)){
               areaCima=frecuencias[temp]*i;
               timefrec=frecuencias[temp];
               timedur=i;
           }else{
               areaCima=frecuencias[temp]*(i-cima(pila)-1);
               timefrec=frecuencias[temp];
               timedur=i-cima(pila)-1;
           }
           if(areamax<areaCima){    
               areamax=areaCima;
               frecmax=timefrec;
               durmax=timedur;
           }
        }
    }
    while(!esPilaVacia(pila)){
        temp=desapilar(pila);
        if(esPilaVacia(pila)){
            areaCima=frecuencias[temp]*i;
            timefrec=frecuencias[temp];
            timedur=i;
        }else{
            areaCima=frecuencias[temp]*(i-cima(pila)-1);
            timefrec=frecuencias[temp];
            timedur=i-cima(pila)-1;
        }
        if(areamax<areaCima){    
            areamax=areaCima;
            frecmax=timefrec;
            durmax=timedur;
        }
    }
    return areamax;
}

int main(int argc, char** argv) {

    int n=11;
    int frecuencias[n]={1,2,1,4,5,6,4,5,2,2,1};
    
    cout<<"El area mayor es: "<<badSuny(n,frecuencias)<<endl;
    cout<<"Frecuencia maxima="<<frecmax<<" "<<"Duración="<<durmax;
    return 0;
}

//void badSuny(int n,int*frecuencias){
//    int i=0;
//    int temp;
//    int aux;
//    struct Pila pila;
//    construir(pila);
//    while(i<n){
//        if(esPilaVacia(pila)){
//            apilar(pila,frecuencias[i]);
//            i++;
//        }else{
//            temp=desapilar(pila);
//            if(!esPilaVacia(pila))
//                aux=cima(pila);            
//            if(frecuencias[i]>temp and (temp<aux or esPilaVacia(pila))){
//                apilar(pila,temp);
//                apilar(pila,frecuencias[i]);
//            }else if(frecuencias[i]>=temp and temp>=aux){
//                apilar(pila,temp);
//                apilar(pila,cima(pila));
//            }else if(frecuencias[i]<=temp){
//                apilar(pila,temp);
//                apilar(pila,frecuencias[i]);
//            }
//            i++;
//        }
//        
//    }
//    imprimir(pila);
//    //Buscamos la frecuencia mayor y hallamos la cantidad de veces que se repite
//    int mayor=0;
//    int a;
//    int cont=0;
//    while(!esPilaVacia(pila)){
//        a=desapilar(pila);
//        if(a>mayor){
//            mayor=a;
//            cont=0;
//        }
//        if(a==mayor){
//            cont++;
//        }
//    } 
//    cout<<"Frecuencia maxima="<<mayor<<" "<<"Duración="<<cont;
//}