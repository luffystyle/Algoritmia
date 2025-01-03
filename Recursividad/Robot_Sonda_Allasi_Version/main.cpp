/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on September 11, 2024, 8:30 AM
 */

#include <iostream>

using namespace std;

int tablero[][6] = { {0, 0, 0, 1, 0, 1},
                     {0, 0, 1, 0, 0, 0},
                     {0, 1, 0, 0, 0, 1},
                     {1, 0, 0, 0, 0, 0},
                     {0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0} };



int buscarUnidades(int posX, int posY, int dirX, int dirY, int banderaX, int banderaY, int n, int m) {
    
    int contador = 0; // Creamos un contador para esta instancia
    
    //CASO BASE
    if(posX >= n || posX < 0 || posY >= m || posY < 0) { // Si se cumple una de estas, salgo de la recursividad
        return 0; //No sumo nada. Devuelve el contador en 0
    }
    
    //Estos 3 if solo es para scanear el centro arriba y abajo, derecha izquierda cuando nos posicinamos SOLO LA PRIMERA VEZ
    // Luego que contamos no necesitamos volver a contar esos numero que hicimos en la primera barrida
    if(banderaX == 0 && banderaY == 0) contador += tablero[posX][posY];// Si existe una unidad donde nos posicionamos lo contamos
    if(banderaX == 0) { //Solo la primera vez, barremos VERTICALmente
        for(int i = 0; i<posX; i++) contador += tablero[i][posY]; // ARRIBA
        for(int i = posX+1; i<n; i++) contador += tablero[i][posY]; // ABAJO
    }
    if(banderaY == 0) { // Solo la primera vez, barremos HORIZONTALmente
        for(int i = posY+1; i<m; i++) contador += tablero[posX][i]; // DERECHA
        for(int i = 0; i<posY; i++) contador += tablero[posX][i]; //IZQUIERDA
    }
    contador = contador + buscarUnidades(posX + dirX, posY+dirY, dirX, dirY, dirX, dirY, n, m);
    return contador;
}

// derecha (0,1), izquierda (0,-1), abajo (1,0), arriba (-1,0)
int main(int argc, char** argv) {
    
    int n = 6; // Las filas
    int m = 6; // las columnas
    int contador = 0;
    int posX = 3, posY = 2;
    int dirX = 0, dirY = 1;
    int banderaX = 0, banderaY = 0; // las banderas es pa no contar otra vez
    // la bandera X es el barrido Vertical
    // la bandera Y es el barrido horizontal
    // Una vez que hemos barrido la primera vez tanto VERTICAL como HORIZONTAL
    // debemos barrer VERTICALMENTE porque nos estamos moviendo en ese sentido
    // BARREMOS según nos movemos. Si nos movieramos en verticalmente, la banderaX es el que va sumando de 1 a 1
    
    contador = buscarUnidades(posX, posY, dirX, dirY, banderaX, banderaY, n, m);
    
    cout << "El Robot sonda contó " << contador << " unidades." << endl;
    return 0;
}

