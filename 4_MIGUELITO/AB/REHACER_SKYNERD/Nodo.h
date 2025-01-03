/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 20:43
 */

#ifndef NODO_H
#define NODO_H
#include "NodoArbol.h"

/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    int elemento; /*Dato que cambia por double, char, struct Elemento*/
    NodoArbol *nodoArbol;
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODO_H */