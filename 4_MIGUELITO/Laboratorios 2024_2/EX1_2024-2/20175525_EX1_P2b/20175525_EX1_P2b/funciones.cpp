/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * 
 * Created on 26 de setiembre de 2024, 13:25
 */

#include <iostream>
#include <iomanip>
#include "Cliente.h"
#include "funcionesCola.h"
#include "funcionesCliente.h"
using namespace std;
#define PROCESO 20
#define MAX_CAJEROS 1
#define NUM_CLIENTES 6


void resolucion( Cola &C1, Cliente cli, int &vipAtendidos, int &vipNoAtendidos) {
    
    if(esColaVacia(C1)) {
        if(cli.prioridad == 1) vipAtendidos++;
        //else return;
    } else {
        if(cli.prioridad == 1) { // Nodo con prioridad
            if( cli.horaSalida - cli.horaLlegada < 15) { // el tiempo qe tengo que esperar
                desencolar(C1);
                vipNoAtendidos++;
            } else {
                vipAtendidos++;
                encolarConPrioridad(C1, cli); // cuando no espera y es atentido
            }
        } 
    }   
    
    
    
}


void simulacionDeColas(struct Cola &cola) {

    int vipAtendidos =0, vipNoAtendidos=0;
    int cajeros = 0;
    
//    Cola C1;
//    construir(C1);
    
    Cliente cli1 = {15, 35, 2};
    Cliente cli2 = {30, 55, 1};
    Cliente cli3 = {45, 35, 2};
    Cliente cli4 = {60, 35, 1};
    Cliente cli5 = {75, 35, 2};
    Cliente cli6 = {90, 35, 1};
    
    resolucion(cola, cli1, vipAtendidos, vipNoAtendidos);
    resolucion(cola, cli2, vipAtendidos, vipNoAtendidos);
    resolucion(cola, cli3, vipAtendidos, vipNoAtendidos);
    resolucion(cola, cli4, vipAtendidos, vipNoAtendidos);
    resolucion(cola, cli5, vipAtendidos, vipNoAtendidos);
    resolucion(cola, cli6, vipAtendidos, vipNoAtendidos);
    

    

    /* Mostrar resultados de la simulación */
    cout << setw(8) << cajeros + 1;
    cout << setw(22) << vipAtendidos;
    cout << setw(22) << vipNoAtendidos << endl;

}
