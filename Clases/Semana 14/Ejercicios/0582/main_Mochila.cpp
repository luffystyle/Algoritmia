#include <iostream>
#define N 4

using namespace std;

int maximaGanancia(int pesos[N],int valores[N],int n,int w){
	int solucion[n+1][w+1];
	for (int i=0; i<=n; i++){
		solucion[i][0] = 0;
	}
	for (int j=0; j<=w; j++){
		solucion[0][j] = 0;
	}
	for (int j=1; j<=w; j++){
		for (int i=1; i<=n; i++){
			if (pesos[i-1]<=j){
				if ((valores[i-1] + solucion[i-1][j-pesos[i-1]]) > solucion[i-1][j]){
					solucion[i][j] = valores[i-1] + solucion[i-1][j-pesos[i-1]];
				}
				else {
					solucion[i][j] = solucion[i-1][j];
				}
			}
			else {
				solucion[i][j] = solucion[i-1][j];
			}
		}
	}
	return solucion[n][w];
}
 	
int main(){
	int pesos[N] =  {2,1,3,2};
	int valores[N] = {12,10,20,15};
	int n=4, w=5;
	cout << maximaGanancia(pesos,valores,n,w);
	return 0;
}
