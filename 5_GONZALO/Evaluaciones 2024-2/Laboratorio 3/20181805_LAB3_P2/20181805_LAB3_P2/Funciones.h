/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2024, 08:34 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void obtenerMaxPureza(int terreno[10][10], int , int , int , int &);
int maximo(int *, int );
void obtenerMuestrasMaxNiveles(int terreno[10][10], int idFila, int filaFin, 
                               int numCol, int *muestrasMaxNiveles, 
                               int &cantMuestras, int &maxCantMuestras);
int cuentaMuestras1(int *arr, int inicio, int fin);
int cuentaMuestras2(int *arr, int inicio, int fin);

#endif /* FUNCIONES_H */

