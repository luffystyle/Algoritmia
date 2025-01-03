#include <iostream>

#define MAXF 10
#define MAXC 10

using namespace std;

void imprime(int x,int y,int n,int m,int tablero[MAXF][MAXC]){
	if (x>=n || y>=m){
		return ;
	}
	if (x==n-1 && y==m-1){
		cout << tablero[x][y] << " ";
	}
	
	for (int j=y; j<m-1; j++){
		cout << tablero[x][j] << " ";
	}
	
	for (int i=x; i<n-1; i++){
		cout << tablero[i][m-1] << " ";
	}
	
	for (int j=m-1; j>x; j--){
		cout << tablero[n-1][j] << " ";
	}
	
	for (int i=n-1; i>y; i--){
		cout << tablero[i][y] << " ";
	}
	imprime(x+1,y+1,n-1,m-1,tablero);
}

int main(){
	int n=4, m=4, tablero[MAXF][MAXC], cont=1;
	
	/*Aqui llenamos el tablero*/
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			tablero[i][j] = cont;
			cont++;
		}
	}
	imprime(0,0,n,m,tablero);
	return 0;
}

