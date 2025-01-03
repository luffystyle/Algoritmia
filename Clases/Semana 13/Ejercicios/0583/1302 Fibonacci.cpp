#include <iostream>
using namespace std;

int fibonacci(int n) {
    int i;
	//Tabla de resultados:
	int fib[n + 1];

    // Casos de partida:
    fib[0] = 0;
    fib[1] = 1;

    // Calcular los n�meros de Fibonacci utilizando programaci�n din�mica
    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
	
	cout<<"Tabla de resultados: ";
	for (i=0;i<=n;i++)
		cout<<fib[i]<<" ";
	cout<<endl;

    return fib[n];
}

int main() {
    int n;
    cout << "Ingrese el n�mero n para calcular el n�mero de Fibonacci: ";
    //cin >> n;
    n = 1;
    int resultado = fibonacci(n);

    cout << "El n�mero de Fibonacci en la posici�n " << n << " es: " << resultado << endl;

    return 0;
}

