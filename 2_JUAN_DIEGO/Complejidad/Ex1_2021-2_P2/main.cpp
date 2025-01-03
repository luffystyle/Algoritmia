/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 12 de junio de 2024, 01:32 PM
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h"
#define m 7
using namespace std;
#include "funcionesLista.h"
int cont=0;

/*
 * 
 */
int buenas(int*estado,int ini,int fin){
    if(estado[ini]==1){
        if(ini==fin){
            return 1-estado[ini];
        }    
        int med=(ini+fin)/2;    
        if(estado[med]==0){
            return (fin-med)+buenas(estado,ini,med);
        }else{
            return buenas(estado,med+1,fin);
        }
    }else{
        if(ini==fin){
            return 1-estado[ini];
        }    
        int med=(ini+fin)/2;    
        if(estado[med]==0){
            return (fin-med)+ buenas(estado,med+1,fin);
        }else{
            return buenas(estado,ini,med);
        }
    }    
}

void unir(Lista & lista1,Lista & lista2){
    if(!esListaVacia(lista2)){
        Nodo*ultimo=lista1.cola;
        ultimo->siguiente=lista2.cabeza;
        lista1.cola=lista2.cola;
        lista1.longitud+=lista2.longitud;
    }
}

int main(int argc, char** argv) {
    
    //bandeja 1    
   int estado[m]={1,1,1,0,0,0,0};
   int tipo[m]={2,1,3,2,3,1,1};   
   cout<<"Pizzas en buen estado: "<<m-buenas(estado,0,m-1)<<endl;   
   //bandeja 2    
   int estado_2[m]={1,1,1,1,1,1,0};
   int tipo_2[m]={1,2,3,3,3,2,1};   
   cout<<"Pizzas en buen estado: "<<m-buenas(estado_2,0,m-1)<<endl;   
   //bandeja 3    
   int estado_3[m]={1,1,1,1,1,0,0};
   int tipo_3[m]={1,2,1,1,3,1,2};   
   cout<<"Pizzas en buen estado: "<<m-buenas(estado_3,0,m-1)<<endl;   
    //bandeja 4  
   int estado_4[m]={0,0,1,1,1,1,1};
   int tipo_4[m]={3,1,3,2,3,3,1};   
   cout<<"Pizzas en buen estado: "<<m-buenas(estado_4,0,m-1)<<endl;
   
   /*Parte B*/
   struct Lista lista1,lista2,lista3,lista4;
   construir(lista1);
   construir(lista2);
   construir(lista3);
   construir(lista4);
   
   //Para la lista 1   
   for(int j=0;j<m;j++){
       if(estado[j]==1){
           insertarAlFinal(lista1,tipo[j]);       
       }
   }
    for(int j=0;j<m;j++){
       if(estado_2[j]==1){
           insertarAlFinal(lista2,tipo_2[j]);       
       }
   }
    for(int j=0;j<m;j++){
       if(estado_3[j]==1){
           insertarAlFinal(lista3,tipo_3[j]);       
       }
   }
    for(int j=0;j<m;j++){
       if(estado_4[j]==1){
           insertarAlFinal(lista4,tipo_4[j]);       
       }
   }    
   imprime(lista1);
   imprime(lista2);
   imprime(lista3);
   imprime(lista4);
   
   unir(lista1,lista2);
   unir(lista1,lista3);
   unir(lista1,lista4);
   imprime(lista1);
   cout<<longitud(lista1)<<endl;
   
    return 0;
}

