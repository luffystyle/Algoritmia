#include <iostream>
#include <cmath>
#define N 6
#define M 6

using namespace std;

int calculaDistancia(int tablero[N][M],int n,int m){
	int solucion[N][M];
	solucion[0][0] = tablero[0][0];
	/*Derecha*/
	for (int j=1; j<M; j++){
		solucion[0][j] = solucion[0][j-1] + tablero[0][j];
	}	
	/*Abajo*/
	for (int i=1; i<N; i++){
		solucion[i][0] = solucion[i-1][0] + tablero[i][0];
	}
	/*Ahora si viene lo de PD para las otras posiciones*/
	for (int i=1; i<n; i++){
		for (int j=1; j<m; j++){
			int abajo = solucion[i-1][j] + tablero[i][j];
//			int diagonal = abs(tablero[i][j] - tablero[i-1][j-1]) + solucion[i-1][j-1];
			int derecha = solucion[i][j-1] + tablero[i][j];
			if (abajo>=derecha){
				solucion[i][j] = abajo;
			}
			else {
				solucion[i][j] = derecha;
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
	int tablero[N][M] = {{1,2,9,1,2,3},
						 {5,1,7,1,2,1},
						 {1,7,1,3,8,1},
						 {2,2,6,1,2,2},
						 {3,6,9,5,1,5},
						 {1,1,4,1,9,1}};
	int n=6, m=6;
	cout << calculaDistancia(tablero,n,m);
	return 0;
}

