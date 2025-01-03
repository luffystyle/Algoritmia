/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 14 de diciembre de 2024, 08:43 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void insertaCantidad(struct ArbolBinarioBusqueda & arbol, int produccion[4][7], 
                     int numDias, int numTurnos);
void pasarMatrizArreglo(struct Elemento * arr, int produccion[4][7], 
                        int numDias, int numTurnos);
void balancearArbol(struct ArbolBinarioBusqueda & arbol, struct Elemento * arr, 
                    int posInicio, int posFin);
int verificarEquilibrio(const struct ArbolBinarioBusqueda & arbol);
void ordenarMezcla(struct Elemento * arr, int posInicio, int posFin);
void mezclar(struct Elemento * arr, int posInicio, int posMedio, int posFin);
void imprimir(struct Elemento * arr);

#endif /* FUNCIONESAUXILIARES_H */

