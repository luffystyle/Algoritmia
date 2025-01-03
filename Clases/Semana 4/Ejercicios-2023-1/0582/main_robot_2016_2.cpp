#include <iostream>

#define MAXF 10
#define MAXC 8

using namespace std;

int obtenerPuntajeMaximo(int i,int j,int n,int m,int tablero[MAXF][MAXC]){
	int derecha = -100000, abajo=-100000, total;
	if (i==n-1 && j==m-1){
		return tablero[i][j];
	}
	if (j<m-1){
		derecha = obtenerPuntajeMaximo(i,j+1,n,m,tablero);
	}
	if (i<n-1){
		abajo = obtenerPuntajeMaximo(i+1,j,n,m,tablero);
	}
	if (derecha < abajo){
		total = tablero[i][j] + abajo;
	}
	else {
		total = tablero[i][j] + derecha;
	}
	return total;
}

int main(){
	int n, m, tablero[MAXF][MAXC], puntaje;
	cout << "Ingrese los valores de n y m: ";
	cin >> n >> m;
	/*Lectura de datos del tablero*/
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> tablero[i][j];
		}
	}
	puntaje = obtenerPuntajeMaximo(0,0,n,m,tablero);
	cout << "El puntaje maximo es: " << puntaje;
	return 0;
}
