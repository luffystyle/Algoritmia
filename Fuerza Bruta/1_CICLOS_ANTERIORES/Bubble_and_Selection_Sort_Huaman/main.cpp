
#include <iostream>

using namespace std;

//Ordenamiento por selección
void selection_sort(int arreglo[], int n) { // en cada iteracion busco el menor del arreglo, luego de buscar el meno, recién lo cambio
    int min, aux;
    for(int i = 0; i<=n-2; i++) {
        min = i;
        for(int j = i + 1; j<= n - 1; j++) { // este este hasta el ultimo valor, o sea n - 1
            if(arreglo[j] < arreglo[min]) {
                min = j;
            }
        }
        aux = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = aux;
    }
}

void bubble_sort(int arreglo[], int n) {
 
    int aux;
    for( int i = 0; i<= n-2; i++) {
        for( int j = 0; j<= n-2-i ; j++) { // el valor mayor lo pongo al ultimo, entonces cada vez se va achicando desde el último
            if(arreglo[j+1] < arreglo[j]) {
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
    }
}


int main(int argc, char** argv) {

    int cont, valor, n = 8;//cantidad de elementos o el largo
    int arreglo[] = {3, 2, 1, 4, 2, 7, 9, 5};

    //cout << "Ordenamiento por Selección: ";//Selection Sort
    //selection_sort(arreglo, n);
    
    cout << "Ordenamiento por Burbuja: ";
    bubble_sort(arreglo, n);

    for( int i = 0; i<n; i++) {
        cout << arreglo[i] <<  " ";
    }
    cout<<endl<<endl;
    
    return 0;
}

