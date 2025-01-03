/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:51 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    struct Nodo * cola;
    struct Nodo * mayor; //Apuntará a los mayores de 80 años
    struct Nodo * menor; //Apuntará al los valores de los menores a 10 años

    int longitud; /*guarda la longitud de la lista*/
};

#endif /* LISTA_H */

