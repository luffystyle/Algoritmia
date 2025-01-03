/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#define PROBADA 3
#define RUTA 7
using namespace std;


bool valida(int tablero[3][5], int fil, int col){
    bool resultado = false;
    /*dentro de los límites de la matriz*/
    if(fil >= 0 and fil < 3 and col >= 0 and col < 5)
        if(tablero[fil][col] == 1) /* no es pared y no ha sido probada*/
            resultado = true;
    return resultado;
}
void mostrar(int tablero[3][5]){
 
    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 5; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}


bool laberinto(int tablero[3][5], int fil, int col){
    
    bool terminado = false;
    
    if(valida(tablero, fil, col)){
        tablero[fil][col] = PROBADA; /* ya ha sido probada*/
        mostrar(tablero);
        if(fil == 2 and col == 4)
            terminado = true;
        else{
            if (not terminado)
                terminado = laberinto(tablero, fil + 1, col); /*hacia abajo*/
            if (not terminado)
                terminado = laberinto(tablero, fil, col + 1); /*hacia la derecha*/
            if (not terminado)
                terminado = laberinto(tablero, fil -1, col); /*hacia arriba*/
            if(not terminado) 
                terminado = laberinto(tablero, fil, col - 1); /*hacia la izquierda*/  
        }
        mostrar(tablero);
        if(terminado)
            tablero[fil][col] = RUTA;
      
    }
    return terminado;
}




int main(int argc, char** argv) {

    int tablero[3][5] = {{1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 0, 1, 0, 1}};
    bool terminado;
    
    //inicializaTablero(matriz);
    mostrar(tablero);
    terminado = laberinto(tablero, 0, 0);
    mostrar(tablero);
    




    return 0;
}

