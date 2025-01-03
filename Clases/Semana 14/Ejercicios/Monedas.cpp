#include <iostream>

using namespace std;

int evaluamonedas(int mon[],int n){
	int f[n+1];	
	
	f[0]=0;
	f[1]=mon[0];
	
	for(int i=2;i<=n;i++){
		int ady=f[i-1],act=f[i-2]+mon[i-1];
		
		if(ady>act) f[i]=ady;
		else f[i]=act; 
	}
	return f[n];
}


int main(){
	int n=6;
	int monedas[]={5,1,2,10,6,2};
	
	cout <<"La solucion: "<< evaluamonedas(monedas,n);
	
}
