/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 4 de abril de 2024, 03:48 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void construir(struct Lista & lista);
bool esListaVacia(const struct Lista & lista);
void insertarAlInicio(struct Lista & lista, int elemento);
void insertarAlFinal(struct Lista & lista, int elemento);
void insertarEnOrden(struct Lista & lista, int elemento);

struct Nodo * obtenerUltimoNodo(const struct Lista & lista);
struct Nodo * obtenerNodoAnterior(const struct Lista & lista, int elemento);
void imprime(const struct Lista & lista);

#endif /* FUNCIONES_H */

