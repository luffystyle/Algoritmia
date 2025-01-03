/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2024, 08:05 AM
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"
#define N 13

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int bitacora[N] = {1,6,3,4,5,6,3,7,5,4,3,1,7};
    int n = 13;
    int empSolitario;
    ordenarMezcla(bitacora, 0, n-1);
    empSolitario = buscarSolitario(bitacora, 0, n-1);
    cout << empSolitario << endl;
    return 0;
}

