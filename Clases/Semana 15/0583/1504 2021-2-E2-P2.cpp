#include <iostream>
using namespace std;

int robotdp(int xi, int yi, int xf, int yf, int m, int matriz[][6]) {
    int i, j, abajo, derecha;
    
	//Matriz de resultados
    int dp[xf - xi + 1][yf - yi + 1];

    //Inicializamos la última columna de la matriz con ceros
    for (i = 0; i <= xf; i++)
        dp[i][yf] = 0;

    //Inicializamos la última fila de la matriz con ceros
    for (j = 0; j <= yf; j++)
        dp[xf][j] = 0;

    //Programación dinámica
    for (i = xf - 1; i >= xi; i--) {
        for (j = yf - 1; j >= yi; j--) {
            derecha = dp[i][j + 1];//la "consulta" es a la matriz de resultados (la "mayor ruta")
            abajo = dp[i + 1][j];//la "consulta" es a la matriz de resultados (la "mayor ruta")
            
			//"Guardamos el valor en dp eligiendo el camino con el valor máximo
            if (derecha > abajo)
                dp[i][j] = matriz[i][j] + derecha;
            else
                dp[i][j] = matriz[i][j] + abajo;
            //Mostramos el valor en dp
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    //Devolvemos el resultado final
    return dp[xi][yi];
}

// Función principal
int main() {

    //Matriz de entrada
    int matriz[][6] = {
        {1, 2, 9, 1, 2, 3},
        {5, 1, 7, 1, 2, 1},
        {1, 7, 1, 3, 8, 1},
        {2, 2, 6, 1, 2, 2},
        {3, 6, 9, 5, 1, 5},
        {1, 1, 4, 1, 9, 1}};
    int m = 6;
    int n = 6;

    cout << "Suma: " << robotdp(0, 0, 6, 6, m, matriz) << endl;

    return 0;
}

