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
#include "Lista.h"
#include "Nodo.h"
#include "funcionesCola.h"
#include "funcionesLista.h"




int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    encolar(cola,'N',24);
    encolar(cola,'C',10);
    encolar(cola,'V',2);
    encolar(cola,'V',4);
    encolar(cola,'V',6);
    encolar(cola,'C',12);
    encolar(cola,'N',20);
    
    imprime(cola);
    
    
    
    return 0;
}

