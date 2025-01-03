/* 
 * File:   Lse.c
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
#include "Lse.h"

void construirLista( Lista *pL )
{
    pL->cabeza = NULL;
    pL->longitud = 0;
}

int esListaVacia( Lista L )
{
    return L.cabeza == NULL;
}

NodoL* crearNuevoNodoL( ElementoLista elemento, NodoL *sig )
{
    NodoL *pNuevoNodo;
    pNuevoNodo = (NodoL*)malloc(sizeof(NodoL));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void insertarComienzo( Lista *pL, ElementoLista elemento )
{
    NodoL *pNuevoNodo;
    pNuevoNodo = crearNuevoNodoL( elemento, pL->cabeza);
    pL->cabeza = pNuevoNodo;
    pL->longitud ++;
}

void mostrar( Lista L )
{
    NodoL *pNodo;
    if ( esListaVacia( L) )
        printf("La lista esta vacia\n");
    else
    {
        pNodo = L.cabeza;
        while ( pNodo != NULL )
        {
            printf("%d(%d) (%s) ", pNodo->elemento.hora,pNodo->elemento.num_sucur,pNodo->elemento.dia);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

NodoL* obtenerUltimoNodo( Lista L )
{
    NodoL *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = L.cabeza;
    while( pNodo != NULL )
    {
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}

void insertarFinal(Lista *pL, ElementoLista elemento )
{
    NodoL *pNuevoNodo, *pUltimo;
    pNuevoNodo = crearNuevoNodoL( elemento, NULL);
    pUltimo = obtenerUltimoNodo(*pL);
    if ( pUltimo == NULL )
        pL->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
    
    pL->longitud ++;
}

int buscar( Lista L, ElementoLista valor )
{
    NodoL *pNodo;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if (valor.hora==pNodo->elemento.hora)
            return 1;
        pNodo = pNodo->sig;    
    }
    return 0;
}

NodoL* obtenerNodo(Lista L, ElementoLista valor)
{
    NodoL *pNodo;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if (valor.hora == pNodo->elemento.hora)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

NodoL* obtenerNodoAnterior( Lista L, ElementoLista valor)
{
    NodoL *pNodo, *pAnterior;
    pAnterior = NULL;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if ( pNodo->elemento.hora == valor.hora )
            break;
        pAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pAnterior;
}

void eliminarNodo( Lista *pL, ElementoLista valor )
{
    NodoL *pNodoEliminar, *pAnterior;
    pNodoEliminar = obtenerNodo( *pL, valor);
    if ( pNodoEliminar == NULL )
        printf("%d no esta en la lista\n",valor);
    else
    {
        pAnterior = obtenerNodoAnterior(*pL, valor);
        if ( pAnterior == NULL )
            pL->cabeza = pNodoEliminar->sig;
        else
            pAnterior->sig =pNodoEliminar->sig;
        free(pNodoEliminar);
        printf("El nodo fue eliminado\n");
    }
    pL->longitud --;
}

void destruirLista( Lista *pL )
{
    NodoL *pNodo, *pAux;
    pNodo = pL->cabeza;
    while ( pNodo != NULL )
    {
        pAux = pNodo->sig;
        free(pNodo);
        pNodo = pAux;
    }
    pL->cabeza = NULL;
    printf("Todos los nodos han sido eliminados\n");
    pL->longitud = 0;
}

int obtenerLongitud( Lista L )
{
    NodoL *pNodo;
    int nodos = 0;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        nodos++;
        pNodo = pNodo->sig;
    }
    return nodos;
}