

/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on 16 de abril de 2024, 08:26
 */

#include <iostream>

using namespace std;
#include "funciones.h"
#include "Lista.h"


int main(int argc, char** argv) {

    struct Lista lista;
    construir(lista);
    //cout << esListaVacia(lista) << endl;
    
//    insertarAlInicio(lista, 5);
//    insertarAlInicio(lista, 3);
//    insertarAlInicio(lista, 1);
    
//    imprime(lista);
    
    
    insertarAlFinal(lista, 10);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 15);
    insertarAlFinal(lista, 46);
    insertarAlFinal(lista, 23);
    imprime(lista);
    
    
    
    //eliminaCabeza(lista);// Eliminamos el primer Nodo de la Lista
    imprime(lista);
    
    //eliminaNodo(lista, 15);
    imprime(lista);
    
    destruir(lista);
    imprime(lista);
    
    return 0;
}

