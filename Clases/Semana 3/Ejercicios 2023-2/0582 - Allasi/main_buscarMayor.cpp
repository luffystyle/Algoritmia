#include <iostream>
#define N 5

using namespace std;

int buscarMayor(int arreglo[N],int size,int mayorTemporal,int posicion){
	/*Caso Base*/
	if (posicion>=size){
		return mayorTemporal;
	}
	else {
		if (arreglo[posicion]>mayorTemporal){
			mayorTemporal = arreglo[posicion];
		}
		return buscarMayor(arreglo,size,mayorTemporal,posicion+1);
	}
}

int main(){
	int arreglo[N] = {7,19,2,20,1};
	int size=5, mayor;
	int mayorTemporal = arreglo[0];
	int posicion=1;
	mayor = buscarMayor(arreglo,size,mayorTemporal,posicion);
	cout << "El mayor es: " << mayor;
	return 0;
}
