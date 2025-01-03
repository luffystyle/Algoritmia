/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:00 PM
 */

#ifndef NODOCOL_H
#define NODOCOL_H

#include "NodoArbol.h"
/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    NodoArbol* elemento; /*Dato que cambia por double, char, struct */
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODOCOL_H */

