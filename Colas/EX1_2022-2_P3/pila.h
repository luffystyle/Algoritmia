/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pila.h
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 13 de diciembre de 2022, 16:44
 */

#ifndef PILA_H
#define PILA_H
#include "lista.h"

typedef ElementoLista ElementoPila;

typedef struct {
	Lista contenido;    
} Pila;

void construir_pila(Pila *tad);
void destruir_pila(Pila *tad);
int es_pila_vacia(Pila tad);
void apilar(Pila *tad, ElementoPila elemento);
ElementoPila desapilar(Pila *tad);
ElementoPila cima(Pila tad);

#endif /* PILA_H */

