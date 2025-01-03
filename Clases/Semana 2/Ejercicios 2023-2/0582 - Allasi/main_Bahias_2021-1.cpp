#include <iostream>
#include <math.h>

#define MAXP 10

using namespace std;

void cargaBin(int num,int size,int cromo[MAXP]){
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
	int n, m, c, productos, pesoParcial, solucionI, solucionJ, solucionK;
	int combinaciones, i, j, k;
	int bahia1[MAXP], bahia2[MAXP], bahia3[MAXP];
	int cromo1[MAXP], cromo2[MAXP], cromo3[MAXP];
	/*Parte a*/
	cout << "Ingrese n: ";
	cin >> n;
	cout << "Ingrese m: ";
	cin >> m;
	cout << "Ingrese c: ";
	cin >> c;
	for (i=1; i<=3; i++){
		cout << "Ingrese los productos de la bahia " << i << endl;
		for (j=1; j<=n; j++){
			cout << "Producto " << j << ": ";
			if (i==1){
				cin >> bahia1[j-1];	
			}
			else {
				if (i==2){
					cin >> bahia2[j-1];
				}
				else {
					cin >> bahia3[j-1];
				}
			}
		}
	}
	/*Parte b*/
	combinaciones = pow(2,n);
	/*Vamos a realizar las combinaciones de la bahia 1 */
	for (i=0; i<combinaciones; i++){
		cargaBin(i,n,cromo1);
		for (j=0; j<combinaciones; j++){
			cargaBin(j,n,cromo2);
			for (k=0; k<combinaciones; k++){
				cargaBin(k,n,cromo3);
				/*Contamos productos y sumamos pesos*/
				productos = 0;
				pesoParcial = 0;
				for (int l=0; l<n; l++){
					if (cromo1[l]==1){
						productos++;
						pesoParcial = pesoParcial + bahia1[l];
					}
					if (cromo2[l]==1){
						productos++;
						pesoParcial = pesoParcial + bahia2[l];
					}
					if (cromo3[l]==1){
						productos++;
						pesoParcial = pesoParcial + bahia3[l];
					}
				}
				if (pesoParcial == c && productos==m){
					solucionI = i;
					solucionJ = j;
					solucionK = k;
					j = combinaciones + 1;
					i = combinaciones + 1; 
					
				}
			}	
		}
	}
	/*Imprimir el resultado esperado*/
	cargaBin(solucionI,n,cromo1);
	cargaBin(solucionJ,n,cromo2);
	cargaBin(solucionK,n,cromo3);
	cout << "Bahia 1: ";
	for (i=0; i<n; i++){
		if (cromo1[i]==1){
			cout << bahia1[i] << " ";
		}
		cout << endl;
	}
	cout << "Bahia 2: ";
	for (i=0; i<n; i++){
		if (cromo2[i]==1){
			cout << bahia2[i] << " ";
		}
		cout << endl;
	}
	cout << "Bahia 3: ";
	for (i=0; i<n; i++){
		if (cromo3[i]==1){
			cout << bahia3[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
