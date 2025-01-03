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
	int peso=15,n=5,parcial,mpeso=0,mcomb,mvalor=0,pvalor;
	int paq[]={1,2,4,12,1};
	int valor[]={20,10,50,2,10};
	int cromo[n];
	int opcion=(int)pow(2,n);
	
	for(int i=0;i<opcion;i++){
		cargabin(i,n,cromo);
		parcial = 0;
		pvalor = 0;
		for(int j=0;j<n;j++){
			parcial=cromo[j]*paq[j]+parcial;
			pvalor=cromo[j]*valor[j]+pvalor;
		}
		if(parcial<=peso && mvalor<pvalor){
			mpeso = parcial;
			mvalor = pvalor;
			mcomb = i;

		}

	}
	
	cout << mpeso <<" "<<mcomb<<" "<<mvalor;
	
	
	return 0;
}
