
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 13, 2024, 10:27 PM
 */

#include <iostream>

#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "FuncionesArboles.h"

using namespace std;

int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    ArbolBinario arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7;
    
    //plantarArbolBinario(arbol, nullptr, 100, nullptr);
    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
    plantarArbolBinario(arbol3, arbol1, 10, arbol2);
    plantarArbolBinario(arbol5, nullptr, 30, nullptr);
    plantarArbolBinario(arbol6, nullptr, 40, nullptr);
    plantarArbolBinario(arbol7, arbol5, 5, arbol6);
    plantarArbolBinario(arbol, arbol3, 100, arbol7);
//    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
//    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
//    plantarArbolBinario(arbol3, arbol1, 10, arbol2);
//    plantarArbolBinario(arbol5, nullptr, 30, nullptr);
//    plantarArbolBinario(arbol6, nullptr, 40, nullptr);
//    plantarArbolBinario(arbol7, arbol5, 5, arbol6);
//    plantarArbolBinario(arbol, arbol3, 40, arbol7); // MI RAIZ ES 40
    
    cout << "RECORRER EN ORDEN:" << endl;
    recorrerEnOrden(arbol); cout << endl;
    cout << "RECORRER EN PRE-ORDEN" << endl;
    recorrerEnPreOrden(arbol); cout << endl;
    cout << "RECORRER EN POST-ORDEN" << endl;
    recorrerPostOrden(arbol);
    
    
    return 0;
}

