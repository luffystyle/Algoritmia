/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPila.h
 * Author: juanD
 *
 * Created on 18 de abril de 2024, 06:48 PM
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, int ); 
int desapilar(struct Pila &);
int cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimirPila(const struct Pila &);

#endif /* FUNCIONESPILA_H */

