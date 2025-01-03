#include <iostream>
#include <cmath>

using namespace std;

int lista[][4]={{100,4,8,2},
				{101,2,10,2},
				{102,3,12,2},
				{103,1,13,2},
				{104,3,15,1},
				{105,1,10,2},
				{106,4,16,1},
				{107,2,8,2},
				{108,3,14,1},
				{109,2,18,2},
				{110,1,18,2},
				{111,4,14,2}};	

void cargabin(int num,int n,int cromo[]){
	int res,i=0;
	for(int j=0;j<n;j++)cromo[j]=0;
	while(num>0){
		res = num%2;	
		num = num/2;
		cromo[i]=res;
		i++;
	}
}



int main(){
	int n=12,opcion,mcomb=0,p1,p2,p3,p4,cruce=0;
	int cromo[n],horario[24];
	
	opcion = pow(2,n);
	
	for(int i=0;i<opcion;i++){
		cargabin(i,n,cromo);
		for(int k=0;k<24;k++) horario[k]=0;	
		p1=0;p2=0;p3=0;p4=0;
		cruce=0;
		for(int j=0;j<n;j++){
			if(cromo[j]==1){
				if(lista[j][1]==1) p1++;
				if(lista[j][1]==2) p2++;
				if(lista[j][1]==3) p3++;				
				if(lista[j][1]==4) p4++;
				for(int k= lista[j][2];k<lista[j][2]+lista[j][3];k++)
				{	if(horario[k]==0)
						horario[k]=1;
					else{
						cruce=1;
						break;
					}			
				}
				if(cruce==1) break;				
			}
		}				
		if(cruce==0 && p1>=2 && p2>=2 && p3>=1 && p4>=1){
			for(int m=0;m<n;m++)
				if(cromo[m]==1)
					cout << lista[m][0] <<" "<< lista[m][1] <<endl;	
			break;				
			
		}
	}
	
	return 0;
}
	
