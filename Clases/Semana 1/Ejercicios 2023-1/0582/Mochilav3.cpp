#include <iostream>
#include <math.h>
#define N 7

using namespace std;

void cargaBin(int num,int cromo[N],int size){
	int i, digito;
	for (i=0; i<size; i++){
		cromo[i] = 0;
	}
	i = 0;
	while (num>0){
		digito = num%2;
		num = num/2;
		cromo[i] = digito;
		i++;
	}
}


int main(){
	int objetos[N] = {19, 5, 8, 20, 12, 7, 1};
	int cromo[N]; /*Este es el arreglo cromosoma*/
	int pesoMax, pesoMochila, combinaciones, pesoMayor=0, indice;
	
	cout << "Ingrese el peso maximo de la mochila: ";
	cin >> pesoMax;
	combinaciones = pow(2,N);
	int contador=0;
	for (int i=1; i<combinaciones; i++){
		cargaBin(i,cromo,N);
		pesoMochila = 0;
		for (int j=0; j<N; j++){
			if (cromo[j]==1){
				pesoMochila = pesoMochila + objetos[j];
			}
		}
		if (pesoMochila<=pesoMax && pesoMochila>pesoMayor){
			pesoMayor = pesoMochila;
		}
	}
	cout << "El mayor peso que se puede cargar es: " << pesoMayor << endl;
	cout << "Todas las soluciones: " << endl;
	for (int i=1; i<combinaciones; i++){
		cargaBin(i,cromo,N);
		pesoMochila = 0;
		for (int j=0; j<N; j++){
			if (cromo[j]==1){
				pesoMochila = pesoMochila + objetos[j];
			}
		}
		if (pesoMochila==pesoMayor){
			for (int j=0; j<N; j++){
				if (cromo[j]==1){
					cout << objetos[j] << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
