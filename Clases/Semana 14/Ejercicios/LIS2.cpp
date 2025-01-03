#include <iostream>

using namespace std;

int calculalis(int arr[],int n){
	int maximo = 1;
	int LIS[n];
	
	for(int i=0;i<n;i++){
		LIS[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && LIS[j]+1>LIS[i])
				LIS[i] = LIS[j]+1;
		}
		if(LIS[i]>maximo) maximo=LIS[i];
	}
	return maximo;	
}


int main(){
	int arr[]={17,10,9,2,3,8,18,1};
	int n=8;
	cout << "El largo es:"<<calculalis(arr,8);
	
	return 0;
}

