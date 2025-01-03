/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Luis Rios
 *
 * Created on 22 de septiembre de 2024, 16:20
 */


#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "Nodo.h"
#include "funciones.h"
#define Ndias 5
using namespace std;

/*
 * 
 */

void fusionarListas(Lista&listaLunes,Lista&lista2){
    Nodo *recorrido1,*recorrido2,*aux;
    for(int i=0;i<longitud(lista2);i++){//0 LUNES 1 MARTES...
        recorrido1=listaLunes.cabeza;recorrido2=lista2.cabeza;
        for(int j=0;j<longitud(listaLunes);j++){
            if(recorrido2->elemento.hora>=recorrido1->elemento.hora){
                //vamos al siguiente de recorrido1
                recorrido1=recorrido1->siguiente;
                if(recorrido1==nullptr){
                    insertarAlFinal(listaLunes,recorrido2->elemento.hora,
                                    recorrido2->elemento.sucursal);
                    aux=recorrido2->siguiente;break;
                }
            }
            else{
                if(recorrido2->elemento.hora<recorrido1->elemento.hora){
                    aux=recorrido2->siguiente;
                    recorrido1=obtenerNodoAnterior(listaLunes,
                                                   recorrido1->elemento.hora);
                    recorrido2->siguiente=recorrido1->siguiente;
                    recorrido1->siguiente=recorrido2;
                    listaLunes.longitud++;break;
                }
            }
        }
        lista2.cabeza=aux;
    }
}

int main(int argc, char** argv) {
    Lista arrDias[Ndias];
    for(int i=0;i<Ndias;i++){
        construir(arrDias[i]);
    }
    
    //lunes
    insertarEnOrden(arrDias[0],8,6);
    insertarEnOrden(arrDias[0],10,14);
    insertarEnOrden(arrDias[0],12,1);
    imprime(arrDias[0]);
    //martes
    insertarEnOrden(arrDias[1],9,3);
    insertarEnOrden(arrDias[1],11,8);
    imprime(arrDias[1]);
    //miercoles
    insertarEnOrden(arrDias[2],8,2);
    insertarEnOrden(arrDias[2],9,5);
    insertarEnOrden(arrDias[2],10,10);
    imprime(arrDias[2]);
    //jueves
    insertarEnOrden(arrDias[3],14,13);
    insertarEnOrden(arrDias[3],15,9);
    insertarEnOrden(arrDias[3],16,11);
    imprime(arrDias[3]);
    //viernes
    insertarEnOrden(arrDias[4],17,4);
    insertarEnOrden(arrDias[4],18,12);
    insertarEnOrden(arrDias[4],19,7);
    imprime(arrDias[4]);
    fusionarListas(arrDias[0],arrDias[1]);
    imprime(arrDias[0]);
    fusionarListas(arrDias[0],arrDias[2]);
    imprime(arrDias[0]);
    fusionarListas(arrDias[0],arrDias[3]);
    imprime(arrDias[0]);
    fusionarListas(arrDias[0],arrDias[4]);
    imprime(arrDias[0]);
    return 0;
}

