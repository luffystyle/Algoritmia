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
 * Created on 15 de octubre de 2022, 09:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lse.h"
#include <string.h>
#include "assert.h"
/*
 * 
 */
void ordenar_lista(Lista *lista_dia);
void unir_listas(Lista* lista1,Lista* lista2);

int main(int argc, char** argv) {
    Lista lista_lun, lista_mar, lista_mier, lista_j, lista_v;
    construirLista(&lista_lun);
    construirLista(&lista_mar);
    construirLista(&lista_mier);
    construirLista(&lista_j);
    construirLista(&lista_v);
    //lunes: 
    ElementoLista e1,e2,e3;
    e1.hora= 8;
    e1.num_sucur =6;
    strcpy(e1.dia,"Lunes");
    insertarFinal(&lista_lun,e1);
    
    e2.hora= 10;
    e2.num_sucur =14;
    strcpy(e2.dia,"Lunes");
    insertarFinal(&lista_lun,e2);
    
    e3.hora=12;
    e3.num_sucur =1;
    strcpy(e3.dia,"Lunes");
    insertarFinal(&lista_lun,e3);
    //martes: 
    ElementoLista e4,e5;
    e4.hora= 9;
    e4.num_sucur =3;
    strcpy(e4.dia,"Martes");
    insertarFinal(&lista_mar,e4);
    
    e5.hora= 11;
    e5.num_sucur =8;
    strcpy(e5.dia,"Martes");
    insertarFinal(&lista_mar,e5);
    
    //miercoles: 
    ElementoLista e6,e7,e8;
    e6.hora= 8;
    e6.num_sucur =2;
    strcpy(e6.dia,"Miercoles");
    insertarFinal(&lista_mier,e6);
    
    e7.hora= 9;
    e7.num_sucur =5;
    strcpy(e7.dia,"Miercoles");
    insertarFinal(&lista_mier,e7);
    
    e8.hora= 10;
    e8.num_sucur = 10;
    strcpy(e8.dia,"Miercoles");
    insertarFinal(&lista_mier,e8);
    
    //jueves: 
    ElementoLista e9,e10,e11;
    e9.hora= 14;
    e9.num_sucur =13;
    strcpy(e9.dia,"Jueves");
    insertarFinal(&lista_j,e9);
    
    e10.hora= 15;
    e10.num_sucur = 9;
    strcpy(e10.dia,"Jueves");
    insertarFinal(&lista_j,e10);
    
    e11.hora= 16;
    e11.num_sucur = 11;
    strcpy(e11.dia,"Jueves");
    insertarFinal(&lista_j,e11);
    
    //viernes:
    ElementoLista e12,e13,e14;
    e12.hora= 17;
    e12.num_sucur = 4;
    strcpy(e12.dia,"Viernes");
    insertarFinal(&lista_v,e12);
    
    e13.hora= 18;
    e13.num_sucur = 12;
    strcpy(e13.dia,"Viernes");
    insertarFinal(&lista_v,e13);
    
    e14.hora = 19;
    e14.num_sucur = 7;
    strcpy(e14.dia,"Viernes");
    insertarFinal(&lista_v,e14);
    //lenamos nuestros dias
    mostrar(lista_lun);
    mostrar(lista_mar);
    mostrar(lista_mier);
    mostrar(lista_j);
    mostrar(lista_v);
    //ordenamos las listas
    ordenar_lista(&lista_lun);
    ordenar_lista(&lista_mar);
    ordenar_lista(&lista_mier);
    ordenar_lista(&lista_j);
    ordenar_lista(&lista_v);
    //mostramos_las listas para ver si se ordeno de forma correcta:
    printf("Listas ordenadas: \n");
    mostrar(lista_lun);
    mostrar(lista_mar);
    mostrar(lista_mier);
    mostrar(lista_j);
    mostrar(lista_v);
    //fusionar_listas:
    unir_listas(&lista_lun,&lista_mar);
    unir_listas(&lista_lun,&lista_mier);
    unir_listas(&lista_lun,&lista_j);
    unir_listas(&lista_lun,&lista_v);
    //mostramos el lunes:
    printf("\nLa lista final queda de la siguiente manera: \n");
    mostrar(lista_lun);
    
    return (EXIT_SUCCESS);
}

void ordenar_lista(Lista *lista_dia){
    NodoL *pNodo = lista_dia->cabeza;
    NodoL *pNodoAux = NULL;
    ElementoLista cliente_temp;
     if(pNodo == NULL) {  
            return;  
        }  
        else {  
            while(pNodo != NULL) {  
                pNodoAux = pNodo->sig;                   
                while(pNodoAux != NULL) {                      
                    if(pNodo->elemento.hora > pNodoAux->elemento.hora) {  
                        cliente_temp = pNodo->elemento;  
                        pNodo->elemento= pNodoAux->elemento;  
                        pNodoAux->elemento= cliente_temp;  
                    }  
                    pNodoAux = pNodoAux->sig;  
                }  
                pNodo = pNodo->sig;  
            }      
    }  
}

void unir_listas(Lista* lista1,Lista* lista2) {
    if (lista2->cabeza==NULL) {
        return;
    }

    NodoL* lastNodeT = obtenerUltimoNodo(*lista1);
    if (lastNodeT==NULL) {
        lista1->cabeza = lista2->cabeza;
        lista1->longitud = lista2->longitud;
        lista2->cabeza = NULL;
        lista2->longitud = 0;
    } else if (lastNodeT->elemento.hora<lista2->cabeza->elemento.hora) {
        lastNodeT->sig = lista2->cabeza;
        lista1->longitud += lista2->longitud;
        lista2->cabeza = NULL;
        lista2->longitud = 0;
    } else {
        NodoL* currentNode = lista1->cabeza;
        while (lista2->longitud!=0) {
            if (currentNode->sig!=NULL) {
                if (currentNode->sig->elemento.hora>lista2->cabeza->elemento.hora) {
                    NodoL* tempNode = currentNode->sig;
                    currentNode->sig = lista2->cabeza;
                    lista2->cabeza = lista2->cabeza->sig;
                    currentNode->sig->sig = tempNode;
                    lista2->longitud--;
                    lista1->longitud++;
                }
                currentNode = currentNode->sig;
            } else {
                currentNode->sig = lista2->cabeza;
                lista1->longitud += lista2->longitud;
                lista2->cabeza = NULL;
                lista2->longitud = 0;
            }
        }
    }
    assert(esListaVacia(*lista2));
}
