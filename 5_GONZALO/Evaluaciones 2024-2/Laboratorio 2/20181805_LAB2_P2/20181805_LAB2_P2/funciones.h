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

void insertarAlInicio(struct Lista &, struct Pedido);
void insertarAlFinal(struct Lista &, struct Pedido);
//void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(struct Pedido elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
//struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
//struct Nodo * seEncuentra(const struct Lista &, int);
struct Pedido retornaCabeza(const struct Lista & lista);

//void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
//void eliminaCola(struct Lista &);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONES_H */