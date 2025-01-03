#include <iostream>

#define ELEM 4
#define W 5

int max(int val1, int val2){
    if (val1 > val2)
        return val1;
    else
        return val2;
}

void llenar_mochila(int pesos[], double valores[], double V[ELEM + 1][W + 1]) {
    // Condiciones iniciales
    for (int j = 0; j <= W; j++)
        V[0][j] = 0; // Valor inicial para la primera fila de la matriz es 0
    for (int i = 0; i <= ELEM; i++)
        V[i][0] = 0; // Valor inicial para la primera columna de la matriz es 0

    // Iteraciones
    for (int j = 1; j <= W; j++) {//Itera a través de las diferentes capacidades de la mochila (desde 1 hasta W)
        for (int i = 1; i <= ELEM; i++) {//Itera a través de los elementos disponibles (desde 1 hasta ELEM).
            if (j - pesos[i - 1] >= 0)//se comprueba si el peso del elemento actual (pesos[i - 1]) puede caber en la capacidad actual de la mochila (j).
                //V[i][j], representa el valor máximo posible hasta el momento 
				//para esta combinación de elementos y capacidad de la mochila.
				V[i][j] = max( V[i - 1][j] , valores[i - 1] + V[i - 1][j - pesos[i - 1]]);
                // Si el peso actual cabe en la mochila, se elige el máximo entre:
                // - No tomar el elemento actual (valor de la fila anterior)
                // - Tomar el elemento actual (valor del elemento actual + valor anterior en la fila y la columna restante)
            else
                V[i][j] = V[i - 1][j]; // Si el peso actual no cabe en la mochila, se toma el valor de la fila anterior
                //El valor óptimo para esta combinación de elementos y capacidad 
				//será el mismo que el valor óptimo obtenido anteriormente para la misma capacidad, 
				//pero sin incluir el elemento actual. 
				//Por lo tanto, se copia el valor de la fila anterior (V[i - 1][j]) en V[i][j].
        }
    }
}

void pprint(double V[ELEM + 1][W + 1]) {
    for (int i = 0; i <= ELEM; i++) {
        for (int j = 0; j <= W; j++) {
            std::cout << V[i][j] << " "; // Imprimir el valor de cada celda de la matriz
        }
        std::cout << std::endl; // Imprimir una nueva línea después de cada fila
    }
}

int main() {
    int pesos[ELEM] = {2, 1, 3, 2};
    double valores[ELEM] = {12, 10, 20, 15};

    double V[ELEM + 1][W + 1];

    llenar_mochila(pesos, valores, V); // Llenar la matriz V con los valores óptimos para la mochila

    std::cout << "Maximo valor: " << V[ELEM][W] << std::endl; // Imprimir el valor máximo obtenido

    std::cout << "Estructura Auxiliar:" << std::endl;
    pprint(V); // Imprimir la estructura auxiliar (matriz V)

    return 0;
}

