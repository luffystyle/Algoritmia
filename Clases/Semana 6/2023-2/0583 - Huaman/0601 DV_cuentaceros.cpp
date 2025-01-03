/*
Dado un arreglo de 0’s y 1’s el cual tiene todos los 1’s primero
seguido de todos los 0’s. Encontrar el número de 0’s.
Ejemplos:
Entrada: {1, 1, 1, 0, 0, 0, 0}
Output: 4
Entrada: {1, 1, 1, 1, 1}
Salida: 0
*/
#include <iostream>
using namespace std;

int CuentaCeros(int A[], int posicion_inicial, int posicion_final, int contador_ceros){
	//CASO BASE
	if (posicion_inicial==posicion_final)
		if (A[posicion_inicial]==0)
			return contador_ceros+1;//Si es 0, contamos +1
		else
			return contador_ceros;//Si es 1, no contamos
	
	
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	if (A[posicion_medio]==0)//Cuando el elemento de la posicion del medio es 0
							//analizamos el subarreglo de la IZQUIERDA y sabemos que el de la derecha son puros 0s
		return CuentaCeros(A,posicion_inicial, posicion_medio-1,contador_ceros+(posicion_final-posicion_medio+1));
	else//Cuando el elemento de la posicion del medio es 1
		//analizamos el subarreglo de la DERECHA y descartamos el de la IZQUIERDA pues tien puros 1s
		return CuentaCeros(A,posicion_medio+1, posicion_final,contador_ceros);
}

int main(){
	int A[]={1, 1, 1, 1, 1, 1, 0};
	int n=7;
	cout<<"Cantidad de 0's = "<<CuentaCeros(A,0,n-1,0);
	return 0;
}
