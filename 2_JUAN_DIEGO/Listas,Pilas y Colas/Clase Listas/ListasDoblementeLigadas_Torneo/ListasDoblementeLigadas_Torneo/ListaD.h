/* 
 * File:   ListaD.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef LISTAD_H
#define LISTAD_H
/*LISTA DOBLEMENTE ENLAZADAS*/
#include "Nodo.h"
struct Lista{
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    /*Para tener un fácil acceso a la información de la lista es recomendable
     usar dos apuntadores*/
    struct Nodo * cola;   /*apunta al fin de la lista*/
    int longitud;  /*guarda la longitud de la lista doble*/
};


#endif /* LISTAD_H */

