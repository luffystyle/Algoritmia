/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

//void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, struct NodoArbol *);
void insertarAlFinal(struct Lista &, struct NodoArbol *);

struct Nodo * crearNodo(struct NodoArbol * elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
//struct Nodo * obtenerNodoAnterior(const struct Lista &, int);

int longitud(const struct Lista &);
const bool esListaVacia(const struct Lista & tad);
void eliminaCabeza(struct Lista & tad);
struct NodoArbol * retornaCabeza(const struct Lista & tad);
void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

