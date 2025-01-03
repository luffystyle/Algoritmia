
#include <iostream>
#define MAXCOLUM 10
#define MAXFIL 10

using namespace std;

int puntajeMaximo(int tablero[][MAXCOLUM], int n, int m, int x, int y) {
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
    
    int n, m, tablero[MAXFIL][MAXCOLUM];
    
    cout << "Ingrese los valores de n y m: ";
    cin >> n >> m;
    
    cout<< "Ingrese los valores de la matriz " << n << "x" << m << endl;
    for(int i = 0; i<n; i++) {
        for( int j = 0; j<m; j++) {
            cin >> tablero[i][j];//lo que estoy haciendo, NO toy creando un creando una matriz de nxm
            // si no, que al crear la matriz es de 10x10, solo que NOS LIMITAMOS a llenar hasta nxm
            // pero la matriz NUNCA CAMBIARÁ porque es de 10x10, solo que TRABAJAREMOS en ese rango de
            // nxm. SoLamente haremos eso. 
            
        }
    }
        
    //y le pasamos el x, y
    int maximoPuntaje = puntajeMaximo(tablero, n, m, 0, 0);
    cout << "El máximo puntaje es " << maximoPuntaje << endl;

    return 0;
}






