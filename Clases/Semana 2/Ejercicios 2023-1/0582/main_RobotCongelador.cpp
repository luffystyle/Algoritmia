#include <iostream>
#include <math.h>

#define TOTAL 16

using namespace std;

void cargaBin(int num,int size,int cromo[TOTAL]){
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
	int cromo[TOTAL], rack[TOTAL], pos, bloque, pesoParcial;
	int soluciones[100]; /*Asumire que a lo mas hay 100, pero en realidad deberian ser combinaciones*/
	int almacen[TOTAL] = {7,17,14,19,9,12,11,8,8,6,10,12,18,7,15,11};
	int n=4, peso=23, combinaciones, cantSoluciones=0;
	
	/*Parte a, tu mismo eres*/
	
	/*Parte b, ahora si*/
	combinaciones = pow(2,n*4);
	for (int i=0; i<combinaciones; i++){
		cargaBin(i,n*4,cromo);
		pesoParcial = 0;
		for (int j=0; j<n*4; j++){
			if (cromo[j]==1){
				pesoParcial = pesoParcial + almacen[j];
			}
		}
		if (peso==pesoParcial){
			soluciones[cantSoluciones] = i;
			cantSoluciones++;
		}
	}
	/*Imprimir las soluciones*/
	for (int i=0; i<cantSoluciones; i++){
		cout << "Resultado " << i+1 << ": ";
		cargaBin(soluciones[i],n*4,rack);
		for (int j=0; j< n*4; j++){
			if (rack[j]==1){
				cout << almacen[j] << " ";
			}
		}
		cout << "Ubicaciones: ";
		for (int j=0; j< n*4; j++){
			if (rack[j]==1){
				bloque = j/4;
				pos = j%4;
				if (bloque==0 || bloque==1){
					cout << "I";
				}
				else {
					cout << "D";
				}
				if (bloque==0 || bloque==2){
					cout << "A";
				}
				else {
					cout << "B";
				}
				cout << pos+1 << " ";
			}
		}
		cout << endl;
	}	
}
