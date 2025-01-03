#include <iostream>
using namespace std;

int cuenta_ceros(int arreglo[], int posicion_inicial, int posicion_final){
	//CASO BASE
	if(posicion_inicial==posicion_final)
		return 1-arreglo[posicion_inicial];
		
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	if (arreglo[posicion_medio]==0)
		return (posicion_final-posicion_medio) + cuenta_ceros(arreglo, posicion_inicial, posicion_medio);
		//return (posicion_final-posicion_medio) + 1 + cuenta_ceros(arreglo, posicion_inicial, posicion_medio-1);		
	else//cuando el medio es 1
		return cuenta_ceros(arreglo, posicion_medio+1, posicion_final);
}

int main(){
	int arreglo[]={1,0,0,0,0,0,0}; //arreglo
	int n=7; //longitud del arreglo
	cout<<"Resultado: "<<cuenta_ceros(arreglo,0, n-1)<<endl;
	return 0;
}
