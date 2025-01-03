#include <iostream>
using namespace std;

#define MAX_MOV 8
#define N 100

int movimientosPosibles[MAX_MOV][2];

// Funci�n para generar los movimientos posibles del caballo
void generarMovimientos() {
    movimientosPosibles[0][0] =  2; movimientosPosibles[0][1] =  1;
    movimientosPosibles[1][0] =  1; movimientosPosibles[1][1] =  2;
    movimientosPosibles[2][0] = -1; movimientosPosibles[2][1] =  2;
    movimientosPosibles[3][0] = -2; movimientosPosibles[3][1] =  1;
    movimientosPosibles[4][0] = -2; movimientosPosibles[4][1] = -1;
    movimientosPosibles[5][0] = -1; movimientosPosibles[5][1] = -2;
    movimientosPosibles[6][0] =  1; movimientosPosibles[6][1] = -2;
    movimientosPosibles[7][0] =  2; movimientosPosibles[7][1] = -1;
}

// Funci�n para generar un tablero con celdas en 0
void generarTablero(int tablero[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = 0;
        }
    }
}

// Funci�n para imprimir el tablero en la consola
void imprimirTablero(int tablero[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
}

// Funci�n para verificar si una casilla es v�lida y no ha sido visitada
int esValido(int tablero[N][N], int x, int y, int n) {
    if (x < n && y < n && x >= 0 && y >= 0 && tablero[x][y] == 0) {
        // Comprueba si las coordenadas (x, y) est�n dentro de los l�mites del tablero y si la casilla no ha sido visitada
        return 1;  // Si es v�lido y no ha sido visitada, devuelve 1 (verdadero)
    }
    return 0;  // Si no es v�lido o ya ha sido visitada, devuelve 0 (falso)
}


// Funci�n recursiva para resolver el problema del caballo
//tablero[N][N]: tablero de ajedrez. Cada celda contiene un valor que indica si esa casilla ha sido visitada por el caballo o no. 
//n: longitud de un lado del tablero cuadrado. n se utiliza para verificar si una casilla es v�lida, asegur�ndose de que las coordenadas x y y est�n dentro de los l�mites del tablero.
//x, y: Estas son las coordenadas actuales del caballo en el tablero, que representan la posici�n actual del caballo en t�rminos de fila (x) y columna (y).
//nMov: Es un contador que indica el n�mero de movimientos realizados por el caballo. Se inicia con 2, ya que el caballo ya ha realizado su primer movimiento al comienzo del juego.
int resolverCaballero(int tablero[N][N], int n, int x, int y, int nMov) {
    int i, nueva_x, nueva_y;
    //imprimirTablero(tablero, n);  // Imprime el tablero actual
    //cout << endl;

    if (nMov == n * n + 1)  // Si hemos visitado todas las casillas, hemos encontrado una soluci�n
        return 1;

    for (i = 0; i < MAX_MOV; i++) {
        nueva_x = x + movimientosPosibles[i][0];  // Calcula la nueva posici�n en x
        nueva_y = y + movimientosPosibles[i][1];  // Calcula la nueva posici�n en y
        if (esValido(tablero, nueva_x, nueva_y, n)) {  // Comprueba si la nueva casilla es v�lida y no ha sido visitada
            tablero[nueva_x][nueva_y] = nMov;  // Marca la casilla como visitada
            if (resolverCaballero(tablero, n, nueva_x, nueva_y, nMov + 1)) {  // Llamada recursiva para el siguiente movimiento
                return 1;  // Si encontramos una soluci�n, regresamos 1
            }
            tablero[nueva_x][nueva_y] = 0;  // Si no encontramos una soluci�n, desmarcamos la casilla
        }
    }

    return 0;  // Si no encontramos una soluci�n, regresamos 0
}

int main() {
    int n;
    int x, y;
    n = 5;
    x = 0;
    y = 0;
    int tablero[N][N];
    generarMovimientos();
    generarTablero(tablero, n);
    tablero[x][y] = 1;
    int res = resolverCaballero(tablero, n, x, y, 2);
    cout << "�Logr� encontrar la soluci�n? " << res << endl;
    imprimirTablero(tablero, n);
    return 0;
}

