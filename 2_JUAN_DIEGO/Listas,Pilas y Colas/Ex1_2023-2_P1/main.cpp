/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
int main(int argc, char** argv) {

    struct Lista cam1,cam2,cam3,cam4,cam5;
    int n=5;// cant camiones
    int arrTortugas[4]={34,24,12,30};//{Leonardo,Rafael,Donatello,MiguelA.}
    /*Construimos la lista, la lista esta vacía*/
    construir(cam1);
    construir(cam2);
    construir(cam3);
    construir(cam4);
    construir(cam5);    
       
    /*Camion 1*/
    insertarAlFinal(cam1,8);
    insertarAlFinal(cam1,9);
    /*Camion 2*/
    insertarAlFinal(cam2,15);
    insertarAlFinal(cam2,9);
    /*Camion 3*/
    insertarAlFinal(cam3,3);
    insertarAlFinal(cam3,6);
    /*Camion 4*/
    insertarAlFinal(cam4,1);
    insertarAlFinal(cam4,6);
    insertarAlFinal(cam4,8);
    insertarAlFinal(cam4,4);
    insertarAlFinal(cam4,6);
    /*Camion 5*/
    insertarAlFinal(cam5,5);
    insertarAlFinal(cam5,6);
    insertarAlFinal(cam5,3);
    Lista*arrCamion[n]={&cam1,&cam2,&cam3,&cam4,&cam5};
    int pesos[n]={}; 
    
    imprime(cam1);
    imprime(cam2);
    imprime(cam3);
    imprime(cam4);
    imprime(cam5);
    
    

    return 0;
}

