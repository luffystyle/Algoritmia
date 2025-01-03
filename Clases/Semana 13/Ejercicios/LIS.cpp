
#include <iostream>

using namespace std;

int calculalis(int lis[],int n){
	int maxlis=1;
	int Flis[n];	
		
	for(int i=0;i<n;i++){
		Flis[i]=1;
		for(int j=0;j<i;j++){
			if(lis[i]>lis[j] && Flis[j]+1>Flis[i])
				Flis[i]=Flis[j]+1;
		}
		if(Flis[i]>maxlis) maxlis=Flis[i];
	}
	return maxlis;	
}


int main(){
	int LIS[]={2,3,-1,5,4,-3,-2};
	int n=7;

	cout <<"El resultado es: "<< calculalis(LIS,n);
		
	return 0;
}
