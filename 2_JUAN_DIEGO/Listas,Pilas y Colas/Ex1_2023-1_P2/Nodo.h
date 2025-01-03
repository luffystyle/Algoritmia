/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:00 PM
 */

#ifndef NODO_H
#define NODO_H

/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    int prioridad; /*Dato que cambia por double, char, struct */
    int codigo;
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODO_H */

