/* 
 * File:   funcionesListaDoble.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef FUNCIONESLISTADOBLE_H
#define FUNCIONESLISTADOBLE_H

void construir(struct Lista & tad);
bool esListaVacia(struct Lista tad);
struct Nodo *crearNuevoNodo(int , struct Nodo * , struct Nodo* );
void insertarAlInicio(struct Lista & , int );
void imprimeDesdeFinal(const struct Lista & );
void imprime(const struct Lista & );

#endif /* FUNCIONESLISTADOBLE_H */

