#include <iostream>
#define max 50
using namespace std;

int robot(int x, int y, int n, int m, int tablero[][max]){
	int abajo, derecha;//variables para evaluar los movimientos del robot
	int total;
	
	//CASO BASE
	if (x==n-1 && y==m-1)//Cuando hemos llegado al objetivo: n-1 y m-1
		return tablero[x][y];//el valor de la celda destino
	
	if (x+1<n)//si todavía podemos avanzar hacia la derecha
		derecha = robot(x+1, y, n, m, tablero);
	if (y+1<m)//si todavía podemos avanzar hacia abajo
		abajo = robot(x, y+1, n, m, tablero);
	
	//Una vez que las llamadas a las funciones recursivas retornan, tengo que evaluar cuál trae el mejor puntaje
	if (derecha<abajo)//El camino hacia ABAJO es MEJOR
		total = tablero[x][y] + abajo;
	else//El camino hacia la DERECHA es MEJOR
		total = tablero[x][y] + derecha;
		
	//la función recursiva retorna el mejor puntaje de esta instancia (universo)
	return total;
} 

int main(){
	int n, m;
	int tablero[max][max];
	
	cout<<"N = ";
	cin >> n;
	cout<<"M = ";
	cin >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> tablero[i][j];
		}
	}
	cout << robot(0,0,n,m,tablero) <<endl;
	//robot(x=0, y=0, n=2 , m=3,tablero), es {0,0} porque inicia en esa posición del tablero

	return 0;
}
