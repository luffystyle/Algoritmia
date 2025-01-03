/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesCola.h
 * Author: juanD
 *
 * Created on 18 de abril de 2024, 06:48 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
int desencolar(struct Cola & cola);
int longitud(const struct Cola & cola);
void imprimeCola(const struct Cola & cola);
void destruirCola(struct Cola & cola);
#endif /* FUNCIONESCOLA_H */

