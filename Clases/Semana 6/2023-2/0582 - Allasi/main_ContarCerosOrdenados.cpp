#include <iostream>
#define N 9

using namespace std;

int cuentaCeros(int numero[N],int inicio,int fin, int cuenta){
	if (inicio>fin){
		return cuenta;
	}
	int medio = (inicio+fin)/2;
	if (numero[medio]==0){
		return cuentaCeros(numero,inicio,medio-1,cuenta+fin-medio+1);
	}
	else {
		return cuentaCeros(numero,medio+1,fin,cuenta);
	}
}

int main(){
	int numeros[N] = {1,1,1,0,0,0,0,0,0};
	cout << "Existen " << cuentaCeros(numeros,0,N-1,0) << " ceros en el arreglo";
	return 0;
}
