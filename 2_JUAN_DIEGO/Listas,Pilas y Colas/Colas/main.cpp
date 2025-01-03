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
    encolar(cola,1);
    encolar(cola,2);
    encolar(cola,1);
    encolar(cola,3);

    

    imprime(cola);
    return 0;
}

