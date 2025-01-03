/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:16 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
bool esListaVacia(const struct Lista &);
int longitud(const struct Lista & );
struct Nodo * crearNuevoNodo(int , struct Nodo * );
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int );
void insertarAlInicio(struct Lista & , int );
void insertarAlFinal(struct Lista  & , int );
void insertarEnOrden(struct Lista & , int );
void imprime(const struct Lista & );
void problemaJosefo(struct Lista & , int );
void eliminaNodo(struct Lista & , int );
void destruirLista(struct Lista  & );

#endif /* FUNCIONESLISTA_H */

