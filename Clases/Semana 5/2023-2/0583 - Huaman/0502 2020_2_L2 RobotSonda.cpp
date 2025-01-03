#include <iostream>
using namespace std;

//Para gestionar el mapa:
int mapa[][6]={	{0,0,0,1,0,1},
				{0,0,1,0,0,0},
				{0,1,0,0,0,1},
				{1,0,0,0,0,0},
				{0,1,0,0,0,0},
				{0,0,0,0,1,0}};

int sonda_robot(int x, int y, int x1, int y1, int x2, int y2, int n, int m){
	int i;
	int contador=0;//donde contaremos las unidades en esta llamada, en este "mundo"
	
	//CASO BASE 1
	if (x>=n || y>=m || x<0 || y<0)//cuando se sale de algún borde del mapa
		return 0;
		
	//CASO BASE 2, cuando estamos en la posición inicial (x,y) y en el primer movimiento (x2=0,y2=0) y hay una unidad desparecida
	if (mapa[x][y] && x2==0 && y2==0)
		contador++;
	
	//Contamos todas las unidades que encontremos menos la posición en la que se encuentra el sonda-robot
	if (x2==0){//Nos desplazamos en X
		//en X
		for (i=x+1;i<n;i++)
			contador=contador+mapa[i][y];
		for (i=0;i<x;i++)
			contador=contador+mapa[i][y];
	}
	if (y2==0){//Nos desplazamos en Y
		//en Y
		for (i=y+1;i<m;i++)
			contador=contador+mapa[x][i];
		for (i=0;i<y;i++)
			contador=contador+mapa[x][i];
	}
	
	contador=contador+sonda_robot(x+x1,y+y1,x1,y1,x1,y1,n,m);
								//(x+desplaz. , y+desplaz. , desplaz. , desplaz. , 0 , 1, n, m)
	return contador;
}

int main(){
	int n=6,m=6;
	int x=3,y=2;
	int contador;//para almacenar las unidades desaparecidas que se han encontrado
	
	//(x,y) posicion inicial del sonda-robot
	//(x1,y1) para el movimiento (constante) del sonda-robot
	//	0,+1 	derecha
	//	0,-1	izquierda
	//	-1,0 	arriba
	//	+1,0 	abajo
	//(x2,y2) para que indique la primera vez que contaremos la fila/columna en la que se moverá el sonda-robot
	//(n,m) límites/dimensiones del mapa
	cout<<"Unidades encontradas: "<<sonda_robot(3,2,0,1,0,0,n,m);
								//sonda_robot(x,y,x1,y1,x2,y2,n,m)
	//robot(x=0, y=0, n=2 , m=3,tablero), es {0,0} porque inicia en esa posición del tablero

	return 0;
}
