/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include <cmath>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
void prodAlimenticios(Pila & contenedor,int cant,int capacidad){
    struct Pila caja1,caja2,caja3,caja4;
    construir(caja1);
    construir(caja2);
    construir(caja3);
    construir(caja4);
    Pila*arr[4]={&caja1,&caja2,&caja3,&caja4};
    int n=0;
    int id;
    int date,date2;
    int days,days2=999;
    int large=caja1.lista.longitud;
    
    Nodo * brazo = cima(contenedor);
    
    while(!esPilaVacia(contenedor)){
        brazo = cima(contenedor);
        id=brazo->ID;
        date=brazo->fecha;
        days=((date%10000)/100)*60+date%100;
        
        if(arr[n]->lista.longitud!=3){
            desapilar(contenedor);
            if(esPilaVacia(*arr[n]) || days<=days2){
                apilar(*arr[n],date,id);
                date2=cima(*arr[n])->fecha;
                days2=((date2%10000)/100)*60+date2%100;
            }else{
                while(days2<days){
                    apilar(contenedor,cima(*arr[n])->fecha,cima(*arr[n])->ID);
                    desapilar(*arr[n]);
                    if(!esPilaVacia(*arr[n])){                        
                        date2=cima(*arr[n])->fecha;
                        days2=((date2%10000)/100)*60+date2%100;
                    }else{
                        if(n>0){
                            n--;
                        }else
                            break;
                    }                    
                }
                apilar(*arr[n],date,id);
            }            
        }else{
            date2=cima(*arr[n])->fecha;
            days2=((date2%10000)/100)*60+date2%100;
            if(days>days2){
                desapilar(contenedor);
                apilar(contenedor,cima(*arr[n])->fecha,cima(*arr[n])->ID);
                desapilar(*arr[n]);
                apilar(*arr[n],date,id);                
            }else
                n++; 
        }               
    } 
    cout<<"Caja 1: ";
    imprimir(caja1);
    cout<<"Caja 2: ";
    imprimir(caja2);
    cout<<"Caja 3: ";
    imprimir(caja3);
    cout<<"Caja 4: ";
    imprimir(caja4);
}
int main(int argc, char** argv) {
    int cantProd=4;
    int caapacidadCaj=3;
    struct Pila contenedor;
    construir(contenedor);
    /*Apilamos elementos en la pila*/
    apilar(contenedor, 20110603,1);
    apilar(contenedor, 20221006,2);
    apilar(contenedor, 20220630,3);
    apilar(contenedor, 20220918,4);
    apilar(contenedor, 20221003,5);
    apilar(contenedor, 20221106,6);
    apilar(contenedor, 20220814,7);
    apilar(contenedor, 20221212,8);
    apilar(contenedor, 20221130,9);
    apilar(contenedor, 20221224,10);
    prodAlimenticios(contenedor,cantProd,caapacidadCaj);
//    imprimir(contenedor);   
    return 0;
}

