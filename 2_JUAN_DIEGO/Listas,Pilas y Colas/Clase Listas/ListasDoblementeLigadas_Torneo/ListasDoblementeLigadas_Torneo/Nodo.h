/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef NODO_H
#define NODO_H
/*LISTA DOBLEMENTE ENLAZADA*/
#include "Equipo.h"
struct Nodo{
    struct Equipo equipo;
    struct Nodo * anterior;   /*apunta a su predecesor*/
    struct Nodo * siguiente;  /*apunta a su sucesor*/
};

#endif /* NODO_H */

