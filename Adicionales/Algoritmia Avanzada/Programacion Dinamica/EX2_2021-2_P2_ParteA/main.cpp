// PROGRAMACION DINAMICA
// ROBOTS ALMACENEROS

// PARTE A
#include <iostream>
#include <cmath>
#define N 4
#define M 4

using namespace std;

void imprimirMatriz(int matriz[N][M]) {
    
    cout << "La matriz resultado es : " << endl;
    for( int i = 0; i<N; i++) {
        for( int j = 0; j<M; j++) cout << matriz[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
}

void calculaDistancia(int almacen[N][M], int matriz[N][M]) {
    
    int i, j;
    int arriba, abajo, diagonal;
        
    // Caso de entrada
    matriz[0][0] = 0; // Aqui la distancia es 0 es por donde empezamos
    
    // Vamos a llenar toda la fila de la derecha y columa de abajo porque la primera FILA 
    // y a la primera COLUMNA no depende de otras opciones, solo del valor anterior
    
    // 1) Completamos Toda la primera fila de la derecha
    for( j = 1; j < M; j++) matriz[0][j] = matriz[0][j-1] + abs(almacen[0][j-1] - almacen[0][j]);
    // 2) Completamos toda la primera columna hacia abajo
    for( i = 1; i < N; i++) matriz[i][0] = matriz[i-1][0] + abs(almacen[i-1][0] - almacen[i][0]); 
    
    // 3) Evaluamos las opciones
    for( i = 1; i < N; i++) {
        for( j = 1; j < M; j++) {
            diagonal = abs(almacen[i][j]- almacen[i-1][j-1]) + matriz[i-1][j-1];
            arriba = abs(almacen[i][j]- almacen[i-1][j]) + matriz[i-1][j];
            abajo = abs(almacen[i][j]- almacen[i][j-1]) + matriz[i][j-1];
            if(diagonal <= arriba && diagonal <= abajo) matriz[i][j] = diagonal;
            else if( arriba <= diagonal && arriba <= abajo) matriz[i][j] = arriba;
            else if( abajo <= arriba && abajo <= diagonal) matriz[i][j] = abajo;
        }
    }
}

int main(int argc, char** argv) {
    
    int almacen[N][M] ={{4, 2, 2, 4}, 
                        {1, 4, 6, 8},
                        {2, 5, 9, 1}, 
                        {1, 3, 11, 12} };
    
    int matriz[N][M];
    
    calculaDistancia(almacen, matriz);
    imprimirMatriz(matriz);
    
    // La distancia recorrida minima
    cout << "La distancia total minima recorrido es: " << matriz[N-1][M-1];
    
    return 0;
}

