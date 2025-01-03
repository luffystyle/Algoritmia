/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODO_H
#define NODO_H
#include "lote.h"

struct NodoArbol{
    Lote elemento;  //Este dato representa el Elemento
    NodoArbol * izquierda;  //puntero al hijo izquierdo
    NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODO_H */

