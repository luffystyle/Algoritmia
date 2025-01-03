#include <iostream>
using namespace std;
#include "Funciones.h"

void ordernaPilaRecursividad(Pila &pPila, int n) {
    Pila pila2;
    construir(pila2);
    int max, i = n-1, aux;
    
    if( n == 0) return;
    max = desapilar(pPila);
    while( i > 0) {
        aux = desapilar(pPila);
        if(max < aux) {
            apilar(pila2, max);
            max = aux;
        } else {
            apilar(pila2, aux);
        }
        i--;
    }
    apilar(pPila, max);
    while(!esPilaVacia(pila2)) {
        aux = desapilar(pila2);
        apilar(pPila, aux);
    }
    ordernaPilaRecursividad(pPila, n-1);
}

int main(int argc, char** argv) {

    Pila Ppila ;
    Elemento e;
    construir( Ppila);
    mostrar(Ppila);
    
    apilar( Ppila, 19);  
    apilar( Ppila, 48);
    apilar( Ppila, 37);
    apilar( Ppila, 84);
    mostrar( Ppila);
    cout << "La pila está ordenada" << endl;
    ordernaPilaRecursividad(Ppila, Ppila.longitud);
    mostrar(Ppila);        
    
    return 0;
}
