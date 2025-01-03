
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 26, 2024, 5:19 PM
 */

#include <iostream>

#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

using namespace std;


void combinarArboles(ArbolBinarioBusqueda &arbolEmisor, ArbolBinarioBusqueda &arbolDestino) {
    
    
    
    
    
}

int main(int argc, char** argv) {

    ArbolBinarioBusqueda arbolEmisor, arbolDestino;
    construir(arbolEmisor.arbolBinario);
    construir(arbolDestino.arbolBinario);
    
    
    Elemento elem = {20170620, 20};
    insertar(arbolDestino, elem);
    elem = {20170810, 20};
    insertar(arbolDestino, elem);
    elem = {20180211, 20};
    insertar(arbolDestino, elem);
    elem = {20180409, 10};
    insertar(arbolDestino, elem);    
    recorrerEnOrden(arbolDestino.arbolBinario);
    
    
    elem = {20170811, 5};
    insertar(arbolEmisor, elem);
    elem = {20180211, 10};
    insertar(arbolEmisor, elem);
    elem = {20180410, 15};
    insertar(arbolEmisor, elem);  
    cout << endl << endl;
    recorrerEnOrden(arbolEmisor.arbolBinario);
    
    combinarArboles(arbolEmisor, arbolDestino);
    cout << "Cantidad de nodos " << numeroNodos(arbolDestino.arbolBinario);
    cout << "Cantidad de nodos " << numeroNodos(arbolEmisor.arbolBinario);
    
    
    return 0;
}

