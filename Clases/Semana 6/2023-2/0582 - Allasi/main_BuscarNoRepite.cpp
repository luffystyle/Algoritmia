#include <iostream>
#define N 11

using namespace std;

void noRepite(int numeros[N],int inicio,int fin){
	if (inicio>fin){
		return;
	}
	if (inicio==fin){
		cout << "El numero que no se repite es: " << numeros[inicio];
		return;
	}
	int medio = (inicio+fin)/2;
	if (medio%2==0){
		if (numeros[medio]==numeros[medio+1]){
			noRepite(numeros,medio+2,fin);
		}
		else {
			noRepite(numeros,inicio,medio);
		}
	}
	else {
		if (numeros[medio]==numeros[medio-1]){
			noRepite(numeros,medio+1,fin);
		}
		else {
			noRepite(numeros,inicio,medio-1);
		}
	}
}

int main(){
	int numeros[N] = {1,1,3,3,4,4,5,5,7,8,8};
	noRepite(numeros,0,N-1);
	return 0;
}
