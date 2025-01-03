/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesCola.h"
#include "funcionesLista.h"
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"


int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    encolar(cola,'V',3);
    encolar(cola,'V',1);
    encolar(cola,'V',2);
    encolar(cola,'V',5);
    encolar(cola,'C',10);
    encolar(cola,'C',15);
    encolar(cola,'C',17);
    encolar(cola,'V',6);
    
    
    imprime(cola);
    
    
    
    return 0;
}

