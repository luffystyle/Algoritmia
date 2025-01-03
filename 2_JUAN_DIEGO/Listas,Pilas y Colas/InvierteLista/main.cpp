/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: ferhu
 *
 * Created on 1 de abril de 2024, 21:58
 */


#include <iostream>

#include "Lista.h"
using namespace std;
#include "masFuncionesLista.h"
#include "funcionesLista.h"


/*
 * 
 */
int main(int argc, char** argv) {
    struct Lista lista;
    /*Construimos la lista, la lista esta vacía*/
    construir(lista);
    cout<<esListaVacia(lista)<<endl;
       
        
    /*Inserta datos comenzando desde el inicio de la lista*/
    insertarAlInicio(lista, 5);
    insertarAlInicio(lista, 3);
    insertarAlInicio(lista, 1);
    imprime(lista);
    
    /*Inserta datos desde el final de la lista*/
    insertarAlFinal(lista, 6);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 10);
    imprime(lista);

    /*Insertar en orden los elementos de la lista*/
    insertarEnOrden(lista, 4);
    insertarEnOrden(lista, 2);
    insertarEnOrden(lista, 7);
    insertarAlInicio(lista, 3);
    imprime(lista);

    invertirLista(lista);
    imprime(lista);
    
    
    rotarListaIzquierda(lista);
    imprime(lista);
    
    intercambiarPares(lista);
    imprime(lista);
    
    eliminarRepetidos(lista);
    imprime(lista);
    /*Liberamos la memoria de la lista*/
    destruir(lista);
    /*Muestra los elementos de la lista*/
    imprime(lista);

    return 0;
}
