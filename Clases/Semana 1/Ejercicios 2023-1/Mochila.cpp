#include <iostream>
#include <cmath>

using namespace std;

void cargabin(int num,int n,int cromo[]){
	int i,res;
	for(i=0;i<n;i++)cromo[i]=0; 
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}


int main(){
	int peso=15,n=5,parcial,mpeso=0,mcomb;
	int paq[]={1,2,12,3,1};
	int cromo[n];
	int opcion=(int)pow(2,n);
	
	for(int i=0;i<opcion;i++){
		cargabin(i,n,cromo);
		parcial = 0;
		
		for(int j=0;j<n;j++)
			parcial=cromo[j]*paq[j]+parcial;

		if(parcial<=peso && mpeso<=parcial){
			mpeso = parcial;
			mcomb = i;

		}

	}
	
	cout << mpeso <<" "<<mcomb;
	
	
	return 0;
}
