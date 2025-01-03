/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de noviembre de 2024, 08:13 AM
 */

#include <iostream>
#include <iomanip>
#include "ArbolB.h"
#include "funcionesAB.h"
#include "funcionesAuxiliares.h"

using namespace std;

int main(int argc, char** argv) {
    struct ArbolBinario arbol;
    construir(arbol);
    generarArbol(arbol);
    imprimirArbol(arbol);
    destruirArbolBinario(arbol);
    return 0;
}

