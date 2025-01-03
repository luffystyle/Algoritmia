/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 18, 2024, 10:30 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"



void actualizar(Cola &C1, long long nuevoTiempoPrimero) {
    
    int horaPrimero = (((nuevoTiempoPrimero%10000000)/10000)/100)*60 + ((nuevoTiempoPrimero%10000000)/10000)%100;
    int codigoPrimero =  nuevoTiempoPrimero/100000000;
    
    int i = 0;
    while(i<C1.lista.longitud) { 
        long long tiempoActual = desencolar(C1);
        int codigoValor = tiempoActual/100000000;
        if(codigoValor == codigoPrimero) {
            tiempoActual = nuevoTiempoPrimero;
        }
        
        encolar(C1, tiempoActual);
        i++;
    }
    
}


void ordenarColaHoraIni(Cola &C1, int n) {
    
    int aux;

    if(esColaVacia(C1)) {
        return;
    }
    long long tiempoMayor = desencolar(C1);
    int mayor = (((tiempoMayor%100000000)/10000)/100)*60 + ((tiempoMayor%100000000)/10000)%100;
    
    int i = 1;
    while(i<n) { 
        long long tiempoAux = desencolar(C1);
        aux = (((tiempoAux%100000000)/10000)/100)*60 + ((tiempoAux%100000000)/10000)%100;
        if(mayor < aux) {
            encolar(C1, tiempoMayor);
            tiempoMayor = tiempoAux;
            mayor = aux;
        } else {
            encolar(C1, tiempoAux);
        }
        i++;
    }
    ordenarColaHoraIni(C1, C1.lista.longitud);
    encolar(C1, tiempoMayor);
    
}

void ordenarColaHoraFin(Cola &C1, int n) {
    
    int aux;

    if(esColaVacia(C1)) {
        return;
    }
    long long tiempoMayor = desencolar(C1);
    int mayor =  + tiempoMayor%100;
    
    int i = 1;
    while(i<n) { 
        long long tiempoAux = desencolar(C1);
        aux = ((tiempoAux%10000)/100)*60 + tiempoAux%100;
        if(mayor < aux) {
            encolar(C1, tiempoMayor);
            tiempoMayor = tiempoAux;
            mayor = aux;
        } else {
            encolar(C1, tiempoAux);
        }
        i++;
    }
    ordenarColaHoraFin(C1, C1.lista.longitud);
    encolar(C1, tiempoMayor);
    
}

int main(int argc, char** argv) {

    Cola C1;
    construir(C1);
    encolar(C1, 210100550055);
    encolar(C1, 110201450145);
    encolar(C1, 411100300030);
    encolar(C1, 210501220122);
    encolar(C1, 310805250525);
    
    cout << setw(25) << "AEROPUERTO AURORA" << endl; 
    cout << "HORA DE LLEGADA:" << endl;
    imprime(C1);
    ordenarColaHoraIni(C1, C1.lista.longitud);
    cout << endl << endl;
    
    cout << "NUEVA HORA DE LLEGADA:" << endl;
    actualizar(C1, 210100550015);
    actualizar(C1, 210501220210);
    ordenarColaHoraFin(C1, C1.lista.longitud);
    
    imprime(C1);

    return 0;
}
