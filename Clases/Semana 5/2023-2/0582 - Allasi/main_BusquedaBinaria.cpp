#include <iostream>
#define N 8

using namespace std;

int busquedaBinaria(int numeros[N],int valorBuscado,int inicio,int fin){
	if (inicio>fin)
		return 0;
	int medio = (inicio+fin)/2;
	if (numeros[medio]==valorBuscado)
		return 1;
	else {
		if (numeros[medio]>valorBuscado){
			return busquedaBinaria(numeros,valorBuscado,inicio,medio-1);
		}
		else {
			return busquedaBinaria(numeros,valorBuscado,medio+1,fin);
		}
	}
}

int main(){
	int numeros[N] = {1,5,7,12,14,18,21,31};
	int size = 8;
	int valorBuscado = 31;
	int encontro = busquedaBinaria(numeros,valorBuscado,0,size-1);
	if (encontro){
		cout << "El elemento se encuentra en el arreglo";
	}
	else {
		cout << "El elemento NO se encuentra en el arreglo";
	}
	return 0;
}
