/* 
 * File:   funciones.cpp
 * Author: miguel
 *
 * Created on October 8, 2023, 6:15 PM
 */
#include <iostream>
using namespace std;
#include "funciones.h"




void construir( Cola *pC )
{
    pC->frente = NULL;
    pC->final = NULL;
    pC->longitud = 0;
    // la cola empieza vacia
}

bool esColaVacia( Cola C )
{
    return C.frente == NULL;
    // return C.final == NULL;
    // return C.longitud == 0;
}

int obtenerLongitud( Cola C )
{
    return C.longitud;
}

NodoC* crearNodo( Elemento e, NodoC *s )
{
    NodoC *p;
    p = new NodoC; // se crea el nuevo nodo
    p->elem = e;
    p->sig = s;
    return p; // retorna la direccion del nodo creado
} 

void mostrar( Cola C ) {
    NodoC *p;
    int i;
    if ( esColaVacia(C) )
        cout << "Cola vacia" << endl;
    else {
        p = C.frente;
        for(i=1; i<=C.longitud; i++) {
            cout << p->elem;
            if(i != C.longitud) cout << " -> ";
            p = p->sig;
        }
        cout << endl;
    }
}

void encolar( Cola &pC, Elemento e )
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    if( esColaVacia(pC) )
    {
        pC.frente = p;
    }
    else
    {
        pU = pC.final;
        pU->sig = p;
    }
    pC.final = p;
    pC.longitud++;
}

// esta funcion solo sera invocada si la cola no esta vacia
Elemento desencolar( Cola &pC )
{
    NodoC *p;
    Elemento x;
    p = pC.frente;
    x = p->elem;
    pC.frente = p->sig;
    if ( pC.frente == NULL )
        pC.final = NULL;
    pC.longitud--;
    delete p; // elimina el Nodo
    return x;
}







