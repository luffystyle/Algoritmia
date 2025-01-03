// -*- C++ -*-

/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 20:43
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void construir(struct Lista &);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void insertarAlInicio(struct Lista &, int, int);
void insertarAlFinal(struct Lista &, int ,int );
void insertarEnOrden(struct Lista &, int ,int );


struct Nodo * crearNodo(int ,int , struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int, int);
Elemento retornaCabeza(const struct Lista &);

void eliminaNodo(struct Lista &, int ,int );
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONES_H */