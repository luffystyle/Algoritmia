
/* 
 * CLASE CUEVITA SEMANA 3
 */

#include <iostream>
#define N 3

using namespace std;

int robot(int x, int y, int n, int m, int tablero[][N]) {
    
    //tenemos que inicializar en caso se salga del tablero 
    int derecha = -999999, abajo = -999999; // Son sus movimientos del robot
    
    // El y controla las columnas y el x las filas NO CAMBIAN porque es el final, al menos cuando estamos
    // ingresando a los universos. Ya luego restaremos cuando estemos regresando
    if( x == n-1 && y == m-1) return tablero[x][y];
    
    //Estamos avanzando 
    //El n y m no varia porque
    if(y+1<m) derecha = robot(x, y+1, n, m, tablero);
    if(x+1<n) abajo = robot(x+1, y, n, m, tablero);
    
    if(abajo <derecha)
        return derecha + tablero[x][y];    
    
    return abajo +tablero[x][y]; // esto es como el else, solo que lo ponemos asi. Sea en caso de derecha > abajo  
}

int main() {
    
    int n = 3, m = 3;
    int  tablero[][3] = {{2, 5, 1}, {2, 9, 1}, {14, 3, 5}};
    
    // EL inicio necesito tenemos que agregarle
    // tambien enviamos la coordenada final para decirle cuando parar
    cout << "El total es: " << robot(0, 0, 3, 3, tablero);

    return 0;
}
