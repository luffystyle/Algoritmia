#include <iostream>

using namespace std;

int robot(int x,int y,int n,int m,int tablero[][3]){
	int derecha=-999999,abajo=-999999;
	
	if(x==n-1 && y==m-1) return tablero[x][y];
	if(y+1<m)derecha=robot(x,y+1,n,m,tablero);
	if(x+1<n)abajo=robot(x+1,y,n,m,tablero);		
	if(derecha>abajo) return tablero[x][y]+derecha;
	return tablero[x][y]+abajo;
}





int main(){
	int n=2,m=3;
	int tablero[][3]={	{3,-2,4},
						{1,-2,3}};
	
	cout << "La ruta tiene un valor:"<<robot(0,0,n,m,tablero);
	return 0;
}
