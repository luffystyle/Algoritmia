/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: juanD
 *
 * Created on 18 de abril de 2024, 06:45 PM
 */

#ifndef NODO_H
#define NODO_H

/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    int elemento; /*Dato que cambia por double, char, struct */
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODO_H */

