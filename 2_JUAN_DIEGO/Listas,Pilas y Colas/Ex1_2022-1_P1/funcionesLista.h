/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

//void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, int,int);
void insertarAlFinal(struct Lista &, int);

struct Nodo * crearNodo(int ,int, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);

int longitud(const struct Lista &);
const bool esListaVacia(const struct Lista & tad);
void eliminaCabeza(struct Lista & tad);
Nodo * retornaCabeza(const struct Lista & tad);
void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

