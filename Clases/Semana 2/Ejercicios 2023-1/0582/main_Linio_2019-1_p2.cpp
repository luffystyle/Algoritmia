#include <iostream>
#include <math.h>

#define MAX 12

using namespace std;

void cargaBin(int num,int size,int cromo[MAX]){
	int i, digito;
	for (i=0; i<size; i++){
		cromo[i] = 0;
	}
	i = 0;
	while (num>0){
		digito = num%2;
		num = num/2;
		cromo[i] = digito;
		i++;
	}
}

int main(){
	int lista[12][4] = {{100,4,8,2},
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
	int combinaciones, n=12, cromo[MAX], horas[24];
	int prioridad1, prioridad2, prioridad3, prioridad4, hayCruce;
	combinaciones = pow(2,n);
	for (int i=0; i<combinaciones; i++){
		cargaBin(i,n,cromo);
		prioridad1 = 0;
		prioridad2 = 0;
		prioridad3 = 0;
		prioridad4 = 0;
		/*Voy a inicializar mi arreglo de horas en 0*/
		for (int j=0; j<24; j++){
			horas[j] = 0;
		}
		hayCruce = 0;
		for (int j=0; j<n; j++){
			if (cromo[j]==1){
				/*Aqui voy a ver las prioridades*/
				if (lista[j][1]==1){
					prioridad1++;
				}
				else {
					if (lista[j][1]==2){
						prioridad2++;
					}
					else {
						if (lista[j][1]==3){
							prioridad3++;
						}
						else {
							prioridad4++;
						}
					}
				}
				/*Ahora veamos si hay cruces*/
				for (int k=lista[j][2]; k<lista[j][2] + lista[j][3]; k++){
					if (horas[k] ==0){
						horas[k] = 1;
					}
					else {
						hayCruce = 1;
						break;
					}
				}
			}
		}
		if (prioridad1==2 && prioridad2==2 && prioridad3==1 && prioridad4==1 && hayCruce==0){
			for (int j=0; j<n; j++){
				if (cromo[j]==1){
					cout << lista[j][0] << " " << lista[j][1] << endl;
				}
			}
			break;
		}
		/*Falta ordenar la respuesta*/
	}
	return 0;
}
