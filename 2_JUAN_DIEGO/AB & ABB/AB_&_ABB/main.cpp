/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 21 de mayo de 2024, 12:43 PM
 */

#include <cstdlib>
#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ArbolBinario arbol,arbol2,arbol3,arbol4,arbol5;
    //12345
    
    plantarArbolBinario(arbol5,NULL,1,NULL);
    plantarArbolBinario(arbol4,NULL,3,NULL);
    plantarArbolBinario(arbol3,arbol5,2,arbol4);
    plantarArbolBinario(arbol2,NULL,5,NULL);
    plantarArbolBinario(arbol,arbol3,4,arbol2);
    
    
    recorridoPorNivel(arbol);
    enOrdenIterativo(arbol);
//    recorrerPreOrden(arbol);
//    recorrerPostOrden(arbol);
//    cout<<altura(arbol)<<endl;
    preOrdenIterativo(arbol);
    postOrdenIterativo(arbol);
    
    
    

    return 0;
}

