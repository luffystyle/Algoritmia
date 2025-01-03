
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 5, 2024, 4:33 PM
 */

#include <iostream>
#include <climits>

using namespace std;
#define N 10



int subeyBaja(int *arr, int ini, int fin, int &posY) {
    
    if(ini == fin) {
        posY = ini;
        return arr[ini]; // la logica
        
    }
    
    int med = (ini+fin)/2;
    
    
    if(arr[med] > arr[med+1]) {
        return subeyBaja(arr, ini, med, posY);
    } else {
        return subeyBaja(arr, med+1, fin, posY);
    }
    
    
}





void solucion(int matriz[][7], int n, int m, int &maximo, int &posX, int &posY) {
    int valor = 0;
    int posicionenY = 0 ;
    
    for(int i = 0; i<m; i++) {
        if(matriz[i][n/2]!=0) {
            if(matriz[i][n/2+1] != 0) {
                valor = subeyBaja(matriz[i], n/2, n, posicionenY);
                if(maximo < valor) {
                    maximo = valor;
                    posX = i;
                    posY = posicionenY;
                }
            }
            if(matriz[i][n/2-1] != 0) {
                valor = subeyBaja(matriz[i],0, n/2, posicionenY);
                if(maximo < valor) {
                    maximo = valor;
                    posX = i;
                    posY = posicionenY;
                }
            }
        }
        
        if(matriz[i][n/2 - 1] == 1 && matriz[i][n/2] == 0) {
            valor = subeyBaja(matriz[i], 0, n/2-1, posicionenY);
            if(maximo < valor) {
                maximo = valor;
                posX = i;
                posY = posicionenY;
            }
        }
        if(matriz[i][n/2 + 1] == 1 && matriz[i][n/2] == 0){
            valor = subeyBaja(matriz[i],n/2+1, n, posicionenY);
            if(maximo < valor) {
                maximo = valor;
                posX = i;
                posY = posicionenY;
            }
        }  
    }
}




int main(int argc, char** argv) {

//    int matriz[][7] = {{0, 0, 0, 0, 0, 0, 0}, 
//                       {0, 0, 0, 0, 0, 0, 0}, 
//                       {0, 0, 0, 0, 0, 0, 0}, 
//                       {0, 0, 0, 0, 0, 0, 0}, 
//                       {0, 0, 0, 0, 1, 1, 1}, 
//                       {0, 0, 0, 0, 1, 2, 2}, 
//                       {0, 0, 0, 0, 1, 2, 3}, 
//                       {0, 0, 0, 0, 1, 2, 2}, 
//                       {0, 0, 0, 0, 1, 1, 1}, 
//                       {0, 0, 0, 0, 0, 0, 0}};
//    
//    int n = 7;
//    int m = 10;
    
    
    
    int matriz[][7] = {{0, 0, 0, 0, 0, 0, 0}, 
                       {0, 0, 0, 0, 0, 0, 0}, 
                       {0, 0, 0, 0, 0, 0, 0}, 
                       {0, 0, 0, 0, 0, 0, 0}, 
                       {0, 1, 1, 1, 0, 0, 0}, 
                       {0, 1, 2, 1, 0, 0, 0}, 
                       {0, 1, 1, 1, 0, 0, 0}, 
                       {0, 0, 0, 0, 0, 0, 0} };
    int n = 7;
    int m = 8;
    
//    int n = sizeof(matriz[0])/sizeof(matriz[0][0]);
//    int m = sizeof(matriz[0])/sizeof(matriz[0][0]);

    int posX, posY;
    int maximaPotencia = 0;
    solucion(matriz, n, m, maximaPotencia, posX, posY);
    
    
    cout << "La potencia más alta de bomba es " << maximaPotencia << " y la columna donde se ubica es " << posY;
    cout << " y la fila donde se ubica es " << posX << endl;
    
    return 0;
}

