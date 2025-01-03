#include <iostream>

#define MAXF 10
#define MAXC 10

using namespace std;

int cuentaUnidades(int i,int j,int movX,int movY,int n,int m,int tablero[MAXF][MAXC]){
	int cantUnidades = 0, total;
	if (i>=n || j>=m || i<0 || j<0){
		/*En el caso base, vamos a evaluar la fila o columna desde donde voy a iniciar la busqueda*/
		if (movX==0){
			for (int columna=0; columna<m; columna++){
				cantUnidades = cantUnidades + tablero[i][columna];
			}
		}
		else {
			for (int fila=0; fila<n; fila++){
				cantUnidades = cantUnidades + tablero[fila][j];
			}
		}
		return cantUnidades;	
	}
	if (movX==0){
		/*Busco en Vertical*/
		for (int fila=0; fila<n; fila++){
			if (fila!=i){
				cantUnidades = cantUnidades + tablero[fila][j];				
			}
		}
	}
	if (movY==0){
		/*Busco en Horizontal*/
		for (int columna=0; columna<m; columna++){
			if (columna!=j)
				cantUnidades = cantUnidades + tablero[i][columna];	
		}
	}
	
	total = cantUnidades + cuentaUnidades(i+movX,j+movY,movX,movY,n,m,tablero);
	return total;
}

int main(){
	int n=6, m=6, i=3, j=2, movX = -1, movY= 0, unidades;
	int tablero[MAXF][MAXC] = {{0,0,0,1,0,1},
							   {0,0,1,0,0,0},
							   {0,1,0,0,0,1},
							   {1,0,0,0,0,0},
							   {0,1,0,0,0,0},
							   {0,0,0,0,1,0}};
	/*Parte a para ustedes :) */
	/*parte b*/
	unidades = cuentaUnidades(i,j,movX,movY,n,m,tablero);
	cout << "La cantidad de unidades es: " << unidades;
	return 0;
}
