/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 27 de abril de 2024, 08:14 AM
 */
//Alumno: Melvin Custodio   
//Código: 20203530

#include <iostream>
#include <cstring>
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#define ANIOACTUAL 2024
using namespace std;


void prioridadPorEdad(struct Lista &tad, int dia, int mes, int anio, char* cod){
    struct Nodo * nuevoNodo = crearNodo(dia, mes, anio, cod, nullptr);
    
    if( tad.cabeza == nullptr ){//Está vacío
        tad.cabeza=nuevoNodo;
        tad.cola=nuevoNodo;
        //Apuntará al mayor a 80
        if( (ANIOACTUAL-anio) > 80 ){
            tad.mayor= nuevoNodo;
        }
        //Apuntará al menor a 10
        if((ANIOACTUAL-anio) < 10 ){
            tad.menor= nuevoNodo;
        }
    }else{
        if ((ANIOACTUAL-anio) > 80){
            //Si es que donde apunta al mayor no está vacio
            if(tad.mayor!=nullptr){
                //Si el que le sigue al mayor es nullptr, quiere decir que solo
                //Hay personas mayores a 80 años, por lo que la cola se conecta al nuevo nodo
                if(tad.mayor->siguiente == nullptr){
                    tad.cola= nuevoNodo;
                }
                nuevoNodo->siguiente =tad.mayor->siguiente;
                tad.mayor->siguiente=nuevoNodo;
                tad.mayor = nuevoNodo;
            }else{
                //Si es que no hay mayores a 80, se debe colocar antes que
                //todos los valores que hayan en la cola
                tad.mayor = nuevoNodo;
                nuevoNodo->siguiente= tad.cabeza;
                tad.cabeza = nuevoNodo;  
            }
        }else{
            if( (ANIOACTUAL-anio) < 10 ){
                //Si existe un menor, se debe incluir en su posicion
                if(tad.menor!=nullptr){
                    if(tad.menor->siguiente == nullptr){
                        tad.cola= nuevoNodo;
                    }
                    nuevoNodo->siguiente =tad.menor->siguiente;
                    tad.menor->siguiente=nuevoNodo;
                    tad.menor = nuevoNodo;
                }else{
                    tad.menor = nuevoNodo;
                    //Si es que no hay mayores a 80 años, se coloca antes que
                    //todos
                    if(tad.mayor== nullptr){
                        nuevoNodo->siguiente= tad.cabeza;
                        tad.cabeza = nuevoNodo;  
                    }else{
                        //Si hay mayores a 80 años, se debe colocar entre los
                        //que son mayores a 80 y los demas
                        nuevoNodo->siguiente= tad.mayor->siguiente;
                        tad.mayor->siguiente=nuevoNodo;
                    }
                }
            }else{
                //Se encola al final si no cumple las dos prioridades
                tad.cola-> siguiente = nuevoNodo;
                tad.cola = nuevoNodo;
                
            }
        }
    }
    
    tad.longitud ++;
}

int main(int argc, char** argv) {
    
    struct Cola cola;
    construir(cola);
    char* cod;
    //Esto es para la parte 1, descomentar para probar
//    //Encolamos
//    cod= new char (strlen("BXQ778")+1);
//    strcpy(cod, "BXQ778");
//    encolar(cola, 30, 5, 1943, cod);
//    
//    cod= new char (strlen("HRP112")+1);
//    strcpy(cod, "HRP112");
//    encolar(cola, 20, 4, 2014, cod);
//    
//    cod= new char (strlen("PRL625")+1);
//    strcpy(cod, "PRL625");
//    encolar(cola, 26, 6, 1975, cod);
//    
//    cod= new char (strlen("MKP157")+1);
//    strcpy(cod, "MKP157");
//    encolar(cola, 22, 10, 1949, cod);
//    
//    cod= new char (strlen("ARH749")+1);
//    strcpy(cod, "ARH749");
//    encolar(cola, 13, 5, 2020, cod);
//    
//    cod= new char (strlen("HRQ931")+1);
//    strcpy(cod, "HRQ931");
//    encolar(cola, 14, 2, 1930, cod);
    
//    //Imprime los valores sin prioridad
//    imprime(cola);
    
    
    //Parte b, encolamos por prioridad
    
    cod= new char (strlen("BXQ778")+1);
    strcpy(cod, "BXQ778");
    prioridadPorEdad(cola.lista, 30, 5, 1943, cod);
    
    cod= new char (strlen("HRP112")+1);
    strcpy(cod, "HRP112");
    prioridadPorEdad(cola.lista, 20, 4, 2014, cod);
    
    cod= new char (strlen("PRL625")+1);
    strcpy(cod, "PRL625");
    prioridadPorEdad(cola.lista, 26, 6, 1975, cod);
    
    
    cod= new char (strlen("MKP157")+1);
    strcpy(cod, "MKP157");
    prioridadPorEdad(cola.lista, 22, 10, 1949, cod);
    
    
    cod= new char (strlen("ARH749")+1);
    strcpy(cod, "ARH749");
    prioridadPorEdad(cola.lista, 13, 5, 2020, cod);
    
    
    cod= new char (strlen("HRQ931")+1);
    strcpy(cod, "HRQ931");
    prioridadPorEdad(cola.lista, 14, 2, 1930, cod);
    
    
    //Parte c, impresión de lo solicitado
    imprime(cola);
    
    return 0;
}

