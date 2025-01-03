// COINROW PROBLEM

#include <iostream>
using namespace std;

int coinRow(int M[], int n) {
    
    // Tabla de resultados
    // LA tabla resultados es el F
    int F[n+1]; // esto es longitud del arreglo F
    
    //Casos de partida
    F[0] = 0;
    F[1] = M[0];
    
    // los numeros son para compararlos entre sí y hallar el máximo
    int num1, num2;
    
    for(int i = 2; i<=n; i++) {
        num1 = M[i-1] + F[i-2];
        num2 = F[i-1];
        if(num1 < num2) F[i] = num2; 
        else F[i] = num1;
    }
    // La tabla de resultados
    cout << "La tabla de resultados: " << endl;
    for( int i = 0; i<=n; i++) {
        cout << F[i] << " ";
    }
    cout << endl << endl;
    
    return F[n]; // Este es el último término de F    
}

int main(int argc, char** argv) {

    int n = 6;
    int M[n] = {5, 1, 2, 10, 6, 2};
    int valor = coinRow(M, n);
    cout << "Valor máximo es " << valor << endl;

    return 0;
}
