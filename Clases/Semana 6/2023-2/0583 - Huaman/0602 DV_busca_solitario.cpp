//Gianella Marquina
/*
Dado un arreglo ordenado en el cual todos los elementos aparecen
dos veces y un elemento aparece una sola vez. Encontrar el
elemento que aparece una sola vez. El algoritmo debe tener
complejidad O(log n).
Ejemplo:
Entrada: {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
Salida: 4
*/
#include <iostream>
using namespace std;

void BuscaSoli(int A[], int posicion_inicial, int posicion_final){
	//CASO BASE
	if (posicion_inicial==posicion_final){//Para revisar
		cout<<A[posicion_inicial]<<endl;
		return;
	}
	
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	//En este problema, tenemos que analizar la variable posicion_medio
	//Si posicion_medio es par => voy a analizar medio y medio+1
	//Si posicion_medio es impar => vpy a analizar medio-1 y medio
	
	if (posicion_medio%2==0)//si el posicion_medio es par
		if (A[posicion_medio]==A[posicion_medio+1])
			//quiere decir que el subarreglo de la IZQUIERDA tiene todos sus elementos en pareja
			//tengo que analizar el subarreglo de la DERECHA
			BuscaSoli(A,posicion_medio+2, posicion_final);
		else//quiere decir que el subarreglo de la DERECHA tiene todos sus elementos en pareja
			//tengo que analizar el subarreglo de la IZQUIERDA
			BuscaSoli(A,posicion_inicial,posicion_medio);
	
	else//si el posicion_medio es impar
		if (A[posicion_medio]==A[posicion_medio-1])
			//quiere decir que el subarreglo de la IZQUIERDA tiene todos sus elementos en pareja
			//tengo que analizar el subarreglo de la DERECHA
			BuscaSoli(A,posicion_medio+1, posicion_final);
		else//quiere decir que el subarreglo de la DERECHA tiene todos sus elementos en pareja
			//tengo que analizar el subarreglo de la IZQUIERDA
			BuscaSoli(A,posicion_inicial,posicion_medio-1);
}

int main(){
	int A[]={1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
	int n=11;
	BuscaSoli(A,0,n-1);
	return 0;
}
	