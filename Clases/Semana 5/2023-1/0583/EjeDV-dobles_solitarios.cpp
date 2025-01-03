#include <iostream>
using namespace std;
/*
Dado un arreglo ordenado en el cual todos los elementos aparecen
dos veces y un elemento aparece una sola vez. Encontrar el
elemento que aparece una sola vez. El algoritmo debe tener
complejidad O(log n).
Ejemplo:
	Entrada: {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
	Salida: 4
*/

void busca_solitario(int A[], int inicial, int final){
	
	if (inicial>final)//condición de parada
		return;
		
	if (inicial==final){
		cout<<A[inicial]<<endl;
		return;
	}
	
	int medio=(inicial+final)/2;//para analizar la posición del medio
	
	if(medio%2==0){//Si medio es par
		if (A[medio]==A[medio+1])//Si son iguales, busco en el subarreglo de la derecha 
			busca_solitario(A,medio+2, final);
		else//si no son iguales, busco en el subarreglo de la izquierda
			busca_solitario(A,inicial, medio);
	}
	else{//si medio es impar
		if (A[medio]==A[medio-1])//Si son iguales, busco en el subarreglo de la derecha 
			busca_solitario(A,medio+1, final);
		else//si no son iguales, busco en el subarreglo de la izquierda
			busca_solitario(A,inicial, medio-1);
	}
}

int main(){
	int A[]={1, 1, 3, 3, 4, 4, 5, 5, 7, 8, 8};
	int n=11;
	
	busca_solitario(A,0,n-1);
	
	return 0;
}
