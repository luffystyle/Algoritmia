/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on September 24, 2024, 11:04 PM
 */

#include <iostream>

using namespace std;

#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"









int main(int argc, char** argv) {

    
    Lista lista;
    construir(lista);
    
    insertarAlInicio(lista, 15);
    insertarAlInicio(lista, 20);
    insertarAlInicio(lista, 6);
    insertarAlInicio(lista, 10);
    insertarAlInicio(lista, 12);
    
    imprime(lista);
    
    
    
    
    
    
    return 0;
}

