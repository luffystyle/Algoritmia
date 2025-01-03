//  N reinas
//  BACKTRACKING

#include <iostream>
#include <iomanip>
#define N 4
#define cont 0

using namespace std;

// Esta función verifica si se puede COLOCAR en esa posicion de (fila, columna) UNA REINA
// esta funcion HACE UN BARRIDO DE LA FILA y verifica si puede ir en alguna posición de la fila
int es_valido(int tablero[][N], int fila, int columna) {
    // verificamos el lado izquierdo de la misma fila, verificamos TODA LA FILA
    for(int j = 0; j < columna; j++) 
        if( tablero[fila][j] == 1) return 0;
    //Verificamos la diagonal superior izquierda
    for( int i = fila - 1, j = columna - 1; i >= 0 && j >= 0; i--, j--) 
        if( tablero[i][j] == 1) return 0;
    // verificamos la diagonal inferior izquierda
    for( int i = fila + 1, j = columna - 1; i < N && j >= 0; i++, j--)
        if(tablero[i][j] == 1) return 0;
    return 1; //  en caso contrario;        
}

// la columna que voy incrementando solo es la columna voy de  j = 0 hasta j = 4
// y por qué recorro solo los j y no los i(filas)? Porque cada vez que llegue al limite y no encuentre retorno 0
// esto quiere decir que no pude colocar una reina en esa fila, entonces me retorna 0 y hago backtracking
int resuelve( int tablero[][N], int columna) {
    int i; //  las filas
    if( columna >= N ) return 1;// cuando llegue a la ultima fila y si halla solucion devuelve 1
    
    // Dentro del problema, cada columna es un universo y cada casillero que encuentro disponible
    // creo otro universo
    // es decir, cada vez que encuentro un espacio disponible CREA UN UNIVERSO nuevo
    for( i = 0; i < N; i++) { // aqui REVISAMOS TODAS LAS FILAS, solo filas 
        if( es_valido(tablero, i, columna) ) {
            tablero[i][columna] = 1; // cuando encuentro una solucion RELLENO con una reina el tablero
            if(resuelve(tablero, columna + 1)) return 1;
            tablero[i][columna] = 0; //EL BACKTRACKING y quito la reina por el valor de 0
        }        
    }
    //cuando el for no encuentra el número en cada columna, entonces RETORNO 0
    // es decir, HAGO BACKTRACKING SI O SI, porque en la columna no hay opciones que pueda continua
    return 0; // Si no encuentro una solución, retorno 0
}

void imprimirSolucion( int tablero[][N]) {
    for( int i = 0; i < N; i++) {
        for( int j = 0; j < N; j++) cout << tablero[i][j] << " ";
        cout << endl;
    }
}


int main(int argc, char** argv) {

    int tablero[][N] = {{0, 0, 0, 0}, 
                        {0, 0, 0, 0}, 
                        {0, 0, 0, 0}, 
                        {0, 0, 0, 0} };
    
    // Este funcion resuelve() es el universo MAYOR, cuando no hay ninguna solución recién devuelvo 0
    // Por otro lado, nosotros nos damos cuenta no hemos pasado las filas, porque las filas se mantedran constante dentro
    // de la recursividad. Las filas siempre se mantendran constante segun lo colocado, por eso en la llamada recursiva no 
    // ponemos fila+1, ni nada de eso.
    if( !resuelve(tablero, 0) ) cout << "No existe solucion." << endl;
    else imprimirSolucion(tablero);

    return 0;
}
