/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef NODO_H
#define NODO_H

struct Nodo{
    int elemento;
    struct Nodo * anterior;
    struct Nodo * siguiente;
};

#endif /* NODO_H */

