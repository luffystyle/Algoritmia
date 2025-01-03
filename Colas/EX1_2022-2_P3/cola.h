/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cola.h
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 13 de diciembre de 2022, 16:43
 */

#ifndef COLA_H
#define COLA_H
#include "lista.h"

typedef ElementoLista ElementoCola;

typedef struct {
	Lista contenido;    
} Cola;

void construir_cola(Cola *tad);
void destruir_cola(Cola *tad);
int es_cola_vacia(Cola tad);
void pide_vez(Cola *tad, ElementoCola elemento);
ElementoCola avanzar(Cola *tad);

#endif /* COLA_H */

