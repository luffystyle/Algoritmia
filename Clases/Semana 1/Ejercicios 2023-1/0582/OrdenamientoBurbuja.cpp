#include <iostream>

#define N 7

using namespace std;

int main(){
	int arreglo[N] = {89, 45, 68, 90, 29, 34, 17};
	int aux;
	/*Imprimir arreglo*/
	for (int i=0; i<=N-1; i++){
		cout << arreglo[i] << " ";
	}
	cout << endl;
	/*Ordenamiento por Burbuja*/
	for (int i=0; i<=N-2; i++){ /*cantidad de repeticiones de la comparacion de pares*/
		for (int j=0; j<=N-2-i; j++){
			if (arreglo[j]>arreglo[j+1]){
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}
	/*Arreglo ordenado*/
	for (int i=0; i<=N-1; i++){
		cout << arreglo[i] << " ";
	}
	return 0;
}
