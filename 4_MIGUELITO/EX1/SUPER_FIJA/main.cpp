
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 19, 2024, 12:32 AM
 */

#include <iostream>
#include <ratio>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"


struct Efectivo {
    int id;
    int grado;
    int tiempo;
};

void imprimirPila(Pila &pila) {
    cout << "{ ";
    imprimir(pila); // Usa la función de la pila para imprimir
    cout << " }" << endl;
}

int agrupacion(Efectivo *efectivos, int n) {
    int total = 0;
    Pila pila;
    construir(pila);
    
    // Pongo todo a la pila
    for(int i = 0; i<n; i++) {
        apilar(pila, efectivos[i].id);
    }
    
    while(!esPilaVacia(pila)) { 
        int valor = desapilar(pila);
        for(int i = valor; i<n; i++) { // aqui uso el arreglo
            if(efectivos[valor-1].grado<efectivos[i].grado) break;
            
            if(efectivos[valor-1].grado == efectivos[i].grado) {
                if(efectivos[valor-1].tiempo <= efectivos[i].tiempo) 
                    break;
            }
            total++;
        }
        total++;
    }
    return total;
}





int main(int argc, char** argv) {

    
    Efectivo efectivos[] = { {1, 2, 4}, 
                    {2, 2, 1}, 
                    {3, 2, 4},  } ;
    
    int n = 3;

//    Efectivo efectivos[] = { {1, 1, 1}, 
//                    {2, 2, 3}, 
//                    {3, 2, 5}, 
//                    {4, 1, 2} } ;
//    
//    int n = 4;
    
    
    
    cout << "Se pueden formar " << agrupacion(efectivos, n) << " agrupaciones." << endl;
    
    return 0;
}

