#include <iostream>
#define max 40
using namespace std;

//2020-1 Laboratorio 2 Pregunta 1

//asumimos que la matriz es 4x4

void carga(int x, int y, int n, int m, int matriz[][max]) {
    int i, cont = 0;

    if (x >= n || y >= m)//Si se pasa los bordes: Caso base
        return;
        
    for (i = x; i < n - 1; i++)//nos movemos a la derecha
        cout << matriz[y][i] << " ";//se mueve las columnas y se fija la fila en y (posición inicial)
        
    for (i = y; i < m - 1; i++)//nos movemos hacia abajo
        cout << matriz[i][n - 1] << " ";//se mueve las filas y se fija la columna en n-1 (máximo del remolino)
        
    for (i = n - 1; i > x; i--)//nos movemos hacia la izquierda
        cout << matriz[m - 1][i] << " ";//se mueve las columnas y se fija la fila en m-1 (máximo del remolino)
        
    for (i = m - 1; i > y; i--)//nos movemos hacia arriba
        cout << matriz[i][x] << " ";//se mueve las filas y se fija la columna x (posición inicial)

    carga(x + 1, y + 1, n - 1, m - 1, matriz);//llamada recursiva para el siguiente remolino, 
											  //reducimos los máximos n y m
    										  //aumentamos x e y 
}

int main() {
    int i, j, cont = 0, flag;
    int x = 0, y = 0, n = 4, m = 4;
    int alma[max][max];

    for (j = 0; j < m; j++)
        for (i = 0; i < n; i++)
            alma[j][i] = cont++;

    carga(x, y, n, m, alma);
    return 0;
}

