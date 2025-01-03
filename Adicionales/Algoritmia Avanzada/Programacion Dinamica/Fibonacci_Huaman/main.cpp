// FIBONACCI

#include <iostream>
using namespace std;

int fibonacci(int n) {
    // La tabla de resultados
    int F[n+1];
    
    // Caso de partida
    F[0] = 0;
    F[1] = 1; 
    
    for( int i = 2; i<=n; i++) {
        F[i] = F[i-1] + F[i-2];
    }   
    
    // Voy a imprimir la tabla de resultados
    cout << "Tabla de Resultados: "<< endl;
    for( int i = 0; i<=n; i++) {
        cout << F[i] << " ";
    }
    cout << endl;
    
    return F[n];
}

int main(int argc, char** argv) {
    
    int n, resultado;
    cout << "Ingrese el número n para calcular el número de Fibonacci: ";
    cin >> n;
    
    resultado = fibonacci(n);
    cout << "El número de Fibonacci en la posición " << n << " es : " << resultado<< endl;

    return 0;
}
