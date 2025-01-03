/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 7 de diciembre de 2024, 08:32 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void definirContrasenha(struct ArbolBinarioBusqueda & arbol);
int longitudContrasenha(const struct ArbolBinarioBusqueda & arbol);
bool buscarCaracterIngresado(const struct ArbolBinarioBusqueda & arbol, char caracter, int posicion);
bool buscarCaracter(const struct ArbolBinarioBusqueda & arbol, struct Elemento elemento);
bool buscarCaracterRecursivo(struct NodoArbol * nodo, struct Elemento elemento);

#endif /* FUNCIONESAUXILIARES_H */

