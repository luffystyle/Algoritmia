
#include <iostream>
#include <locale>
using namespace std;
#define N 5 // filas
#define M 5 //columnas

void imprimirTablero(int tablero[][M], int x, int y, int m, int n) {
    
    
    if( x >= n || y >= m) return;
    
    if( x == n-1 and y == m-1) cout << tablero[x][y];
    
    //avanzo a la derecha
    for(int i = y; i<m-1 ; i++) {
        cout << tablero[x][i]  << " ";
    }
    for(int i = x; i<n-1; i++) {
        cout << tablero[i][n-1]  << " ";
    }
    for(int i = m-1; i>y; i--) {
        cout << tablero[m-1][i]  << " ";
    }
    for(int i = n-1; i>x; i--) {
        cout << tablero[i][y]  << " ";
    }    
    imprimirTablero(tablero, x+1, y+1, m-1, n-1);
}




int main(int argc, char** argv) {

    int n = 5; // filas
    int m = 5; // columnas
    int tablero[N][M];
    int indice = 1;
    
    for( int i = 0; i< n; i++) {
        for(int j = 0; j<m; j++) {
            tablero[i][j] = indice; 
            indice++;
        }
        
    }
    for( int i = 0; i< m; i++) {
        for( int j = 0; j<n; j++) {
            cout << tablero[i][j]  << " ";
        }
        cout << endl;
    }
    
    //(0, 0) posicion inicial
    
    imprimirTablero(tablero, 0, 0, m, n);
    
    return 0;
}

