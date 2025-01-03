/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"

using namespace std;
#include "funcionesCola.h"



int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    encolar(cola,'V',1);
    encolar(cola,'V',2);
    encolar(cola,'N',1);
    encolar(cola,'V',3);

    

    imprime(cola);
    return 0;
}

