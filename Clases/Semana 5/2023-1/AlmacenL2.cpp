
#include <iostream>
#define MAX 6

int almacen[][MAX]={{1,2,9,1,2,3},
					{5,1,7,0,2,1},
					{0,7,0,3,8,1},
					{1,2,6,1,2,2},
					{0,6,9,5,0,5},
					{0,0,4,0,9,0}};

using namespace std;

int recorreh(int i,int n,int x){
	if(i==n) return 0; 
	return recorreh(i+1,n,x)+almacen[x][i];
}

int recorrev(int i,int n,int y){
	if(i==n) return 0; 
	return recorrev(i+1,n,y)+almacen[i][y];
}

int pesomax(int x,int y,int n,int m){
	int parcial,sumav,sumah,sumat;
	
	if(m-1==0) return 0;
	
	sumah=recorreh(0,m,x);
	sumav=recorrev(x+1,n,m-1);
	sumat = sumav+sumah;
	
	parcial = pesomax(x+1,y,n,m-1);
	if(sumat>parcial) return sumat;
	else
		return parcial;
}

int revisa(int p,int pedido[],int valor,int i){


}

int busca(int x,int y,int n,int m,int p,int pedido[]){
	int aux[p],cont=0;
	
	if(m-1==0) return 0;
	for(int i=0;i<p;i++) aux[i]=pedido[i];
	for(int i=0;i<m;i++)
		if(almacen[x][i]!=0)
			cont=cont+revisa(p,aux,almacen[x][i],0);	
	for(int i=x+1;i<n;i++)
		if(almacen[i][m-1]!=0)
			cont=cont+revisa(p,aux,almacen[i][m-1],0);		
	if(cont==p || busca(x+1,y,n,m-1,p,pedido)) return 1;
	return 0;
}


int main(){
	int n=6,p=2;
	int pedido[]={6,8};
	cout <<"El peso maximo es:" << pesomax(0,0,n,n)<<endl;
	cout <<"Se puede atender:" << busca(0,0,n,n,p,pedido);
	
}

