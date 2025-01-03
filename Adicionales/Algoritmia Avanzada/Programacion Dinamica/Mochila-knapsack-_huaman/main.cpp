// KNAPSACK PROBLEM (PROBLEMA DE LA MOCHILA)

#include <iostream>
using namespace std;
#define n 4 // numero de elementos
#define w 5 // maximo peso de la mochila

void completarMatriz(int pesos[], int valores[], int V[][w+1]) {
    
    int i, j, k;  
    // Los valores iniciales
    for(k = 0; k<w+1; k++) V[0][k] = 0;// primera fila con números 0
    for(k = 0; k<n+1; k++) V[k][0] = 0;// primera columna con números 0
    
    for( j = 1; j<w+1; j++) { // yo voy a avanzar desde la columna, no desde la filas
        for( i = 1; i<n+1; i++) {
            if( j >= pesos[i-1]) {
                if(V[i-1][j] > valores[i-1] + V[i-1][j-pesos[i-1]]) V[i][j] = V[i-1][j];
                else V[i][j] = valores[i-1] + V[i-1][j-pesos[i-1]];
            } else {
                V[i][j] = V[i-1][j];
            }            
        }  
    }   
}

int main(int argc, char** argv) {

    
    int pesos[n] = {2, 1, 3, 2};
    int valores[n] = {12, 10, 20, 15};
    int V[n+1][w+1];
    
    completarMatriz(pesos, valores, V);
    
    for(int i = 0; i<n+1 ;i++) {
        for(int j = 0; j<w+1 ; j++) cout << V[i][j] << " ";
        cout << endl;
    }
   
    cout << "La máxima ganancia es: $" << V[n][w] << endl;

    return 0;
}

