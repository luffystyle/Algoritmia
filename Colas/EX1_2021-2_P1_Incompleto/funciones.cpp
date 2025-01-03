
#include <iostream>
using namespace std;
#include "funciones.h"

// cuando construimos, siempre todo NULL y longitud en 0
void construir(Cola *pC) {
    pC->cabeza = NULL;
    pC->cola = NULL;
    pC->longitud = 0;
}

bool esColaVacia(Cola C) {
    return C.longitud == 0;
}

int obtenerLongitud(Cola C) {
    return C.longitud;
} 

Nodo* crearNodo(int piso, int direccion, Nodo *s) {
    Nodo *pC;// creo un nodo X y lo relleno, luego lo devuelvo
    pC = new Nodo;
    pC->piso = piso;
    pC->direccion = direccion;
    pC->sig = s;
    return pC;
}

void mostrar( Cola C) {
    Nodo *p;
    if( esColaVacia(C)) {
        cout << "La Cola está vacía." << endl;
    } else {
    p = C.cabeza;
        for( int i = 1; i<=C.longitud; i++) {
            
            cout << p->piso << "-" << p->direccion  ;
            if(i != C.longitud) cout << " -> ";
            p = p->sig;
        }
    }    
}


// insertamos al final
void encolar( Cola &pC, int piso, int direccion) {
    // EL ÚLTIMO EN INGRESAR ES EL PRIMERO DE LA COLA
    Nodo *p, *pU;
    p = crearNodo(piso, direccion, NULL);
    if(esColaVacia(pC)) { // cuando es la primera vez que voy a encolar
        pC.cabeza = p; 
    } else {
        pU = pC.cola;
        pU->sig= p;
    }
    pC.cola = p;
    pC.longitud++;
}

// Cuando vamos a desencolar, devolvemos un valor puede ser piso o direcci, da igual
// lo hacemos para mostrar qué elemento estamos eliminando solo por eso, pero también podría ser
// fácilmente un void
int desencolar(Cola &pC) {
    Nodo *p;
    int piso;
    p = pC.cabeza;
    piso = p->piso;
    if( pC.cabeza == NULL) pC.cola =  NULL;
    pC.cabeza = p->sig;
    pC.longitud--;
    delete p;
    return piso;
}






























































































