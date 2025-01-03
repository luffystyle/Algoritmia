
/* 
 * File:   funcionesListas.h
 * Author: Miguelito
 *
 * Created on 16 de abril de 2024, 08:27
 */

#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H

void destruir(struct Lista &tad);
struct Nodo* obtenerNodoAnterior(const struct Lista &tad, int elemento);
void eliminaNodo(struct Lista &lista, int elemento);
void eliminaCabeza(struct Lista &tad);
struct Nodo* obtenerUltimoNodo(const struct Lista &tad);
void insertarAlFinal(struct Lista &, int );
void construir(struct Lista &);
int longitud(struct Lista &);
const bool esListaVacia(const struct Lista &);
void insertarAlInicio (struct Lista &, int);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTAS_H */

