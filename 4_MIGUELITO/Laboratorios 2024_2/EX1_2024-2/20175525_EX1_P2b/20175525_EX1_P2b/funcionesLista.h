/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 22:27
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void insertarAlFinal(struct Lista &, struct Cliente);

struct Nodo * crearNodo(struct Cliente elemento, struct Nodo *);
struct Cliente retornaCabeza(const struct Lista & lista);

void eliminaCabeza(struct Lista &);

void destruir(struct Lista &);
void imprime(const struct Lista &);
void insertarConPrioridad(struct Lista & lista, const struct Cliente & cliente);

#endif /* FUNCIONESLISTA_H */