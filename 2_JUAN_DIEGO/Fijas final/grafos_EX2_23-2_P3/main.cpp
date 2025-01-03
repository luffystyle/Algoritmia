/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 3 de julio de 2024, 07:40 PM
 */

#include <cstdlib>
#include <iostream>
#define N 9

using namespace std;

/*
 * 
 */
void mostrar(int * arrEtiquetas){
    for(int i=0;i<N;i++){
        cout<<arrEtiquetas[i]<<" ";
    }
}
void incializatEtiquetas(int*arrEtiquetas){
    for (int i=0;i<N;i++){
        arrEtiquetas[i]=0;
    }
}
void etiquetar(int matriz[][N],int *arrEtiquetas){
    int etiqueta=1;
    int temp=0;
    for(int i=1;i<N;i++){//Iniciamos desde la segunda psocicion.
        etiqueta=1;
        temp=0;
        for(int j=0;j<=i;j++){
            if(matriz[i][j]>=1){
                if(arrEtiquetas[j]!=etiqueta && temp==0){
                    arrEtiquetas[i]=etiqueta;
                    temp=1;
                }else{
                    etiqueta++;
                }
                if(arrEtiquetas[i-1]==arrEtiquetas[i] && temp==1){
                    arrEtiquetas[i]=etiqueta+1;
                }
            }           
        }
    }
}
int main(int argc, char** argv) {
    int matriz[N][N]={{1, 2, 0, 6, 0, 0, 0, 0, 2},
                      {7, 1, 5, 2, 0, 0, 0, 0, 7},
                      {0, 3, 1, 2, 3, 8, 9, 7, 5},
                      {2, 7, 5, 1, 2, 0, 0, 0, 0},
                      {0, 0, 5, 3, 1, 4, 0, 0, 0},
                      {0, 0, 9, 0, 6, 1, 2, 0, 0},
                      {0, 0, 3, 0, 0, 7, 1, 4, 0},
                      {0, 0, 4, 0, 0, 0, 9, 1, 9},
                      {5, 3, 6, 0, 0, 0, 0, 4, 1}};
    int arrEtiquetas[N];
    incializatEtiquetas(arrEtiquetas);
    arrEtiquetas[0]=1;
    etiquetar(matriz,arrEtiquetas);
    mostrar(arrEtiquetas);
    
    return 0;
}

