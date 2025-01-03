#include <iostream>
#include <math.h>
#define N 5 //porque son 5 cajas

//Tengo 5 cajas, cada una con un peso definido
//Tengo 1 mochila que soporta 15Kg, el peso es el limitante
//Quiero hallar la mejor solucion version 2 (si llego al peso maximo, termino el algoritmo)

//USO de BANDERA

using namespace std;

void cargaBinaria(int numero,int cromosoma[],int longitud_cromosoma){
	int i, aux;
	for (i=0; i<longitud_cromosoma; i++){
		cromosoma[i] = 0;
	}
	i = 0;
	while (numero>0){
		aux = numero%2;
		numero = numero/2;
		cromosoma[i] = aux;
		i++;
	}
}


int main(){
	int objetos[N] = { 1, 2, 1, 12, 4 }; // peso de las cajas
	int cromosoma[N]; //arreglo de nuestro cromosoma
	int peso_mochila, //es el peso que iremos calculando para cada cominacion
	combinaciones; //cantidad de combinaciones
	
	int alcanzo_peso_maximo=0; //BANDERA para indicar si alcanzo el peso maximo
	
	int mejor_peso_mochila=0, mejor_combinacion=0; //para encontrar el mejor peso
	
	int peso_maximo; //es la limitante de la mochila: el peso
	//Solicitamos el peso maximo a considerar (nuestra limitante)
	cout << "Peso maximo de la mochila: ";
	cin >> peso_maximo;
	
	//Definimos la cantidad de combinaciones
	combinaciones = pow(2,N);
	
	int soluciones[combinaciones];//Para almacenar las soluciones
	
	//iniciamos nuestros for de fuerza bruta
	for (int i=1; i<combinaciones; i++){ //recorremos cada combinacion
		cargaBinaria(i,cromosoma,N); //convertimos la combinacion a binario
		peso_mochila = 0; //inicializo en 0 el peso de la combinacion
		for (int j=0; j<N; j++){//Voy a calcular el peso de la combinacion
			if (cromosoma[j]==1)//cada vez que encuentre un objeto/caja asignado, acumulo el peso
				peso_mochila = peso_mochila + objetos[j];//acumulo el peso
		}
		
		if (peso_mochila<=peso_maximo && mejor_peso_mochila <= peso_mochila){//Cuando el peso de la mochila es menor igual a mi limitante  Y encontramos un nuevo mejor peso
			mejor_peso_mochila=peso_mochila;
			mejor_combinacion=i;
			if (peso_mochila==peso_maximo) alcanzo_peso_maximo=1;
		}
		if (alcanzo_peso_maximo) break;
	}
	
	cargaBinaria(mejor_combinacion,cromosoma,N);
	cout << "Solucion: " << ": "; //Muestro la solucion
	for (int j=0; j<N; j++){
		if (cromosoma[j]==1){
			cout << objetos[j] << " "; //Se muestra la solución
		}
	}
	cout << endl;
	return 0;
}
