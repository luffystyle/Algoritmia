#include <iostream>
#define N 4

using namespace std;

void merge(int lonchera[N],int inicio,int medio,int fin){
	int auxC[N],p,q,m;
	/*Aqui mezclamos, pero no necesariamente se han mezclado todos*/
	for (p=inicio,q=medio+1,m=inicio; p<=medio && q<=fin; m++){
		if (lonchera[p]<lonchera[q]){
			auxC[m] = lonchera[p];
			p++;
		}
		else {
			auxC[m] = lonchera[q];
			q++;
		}
	}
	
	/*Vamos a pasar los elementos de p que nos sobre al arreglo aux*/
	while (p<=medio){
		auxC[m] = lonchera[p];
		p++;
		m++;
	}
	
	/*Vamos a pasar los elementos de p que nos sobre al arreglo aux*/
	while (q<=fin){
		auxC[m] = lonchera[q];
		q++;
		m++;
	}
	
	/*Ahora actualizo el arreglo auxiliar en mi arreglo original*/
	for (int i=inicio; i<=fin; i++){
		lonchera[i] = auxC[i];
	}
	
}

void mergeSort(int lonchera[N],int inicio,int fin){
	if (inicio==fin){
		return;
	}
	int medio = (inicio+fin)/2;
	mergeSort(lonchera,inicio,medio);
	mergeSort(lonchera,medio+1,fin);
	merge(lonchera,inicio,medio,fin);
}

int buscarMenorCaloria(int calorias[N][N],int i,int inicio,int fin){
	if (inicio==fin){
		return calorias[i][inicio];
	}
	int medio = (inicio+fin)/2;
	int menorIzq = buscarMenorCaloria(calorias,i,inicio,medio);
	int menorDer = buscarMenorCaloria(calorias,i,medio+1,fin);
	if (menorIzq<menorDer){
		return menorIzq;
	}
	else {
		return menorDer;
	}
}


int main(){
	int calorias[N][N]; /*Todas las calorias por productos*/
	int lonchera[N]; /*Las 4 calorias mas bajas*/
	
	/*Parte a) Lectura de Datos*/
	for (int i=0; i<N; i++){
		cout << "Ingrese las calorias de los 4 productos del Tipo " << i+1 <<":";
		cin >> calorias[i][0] >> calorias[i][1] >> calorias[i][2] >> calorias[i][3];
	}
	
	/*Parte b) determinar la menor caloria por cada tipo de producto*/
	for (int i=0; i<N; i++){
		lonchera[i] = buscarMenorCaloria(calorias,i,0,N-1);
	}
	
	/*Impresion de las menores calorias encontradas*/
	for (int i=0; i<N; i++){
		cout << "Tipo Producto: " << i+1 << ": " << lonchera[i] << endl;
	}
	
	/*Parte c) Ordenar las calorias de menor a mayor utilizando DV = mergeSort*/
	mergeSort(lonchera,0,N-1);
	
	cout << "Las calorias ordenadas son: " << endl;
	
	/*Impresion de las menores calorias encontradas ya ordenadas*/
	for (int i=0; i<N; i++){
		cout << "Tipo Producto: " << i+1 << ": " << lonchera[i] << endl;
	}
	
	return 0;	
}
