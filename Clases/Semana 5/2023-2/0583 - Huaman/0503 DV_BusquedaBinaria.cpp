#include <iostream>
using namespace std;

int busqueda_binaria(int A[],int k, int posicion_inicial, int posicion_final){
	//CASO BASE
	if (posicion_inicial>posicion_final)
		return -1;//es decir no encontramos el elemento, osea, devolvemos -1 como posici�n
		
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	if (A[posicion_medio]==k)//buscamos en la misma posicion_medio
		return posicion_medio;
	else//Si no est� en la misma posicion_medio, analizamos qu� subarreglo enviamos a buscar en la llamada recursiva
		if (A[posicion_medio]>k)
			//buscamos en el subarreglo IZQUIERDO
			return busqueda_binaria(A, k, posicion_inicial, posicion_medio-1);
		else
			//buscamos en el subarreglo DERECHO
			return busqueda_binaria(A, k, posicion_medio+1, posicion_final);
}


int main(){

	int A[]={1,5,7,9,12,15,17,20};//Arreglo de n�meros
	int n=8;//dimensi�n del Arreglo
	int k=21; //Clave a buscar
	
	int posicion=busqueda_binaria(A,k,0,n-1);
	if (posicion==-1)
		cout<<"No se encontr� el elemento"<<endl;
	else
		cout<<"Se encuentra en la posici�n: "<< posicion+1<<endl;	
	
	return 0;
}
