#include <iostream>

#define N 4

using namespace std;

int cont = 0;

void imprimir_tablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

void llenar_tablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            tablero[i][j] = 0;
    }
}

// Verifica si es seguro colocar una reina en la posición (fila, col) del tablero
int es_valido(int tablero[N][N], int col, int fila) {
    cout << "Fila es " << fila << " y columna es " << col << endl;
    // Verificar el lado izquierdo de la misma fila
    for (int i = 0; i < col; i++) {
        if (tablero[fila][i] == 1)
            return 0;
    }

    // Verificar la diagonal super izquierda
    for (int i = col - 1, j = fila - 1; i >= 0 && j >= 0; i--, j--) {
        if (tablero[j][i] == 1)
            return 0;
    }

    // Verificar la diagonal inferior izquierda
    for (int i = col - 1, j = fila + 1; i >= 0 && j < N; i--, j++) {
        if (tablero[j][i] == 1)
            return 0;
    }

    return 1;
}

// Función recursiva para resolver el problema N-Queens utilizando backtracking
// n: tamaño del tablero de ajedrez, el número de reinas que se deben colocar en el tablero.
// tablero[][N]: tablero de ajedrez
// col: columna actual en la que se está intentando colocar una reina. Con la llamada recursiva exploramos todas las posibles soluciones del tablero, moviéndonos de columna en columna.
int resolver_NQ(int n, int tablero[][N], int col) {
    // Si todas las reinas se han colocado con éxito, imprimir la solución y retornar 0
    if (col == n) {
        cont++;
        cout << "Solución " << cont << ":" << endl;
        imprimir_tablero(tablero);
        return 0;
    }

    // Intentar colocar una reina en cada fila de la columna actual
    for (int i = 0; i < n; i++) {
    	//BACKTRACKING
        if (es_valido(tablero, col, i)) {
            tablero[i][col] = 1; // Colocar una reina en la posición (i, col)

            // Llamar recursivamente para colocar las reinas en las columnas restantes
            if (resolver_NQ(n, tablero, col + 1))
                return 1;
            else
                tablero[i][col] = 0; // Si no es posible, retroceder y quitar la reina
        }
    }
    return 0; // No se encontró una solución válida en esta rama
}

int main() {
    int tablero[N][N];
    llenar_tablero(tablero);

    resolver_NQ(N, tablero, 0);

    return 0;
}

