/* 
 * File:   lista.c
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 13 de diciembre de 2022, 16:44
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void construir_lista(Lista *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_vacia(Lista tad){
    return tad.cabeza==NULL;
}

NodoLista *crear_nuevo_nodo(ElementoLista elemento, NodoLista* sig){
    NodoLista* nuevo_nodo = (NodoLista*)malloc(sizeof(NodoLista));
    if (nuevo_nodo==NULL){
        printf("No ha sido posible asignar memoria dinámica.\n");
        exit(1);
    }
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    return nuevo_nodo;
}

void insertar_al_inicio(Lista *tad, ElementoLista elemento){
    NodoLista *nuevo_nodo = crear_nuevo_nodo(elemento, tad->cabeza);
    tad->cabeza=nuevo_nodo;
    tad->longitud++;
}

int longitud(Lista tad){
    return tad.longitud;
}

void imprime(Lista tad){
    NodoLista* recorrido = tad.cabeza;
    int esta_imprimiendo_la_cabeza=1;
    printf("[");
    while(recorrido != NULL){
        if (!esta_imprimiendo_la_cabeza)
            printf(", ");
        esta_imprimiendo_la_cabeza=0;
        printf("%d", recorrido->elemento);        
        recorrido = recorrido->sig;
    }
    printf("]\n");
}

NodoLista *obtener_ultimo_nodo(Lista tad){
    NodoLista* ultimo=NULL;
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void insertar_al_final(Lista *tad, ElementoLista elemento){
    NodoLista *nuevo_nodo = crear_nuevo_nodo(elemento, NULL);
    NodoLista *ultimo_nodo = obtener_ultimo_nodo(*tad);    
    if (ultimo_nodo==NULL)
        tad->cabeza=nuevo_nodo;
    else    
        ultimo_nodo->sig=nuevo_nodo;
    tad->longitud++; 
}

NodoLista *obtener_nodo_anterior(Lista tad, ElementoLista elemento){
    NodoLista* anterior=NULL;
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento<elemento){
        anterior = recorrido;        
        recorrido = recorrido->sig;
    }
    return anterior;    
}

void insertar_en_orden(Lista *tad, ElementoLista elemento){
    NodoLista *nuevo_nodo = crear_nuevo_nodo(elemento, NULL);
    NodoLista *nodo_anterior = obtener_nodo_anterior(*tad, elemento);    
    if (nodo_anterior==NULL){
        nuevo_nodo->sig=tad->cabeza;
        tad->cabeza=nuevo_nodo;
    }else{    
        nuevo_nodo->sig=nodo_anterior->sig;
        nodo_anterior->sig=nuevo_nodo;
    }
    tad->longitud++;     
}

NodoLista* se_encuentra(Lista tad, ElementoLista llave){
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){        
        recorrido = recorrido->sig;
    }
    return recorrido;        
}

void destruir_lista(Lista *tad){    
    NodoLista* recorrido = tad->cabeza;
    while(recorrido != NULL){
        NodoLista *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}

ElementoLista retorna_cabeza(Lista tad){
    if (es_lista_vacia(tad)){
        printf("No existe la cabeza por que la lista está vacía.\n");
        exit(4);
    }
    return tad.cabeza->elemento;
}

void elimina_cabeza(Lista *tad){
    if (es_lista_vacia(*tad)){
        printf("No se puede eliminar la cabeza pues la lista está vacía.\n");
        exit(2);
    }
    NodoLista *nodo_a_eliminar=tad->cabeza;    
    tad->cabeza=tad->cabeza->sig;
    free(nodo_a_eliminar); 
    tad->longitud--;          
}

void elimina_cola(Lista *tad){
    if (es_lista_vacia(*tad)){
        printf("No se puede eliminar la cola pues la lista está vacía.\n");
        exit(3);
    }
    NodoLista *ultimo=NULL, *penultimo=NULL;
    NodoLista *recorrido = tad->cabeza;
    while(recorrido != NULL){
        if (ultimo!=NULL)
            penultimo=ultimo;
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }    
    if (penultimo==NULL)
        tad->cabeza=NULL;            
    else
        penultimo->sig=NULL;
    free(ultimo);
    tad->longitud--;                  
}

void elimina_nodo(Lista *tad, ElementoLista elemento){
    NodoLista *ultimo=NULL;
    NodoLista *recorrido = tad->cabeza;
    while(recorrido != NULL && recorrido->elemento!=elemento){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    if (recorrido != NULL){
        if (ultimo==NULL)
            tad->cabeza=recorrido->sig;
        else    
            ultimo->sig=recorrido->sig;
        free(recorrido);
        tad->longitud--;
    }
}