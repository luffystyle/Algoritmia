#include <iostream>
using namespace std;

// Constantes para el m�ximo n�mero de movimientos, tama�o del tablero y n�mero m�ximo de direcciones iniciales.
const int MAX_MOV = 20; //se establece en 20, lo que significa que el robot puede realizar un m�ximo de 20 movimientos en su intento de encontrar una soluci�n al problema.
const int MAX_INI = 8; // se establece en 8, lo que significa que el robot puede moverse en ocho direcciones diferentes desde su posici�n actual: arriba, abajo, izquierda, derecha y en las cuatro direcciones diagonales
const int N = 100; // Tama�o m�ximo del tablero en el eje x
const int M = 100; // Tama�o m�ximo del tablero en el eje y

int mov[MAX_INI][2]; // Arreglo bidimensional para almacenar las posiciones de movimiento del robot
int maximo = 0; // Variable que registra el n�mero m�ximo de soluciones encontradas


// Funci�n para generar las posiciones de movimiento
void generarPosiciones() {
    mov[0][0] = 1; mov[0][1] = 0;//abajo
    mov[1][0] = 0; mov[1][1] = -1;//izquierda
    mov[2][0] = 0; mov[2][1] = 1;//derecha
    mov[3][0] = -1; mov[3][1] = 0;//arriba
    
    mov[4][0] = 1; mov[4][1] = 1;//abajo, derecha
    mov[5][0] = -1; mov[5][1] = -1;//arriba, izquierda
    mov[6][0] = 1; mov[6][1] = -1;//abajo, izquierda
    mov[7][0] = -1; mov[7][1] = 1;//arriba, derecha
}

// Funci�n para generar un tablero vac�o
void generarTablero(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '0';
        }
    }
}

// Funci�n para colocar minas en el tablero
void cargarMinas(char a[N][M]) {
    a[0][41] = '*';
    a[2][2] = '*';
    a[4][1] = '*';
    a[4][2] = '*';
    a[4][4] = '*';
    a[5][1] = '*';
    a[5][2] = '*';
    a[5][4] = '*';
    a[6][1] = '*';
    a[6][3] = '*';
    a[7][0] = '*';
    a[7][1] = '*';
    a[7][2] = '*';
    a[7][3] = '*';
}

// Funci�n para imprimir el contenido del tablero
void imprimir(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Funci�n para verificar si una casilla es v�lida
bool esValido(char a[N][M], int x, int y, int n, int m) {
    return x < n && y < m && x >= 0 && y >= 0 && a[x][y] == '0';
}

// Funci�n para descubrir las casillas adyacentes a una posici�n (x, y) en el tablero
void descubrir(char a[N][M], int n, int m, int x, int y, char solu[N][M]) {
    // Recorremos las 8 direcciones posibles utilizando el arreglo de movimientos "mov"
    for (int i = 0; i < MAX_INI; i++) {
        int nueva_x = x + mov[i][0]; // Calculamos la nueva coordenada en el eje x
        int nueva_y = y + mov[i][1]; // Calculamos la nueva coordenada en el eje y
        
        // Verificamos si la nueva posici�n (nueva_x, nueva_y) es v�lida y si contiene una mina '*'
        if (esValido(solu, nueva_x, nueva_y, n, m) && a[nueva_x][nueva_y] == '*') {
            solu[nueva_x][nueva_y] = '*'; // Si es v�lido y hay una mina, marcamos esa casilla como mina en el tablero de soluci�n
        }
    }
}

// Funci�n para resolver el problema del robot
bool resolverRobot(char a[N][M], int n, int m, int x, int y, char solu[N][M], char pasos) {
    if (maximo == MAX_MOV) return true; // Verifica si se ha alcanzado el n�mero m�ximo de movimientos permitidos
    if (x == n - 1 && y == m - 1) {
        imprimir(solu, n, m); // Si el robot llega al final, imprime el tablero de soluci�n
        cout << endl;
        maximo++;
        return false;
    }
    
    // Echo un vistazo a los alrededores de la posici�n en la que me encuentro
    descubrir(a, n, m, x, y, solu); 
    
    
	//Ahora s� hago el movimiento del robot
	//BACKTRACKING
    for (int i = 0; i < MAX_INI; i++) {
        int nueva_x = x + mov[i][0]; // Calcula la nueva coordenada en el eje x
        int nueva_y = y + mov[i][1]; // Calcula la nueva coordenada en el eje y
        if (esValido(solu, nueva_x, nueva_y, n, m)) { // Verifica si la nueva posici�n es v�lida
            solu[nueva_x][nueva_y] = pasos + 1; // Marca la casilla en el tablero de soluci�n con el n�mero de pasos
            if (resolverRobot(a, n, m, nueva_x, nueva_y, solu, pasos + 1)) { // Llamada recursiva para el siguiente movimiento
                return true; // Si se encontr� una soluci�n, regresa true
            }
            solu[nueva_x][nueva_y] = '0'; // Si no se encontr� una soluci�n, se vuelve a marcar como no visitada
        }
    }
    
    return false; // Si no se encontr� una soluci�n en ninguna direcci�n, regresa false
}


int main() {
    char pasos = 'A'; // Inicializa una variable para llevar el registro de los pasos del robot
    int n = 9; // Tama�o del tablero en el eje x
    int m = 5; // Tama�o del tablero en el eje y
    int x = 0; // Coordenada inicial en el eje x
    int y = 0; // Coordenada inicial en el eje y
    
    char tabla[N][M]; // Tablero principal donde se colocan las minas
    char solucion[N][M]; // Tablero de soluci�n que registra el recorrido del robot
    
    generarPosiciones(); // Genera las posiciones de movimiento del robot
    generarTablero(tabla, n, m); // Inicializa el tablero principal
    cargarMinas(tabla); // Coloca las minas en el tablero
    imprimir(tabla, n, m); // Imprime el tablero principal
    cout << endl;
    generarTablero(solucion, n, m); // Inicializa el tablero de soluci�n
    
    solucion[0][0] = pasos; // Marca la posici�n inicial del robot en el tablero de soluci�n con 'A'
    
    resolverRobot(tabla, n, m, x, y, solucion, pasos); // Llama a la funci�n para resolver el problema del robot
    
    return 0;
}


