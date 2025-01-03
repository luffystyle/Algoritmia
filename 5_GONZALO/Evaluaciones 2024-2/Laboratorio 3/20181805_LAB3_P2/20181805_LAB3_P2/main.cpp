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
#include <valarray>
#include "Funciones.h"
#define N 10

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int terreno[N][N] = {{0,0,0,3,3,7,5,5,1,1},
                         {8,8,10,9,9,5,4,4,2,0},
                         {3,5,8,9,7,6,4,2,0,0},
                         {9,7,7,4,4,4,2,0,0,0},
                         {0,2,2,3,3,4,4,5,3,3},
                         {0,0,0,0,0,0,2,3,4,5},
                         {1,2,2,3,3,4,3,2,0,0},
                         {0,0,0,0,0,0,3,5,5,7},
                         {6,5,5,2,2,1,0,0,0,0},
                         {3,2,2,0,0,0,0,0,0,0}};
    int numFilas = 10, numCol = 10;
    int maxPureza = 0;
    int muestrasMaxNiveles[N], cantMuestras = 0;
    int maxCantMuestras = 0;
    obtenerMaxPureza(terreno, 0, numFilas-1, numCol, maxPureza);
    cout << "La maxima pureza de las muestras es: " << maxPureza << endl;
    obtenerMuestrasMaxNiveles(terreno, 0, numFilas-1, numCol, 
            muestrasMaxNiveles, cantMuestras, maxCantMuestras);
    if (cantMuestras>0){
        cout << "Las muestras con mayor cantidad de niveles con minerales son: ";
        for(int i=0; i<cantMuestras; i++) cout << muestrasMaxNiveles[i] << " ";
        cout << endl;
        cout << "Con " << maxCantMuestras << " estratos de minerales" << endl;
    }
    return 0;
}

