/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 14 de septiembre de 2024, 08:11 AM
 */

#include <iostream>

using namespace std;

void reponerCantidades(int x, int y, int almacen[][5], int almacenRepuesta[][5], 
                       int numFilas, int numCol, int &max, int faseProceso){
    if (faseProceso==1){
        if (x>numFilas-1 or y>numCol-1) return;
        else {
            if (almacen[x][y]>max){
                max = almacen[x][y];
            }
            reponerCantidades(x, y+1, almacen, almacenRepuesta, numFilas, numCol, max, faseProceso);
            reponerCantidades(x+1, 0, almacen, almacenRepuesta, numFilas, numCol, max, faseProceso);
            faseProceso = 2;
            reponerCantidades(0, 0, almacen, almacenRepuesta, numFilas, numCol, max, faseProceso);
        }
    } else {
       if (x>numFilas-1 or y>numCol-1) return;
       else {
            almacenRepuesta[x][y] = max - almacen[x][y];
            reponerCantidades(x, y+1, almacen, almacenRepuesta, numFilas, numCol, max, faseProceso);
            reponerCantidades(x+1, 0, almacen, almacenRepuesta, numFilas, numCol, max, faseProceso);
       }
    }
}

int main(int argc, char** argv) {
    int almacen[5][5] = {{4,3,6,8,7},
                         {6,3,8,4,10},
                         {2,15,1,2,13},
                         {5,1,10,11,2},
                         {10,4,7,9,4}};
    int numFilas = 5;
    int numCol = 5;
    int almacenRepuesta[5][5];
    int max;
    max = 0;
    reponerCantidades(0, 0, almacen, almacenRepuesta, numFilas, numCol, max, 1);
    cout<<max<<endl;
    for(int i=0; i<numFilas; i++){
        for(int j=0; j<numCol; j++){
            cout<<almacen[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<numFilas; i++){
        for(int j=0; j<numCol; j++){
            cout<<almacenRepuesta[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

