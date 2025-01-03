/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 19 de octubre de 2024, 09:55 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
#include "FuncionesAuxiliares.h"
#define MAX_COMPUTADORAS 6


using namespace std;


int main(int argc, char** argv) {
    struct Lista computadoras[MAX_COMPUTADORAS];
    for(int i=0; i<MAX_COMPUTADORAS; i++) construir(computadoras[i]);
    agregarConexion(1, 2, computadoras, MAX_COMPUTADORAS);
    agregarConexion(1, 3, computadoras, MAX_COMPUTADORAS);
    agregarConexion(2, 4, computadoras, MAX_COMPUTADORAS);
    agregarConexion(5, 6, computadoras, MAX_COMPUTADORAS);
    imprimirRed(computadoras, MAX_COMPUTADORAS);
    hayEscaladaPrivilegios(1, 6, computadoras, MAX_COMPUTADORAS);
    eliminarConexion(5, 6, computadoras, MAX_COMPUTADORAS);
    imprimirRed(computadoras, MAX_COMPUTADORAS);
    return 0;
}

