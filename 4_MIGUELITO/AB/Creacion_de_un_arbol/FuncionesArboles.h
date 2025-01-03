
/* 
 * File:   FuncionesArboles.h
 * Author: miguel
 *
 * Created on November 13, 2024, 10:35 PM
 */

#ifndef FUNCIONESARBOLES_H
#define FUNCIONESARBOLES_H
#include "ArbolBinario.h"
#include "NodoArbol.h"

void construir(ArbolBinario &arbol);
bool esNodoVacio(NodoArbol *nodo);
bool esArbolVacio(ArbolBinario &arbol);
NodoArbol *crearNuevoNodoArbol(NodoArbol *arbolIzquierdo, int elemento, NodoArbol *arbolDerecho);
void plantarArbolBinario(ArbolBinario &, NodoArbol *, int , NodoArbol *);
void plantarArbolBinario(ArbolBinario &, ArbolBinario , int , ArbolBinario );
int raiz(NodoArbol *nodo);
NodoArbol *hijoIzquierdo(ArbolBinario &arbol);
void imprimirRaiz(ArbolBinario &arbol);
void imprimeNodo(NodoArbol *nodo);
void recorrerEnOrdenRecursivo(NodoArbol *nodo);
void recorrerEnOrden(ArbolBinario &arbol);
void recorrerEnPreOrdenRecursivo(NodoArbol *nodo);
void recorrerEnPreOrden(ArbolBinario &arbol);
void recorrerPostOrdenRecursivo(NodoArbol *nodo);
void recorrerPostOrden(ArbolBinario &arbol);
#endif /* FUNCIONESARBOLES_H */

