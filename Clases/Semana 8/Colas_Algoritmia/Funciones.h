
/* 
 * File:   Funciones.h
 * Author: Miguelito
 *
 * Created on May 8, 2023, 10:55 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef int Elemento;

typedef struct nodoC
{
    Elemento elem;
    struct nodoC *sig;
} NodoC;

typedef struct
{
    NodoC* frente;
    NodoC* final;
    int longitud;
} Cola;

void construir( Cola * );
bool esColaVacia( Cola  );
int obtenerLongitud( Cola  );
NodoC* crearNodo( Elemento , NodoC *);
void mostrar( Cola );
void encolar( Cola &, Elemento );
Elemento desencolar( Cola &);
void destruir( Cola * );
void ordenaColaRecursiva(Cola &, int );

#endif /* FUNCIONES_H */

