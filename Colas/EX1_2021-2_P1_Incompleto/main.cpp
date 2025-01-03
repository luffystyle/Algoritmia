
#include <iostream>
using namespace std;
#include "funciones.h"

void ordenarec(Cola &pC, int n) {
    int min, aux, i = 1;

    if (esColaVacia(pC)) return;
    min = desencolar(pC);
    while(i > n) {
        aux = desencolar(pC);
        if(min > aux) {
            encolar(pC, min, 1);
            min = aux;
        }
        else encolar(pC, aux, 1);
        i++;
        
    }
    ordenarec1(pC, n - 1);
    encolar(pC, min, 1);
}



void ordenarCola(Cola &pCola, int direc_cabeza) {
    cout << endl;
    // Tengo que eliminar la cabeza y darsela al sigueinte
    // en caso, la cabeza tenga un solicitud para arriba; es decir, el valor de la dirección sea 1
    if(direc_cabeza == 1) {
        ordenarec1(pCola, pCola.longitud);

    } else { //  si la solicitud vaya hacia para abajo; es decir, el valor de la dirección sea 0
        ordenarec1(pCola, pCola.longitud1);
    }
    // tengo que eliminar la cabeza
    
}



int main(int argc, char** argv) {

    int solicitudes, a, b;
    int cant_edificios;
    Cola Cola;
    construir(&Cola);
    
    cout << "Ingrese la cantidad de pisos del edificio: ";
    cin >> cant_edificios;
    cout << "Movimientos del ascensor en un edificio de "<< cant_edificios << " pisos:" << endl;
    
    int bandera = 0;
    int direc_cabeza = 0;
    do {
        cout << "La cola de solicitudes del ascensor es : " << endl;
        if(bandera == 0) {
            encolar(Cola, 1, 1);
            bandera = 1;
        }
        mostrar(Cola);
        cout << " -> " << endl;

        cout << "Ingrese la cantidad de solicitudes: " ;
        cin >> solicitudes;
        
        // antes de desencolarlo, agarro la dirección de la cabeza
        // lo desencolo para que no ordene la cola
        direc_cabeza = Cola.cabeza->direccion;
        desencolar(Cola);
        
        for(int i = 0; i<solicitudes; i++) {
            cout << "Solicitud "<< i+1 <<" [número_piso y dirección(1:sube,0:baja)]: ";
            cin >> a >> b;
            encolar(Cola,a, b);            
        }
        // le doy la cabeza de la decirme cuál es la dirección
        ordenarCola(Cola, direc_cabeza);

        
    } while(esColaVacia(Cola) != true);
    

    return 0;
}

