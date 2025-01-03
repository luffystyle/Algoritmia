#include <iostream>

#define N 7

using namespace std;

int main(){	
	int arreglo[N] = {89, 45, 68, 90, 29, 34, 17};
	int aux, min;
	/*Imprimir arreglo*/
	for (int i=0; i<=N-1; i++){
		cout << arreglo[i] << " ";
	}
	cout << endl;
	/*Ordenamiento por Seleccion*/
	for (int i=0; i<=N-2; i++){
		min = i;
		for (int j=i+1; j<=N-1; j++){
			if (arreglo[j]<arreglo[min]){
				min = j;
			}
		}
		aux = arreglo[i];
		arreglo[i] = arreglo[min];
		arreglo[min] = aux;
	}
	/*Arreglo ordenado*/
	for (int i=0; i<=N-1; i++){
		cout << arreglo[i] << " ";
	}
	return 0;
}
