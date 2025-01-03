/* 
 * File:   Cliente.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 10:55 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

struct Cliente{
    int horaLlegada;
    int horaSalida;
    int prioridad; // Si prioridad = 1; cliente VIP, prioridad = 0; no VIP
};

#endif /* CLIENTE_H */

