#include <iostream>
#include <math.h>
#define N 7

/*Version con restriccion de peso y cantObjetos*/

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
	int objetos[N] = {19, 5, 8, 20, 12, 7, 2};
	int cromo[N]; /*Este es el arreglo cromosoma*/
	int pesoMax, pesoMochila, combinaciones, cantObjetos;
	
	cout << "Ingrese el peso maximo de la mochila: ";
	cin >> pesoMax;
	combinaciones = pow(2,N);
	int contador=0;
	for (int i=1; i<combinaciones; i++){
		cargaBin(i,cromo,N);
		pesoMochila = 0;
		cantObjetos = 0;
		for (int j=0; j<N; j++){
			if (cromo[j]==1){
				pesoMochila = pesoMochila + objetos[j];
				cantObjetos++;
			}
		}
		if (pesoMochila<=pesoMax && cantObjetos>=3){
			contador++;
			cout << "Solucion " << contador << ": ";
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
