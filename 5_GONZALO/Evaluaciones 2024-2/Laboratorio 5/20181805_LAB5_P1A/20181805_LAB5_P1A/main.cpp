/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 14 de diciembre de 2024, 08:39 AM
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"

using namespace std;

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    int produccion[4][7] = {{100, 103, 100, 101, 100, 99, 100},
                            {100, 102, 102, 92, 99, 100, 98},
                            {100, 100, 102, 100, 100, 101, 100},
                            {98, 96, 93, 99, 100, 102, 95}};
    int numTurnos = 4;
    int numDias = 7;
    
    insertaDiaTurno(arbol, produccion, numDias, numTurnos);
    enOrden(arbol);
    cout << endl;
    int estaEquilibrado = verificarEquilibrio(arbol);
    cout << "Es equilibrado: " << estaEquilibrado << endl;
    return 0;
}

