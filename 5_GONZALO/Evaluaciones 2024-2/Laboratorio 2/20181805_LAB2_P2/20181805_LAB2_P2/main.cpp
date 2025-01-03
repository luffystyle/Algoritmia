/* 
 * Archivo:   main.cpp
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 12 de octubre de 2024, 08:02 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Lista.h"
#include "funciones.h"
#include "FuncionesAuxiliares.h"

using namespace std;

int main(int argc, char** argv) {
    struct Lista listaPedidos;
    construir(listaPedidos);
    cargarDatosLista(listaPedidos);
    imprime(listaPedidos);
    ordenarLista(listaPedidos);
    imprime(listaPedidos);
    destruir(listaPedidos);
    return 0;
}

