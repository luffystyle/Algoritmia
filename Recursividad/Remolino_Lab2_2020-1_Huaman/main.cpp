
/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on September 11, 2024, 2:19 PM
 */

#include <iostream>

using namespace std;


void cargaAlmacen(int x, int y, int n, int m, int matriz[][5]) {
    
    // CASO BASE
    if(x >= n || y >= m){
        return;
    }
    
    for(int i = y; i<m; i++)  cout << matriz[x][i] << " "; // Barro de izquierda hacia derecha
    for(int i = x+1; i<n; i++)  cout << matriz[i][m-1] << " "; // Barro de arriba hacia abajo
    for(int i = m-2; i>=y; i--)  cout << matriz[n-1][i] << " "; // Barro de derecha hacia izquierda
    for(int i = n-2; i>=x+1; i--)  cout << matriz[i][y] << " "; // Barro de abajo hacia arriba
    
    cargaAlmacen(x+1, y+1, n-1, m-1, matriz);
}



int main(int argc, char** argv) {

    int secuencia = 0;
    // El n y m son las dimensiones de tu mundo 
    int n = 5, m = 5; // 
    int matriz[5][5];
    int x = 0;
    int y = 0;
    
    for(int i = 0; i <n; i++) {
        for( int j = 0; j<m; j++) {
            matriz[i][j] = secuencia;
            secuencia++;
        }
    }
    
//    for(int i = 0; i <n; i++) {
//        for( int j = 0; j<m; j++) {
//            cout << matriz[i][j] <<  " ";
//        }
//        cout << endl;
//    }
    cargaAlmacen(x, y, n, m, matriz);
    
    return 0;
}

