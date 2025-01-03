

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo : 20175525
 * Created on October 11, 2024, 12:38 AM
 */

#include <iostream>
#include <ratio>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"



//void pasaPilaNormalin(Pila &P1, Pila &P2) {
//    
//    
//    int valor, aux, n;
//    while(!esPilaVacia(P1)) {
//        valor = desapilar(P1);
//        n = 0; // contador de apilacion en Pila 2
//        while(!esPilaVacia(P1)) {
//                 apilar(P2, valor);
//                 valor = desapilar(P1);
//                 n++;
//        }
//        while(!esPilaVacia(P2) && n>0) {
//                apilar(P1, desapilar(P2));
//                n--;
//        }	
//        apilar(P2, valor);
//    }
//    
//}




void pasaPilaNormalin(Pila &P1, Pila &P2) {
    int valor;
    
    
    
    while(!esPilaVacia(P1)) {
        valor = desapilar(P1);
        int cuentaDatos = 0;
        while(!esPilaVacia(P1)) {
            
            apilar(P2, valor);
            valor = desapilar(P1);
            cuentaDatos++;
        }
        
        while(cuentaDatos>0) {
            apilar(P1, desapilar(P2));
            cuentaDatos--;
        }
        apilar(P2, valor);
    }
    
}


void pasaPilaRecursivo(Pila &P1, Pila &P2, int n) {
    int valor;
    
    
    if(n == 0) return;

    valor = desapilar(P1);
    int cuentaDatos = 0;
    while(!esPilaVacia(P1)) {

        apilar(P2, valor);
        valor = desapilar(P1);
        cuentaDatos++;
    }

    while(cuentaDatos>0) {
        apilar(P1, desapilar(P2));
        cuentaDatos--;
    }
    apilar(P2, valor);
    pasaPilaRecursivo(P1, P2, n-1);
}

void pasaPilaRecursivoEnLinea(Pila &P1, Pila &P2, int n) {
    
    if( n == 0) return;
    int valor = desapilar(P1);
    
    pasaPilaRecursivoEnLinea(P1, P2, n-1);
    apilar(P2, valor);
}

void ordenaPilaRecursivo(Pila &P1, int n) {
    
    Pila P2;
    construir(P2);
    if(n == 0) return;
    int valor, max;
    int contador = n-1;
    max = desapilar(P1);
    while( contador>0 ) {
        valor = desapilar(P1);
        if(valor < max) {
            apilar(P2, valor);
        } else {
            apilar(P2, max);
            max = valor;
        }
        contador--;
    }
    apilar(P1, max);
    while( !esPilaVacia(P2)) {
        
        apilar(P1, desapilar(P2));

    }
    
    //imprimir(P1);
    
    ordenaPilaRecursivo(P1, n-1);
}



int main(int argc, char** argv) {

    
    
    Pila P1;
    construir(P1);
    
    apilar(P1, 15);
    apilar(P1, 25);
    apilar(P1, 70);
    apilar(P1, 21);
    apilar(P1, 7);
    apilar(P1, 5);
    cout << "Pila Original" << endl;
    imprimir(P1);
    
//    Pila P2;
//    construir(P2);
    //pasaPilaNormalin(P1, P2);
    //pasaPilaRecursivo(P1, P2, P1.lista.longitud);
//    pasaPilaRecursivoEnLinea(P1, P2, P1.lista.longitud);
//    imprimir(P2);
    ordenaPilaRecursivo(P1, P1.lista.longitud);
    cout << "Pila Ordenada" << endl;
    imprimir(P1);
    
    return 0;
}

