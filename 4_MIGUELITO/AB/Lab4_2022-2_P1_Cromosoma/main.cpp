/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on November 24, 2024, 10:36 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "ArbolB.h"
#include "funcionesAB.h"


//Estoy termina cuando no tiene mas hojas.
void insertarNewRecursivo(NodoArbol *&arbol, Elemento elem) {
    
    if(arbol == nullptr) { // CUANDO ESTE VACIO VA A LA DERECHA O LA IZQUIERDA, YO ME DEDICO A PLANTAR
        plantarArbolBinario(arbol, nullptr, elem, nullptr);
        return;
    } else {
        elem.binario = 0;
        insertarNewRecursivo(arbol->izquierda, elem);
        elem.binario = 1;
        insertarNewRecursivo(arbol->derecha, elem);
    }    
}


void insertarNew(ArbolBinario &arbol, Elemento elem) {
    insertarNewRecursivo(arbol.raiz, elem);    
}


void contruirArbolCromosoma(int *arr, ArbolBinario &arbol, int n) {
    
    //CREAR LA RAIZ
    Elemento elem = {0, 0};
    plantarArbolBinario(arbol, nullptr, elem, nullptr);
    
    int i;
    
    for(i = 0; i<n; i++) {
        elem.numero = arr[i];
        insertarNew(arbol, elem); //LE PASO EL ARBOL DESDE ARRIBA, O SEA DESDE LA RAIZ
    }
    
}


int cantidadCombinacionesRecursivo(NodoArbol *noditoArbolesco, int pesoParcial, int peso) {
    // el peso cuando ingreso a cada iteracion va sumando y cuando llegue a una de las hojas. Recien valido
    // si está bien o no
    pesoParcial = pesoParcial + noditoArbolesco->elemento.numero * noditoArbolesco->elemento.binario;
    if(noditoArbolesco->izquierda == nullptr && noditoArbolesco->derecha == nullptr) { //Hasta que no tengo hijos 
        //LLEGUÉ A UNA HOJA 
        if(pesoParcial == peso) return 1; //CASO BASE
        return 0;
    }
    // con este recorro todo los hojas
    return cantidadCombinacionesRecursivo(noditoArbolesco->izquierda, pesoParcial, peso) +  
           cantidadCombinacionesRecursivo(noditoArbolesco->derecha, pesoParcial, peso);
}



int cantidadCombinaciones(int *arr, int peso, NodoArbol *noditoArbolesco, int n) {
    int pesoParcial = 0;
    return cantidadCombinacionesRecursivo(noditoArbolesco, pesoParcial, peso);
    
}


int main(int argc, char** argv) {

    
    //int arr[] = {10, 50};
    int arr[] = {10, 50, 20, 30, 40};
    //int arr[] = {10};
    //int arr[] = {10, 50, 70};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout << n << endl;
    ArbolBinario arbol;
    construir(arbol);
    contruirArbolCromosoma(arr, arbol, n);
    recorrerEnOrden(arbol); cout << endl;
    
    int sumatoria = 0;
    int pesoMaximo = 70;
    cout << cantidadCombinaciones(arr, pesoMaximo, arbol.raiz, n);
    //cout << altura(arbol) << endl;
    
    return 0;
}

