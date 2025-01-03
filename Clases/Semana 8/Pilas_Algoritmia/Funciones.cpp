/* 
 * File:   main.cpp
 * Author: Miguel Torres
 * Created on September 8, 2022, 7:18 AM
 */
#include <iostream>

using namespace std;
#include "Funciones.h"



void construir( Pila &pP )
{
    pP.cima = NULL;
    pP.longitud = 0;
    // la pila empieza vacia
}

bool esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return P.longitud == 0;
}

int obtenerLongitud( Pila P )
{
    return P.longitud;
}

NodoP* crearNodo( Elemento e, NodoP *s )
{
    NodoP *p;
    p = new NodoP;  // se crea el nodo en memoria
    p->elem = e;
    p->sig = s;
    return p; // retorna la dirección del nodo creado
} 

void apilar( Pila &pP, Elemento e )
{
    NodoP *p;
    p = crearNodo( e, pP.cima );
    pP.cima = p;
    pP.longitud++;
}

void mostrar( Pila P )
{
    NodoP *p;
    int i;
    if ( esPilaVacia(P) )
        cout << "Pila vacia" << endl ;
    else
    {
        p = P.cima;
        for(i=1; i<=P.longitud; i++)
        {
            cout << p->elem << endl;
            p = p->sig;
        }
        cout << endl;
    }
}
// esta funcion solo sera invocada si la pila no esta vacia
Elemento desapilar( Pila &pP )
{
    Elemento x;
    NodoP *p;
    p = pP.cima;
    x = p->elem;
    pP.cima = p->sig;
    pP.longitud--;
    delete p;
    return x;
}
