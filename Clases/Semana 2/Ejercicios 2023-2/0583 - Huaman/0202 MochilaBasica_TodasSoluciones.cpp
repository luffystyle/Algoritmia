#include <iostream>
#include <math.h>
#define N 5 //porque son 5 paquetes

using namespace std;

void carga_binaria(int numero, int cromosoma[], int longitud_cromosoma){
	int i,aux;
	//inicializamos nuestro arreglo cromosoma
	for (i=0; i<longitud_cromosoma; i++){
		cromosoma[i]=0;
	}
	//utilizamos divisiones sucesivas para obtener el número binario
	i=0;
	while (numero>0){
		aux=numero%2;
		numero=numero/2;
		cromosoma[i]=aux;
		i++;
	}
}

int main(){
	int paquetes[N]={1,2,4,1,12};//los pesos de los paquetes
	int cromosoma[5];//arreglo para el cromosoma 2^5
	int peso_mochila;//para ir calculando el peso para cada combinación
	int combinaciones; //para la cantidad de combinaciones
	int alcanzo_peso_maximo=0;//para terminar el bucle una vez se encuentre una buena solución
	
	int mejor_peso_mochila=0, mejor_combinacion=0; //variables para obtener la mejor solución (peso y la combinación)
	
	//Solicitamos el peso máximo de la mochila
	int peso_maximo;//peso máximo de la mochila
	cout<<"Peso maximo de la mochila: ";
	cin>>peso_maximo;

	//definimos la cantidad de combinaciones
	combinaciones=pow(2,N);//N = 5, porque son 5 paquetes
	
	for (int i=0; i<combinaciones; i++){//reccoremos todas las combinaciones para analizar cuáles cumplen con lo pide el problema
		carga_binaria(i,cromosoma,N);//para convertir la combinación que está en base decimal a base 2 (binario)		
		//iniciamos el análisis de cada combinación
		peso_mochila=0;//inicializo el peso de la mochila para cada combinación
		for (int j=0; j<N; j++){//recorro todo el arreglo cromosoma[]
			if (cromosoma[j]==1) peso_mochila = peso_mochila + paquetes[j];//acumulo el peso
		}//hasta aquí tenemos el peso de la combinación
		//Una vez que hemos obtenido el peso, vamos a mostrar sólo los que se igualen al peso límite de la mochila (peso_maximo)
		if (peso_mochila==peso_maximo){
			cout<<endl<<"Solucion: Combinación = "<<i<<" Peso = "<<peso_mochila<<endl;
			cout<<"Cromosoma: ";
			for (int j=0; j<N; j++){	
				cout<< cromosoma[j] << " ";//mostramos el cromosoma		
			}
			cout<<endl;
			cout<<"Pesos seleccionados: ";
			for (int j=0; j<N; j++){
				if (cromosoma[j]==1){	
				cout<< paquetes[j] << " ";//mostramos los paquetes seleccionados
				}		
			}
		cout<<endl;
		}
	}
	return 0;
}
