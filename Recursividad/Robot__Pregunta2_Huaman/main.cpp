
#include <iostream>


using namespace std;

int puntajeMaximo(int tablero[][3], int n, int m, int x, int y) {
    int total, derecha = 0, abajo=0;
    // Debo elegir el camino, si es izquierda o derecha
    // Tenemos que reducir la matriz, así cuando tenia una arreglo y lo achicabamos para llegar al
    // al último, de la misma manera vamosa hacer aqui.
    // Debo llegar al último valor del tablero; es decir, (n-1, m-1)
    
    //condición de parada
    if(x == n-1 and y == m-1) return tablero[x][y];
    
    // este if es para cuando se encuentra en la ultima posicion, si le sumamos 1, se sobrepasa, entonces
    // no entra en la recursividad
    if(x+1<n) derecha = puntajeMaximo(tablero, n, m, x+1, y);
    if(y+1<m) abajo = puntajeMaximo(tablero, n, m, x, y+1);
    
    if(derecha<abajo) total = tablero[x][y] + abajo;
    else total = tablero[x][y] + derecha;
    
    return total;
    
}

int main(int argc, char** argv) {
    
    int n = 2, m = 3;
//    int tablero[2][2] = { {3, 5},
//                          {-2, 4} };
    
    int tablero[2][3] = { {3, -2, 4}, 
                          {1, -2, 3} };
        
    //y le pasamos el x, y
    int maximoPuntaje = puntajeMaximo(tablero, n, m, 0, 0);
    cout << "El máximo puntaje es " << maximoPuntaje << endl;

    return 0;
}





    