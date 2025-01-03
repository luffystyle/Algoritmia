/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 13 de octubre de 2023, 07:36 PM
 */

#include <iostream>
#include"Nodo.h"
#include"Lista.h"
#include"Pila.h"
#include"Cola.h"

#include"funcionesLista.h"
#include"Pila.h"
#include"funcionesCola.h"
#include "funcionesPila.h"



using namespace std;


 void reordenarLinea(Cola &colaLinea,Pila &robot1,Pila &robot2){
     
   
     //Desarrollar una función iterativa para reordenar la línea.
     //Si desea puede usar una pila adicional temporal,
     //además para este proceso puede combinar los tipos de pizza en las pilas.
     //Para esta función no puede usar memoria extra, recursión u otras estructuras
    //auxiliares. Solo puede usar variables simples. (5.0 puntos)
     
     int aux1,aux2;
     
     Pila pilaAux;
     construir(pilaAux);
     
     while(1){
         
         if(esPilaVacia(robot1)&&esPilaVacia(robot2)){
             break;
         }
         
         
         if(!esPilaVacia(robot1)){
              aux1=desapilar(robot1);
         }else{
             aux1=-1;
         }
        
         if(!esPilaVacia(robot2)){
              aux2=desapilar(robot2);
         }else{
             aux2=-1;
         }
         
         if(aux1!=-1&&aux2!=-1){
              if(aux1%100>aux2%100){
             
                 apilar(pilaAux,aux1);
             
             
                   apilar(robot2,aux2);
             
            }else{
                  apilar(pilaAux,aux2);
                  apilar(robot1,aux1);
            }
         }else if(aux1==-1&&aux2!=-1){
              apilar(pilaAux,aux2);
             
         }else if(aux1!=-1&&aux2==-1){
               apilar(pilaAux,aux1);
         }
         
        
         
         
     }
     
     cout<<"PilaAux luego de hacer la ordenacion"<<endl;
     imprimir(pilaAux);
     
     
     //Ahora desencolamos y encolamos el numero de elementos 
     // no entraron en la falla
     int n=2;
     int iterador=0;
     int auxLinea;
     
     while(iterador<n){
         auxLinea=desencolar(colaLinea);
         encolar(colaLinea,auxLinea);
         
         
         iterador++;
     }
     
     cout<<"linea actual"<<endl;
     imprime(colaLinea);
     
     //Ahora itero los numeros que estuvieron en falla
     //y los paso a robot1
     
     int iteraNumFallas=5;
     int auxDesencolo;
     iterador=0;
     while(iterador<iteraNumFallas){
         
         auxDesencolo=desencolar(colaLinea);
         //cout<<auxDesencolo<<endl;
//         if(auxDesencolo/100==1){
//             apilar(robot1,auxDesencolo);
//         }else{
//             apilar(robot2,auxDesencolo);
//         }
          apilar(robot1,auxDesencolo);
         
         iterador++;
     }
     
     cout<<"Robots con los valores durante falla"<<endl;
     imprimir(robot1);
     imprimir(robot2);
     
     
     //Luego  desapilarmos los elementos del aux y lo ponemos en la linea
     
     int numEnPilaAux=5;
     iterador=0;
     int auxDesapilaAux;
     while(iterador<numEnPilaAux){
         auxDesapilaAux=desapilar(pilaAux);
         encolar(colaLinea,auxDesapilaAux);
                
         iterador++;
     }
     
     cout<<"linea "<<endl;
     imprime(colaLinea);
     
     //Por ultimo desencolo y encolo de nuevo los valores que
     //no estaban en la falla
     
      iterador=0;
      int auxDesencoloUltimo;
      
     while(iterador<n){
         auxDesencoloUltimo=desencolar(colaLinea);
         encolar(colaLinea,auxDesencoloUltimo);
         
         iterador++;
     }
     
       cout<<"linea final"<<endl;
     imprime(colaLinea);
     
     
//Línea luego del reordenamiento:
//Línea: P06-> P05 -> A04 -> P03 -> P02 -> A01 -> A00
     
     
     
     
     
     
     
     
     
 }


int main(int argc, char** argv) {
    
    
    
//    a) Definir las estructuras de datos que soporten la aplicación, cargar la línea luego de la
//    retención y el contenido de los 2 robots e imprimirlo. La cantidad de elementos de la
//    cola y pilas pueden ser datos de entrada (2.0 puntos)
    
    
    //P == 2   y   A == 1 
    
   
//    Línea luego de la retención:
//Durante la falla ingresaron los siguientes productos: A07, A08, P09, A10 y P11
//Línea: P11-> A10 -> P09 -> A08 -> A07 -> P06-> P05
    
    
//Robot 1: A04 A01 A00 ||
//Robot 2: P03 P02 ||
    
    
    Cola colaLinea;
    
    
    
    construir(colaLinea);
    
    encolar(colaLinea,205);
    encolar(colaLinea,206);
    encolar(colaLinea,107);
    encolar(colaLinea,108);
    encolar(colaLinea,209);
    encolar(colaLinea,110);
    encolar(colaLinea,211);
    
    imprime(colaLinea);
    
    
    
    Pila robot1,robot2;
    
    construir(robot1);
    construir(robot2);
    
    
    apilar(robot1,100);
    apilar(robot1,101);
    apilar(robot1,104);
    
     apilar(robot2,202);
     apilar(robot2,203);
     
     
     cout<<"Robot 1:"<<endl;
     imprimir(robot1);
     
     cout<<"Robot 2:"<<endl;
     imprimir(robot2);
     
     
//     b) Desarrollar una función iterativa para reordenar la línea. Si desea puede usar una pila
//    adicional temporal, además para este proceso puede combinar los tipos de pizza en las
//    pilas. Para esta función no puede usar memoria extra, recursión u otras estructuras
//    auxiliares. Solo puede usar variables simples. (5.0 puntos)
     
     cout<<"--------------------"<<endl;
     reordenarLinea(colaLinea,robot1,robot2);

     cout<<"--------------------"<<endl;
    
    
    
    
    
    //contenido de los 2 robots

    
    
    
    

    return 0;
}

