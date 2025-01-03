/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 19 de octubre de 2024, 08:23 AM
 */

#include <iostream>
#include "Funciones.h"

using namespace std;


int main(int argc, char** argv) {
    int numero = 1260, esVampiro;
    esVampiro = verificaVampiro(numero);
    if (esVampiro) cout << "El numero " << numero << " es vampiro" << endl;
    else cout << "El numero " << numero << " no es vampiro" << endl;
    return 0;
}

