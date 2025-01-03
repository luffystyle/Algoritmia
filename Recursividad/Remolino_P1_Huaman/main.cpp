
#include <iostream>
#include <iomanip>
#define MAX_COL 10
#define MAX_FIL 10

using namespace std;

void remolino(int tablero[][MAX_COL], int n, int m, int x, int y) {

    // condicion de parada
    // quiere decir que x llegó a n y y llegó a M, es que ya no hay MÁS UNIVERSOS CUADRADOS
    // Vemos que cada vez que haces un mundo, nuestro tablero te vuelve pequeño, CUANDO
    // ya no haya mundos más pequeños, es decir que el x y y sea n y m, respectivamente
    // es cuando finalizamos
    if (x >= n or y >= m) return;

    // para esta parte tenemos que ir a cada for, porque cada movimiento
    // existe un for, en el caso anterior nuestrsa condiciones, pero en esta haremos for
    // y como son 4 movimientos, usaremos 4 for, unos para derecha, otro hacia abaja
    // otro hacia la izquierda y ,por último, arriba. El orden es sentido HORARIO
    // por eso, va en ese orden

    // MOVIMIENTO DERECHA
    // empezamos desde x, en el primer universo es 0, tenemos que generalizar, porque si ponemos 0
    // y en la impresión, el y tbm es general, porque en los demás universos no podemos empezar desde n
    // sino desde y. Además, el i es el que estamos incrementando
    for (int i = x; i<m; i++) cout << tablero[y][i] << " ";

    // MOVIMIENTO ABAJO
    for (int i = y+1; i<n; i++) cout << tablero[i][m - 1] << " ";

    for (int i = m-2; i>=y; i--) cout << tablero[n-1][i] << " ";

    for (int i = n-2; i>x; i--) cout << tablero[i][y] << " ";

    
    // porque ponemos -1 al otro y +1 al otro. En vez de poner por ejemplo remolino(tablero, n, m, x+2, y+2)
    // en ese caso está mal, porque el x no aumenta en 2, sino aumenta en 1. Que quiere decir esto
    // EN primero lugar, tenemos saber que x es el inicio y m es el fin, igualmente con y y n.
    // entonces, partiendo de esto, el inicio aumenta porque ya no empieza en x = 0, sino empieza en 1, y por eso
    // estaría mal ponerle 2. Por esta razón, el x aumenta en 1, y el otro limite que es en m disminuye en 1
    // entonces, la lógica correcta seria que el x+1 y en m-1; es decir, el inicio aumenta y el fin disminute en 1
    // ambos casos
    remolino(tablero, n-1, m-1, x+1, y+1);

}

int main(int argc, char** argv) {

    // el n es el número de filas y el m el número de columnas
    int a = 1;
    int n = 10, m = 5;
    int tablero[MAX_FIL][MAX_COL];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tablero[i][j] = a;
            a++;
        }
    }

//        for( int i = 0; i<n; i++) {
//            for( int j = 0; j<m; j++) {
//                cout <<setw(3)<< tablero[i][j];
//            }
//            cout << endl;
//        }

    // en el problema, no indica que EMPEZAMOS DESDE LA POSICIÓN IZQUIERDA Y LA PRIMERA FILA
    // es decir, en el punto de una matriz de (0, 0)
    int x = 0, y = 0;
    remolino(tablero, n, m, x, y);


    return 0;
}

