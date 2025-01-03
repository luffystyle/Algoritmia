
#include <iostream>

using namespace std;

int bus_secuencial(int arreglo[], int n, int k) { // k es el valor que queremos encontrar
      
    int i;
    for( i = 0; i<n; i++) {
        if(arreglo[i] == k) break;
    }
    if(i>=n) {
        return -1;
    } else {
        return i;
    }
}

int main(int argc, char** argv) {

    int cont, valor, n = 8; // n es el largo del arreglo, lo mandamos como parametro  
    int arreglo[] = {3, 2, 1, 4, 2, 7, 9, 5};
    cout << "Busqueda Secuencial: ";
    valor = bus_secuencial(arreglo, n, 5);
    cout << valor << endl << endl;

    return 0;
}

