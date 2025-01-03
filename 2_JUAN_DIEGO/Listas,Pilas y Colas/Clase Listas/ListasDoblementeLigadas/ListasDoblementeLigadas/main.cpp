/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:40 PM
 */

#include <cstdlib>
#include "Lista.h"
using namespace std;
#include "funcionesListaDoble.h"
/*
 * 
 */
int main(int argc, char** argv) {

    struct Lista lista;
    construir(lista);
    insertarAlInicio(lista, 10);
    insertarAlInicio(lista, 14);
    insertarAlInicio(lista, 18);
    insertarAlInicio(lista, 20);
    imprime(lista);
    imprimeDesdeFinal(lista);
    
    
    return 0;
}

