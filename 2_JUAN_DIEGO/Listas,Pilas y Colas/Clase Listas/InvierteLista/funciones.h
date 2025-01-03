/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 4 de abril de 2024, 09:41 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void construir(struct Lista & lista);
bool esListaVacia(const struct Lista &lista);
void insertarAlInicio(struct Lista & lista, int elemento);
void imprime(const struct Lista & lista);
void invierteLista(struct Lista & lista);
int longitud(const struct Lista & lista); 
struct Nodo * obtenerUltimoNodo(const struct Lista & lista);
struct Nodo * obtenerAnteriorNodo( const struct Lista & lista);
void eliminaRepetidos(struct Lista & lista);

void invierteListaRecursivo(struct Lista & lista, int );
void eliminaRepetidos(struct Lista & lista);
void completarLista(struct Lista & lista);

#endif /* FUNCIONES_H */

