#include <iostream>
#include <cmath>
#define N 4
#define M 4

using namespace std;

int calculaDistancia(int tablero[N][M],int n,int m){
	int solucion[N][M];
	solucion[0][0] = 0;
	/*Derecha*/
	for (int j=1; j<M; j++){
		solucion[0][j] = abs(tablero[0][j] - tablero[0][j-1]) + solucion[0][j-1];
	}	
	/*Abajo*/
	for (int i=1; i<N; i++){
		solucion[i][0] = abs(tablero[i][0] - tablero[i-1][0]) + solucion[i-1][0];
	}
	/*Ahora si viene lo de PD para las otras posiciones*/
	for (int i=1; i<N; i++){
		for (int j=1; j<M; j++){
			int abajo = abs(tablero[i][j] - tablero[i-1][j]) + solucion[i-1][j];
			int diagonal = abs(tablero[i][j] - tablero[i-1][j-1]) + solucion[i-1][j-1];
			int derecha = abs(tablero[i][j] - tablero[i][j-1]) + solucion[i][j-1];
			if (abajo<=diagonal && abajo<=derecha){
				solucion[i][j] = abajo;
			}
			else {
				if (diagonal<=abajo && diagonal<=derecha){
					solucion[i][j] = diagonal;
				}
				else {
					solucion[i][j] = derecha;
				}
			}
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << solucion[i][j] << " ";
		}
		cout << endl;
	}
	return solucion[n-1][m-1];
}

int main(){
	int tablero[N][M] = {{4,2,2,4},
						 {1,4,6,8},
						 {2,5,9,1},
						 {1,3,11,12}};
	int n=4, m=4;
	cout << calculaDistancia(tablero,n,m);
	return 0;
}

