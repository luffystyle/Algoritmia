/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de noviembre de 2024, 09:08 AM
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"
#include "funcionesAB.h"

using namespace std;

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    ingresarLote(arbol, 2018, 100);
    ingresarLote(arbol, 2011, 150);
    ingresarLote(arbol, 2022, 50);
    ingresarLote(arbol, 2010, 175);
    ingresarLote(arbol, 2017, 25);
    ingresarLote(arbol, 2019, 125);
    ingresarLote(arbol, 2023, 200);
    ingresarLote(arbol, 2020, 75);
    //reporteStock(arbol);
    return 0;
}

