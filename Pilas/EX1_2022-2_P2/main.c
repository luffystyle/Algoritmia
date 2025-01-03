/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 20 de octubre de 2022, 14:29
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
/*
 * 
 */
//Para el desarrollo de esta pregunta haremos uso del codigo del profe Hilmar Hinojosa.
int hallar_frecuencia_max(int frecuencia[],int cant_datos,int *frecMax,int *durMax){
    //creamos y construimos la pila:
    Pila pila_frecuencia;
    construirPila(&pila_frecuencia);
    
    int frecuen_actual,duracion_actual;
    int area_max=0,i=0;
    int tp,area_tope;

    while(i<cant_datos){
        if(esPilaVacia(pila_frecuencia) || frecuencia[cima(pila_frecuencia)] <= frecuencia[i]){
            apilar(&pila_frecuencia,i);
            i++;
        }else{
            tp = desapilar(&pila_frecuencia);
            if(esPilaVacia(pila_frecuencia)){
                area_tope = frecuencia[tp]*i;
                frecuen_actual = frecuencia[tp];
                duracion_actual = i;
            }else{
                area_tope = frecuencia[tp]*(i-cima(pila_frecuencia)-1);
                frecuen_actual = frecuencia[tp];
                duracion_actual = i-cima(pila_frecuencia)-1;
            }            
            if(area_max < area_tope){
                area_max = area_tope;
                (*frecMax) = frecuen_actual; // FRECUENCIA MÃXIMA
                (*durMax) = duracion_actual;   // DURACION MÃXIMA
            }
        }
    }   
    while(!esPilaVacia(pila_frecuencia)){
        tp = desapilar(&pila_frecuencia);
        if(esPilaVacia(pila_frecuencia)){
            frecuen_actual = frecuencia[tp];
            area_max = frecuencia[tp]*i;
            duracion_actual = i;
        }else{
            area_tope = frecuencia[tp]*(i-cima(pila_frecuencia)-1);
            frecuen_actual = frecuencia[tp];
            duracion_actual = i-cima(pila_frecuencia)-1;
        }
        if(area_max < area_tope){
            area_max = area_tope;
            (*frecMax) = frecuen_actual;
            (*durMax)= duracion_actual;
        }
    }
    destruir_Pila(&pila_frecuencia);
    
    return area_max;
}

int main(int argc, char** argv) {   
    int cant_datos,i;
    printf("Ingrese la cantidad de datos: ");
    scanf("%d",&cant_datos);
    printf("Ingrese los datos de frecuencia: \n");
    int frecuencia[cant_datos];
    for(i=0;i<cant_datos;i++){
        scanf("%d",&frecuencia[i]);
    }
    /*Datos utilizados:  
     * 11
     * 1 2 1 4 4 4 4 4 2 2 1 
    */
    int frecuencia_max = 0;
    int duracion_max = 0;
    printf("La maxima área es: %d\n",hallar_frecuencia_max(frecuencia,cant_datos,&frecuencia_max,&duracion_max));
    printf("Frecuencia: %d   \n",frecuencia_max);
    printf("Duracion: %d \n",duracion_max);
    return (EXIT_SUCCESS);
}

