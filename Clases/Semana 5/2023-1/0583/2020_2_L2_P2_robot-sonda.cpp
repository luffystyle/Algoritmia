#include <iostream>
using namespace std;
//mapa que recorrerá el robot-sonda
int mapa[][6]={{0,0,0,1,0,1},
               {0,0,1,0,0,0},
               {0,1,0,0,0,1},
               {1,0,0,0,0,0},
               {0,1,0,0,0,0},
               {0,0,0,0,1,0}};

/*2020-02 P2*/
int busca(int x,int y,int x1,int y1,int x2,int y2,int n,int m)
{ 	int i,contador=0;
	if(x>=n || y>=m || x<0 || y<0)//cuando sale de algún borde
		return 0;
		
	if(mapa[x][y] && x2==0 && y2==0)//cuento si hay un objeto en la posición donde cae el robot-sonda
		contador++;	
		
	if(x2==0){//Entra cuando es la primera vez, luego ya no entra pues x2 tomará el valor de x1
		for(i=x+1;i<n;i++)	
			contador=contador+mapa[i][y];
		for(i=0;i<x;i++)	
			contador=contador+mapa[i][y];
		cout << "Me voy en y" << endl;	
	}
	if(y2==0){//Entra cuando es la primera vez, luego ya no entra pues y2 tomará el valor de y1
		for(i=y+1;i<m;i++)	
			contador=contador+mapa[x][i];
		for(i=0;i<y;i++)	
			contador=contador+mapa[x][i];
		cout << "Me voy en x" << endl;	
	}	
	       //       3+0  4+1  0  1  0  1
	contador=contador+busca(x+x1,y+y1,x1,y1,x1,y1,n,m);	
	return contador;	
}

/*
derecha: 0,1  
izquierda: 0,-1
abajo    : 1,0
arriba   :-1,0 
*/
int main(){
	int contador,n=6,m=6;
	//3,2 donde llega
	//0,1 son de movimiento
	//0,0 controlan la iteracion para que no recorra doble
	contador=busca(0,0,0,1,0,0,n,m);
	cout << contador << endl;
	return 0;
}
