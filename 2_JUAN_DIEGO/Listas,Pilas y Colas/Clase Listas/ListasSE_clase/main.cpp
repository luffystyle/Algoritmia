/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 4 de abril de 2024, 03:45 PM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;

/*
 * Mi lista =)
 */
int main(int argc, char** argv) {
    
    struct Lista lista;
    construir(lista);
    cout<<esListaVacia(lista)<<endl;
    
    insertarAlInicio(lista, 5);
    insertarAlInicio(lista, 3);
    insertarAlInicio(lista, 1);
    
    insertarAlFinal(lista, 7);
    insertarAlFinal(lista, 9);
    insertarAlFinal(lista, 11);
    
    insertarEnOrden(lista, 2);
    insertarEnOrden(lista, 7);
    insertarEnOrden(lista, 8);
    insertarEnOrden(lista, -3);
    
    imprime(lista);
    return 0;
}

