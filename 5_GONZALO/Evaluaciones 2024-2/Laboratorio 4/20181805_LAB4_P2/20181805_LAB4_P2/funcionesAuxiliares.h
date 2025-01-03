/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 30 de noviembre de 2024, 09:10 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void ingresarLote(struct ArbolBinarioBusqueda & arbol, int anioLote, int cantidadLote);
void ingresarLoteRecursivo(struct NodoArbol * nodo, struct Lote lote);
struct NodoArbol * buscarLote(struct NodoArbol * nodo, struct Lote lote);
void reporteStock(const struct ArbolBinarioBusqueda & arbol);

#endif /* FUNCIONESAUXILIARES_H */

