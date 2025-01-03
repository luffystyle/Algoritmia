#include <iostream>
using namespace std;

int fibonacci(int n) {
    int i;
	//Tabla de resultados:
	int fib[n + 1];

    // Casos de partida:
    fib[0] = 0;
    fib[1] = 1;

    // Calcular los números de Fibonacci utilizando programación dinámica
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
    cout << "Ingrese el número n para calcular el número de Fibonacci: ";
    //cin >> n;
    n = 1;
    int resultado = fibonacci(n);

    cout << "El número de Fibonacci en la posición " << n << " es: " << resultado << endl;

    return 0;
}

