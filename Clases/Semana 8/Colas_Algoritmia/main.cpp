#include <iostream>
using namespace std;
#include "Funciones.h"

void ordenaColaRecursiva(Cola &ptrCola, int n) {
    
    int i = 1, menor, aux;
    if(esColaVacia(ptrCola)) return;
    menor = desencolar(ptrCola);
    
    while( i<n ) {
        aux = desencolar(ptrCola);
        if( aux < menor ) {
            encolar(ptrCola, menor);
            menor = aux;
        } else {
            encolar(ptrCola, aux);            
        }
        i++;        
    }
    ordenaColaRecursiva(ptrCola, n-1);
    encolar(ptrCola, menor);
}

int main()
{
    Cola PCola;
    construir(&PCola);
    encolar(PCola, 20);
    encolar(PCola, 8);
    encolar(PCola, 18);
    encolar(PCola, 15);
    encolar(PCola, 5);
    mostrar(PCola);    
    ordenaColaRecursiva(PCola, PCola.longitud);
    mostrar(PCola); 
    
    return 0;
}
