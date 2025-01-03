/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 13 de diciembre de 2022, 16:43
 */

#ifndef LISTA_H
#define LISTA_H

typedef int ElementoLista;

typedef struct nodoLista {
    ElementoLista elemento;    
    struct nodoLista *sig;
} NodoLista;

typedef struct {
    int longitud;
    NodoLista *cabeza;
} Lista;

void construir_lista(Lista *tad);
int es_lista_vacia(Lista tad);
NodoLista *crear_nuevo_nodo(ElementoLista elemento, NodoLista* sig);
void insertar_al_inicio(Lista *tad, ElementoLista elemento);
int longitud(Lista tad);
void imprime(Lista tad);
NodoLista *obtener_ultimo_nodo(Lista tad);
void insertar_al_final(Lista *tad, ElementoLista elemento);
NodoLista *obtener_nodo_anterior(Lista tad, ElementoLista elemento);
void insertar_en_orden(Lista *tad, ElementoLista elemento);
NodoLista* se_encuentra(Lista tad, ElementoLista llave);
void destruir_lista(Lista *tad);
ElementoLista retorna_cabeza(Lista tad);
void elimina_cabeza(Lista *tad);
void elimina_cola(Lista *tad);
void elimina_nodo(Lista *tad, ElementoLista elemento);

#endif /* LISTA_H */

