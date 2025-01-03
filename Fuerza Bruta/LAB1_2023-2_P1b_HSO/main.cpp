
/*
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on September 13, 2024, 4:59 PM
 */

#include <iostream>

using namespace std;

int movimientos[][2] = { {0,  1}, //derecha
                         {1,  0}, // abajo
                         {0, -1}, // izquierda
                         {-1, 0} };

bool validarPalabra(char letraIni, char arreglo[]) {

    for (int i=0; i<3; i++){
        if (arreglo[i]==letraIni){
            arreglo[i] = '-';
            return 1;
        }
    }
    return false;

}
void inicializarArreglo(char arreglo[]) {
    arreglo[0] = 'H';
    arreglo[1] = 'S';
    arreglo[2] = 'O';
}

bool encontrarPalabra(int x, int y, int n, char matriz[][10]) {

    char arreglo[3];
    if(matriz[x][y] != 'H') {
        if(matriz[x][y] != 'S') {
            if(matriz[x][y] != 'O'){
                return false;
            }
        }
    }
    int fila, colum;
    //inicializarArreglo(arreglo);
    for(int i = 0; i<n; i++) {
        //inicializarArregloHastaElPrimero(arreglo, matriz[x][y]);
        inicializarArreglo(arreglo);
        //avanzo una casilla, hago un movement. Primer movimiento a la derecha
        fila = x +  movimientos[i][0];
        colum = y + movimientos[i][1];

        //borra 1era letra
        validarPalabra(matriz[x][y], arreglo);
        //Como ya avancé mi p empeiza en 1
        int p;
        for( p = 1; p<3; p++) {
            if(fila>3 || fila<0 || colum>10 || colum<0) break;
            if( validarPalabra(matriz[fila][colum], arreglo) == false) break;
            fila = fila + movimientos[i][0];
            colum = colum + movimientos[i][1];
        }
        if(p == 3) return true;
    }
    //return true;
    return false;

}

void resolucion(char matriz[][10], int n) {

    for(int i = 0; i<4; i++) {
        for(int j = 0; j<10; j++) {
            if(encontrarPalabra(i, j, n, matriz)==true) { // si es valido
                cout << "(" << i << ", " << j  << ") "<< endl;
            }
        }
    }
}


int main(int argc, char** argv) {


    char matriz[][10] = {'H', 'C', 'H', 'B', 'Y', 'S', 'O', 'S', 'O', 'H',
                         'S', 'C', 'S', 'S', 'Y', 'Q', 'O', 'S', 'Z', 'K',
                         'O', 'P', 'N', 'Y', 'O', 'K', 'F', 'H', 'C', 'K',
                         'O', 'B', 'N', 'I', 'Y', 'S', 'P', 'O', 'O', 'K'};

    int n = 4;
    resolucion(matriz, n);

    return 0;
}
























































