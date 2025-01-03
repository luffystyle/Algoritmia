/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODOA_H
#define NODOA_H
#include "LoteNodo.h"

struct NodoArbol{
    Lote *elemento;  //Este dato representa el Elemento
    NodoArbol * izquierda;  //puntero al hijo izquierdo
    NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODOA_H */

