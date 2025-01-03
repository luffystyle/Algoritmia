
/* 
 * File:   Funciones.h
 * Author: Miguelito
 *
 * Created on May 8, 2023, 12:13 PM
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

typedef int Elemento;

typedef struct nodoP
{
    Elemento elem;
    struct nodoP *sig;
} NodoP;

typedef struct
{
    NodoP* cima;
    int longitud;
} Pila;

void construir( Pila &);
bool esPilaVacia( Pila);
int obtenerLongitud( Pila);
NodoP* crearNodo( Elemento , NodoP *);
void apilar( Pila &, Elemento);
void mostrar( Pila);
Elemento desapilar( Pila &);
void ordernaPilaRecursividad(Pila &, int);

#endif /* FUNCIONESPILA_H */

