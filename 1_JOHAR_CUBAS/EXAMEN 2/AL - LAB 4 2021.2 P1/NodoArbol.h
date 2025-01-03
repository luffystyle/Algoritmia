/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODOA_H
#define NODOA_H

struct NodoArbol{
    int elemento;  //Este dato representa el Elemento
    int nivel;
    NodoArbol * izquierda;  //puntero al hijo izquierdo
    NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODOA_H */

