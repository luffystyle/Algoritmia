/* 
 * File:   Pila.c
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 14 de octubre de 2022, 19:12
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

//adaptamos el codigo del profesor Hinojosa y vemos que en realidad solo bastaria
//con cambiar la impresion, pues ahora se posee mÃƒÂ¡s parametros.
void construirPila( Pila *pP )
{
    pP->cima = NULL;
    pP->longitud = 0;
}

int esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return C.longitud == 0;
}

NodoP* crearNuevoNodo( ElementoPila elemento, NodoP *sig )
{
    NodoP *pNuevoNodo;
    pNuevoNodo = (NodoP*)malloc(sizeof(NodoP));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void apilar( Pila *pP, ElementoPila elemento)
{
    NodoP *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo( elemento, pP->cima );
    pP->cima = pNuevoNodo;
    pP->longitud++;
}
//agregamos los parametros que la pila actual posee y los imprimos:
void mostrarP( Pila P )
{
    NodoP *pNodo;
    if ( esPilaVacia(P) )
        printf("La pila esta vacia\n");
    else
    {
        pNodo = P.cima;
        while ( pNodo != NULL )
        {
            printf("%d \n", pNodo->elemento);
            pNodo = pNodo->sig;
        }
        printf("\n\n");
    }
}

int obtenerLongitudP( Pila P )
{
    return P.longitud;    
}

ElementoPila desapilar( Pila *pP )
{
    NodoP *pNodo;
    ElementoPila elemento;
    pNodo = pP->cima;
    elemento = pNodo->elemento;
    pP->cima = pNodo->sig;
    pP->longitud--;
    free(pNodo);
    return elemento;
}
//destruir Pila, similar a destruir lista.
void destruir_Pila(Pila *pP){    
    NodoP* recorrido = pP->cima;
    while(recorrido != NULL){
        NodoP *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    pP->cima=NULL;
    pP->longitud=0;
}
ElementoPila cima(Pila p){
    if(esPilaVacia(p)) exit(2);
    return (ElementoPila)(p.cima->elemento); 
}