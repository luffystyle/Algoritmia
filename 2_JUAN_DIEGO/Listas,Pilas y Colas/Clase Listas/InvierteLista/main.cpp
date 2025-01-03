/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 4 de abril de 2024, 09:40 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;
/*
 * LSE clase
 */
int main(int argc, char** argv) {
    
    struct Lista lista;
    construir(lista);
  
    cout<<"la lista está vacía: "<<esListaVacia(lista)<<endl;
    insertarAlInicio(lista, 7);
    insertarAlInicio(lista, 7);
    insertarAlInicio(lista, 6);
    insertarAlInicio(lista, 4);
    insertarAlInicio(lista, 4);
    insertarAlInicio(lista, 3);
    insertarAlInicio(lista, 1);
    insertarAlInicio(lista, 1);
    imprime(lista);
    
    cout<<"Invierte iterativo: "<<endl;
    invierteLista(lista);
    imprime(lista);
    
    int n = longitud(lista);
    cout<<"Invierte Recursivo: "<<endl;
    invierteListaRecursivo(lista, n);
    imprime(lista);
    
    cout<<"Elimina repetidos consecutivos: "<<endl;
    eliminaRepetidos(lista);
    imprime(lista);
    
    cout<<"Completar lista: "<<endl;
    //completarLista(lista);
    imprime(lista);
    
    return 0;
}

