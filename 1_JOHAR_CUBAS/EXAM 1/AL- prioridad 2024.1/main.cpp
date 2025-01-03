/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesCola.h"
#include "funcionesLista.h"



int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    
    encolar(cola,19430530,"BXQ778");
    encolar(cola,20140420,"HRP112");
    encolar(cola,19750626,"PRL625");
    encolar(cola,19491022,"MKP157");
    encolar(cola,20200513,"ARH749");
    encolar(cola,19300214,"HRQ931");
    
    imprime(cola);
    
    return 0;
}



























