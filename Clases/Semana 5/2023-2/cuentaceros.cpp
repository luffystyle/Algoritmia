#include <iostream>

using namespace std;

int cuentaceros(int ini,int fin,int arr[],int cont){
	
	if(ini==fin)
		return cont+!arr[ini];
	//if(ini>fin)
	//	return cont;
		
	int med = (fin+ini)/2;
	
	if(arr[med]==0)
		cuentaceros(ini,med-1,arr,fin-med+cont+1);
	else
		cuentaceros(med+1,fin,arr,cont);
	
}


int main(){
	
	int n=7;
	int arr[]={1,0,0,0,0,0,0};
	
	cout << cuentaceros(0,n-1,arr,0);		
	
	
}
