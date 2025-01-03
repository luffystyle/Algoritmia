#include <iostream>

using namespace std;

int maximo(int a, int b) { 
//esta función devuelve el máximo de 2 números
	if (a > b)
		return a;
	else
		return b;
}

int maximo3(int a, int b, int c) { 
//esta función devuelve el máximo de 3 números
	return maximo(maximo(a, b), c); 
}

int incremento_cruzado(int arreglo[], int posicion_inicial, int posicion_medio,int posicion_final){
	int contador_izquierda, contador_derecha;
	int i;
	contador_izquierda=contador_derecha=0;
	
	//Contamos hacia la izquierda
	for (i=posicion_medio;i>posicion_inicial;i--){
		if (arreglo[i]>arreglo[i-1])//que haya el decremento
			contador_izquierda++;
		else
			break;//Contaremos mientras sigamos encontrando el decremento
	}
	
	//Contamos hacia la derecha
	for (i=posicion_medio;i<posicion_final;i++){
		if (arreglo[i+1]>arreglo[i])//que haya el incremento
			contador_derecha++;
		else
			break;//Contaremos mientras sigamos encontrando el incremento
	}
	
	return contador_izquierda+contador_derecha+1;//sumamos 1 por la misma razón del caso base de la recursión.
}

int incremento_consecutivo(int arreglo[], int posicion_inicial, int posicion_final){
	//CASO BASE
	if (posicion_inicial==posicion_final) return 1; 
	//asumimos que al ser un sólo elemento (día), este día sería también un incremento
	
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	int izquierda, derecha, centro;
	izquierda=incremento_consecutivo(arreglo, posicion_inicial, posicion_medio);//incremento del subarreglo de la izquierda
	derecha=incremento_consecutivo(arreglo, posicion_medio+1, posicion_final);//incremento del subarreglo de la derecha
	centro=incremento_cruzado(arreglo, posicion_inicial, posicion_medio,posicion_final);//incremento cruzado
	
	return maximo3(izquierda, centro, derecha);
}

int main(){
	
	//int contagios[]={10,20,15,10,12,10,13,18};
	int contagios[]={7,2,9,10,16,10,13,8,2,10};
	int n=10;
	
	cout << (1.0)*incremento_consecutivo(contagios, 0, n-1)/n;
	return 0;
	
}
