#include <iostream>
#define max 100

using namespace std;

//2016-2 Laboratorio 1 Pregunta 2


int robot(int x, int y, int n, int m, int tablero[][max]) {//[][max] por sintaxis en C++ se debe poner las dimensiones de al menos la columna o las filas
    int abajo = -999999, derecha = -999999, total;
    
    if (x == n - 1 && y == m - 1) //caso base: cuando nos queda s�lo una celda (tablero 1x1)
        return tablero[x][y];//cuando el tablero es 1x1, devuelve el mismo valor
        
        
    if (x+1 < n) //si a�n se puede mover a la derecha
        derecha = robot(x + 1, y, n, m, tablero); //llamo a funci�n robot para conocer el mejor resultado de ir a la derecha
    if (y+1 < m)//si a�n se puede mover a abajo
        abajo = robot(x, y + 1, n, m, tablero);//llamo a funci�n robot para conocer el mejor resultado de ir a abajo
    //en este punto, ya se ha tomado el caso base y empezamos a retornar a todos los llamados pendientes.
	if (derecha < abajo) //determinamos qu� camino es el mejor: ir hacia abajo o a la derecha
        total = tablero[x][y] + abajo; //acumulamos
    else
        total = tablero[x][y] + derecha; //acumulamos

    return total; //devolvemos el camino que acumula m�s puntaje.
} 

int main() {
    int i, j, n, m;
    int tablero[max][max];
    cout<<"Ingrese N: ";
    cin >> n;
    cout<<"Ingrese M: ";
	cin >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> tablero[i][j];

    cout << robot(0, 0, n, m, tablero) << endl;

    return 0;
}

