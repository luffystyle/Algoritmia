/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"
#include "masFunciones.h"


int main(int argc, char** argv) {
    struct Lista l1;
    construir(l1);
    insertarAlInicio(l1,20);
    insertarAlInicio(l1,30);
    insertarAlInicio(l1,40);
    insertarAlInicio(l1,50);
    insertarAlFinal(l1,10);
    insertarAlFinal(l1,10);
    imprime(l1);
    
    invertirLista(l1);
    cout<<"Lista Invertida"<<endl;
    imprime(l1);

    rotarNodoIzquierdaFila(l1);
    cout<<"Poner la primer elemento de la fila al utlimo teniendo una lista ya definida"<<endl;
    imprime(l1);
    
    cout<<"Intercambiar Elementos"<<endl;
    intercambiarElementos(l1);
    imprime(l1);
    
    cout<<"Eliminar Repetidos"<<endl;
    eliminarRepetidos(l1);
    imprime(l1);
    
    
    return 0;
}

