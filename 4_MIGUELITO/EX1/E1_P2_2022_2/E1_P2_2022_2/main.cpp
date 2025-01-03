/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 7 de octubre de 2024, 11:00
 */

#include <cstdlib>
#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define N 11

using namespace std;

/*
 * 
 */

void calcularFrecuenciayTiempoMaximo(int frecuencias[N],int size,int *frecMax,int *tiempoMax){
    *frecMax = 0;
    *tiempoMax = 0;
    Pila pila;
    construir(pila);
    int i = 1, tiempo, frecuenciaTiempo, duracionMax=0, duracion;
    while (i<=size){
        if (esPilaVacia(pila) || frecuencias[cima(pila)-1] <= frecuencias[i-1]){
            apilar(pila,i);
            i++;
        }
        else{
            tiempo = desapilar(pila);
            frecuenciaTiempo = frecuencias[tiempo-1];
            duracion = frecuenciaTiempo*(i-tiempo);
            if (duracion>duracionMax){
                duracionMax = duracion;
                *frecMax = frecuenciaTiempo;
                *tiempoMax = i-tiempo;
            }
        }
    }
    
    while (!esPilaVacia(pila)){
        tiempo = desapilar(pila);
        frecuenciaTiempo = frecuencias[tiempo-1];
        duracion = frecuenciaTiempo*(i-tiempo);
        if (duracion>duracionMax){
            duracionMax = duracion;
            *frecMax = frecuenciaTiempo;
            *tiempoMax = i-tiempo;
        }
    }
}

int main(int argc, char** argv) {
    int frecuencias[N] = {1,2,1,4,5,6,4,5,6,2,1};
    int size = 11, frecMax, tiempoMax;
    calcularFrecuenciayTiempoMaximo(frecuencias,size,&frecMax,&tiempoMax);
    cout << "Frecuencia: " << frecMax << endl;
    cout << "Tiempo: " << tiempoMax;
    return 0;
}

