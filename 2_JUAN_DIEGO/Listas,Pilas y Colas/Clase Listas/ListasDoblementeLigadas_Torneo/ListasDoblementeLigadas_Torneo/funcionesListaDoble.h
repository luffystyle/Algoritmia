/* 
 * File:   funcionesListaDoble.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef FUNCIONESLISTADOBLE_H
#define FUNCIONESLISTADOBLE_H

void construir(struct Lista & tad);
bool esListaVacia(const struct Lista &);

void imprimePrimerafecha(const struct Lista &);
void imprimeDesdeFinal(const struct Lista &);
void imprime(const struct Lista &);

struct Nodo * obtenerNodoAnterior(const struct Lista & , int);
struct Nodo * crearNodo(const char * , int , struct Nodo * , struct Nodo *);

void insertarAlFinal(struct Lista & , const char * , int );
void insertarEnOrden(struct Lista & , const char *, int);
void insertarAlInicio(struct Lista & , const char *, int );

struct Nodo * seEncuentra(const struct Lista & , const char * );
void eliminaCabeza(struct Lista  & );
void eliminaCola(struct Lista  & );
void eliminaNodo(struct Lista  & , const char * );

void destruirLista(struct Lista & );

#endif /* FUNCIONESLISTADOBLE_H */

