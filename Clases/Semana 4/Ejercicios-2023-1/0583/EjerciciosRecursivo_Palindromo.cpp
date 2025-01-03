#include <iostream>
#include <string>
using namespace std;

bool esPalindromo(string palabra, int inicio, int fin) {
    // Si el inicio es mayor o igual que el final, la palabra es un palíndromo
    if (inicio >= fin) {
        return true;
    }

    // Si las letras en los índices inicio y fin son diferentes, no es un palíndromo
    if (palabra[inicio] != palabra[fin]) {
        return false;
    }

    // Comprobar el siguiente par de letras recursivamente
    return esPalindromo(palabra, inicio + 1, fin - 1);
}

int main() {
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    if (esPalindromo(palabra, 0, palabra.length() - 1)) {
        cout << palabra << " es un palindromo." << endl;
    } else {
        cout << palabra << " no es un palindromo." << endl;
    }

    return 0;
}

