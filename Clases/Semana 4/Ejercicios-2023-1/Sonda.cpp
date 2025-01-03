#include <iostream>

using namespace std;

	int mapa[][6]={ {0,0,0,1,0,1},
					{0,0,1,0,0,0},
					{0,1,0,0,0,1},
					{1,0,0,0,0,0},
					{0,1,0,0,0,0},
					{0,0,0,0,1,0}};
					
					
int busca(int x,int y,int xm,int ym,int x1,int y1,
		int n, int m){
	int cont=0;
	if(x>=n || x<0 || y>=m || y<0) return 0;	
	if(mapa[x][y]==1 && x1==0 && y1==0) cont++;
	//hacia abajo y hacia arriba
	if (x1==0){
		for(int i=x+1;i<n;i++)cont+=mapa[i][y];
		for(int i=0;i<x;i++)cont+=mapa[i][y];	
	}
	if (y1==0){
		for(int i=y+1;i<m;i++)cont+=mapa[x][i];
		for(int i=0;i<y;i++)cont+=mapa[x][i];	
	}
	cont = cont + busca(x+xm,y+ym,xm,ym,xm,ym,n,m);
	return cont;
}					
					
int main(){
	int n=6,m=6;
	
	cout << busca(5,5,0,-1,0,0,n,m);
	
	return 0;
}					


