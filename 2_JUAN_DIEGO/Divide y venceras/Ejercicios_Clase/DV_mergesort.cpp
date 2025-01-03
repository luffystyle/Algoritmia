#include <iostream>

using namespace std;

void merge(int arreglo[], int posicion_inicial, int posicion_medio, int posicion_final){
	int i, p, q; //índices para los 3 arreglos
	//i es para arreglo[]
	//p es para arreglo[], mitad de la izquierda
	//q es para arreglo[], mitad de la derecha
	
	int longitud1, longitud2;
	longitud1=(posicion_medio+1)-posicion_inicial;
	longitud2=posicion_final-posicion_medio;
	
	//establecemos 2 arreglos auxiliares para reordenar el arreglo[]
	int P[longitud1+1];//Un elemento más en el subarreglo con valor muuuuuy grande
	int Q[longitud2+1];//Un elemento más en el subarreglo con valor muuuuuy grande
	
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	for (i=posicion_inicial;i<posicion_medio+1;i++)
		P[i-posicion_inicial]=arreglo[i];//restamos posicion_inicial al índice para que comience desde 0 para P[]
		
	for (i=posicion_medio+1;i<=posicion_final;i++)
		Q[i-(posicion_medio+1)]=arreglo[i];//restamos posicion_medio+1 al índice para que comience desde 0 para Q[]
		
	p=q=0;
	
	for (i=posicion_inicial; i<=posicion_final; i++)
		if (P[p]<Q[q])//Si el elemento de P[] es el menor, insertamos en arreglo[]
			arreglo[i]=P[p++];
		else//Si el elemento de Q[] es el menor, insertamos en arreglo[]
			arreglo[i]=Q[q++];
}

void mergesort(int arreglo[], int posicion_inicial, int posicion_final){
	//CASO BASE
	if (posicion_inicial==posicion_final)//porque cuando tenemos sólo un elemento, ese elemento ya está ordenado.
		return;
	
	//identificamos la posición del medio
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	mergesort(arreglo, posicion_inicial, posicion_medio);//la mitad del arreglo de la IZQUIERDA
	mergesort(arreglo, posicion_medio+1, posicion_final);//la mitad del arreglo de la DERECHA
	//hasta aqui el arreglo viene "ordenado por partes", necesitamos ordenarlo POR COMPLETO
	
	merge(arreglo, posicion_inicial, posicion_medio, posicion_final);//enviamos la posicion del medio pues es la que nos indica dónde están los 2 subarreglos ordenados por separado
}



int main(){
	int arreglo[]={11,2,7,1,2,3,5}; //arreglo
	int n=7; //longitud del arreglo
	int i;
	
	cout<<"ORIGINAL: "<<endl;
	
	for (i=0;i<n;i++)
		cout<<arreglo[i]<<" ";
	cout<<endl;
	
	mergesort(arreglo, 0, n-1);
	
	cout<<"MERGE SORT: "<<endl;
	for (i=0;i<n;i++)
		cout<<arreglo[i]<<" ";
	cout<<endl;
	
	return 0;
}
