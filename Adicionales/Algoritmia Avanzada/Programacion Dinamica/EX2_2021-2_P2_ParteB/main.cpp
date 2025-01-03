// PROGRAMACION DINAMICA
// ROBOTS ALMACENEROS

// PARTE B
#include <iostream>
#include <iomanip>
#define N 6
#define M 6

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
    int arriba, abajo;
        
    // Caso de entrada
    matriz[0][0] = almacen[0][0]; // Aqui la distancia es 0 es por donde empezamos
    
    // Vamos a llenar toda la fila de la derecha y columa de abajo porque la primera FILA 
    // y a la primera COLUMNA no depende de otras opciones, solo del valor anterior
    
    // 1) Completamos Toda la primera fila de la derecha
    for( j = 1; j < M; j++) matriz[0][j] = matriz[0][j-1] + almacen[0][j];
    // 2) Completamos toda la primera columna hacia abajo
    for( i = 1; i < N; i++) matriz[i][0] = matriz[i-1][0] + almacen[i][0]; 
    
    // 3) Evaluamos las opciones
    for( i = 1; i < N; i++) {
        for( j = 1; j < M; j++) {
            arriba = almacen[i][j] + matriz[i-1][j];
            abajo = almacen[i][j] +  matriz[i][j-1];
            if(arriba >= abajo ) matriz[i][j] = arriba;
            else matriz[i][j] = abajo;
        }
    }
}

int main(int argc, char** argv) {
    
    int almacen[N][M] ={{1, 2, 9, 1, 2, 3}, 
                        {5, 1, 7, 1, 2, 1},
                        {1, 7, 1, 3, 8, 1}, 
                        {2, 2, 6, 1, 2, 2}, 
                        {3, 6, 9, 5, 1, 5}, 
                        {1, 1, 4, 1, 9, 1} };
    
    int matriz[N][M];
    int p, q;
    
    calculaDistancia(almacen, matriz);
    imprimirMatriz(matriz);
    
    p = 2, q = 3;
    cout << "Si el área a considerar es p = " << p << " y q = " << q << " " << endl;
    cout << setw(40) << "La solución a esta disposiciósn es de " << matriz[p-1][q-1] << " unidades." << endl << endl;
    
    p = 3, q = 3;
    cout << "Si el área a considerar es p = " << p << " y q = " << q << " " << endl;
    cout << setw(40) << "La solución a esta disposición es de " << matriz[p-1][q-1] << " unidades." << endl << endl;
    
    p = 6, q = 6;
    cout << "Si el área a considerar es p = " << p << " y q = " << q << " " << endl;
    cout << setw(40) << "La solución a esta disposición es de " << matriz[p-1][q-1] << " unidades." << endl << endl;
    
    return 0;
}

