/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 14 de octubre de 2022, 19:12
 */

#ifndef PILA_H
#define PILA_H

typedef int ElementoPila;

typedef struct nodoP
{
    ElementoPila elemento;
    struct nodoP *sig;
} NodoP;

typedef struct pila
{
    NodoP *cima;
    int longitud;
} Pila;

void construirPila( Pila *pP );
int esPilaVacia( Pila P );
NodoP* crearNuevoNodoP( ElementoPila elemento, NodoP *sig );
void apilar( Pila *pP, ElementoPila elemento);
void mostrarP( Pila P );
int obtenerLongitudP( Pila P );
ElementoPila desapilar( Pila *pP );
//Funcion que se inspira en destruir lista:
void destruir_Pila(Pila *pP);
ElementoPila cima(Pila p);
#endif /* PILA_H */

