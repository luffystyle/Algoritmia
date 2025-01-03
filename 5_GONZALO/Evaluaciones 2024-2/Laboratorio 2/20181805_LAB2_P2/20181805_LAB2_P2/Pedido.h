/* 
 * Archivo:   Pedido.h
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 12 de octubre de 2024, 08:38 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

struct Pedido {
    char id[5];
    int tiempoPreparacion;
    int tiempoEstimadoViaje;
    int tiempoEstimadoTotal;
};

#endif /* PEDIDO_H */

