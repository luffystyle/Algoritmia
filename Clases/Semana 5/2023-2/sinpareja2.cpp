#include <iostream>

using namespace std;

void busca(int ini,int fin,int arr[]){
	
	if(ini==fin){
		cout << "El sin pareja:"<<arr[ini];
		return;
	}
	int med=(ini+fin)/2;
	
	if(med%2==0){
		if(arr[med]==arr[med+1])
			busca(med+2,fin,arr);
		else		
			busca(ini,med,arr);
	}
	else{
		if(arr[med]==arr[med-1])
			busca(med+1,fin,arr);
		else		
			busca(ini,med-1,arr);		
	}
}


int main(){
	int n=5;
	int arreglo[]={1,1,2,2,4};
	busca(0,n-1,arreglo);
	return 0;
}
