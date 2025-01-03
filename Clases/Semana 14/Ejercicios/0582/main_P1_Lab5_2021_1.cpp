#include <iostream>
#define N 12

using namespace std;

int MaximaGanancia(int proyectos[N],int n){
	int solucion[n+1];
	solucion[0] = 0;
	solucion[1] = proyectos[0];
	if (proyectos[1]>proyectos[0]){
		solucion[2] = proyectos[1];			
	}
	else {
		solucion[2] = proyectos[0];	
	}
	for (int i=3; i<=n; i++){
		if (proyectos[i-1] + solucion[i-3]>solucion[i-1]){
			solucion[i] = proyectos[i-1] + solucion[i-3];
		}
		else {
			solucion[i] = solucion[i-1];
		}
	}
	/*Impresion de resultados*/
	int maximo = solucion[n];
	while (maximo>0){
		for (int i=0; i<=n; i++){
			if (solucion[i]==maximo){
				cout << i << " ";
				maximo = maximo - proyectos[i-1];
				break;
			}
		}
	}
	cout << endl;
	return solucion[n];
}

int main(){
	int proyectos[N] = {3,6,1,2,4,5,18,10,13,7,15,2};
	int n=12;
	cout << MaximaGanancia(proyectos,n);
	return 0;
}
