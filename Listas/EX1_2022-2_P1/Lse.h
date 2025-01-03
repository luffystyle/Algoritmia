/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lse.h
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 14 de octubre de 2022, 19:12
 */

#ifndef LSE_H
#define LSE_H

typedef struct{
    int hora;
    int num_sucur;
    char dia[30];
} ElementoLista;

typedef struct nodoL
{
    ElementoLista elemento;
    struct nodoL *sig;
} NodoL;

typedef struct lista
{
    NodoL *cabeza;
    int longitud;
} Lista;

void construirLista( Lista *pL );
int esListaVacia( Lista L );
NodoL* crearNuevoNodoL( ElementoLista elemento, NodoL *sig );
void insertarComienzo( Lista *pL, ElementoLista elemento );
void mostrar( Lista L );
NodoL* obtenerUltimoNodo( Lista L );
void insertarFinal(Lista *pL, ElementoLista elemento );
int buscar( Lista L, ElementoLista valor );
NodoL* obtenerNodo(Lista L, ElementoLista valor);
NodoL* obtenerNodoAnterior( Lista L, ElementoLista valor);
void eliminarNodo( Lista *pL, ElementoLista valor );
void destruirLista( Lista *pL );
int obtenerLongitud( Lista L );

#endif /* LSE_H */

