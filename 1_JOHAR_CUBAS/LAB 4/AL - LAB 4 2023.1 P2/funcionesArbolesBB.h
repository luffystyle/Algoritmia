/* 
 * File:   funcionesArbolesBB.h
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:34 PM
 */

#ifndef FUNCIONESARBOLESBB_H
#define FUNCIONESARBOLESBB_H

//
//void recorrerEnOrdenRecursivo(struct NodoArbol * nodo);
//void imprimeNodo(struct NodoArbol * nodo);
//
//void insertar(struct ArbolBinarioBusqueda & arbol, int elemento);
//void insertarRecursivo(struct Nodo *& nodo, int elemento);
//void eliminar(struct ArbolBB arbol, int elemento);
//struct Nodo * eliminarRecursivo(struct Nodo * nodo, int elemento);
//struct Nodo * minimoNodo(struct Nodo * nodo);

void construir(struct ArbolBinarioBusqueda & arbol);
bool esArbolVacio(const struct ArbolBinarioBusqueda & arbol);

void plantarArbolBB(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, int elemento,int cant, 
                    struct NodoArbol * arbolDerecho);

void preOrden(const struct ArbolBinarioBusqueda & arbol);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void postOrden(const struct ArbolBinarioBusqueda & arbol);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento,int cant);

int minimoNodoABB(const struct ArbolBinarioBusqueda &);
int maximoNodoABB(const struct ArbolBinarioBusqueda &);

struct NodoArbol *  minimoArbol(struct NodoArbol * nodo);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol ,int dato);
void eliminarNodo(struct ArbolBinarioBusqueda & ,int );
int comparaABB(int, int); 
int sumarNodos(const struct ArbolBinarioBusqueda & arbol);

void insertarRecursivo(struct NodoArbol *& raiz, int elemento,int cant);
int minimoNodo(struct NodoArbol * nodo);
int maximoNodo(struct NodoArbol * nodo);
bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento);

#endif /* FUNCIONESARBOLESBB_H */

