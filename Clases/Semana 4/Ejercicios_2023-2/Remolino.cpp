#include <iostream>
#define max 20

using namespace std;

void remolino(int alma[][max],int x,int y,int n,int m){
	
	if(x>=n || y>=m) return;	
	
	if(x==n-1 && y==m-1)cout <<  alma[x][y] <<" ";
		
	for(int i=y;i<m-1;i++)cout << alma[x][i] <<" ";
	
	for(int i=x;i<n-1;i++)cout << alma[i][m-1] <<" ";
	
	for(int i=m-1;i>y;i--)cout << alma[n-1][i] <<" ";
	
	for(int i=n-1;i>x;i--)cout << alma[i][y] <<" ";
	
	remolino(alma,x+1,y+1,n-1,m-1);
}


int main(){
	int cont=1,n=1,m=10;
	int alma[max][max];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)	
			alma[i][j]=cont++;
	
	remolino(alma,0,0,n,m);
	return 0;
}
