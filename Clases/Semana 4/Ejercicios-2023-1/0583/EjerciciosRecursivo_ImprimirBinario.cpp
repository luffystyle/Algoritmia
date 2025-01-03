#include <iostream>
using namespace std;

void imprimirEnBinario(int n) {
    if (n == 0) { // Caso base
        cout << "0";
        return;
    }
    if (n == 1) { // Caso base
        cout << "1";
        return;
    }
    imprimirEnBinario(n / 2); // Llamada recursiva para el cociente de la división por 2
    cout << n % 2; // Imprime el residuo de la división por 2
}

int main() {
    int num;
    cout << "Ingrese un número en base 10: ";
    cin >> num;
    cout << num << " en base 2 es: ";
    imprimirEnBinario(num);
    cout << endl;
    return 0;
}
