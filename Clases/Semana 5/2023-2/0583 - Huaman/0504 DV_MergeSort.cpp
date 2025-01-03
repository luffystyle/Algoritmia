#include <iostream>
using namespace std;

void merge(int A[], int posicion_inicial, int posicion_medio, int posicion_final){
	int i, p, q;
	int longitud1, longitud2;//dimensiones de los subarreglos, izquierda y derecha respectivamente
	
	longitud1=(posicion_medio+1)-posicion_inicial;//dimensión subarreglo izquierdo
	longitud2=posicion_final-posicion_medio;//dimensión subarreglo derecho
	
	//arreglos auxiliares para hacer el merge
	int P[longitud1+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
	int Q[longitud2+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
	
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	//Copiamos en los dos subarreglos auxiliares
	for (i=posicion_inicial;i<=posicion_medio;i++)
		P[i-posicion_inicial]=A[i];
	for (i=posicion_medio+1;i<=posicion_final;i++)
		Q[i-(posicion_medio+1)]=A[i];
	//Hasta aquí tenemos copiados nuestros subarreglos desde el arreglo original A[]
	
	p=q=0;//índices de los dos subarreglos
	//Recorremos todo el arreglo A[], insertando los menores de cada subarreglo P[] y Q[]
	for (i=posicion_inicial; i<=posicion_final;i++)
		if (P[p]<Q[q])
			//Si el menor a insertar es el menor de P[]
			A[i]=P[p++];
			//P[p++] se ejecuta de la siguiente manera
			//Primero asigna P[p] y luego aumenta p++ 
		else
			//Si el menor a insertar es el menor de Q[]
			A[i]=Q[q++];
}

void mergesort(int A[], int posicion_inicial, int posicion_final){	
	//CASO BASE
	if (posicion_inicial==posicion_final)
		return;
		
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	mergesort(A,posicion_inicial,posicion_medio); //complejidad O(log n)
	mergesort(A,posicion_medio+1,posicion_final); //complejidad O(log n)	
	
	merge(A,posicion_inicial, posicion_medio, posicion_final); //complejidad O(n)
	//Todo el algoritmo O(n.logn)
}


int main(){

	int A[]={11,2,7,1,6,3,2,9};//Arreglo de números
	int n=8;//dimensión del Arreglo
	
	int i;
	
	for (i=0;i<n;i++)
		cout << A[i]<< " ";
	cout<<endl;
	
	mergesort(A,0,n-1);
	
	for (i=0;i<n;i++)
		cout << A[i]<< " ";
	cout<<endl;
	
	return 0;
}
