/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo :20175525
 * Created on September 11, 2024, 4:15 PM
 */

#include <iostream>

using namespace std;
#define N 6 // son maximos
#define M 6 // son maximos

// La posicion es estática
int buscarUnidades(int x, int y, int n, int m, int banderaAmarilla, int tablero[][6]) {
    int contador = 0;
    //CASO BASE
    if(x<0 || y < 0 || n > N || m > M) return 0;
    
    if(banderaAmarilla == 0) { // Solo la primera vez que ingreso a la recursión 
        contador += tablero[x+1][y+1];
        banderaAmarilla = 1;
    }
    
    //Contador
    for(int i = y; i<m; i++) contador += tablero[x][i]; // Barro de izquierda hacia derecha
    for(int i = x+1; i<n; i++) contador += tablero[i][m-1]; // Barro de arriba hacia abajo
    for(int i = m-2; i>=y; i--) contador += tablero[n-1][i]; // Barro de derecha hacia izquierda
    for(int i = n-2; i>=x+1; i--) contador += tablero[i][y]; // Barro de abajo hacia arriba
    
    contador += buscarUnidades(x-1, y-1, n+1, m+1, banderaAmarilla, tablero);
    return contador;
}

// Su mundo va creciendo; entonces, el n y m va aumentando
int main(int argc, char** argv) {

     // son las dimensiones de los mundos, Esto va variando
    int tablero[][6] = { {0, 0, 0, 1, 0, 1}, 
                          {0, 0, 1, 0, 0, 0}, 
                          {0, 1, 0, 0, 0, 1}, 
                          {1, 0, 0, 0, 0, 0}, 
                          {0, 1, 0, 0, 1, 0}, 
                          {0, 0, 0, 0, 1, 0} };
    int posX = 4, posY = 4;
    int x = posX-1, y = posY-1;
    int n = posX+2, m = posY+2; // lo puse asi porque mi for, porque normalmente ponen a n = 6, pero la posicion llega hasdta 5
    // En mi condición, tengo i<n, eso pasa cuando n es igual n 6 y no a 5, entonces lo puse mejor posX+2 y no posX+1
    int banderaAmarilla = 0;
    int contadorDeUnidades;
    contadorDeUnidades = buscarUnidades( x, y, n, m, banderaAmarilla, tablero);
    cout << "Las unidades son: " << contadorDeUnidades << endl;
    
    return 0;
}

