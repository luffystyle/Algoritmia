/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
void cargabin(int num,int n,int cromo[]){
	int i, res;
	for(i=0;i<n;i++) cromo[i]=0;
	i=0;
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}	
}
int calcuPredecesores(int pred,int &p1,int &p2,int &p3){
	int n=pred;
	int cant=0;
	while(n!=0){
		n/=10;
		cant++;
	}
	if(cant==1){
		p1=pred;
	}
	if(cant==2){
		p1=pred/10;
		p2=pred%10;
	}
	if(cant==3){
		p3=pred%10;
		pred/=10;
		p2=pred%10;
		p1=pred/10;
	}
	return cant;
}

int main(){
	int n=8,p=100,parcial=0,ganancia=0,p1,p2,p3,max=-1,cant=0;
	int cromo[n];
	int combi=(int)pow(2,n);
	//para este caso se toma los requisitos como un solo numero donde por ejemplo:
	//control 3 -> requisitos : 1 ,2
					//inver- requi-beneficio
	int control[n][3]={{32,0,60},
					   {8,0,32},
					   {40,12,120},
					   {40,0,60},
					   {20,0,32},
					   {4,2,20},
					   {16,6,48},
					   {16,6,60}};
					   
	for(int i=0;i<combi;i++){
		cargabin(i,n,cromo);
		parcial=0;
		ganancia=0;
		p1=0;
		p2=0;
		p3=0;
		
		for(int j=0;j<n;j++){
			if(cromo[j]==1){
				//para el caso que no tenga requisitos
				if(control[j][1]==0){
					parcial+=control[j][0];
					ganancia+=control[j][2];
				}else{
					//En esta funcion podemos calcular la cantidad de requisitos
					//ademas en la matriz control, los requisitos estan como un solo numero, por ello se saca requisito uno por uno
					cant=calcuPredecesores(control[j][1],p1,p2,p3);
					if(cant==1){
						if(cromo[p1-1]==1){
							parcial+=control[j][0];
							ganancia+=control[j][2];
						}
					}
					if(cant==2){
						if(cromo[p1-1]==1 and cromo[p2-1]==1 ){
							parcial+=control[j][0];
							ganancia+=control[j][2];
						}
					}
					if(cant==3){
						if(cromo[p1-1]==1 and cromo[p2-1]==1 and cromo[p3-1]==1){
							parcial+=control[j][0];
							ganancia+=control[j][2];
						}
					}
				}
			}
		}
		
		if(parcial==p){
			cout<<"Soluciones: "<<endl;
			for(int k=0;k<n;k++){
				if(cromo[k]){
					cout<<"Control "<<k+1<<" : inversion: "<<control[k][0]*1000<<" USD. "<<endl;
				}
			}
			cout<<"---------------------"<<endl;
		}
	}
	
}
