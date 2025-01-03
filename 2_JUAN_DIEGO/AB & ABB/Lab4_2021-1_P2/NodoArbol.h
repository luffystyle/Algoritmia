/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H


struct NodoArbol{
    long long  fecha;  //Este dato representa el Elemento
    int dni;
    int numAcciones;
    int total;
    char estado;
    struct NodoArbol * izquierda;  //puntero al hijo izquierdo
    struct NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODO_H */

