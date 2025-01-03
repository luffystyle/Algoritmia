#include <iostream>
#define N 9

using namespace std;

int cuentaCeros(int numero[N],int inicio,int fin){
	if (inicio>fin){
		return 0;
	}
	int medio = (inicio+fin)/2;
	if (numero[medio]==0){
		return 1 + cuentaCeros(numero,inicio,medio-1) + cuentaCeros(numero,medio+1,fin);
	}
	else {
		return cuentaCeros(numero,inicio,medio-1) + cuentaCeros(numero,medio+1,fin);
	}
}

int main(){
	int numeros[N] = {1,0,0,1,0,0,1,0,0};
	cout << "Existen " << cuentaCeros(numeros,0,N-1) << " ceros en el arreglo";
	return 0;
}
