#include <iostream>
#define max 50
using namespace std;

void remolino(int x, int y, int n, int m, int tablero[][max]){
	int i;
	//CASO BASE 1: cuando la matriz es cuadrada par (p.e. 4x4)
	if (x>=n || y>=m)//Cuando pasen los bordes del tablero
		return;
		
	//CASO BASE 2: cuando la matriz es cuadrada impar (p.e. 5x5)
	//if (x==n-1 && y==m-1){//es decir al hacer la última llamada recursiva nos queda un centro.
	//	cout<< tablero[y][x]<<	" ";
	//	return;
	//}
	
	//CASO BASE 2.1: cuando la matriz NO es cuadrada e Y llega a al límite, entonces falta recorrer una fila
	if (y==m-1){
		for (i=x; i<n; i++)//nos movemos hacia DERECHA
			cout<<tablero[y][i]<<" ";
		return;
	}	
	
	//CASO BASE 2.2: cuando la matriz NO es cuadrada y X llega a al límite, entonces falta recorrer una columna
	if (x==n-1){
		for (i=y; i<m; i++)//nos movemos hacia ABAJO
			cout<<tablero[i][x]<<" ";
		return;
	}
	
	for (i=x; i<n-1; i++)//nos movemos hacia DERECHA
		cout<<tablero[y][i]<<" ";
		
	for (i=y; i<m-1; i++)//nos movemos hacia ABAJO
		cout<<tablero[i][n-1]<<" ";
	
	for (i=n-1; i>x; i--)//nos movemos hacia IZQUIERDA
		cout<<tablero[m-1][i]<<" ";
		
	for (i=m-1;i>y;i--)//nos movemos hacia ABAJO
		cout<<tablero[i][x]<<" ";
	
	remolino(x+1,y+1,n-1,m-1,tablero);
} 

int main(){
	int n, m, contador=0;
	int tablero[max][max];
	
	cout<<"N = ";
	cin >> n;
	cout<<"M = ";
	cin >> m;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			tablero[i][j]=contador++;
		}
	}
	remolino(0,0,n,m,tablero);
	//robot(x=0, y=0, n=2 , m=3,tablero), es {0,0} porque inicia en esa posición del tablero

	return 0;
}
