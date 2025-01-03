/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on 13 de abril de 2024, 06:41
 */

#include <iostream>

using namespace std;
#include <cmath>
#define N 6

int recorreHorizontal(int tablero[][N], int ini, int n, int x) {
    int sumando = 0;
    for(int i = ini; i<n; i++) sumando += tablero[n][i];
    return sumando;
}

int recorreVertical(int tablero[][N], int ini, int n) {
    int sumando = 0;
    for( int i = ini; i<n; i++) sumando += tablero[i][n];
    return sumando;
}

int pesoMaximo(int tablero[][N], int n, int x, int y) {
    
    int sumaVertical, sumaHorizontal, sumaTotal, parcial;
    if( 0 == n-1 ) return 0;
    
    
    sumaHorizontal = recorreHorizontal(tablero, 0, n-1, x);
    sumaVertical = recorreVertical(tablero, x+1, n-1);
    sumaTotal = sumaHorizontal + sumaVertical;
    parcial = pesoMaximo(tablero, n-1, x+1, y);
    if(sumaTotal > parcial)  return sumaTotal;
    else return parcial;
}


int main(int argc, char** argv) {
    int n = 6;
    int tablero[N][N] = {{1, 2, 9, 1, 2, 3}, 
                         {5, 1, 7, 0, 2, 1}, 
                         {0, 7, 0, 3, 8, 1}, 
                         {1, 2, 6, 1, 2, 2}, 
                         {0, 6, 9, 5, 0, 5}, 
                         {0, 0, 4, 0, 9, 0}};
    
    
    cout << pesoMaximo(tablero, n, 0, 0) << endl;
    return 0;
}

