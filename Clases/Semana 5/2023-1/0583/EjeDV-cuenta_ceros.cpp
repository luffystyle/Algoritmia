#include <iostream>
using namespace std;
/*
Dado un arreglo de 0�s y 1�s el cual tiene todos los 1�s primero
seguido de todos los 0�s. Encontrar el n�mero de 0�s.
Ejemplos:
	Entrada: {1, 1, 1, 0, 0, 0, 0}
	Output: 4
	
	Entrada: {1, 1, 1, 1, 1}
	Salida: 0
*/

int cuenta_ceros(int A[], int inicial, int final, int contador_ceros){
	if (inicial>final)//condici�n de parada: la �ltima posici�n
		return contador_ceros;//devuelve el valor general de todo
	
	int medio=(inicial+final)/2;//para analizar la posici�n del medio
	
	if (A[medio]==0)//Si es 0 la posici�n del medio, el subarreglo de la derecha es de puros 0
					//entonces tengo que analizar el subarreglo de la izquierda
		return cuenta_ceros(A,inicial, medio-1,contador_ceros+(final-medio+1));//contador_ceros tiene valor de la longitud del subarreglo de la derecha
	else//Si es 1 la posici�n del medio, el subarreglo de la izquierda es de puros 1
		//entonces tengo que analizar el subarreglo de la derecha
		return cuenta_ceros(A,medio+1, final,contador_ceros);//contador_ceros tiene valor del argumento, pues solo hemos identificado puros 1, todav�a no hay 0
}

int main(){
	int A[]={1, 1, 1, 1, 1, 0, 0};
	int n=7;
	
	cout<<"Resultado : "<< cuenta_ceros(A, 0,n-1,0)<<endl;
	return 0;
}
