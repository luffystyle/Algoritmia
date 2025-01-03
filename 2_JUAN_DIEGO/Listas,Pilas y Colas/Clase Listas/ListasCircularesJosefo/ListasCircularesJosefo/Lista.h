/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:15 PM
 */

#ifndef LISTA_H
#define LISTA_H
/*LISTAS CIRCULARES SIMPLES*/
/*Listas circulares, la principal ventaja es que permiten la navegación en 
     * un sentido a través de la misma, además, se puede recorrer toda la lista
     * partiendo de cualquier elemento (Nodo) siempre que tengamos un apuntador
     * a este. Se deben establecer condiciones adecuadas para evitar caer en 
     * ciclos infinitos*/
#include "Nodo.h"
struct Lista{
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    int longitud; /*guarda la longitud de la lista*/
};

#endif /* LISTA_H */

