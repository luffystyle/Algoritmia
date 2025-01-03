#include <iostream>

using namespace std;

int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int max2(int a,int b,int c){
	return(max(max(a,b),c));
}
int merge(int ini,int med,int fin,int arr[]){
	int cont=1;
	
	for(int i=med;i>ini;i--)
		if(arr[i]>arr[i-1]) cont++;
		else	
			break;
	for(int i=med;i<fin;i++)
		if(arr[i]<arr[i+1]) cont++;
		else	
			break;		
			
	return cont;
			
}

int maxcontagios(int ini,int fin,int arr[]){
	int izq,cen,der;
	
	if (ini==fin) return 1;
		
	int med=(ini+fin)/2;
	izq=maxcontagios(ini,med,arr);
	der=maxcontagios(med+1,fin,arr);
	cen=merge(ini,med,fin,arr);
	
	return max2(izq,der,cen);
	
}

int main(){
	int n=10;
	int arreglo[]={7,2,9,10,16,10,13,8,2,10};
	
	cout << maxcontagios(0,n-1,arreglo);
	
	return 0;
	
		
}
