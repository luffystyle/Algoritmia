// PUPILETRAS 
// PC1_2019-1

#include <iostream>
#include <cmath>
#define N 5
#define M 5
using namespace std;

int m[8][2];

int movimientos() { // solo estoy creando una matriz, pero en sentido HORARIO, (y, x)
    // es y, x porque cuando avanzamos nos movemos primero entre los y, luego entro los x
    // las filas se mueven de arriba hacia abajo, en cambio las columans de derecha a izquierda
    m[0][0] = -1;    m[0][1] =  0; // (-1, 0)
    m[1][0] = -1;    m[1][1] =  1; // (-1, 0)
    m[2][0] =  0;    m[2][1] =  1; // ( 0, 1)
    m[3][0] =  1;    m[3][1] =  1; // ( 1, 1)
    m[4][0] =  1;    m[4][1] =  0; // ( 1, 0)
    m[5][0] =  1;    m[5][1] = -1; // ( 1,-1)
    m[6][0] =  0;    m[6][1] = -1; // ( 0,-1)
    m[7][0] = -1;    m[7][1] = -1; // (-1,-1)
}

void solucion(char pupi[][N], char word[], char resultado[][N], int nword, int row, int col) {


    int nrow, ncol;
    int j = 0,k = 0, l = 0, s = 0, flag = 0;
    // Primero, tenemos que ver si la letra que buscamos pertenece a word
    if(word[0] != pupi[row][col]) return ;

    // Segundo, tenemos que usar los movimientos
    for( int i = 0; i<8; i++) { // son 8 movimientos, ESTO SOLO ES PARA INICIAR Y BUSCAR LA PRIMERA LETRA
        
        nrow = row + m[i][0];
        ncol = col + m[i][1];
        // tenemos que hallar que los movimientos NO SEAN NEGATIVOS
        if(nrow>=0 and ncol>=0 and ncol < N and nrow < M) {
            for( j = 1; j<nword; j++) { // en caso, que se encuentre AME, sin 'N' al final, entonces no cumple j == nword
                if(word[j] != pupi[nrow][ncol]) break;
                // una vez encontrada la segunda palabra, SOLO DEBO SEGUIR EL MOVIMIENTO
                // aqui ya repito el movimiento; es decir, si seguimos un movimiento diagonal derecho
                // hacia arriba o todo derecha o todo arriba, etc
                nrow = nrow + m[i][0];
                ncol = ncol + m[i][1];
            }
            if( j == nword) {
                for(k = 0, l = 0, s = 0; s<nword; k += m[i][0], l += m[i][1], s++) resultado[row+k][col+l] = word[s];
            }
        } 
    }
}

void SearchWord(char pupi[][N], char word[], char resultado[][N], int nword) {
    // tengo que recorrer la matriz pupiletras
    for( int i = 0; i<M; i++) {
        for( int j = 0; j<N; j++) {
            solucion(pupi, word, resultado, nword, i, j);
            
        }
    }
}

void PrintResult(char resultado[][N]) {
    for( int i = 0; i<M; i++) {
        for( int j = 0; j<N; j++) {
            cout<< resultado[i][j] << " ";
        }
        cout << endl;
    }
}


int main(int argc, char** argv) {


    char pupi[M][N] = { {'H', 'G', 'A', 'F', 'Y'},
                        {'D', 'Q', 'V', 'Z', 'R'},
                        {'A', 'M', 'E', 'N', 'H'},
                        {'O', 'G', 'O', 'R', 'F'},
                        {'T', 'R', 'W', 'I', 'P'} };
                
    char resultado[M][N] = { {'0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0'} };
    // PopulatedGameBoard();
    // ShowGameBoard();
    char word[] = {'A', 'M', 'E', 'N'};
    cout << "Me llegas al recontar pincho, conchatumadre" << endl;
    int nword = 4;
    movimientos();
    SearchWord(pupi, word, resultado, nword);               
    PrintResult(resultado);

    return 0;
}
s


