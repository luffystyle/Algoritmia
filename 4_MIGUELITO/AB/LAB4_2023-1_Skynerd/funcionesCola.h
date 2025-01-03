/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 06:06 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H
#include "NodoArbol.h"

void construir(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
int desencolar(struct Cola & cola);
int longitud(const struct Cola & cola);
void imprime(const struct Cola & cola);
void destruirCola(struct Cola & cola);
void encolarNew(Cola &cola, NodoArbol *nodoArbol);
NodoArbol *desencolarNew(Cola &cola);

#endif /* FUNCIONESCOLA_H */

