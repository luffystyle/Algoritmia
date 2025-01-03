/* 
 * File:   NodoArbol.h
 * Author: ANA RONCAL
 *
 * Created on 27 de octubre de 2024, 16:59
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H

struct Elemento {
    char tipo;
    int velocidad;
};

struct NodoArbol{
    Elemento elemento;  //Este dato representa el Elemento
    struct NodoArbol * izquierda;  //puntero al hijo izquierdo
    struct NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODOARBOL_H */