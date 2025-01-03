/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Cola.h"
#include "Nodo.h"
#include "Lista.h"
#include "funcionesCola.h"
#include "funcionesLista.h"

void ordenarColar(struct Cola &cola,int n){
    struct Nodo * recorrido=cola.lista.cabeza;
    int aux,mayor,i=1;
    if(esColaVacia(cola)) return;
    mayor = desencolar(cola);
    
    while(i<n){
        int aux= desencolar(cola);
        if(mayor<=aux){
            encolar(cola,mayor);
            mayor= aux;            
        }else{
           encolar(cola,aux); 
        }
        i++;
        
    }
    
    ordenarColar(cola,n-1);
    encolar(cola,mayor);
}




int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    encolar(cola,50);
    encolar(cola,60);
    encolar(cola,40);
    encolar(cola,30);
    encolar(cola,10);
    encolar(cola,20);
    imprime(cola);
    
    cout<<"Ordenar las colas"<<endl;
    ordenarColar(cola,cola.lista.longitud);
    imprime(cola);
    
    
    
    return 0;
}

