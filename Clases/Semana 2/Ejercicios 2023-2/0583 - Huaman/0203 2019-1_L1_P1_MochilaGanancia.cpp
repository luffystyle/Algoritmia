#include <iostream>
#include <math.h>
#define N 6 //porque son 6 artículos

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
	
	int cantidad_productos;
	cout<<"Ingrese cantidad maxima de productos a traer (M): ";
	cin>>cantidad_productos;
	
	int peso_maximo;
	cout<<"Peso maximo de la mochila (W): ";
	cin>>peso_maximo;
	
	int productos[cantidad_productos][2];//Para administrar los datos de cada paquete: peso y ganancia
	//Ingreso de datos.
	for (int i=0; i<cantidad_productos; i++){
		cout<< "Artículo N° "<<i+1<<": ";
		cout<< "Peso (p): ";
		cin>> productos[i][0];
		cout<< "Ganancia (g): ";
		cin>> productos[i][1];	
		cout<<endl;	
	}
	
	int cromosoma[N];//arreglo para el cromosoma 2^N, N=6
	int peso_mochila,//para ir calculando el peso para cada combinación
	ganancia_mochila;//para ir calculando la ganancia para cada combinación
	int combinaciones; //para la cantidad de combinaciones

	//definimos la cantidad de combinaciones
	combinaciones=pow(2,N);//N = 6, porque son 6 paquetes

	//OJO!!!!!!!!!!!!!!!!!!!!!
	int mejor_peso_mochila=0, mejor_combinacion=0, mayor_ganancia=0; //variables para obtener la mejor solución (peso y la combinación)
	
	for (int i=0; i<combinaciones; i++){//reccoremos todas las combinaciones para analizar cuáles cumplen con lo pide el problema
		carga_binaria(i,cromosoma,N);//para convertir la combinación que está en base decimal a base 2 (binario)		
		//iniciamos el análisis de cada combinación
		peso_mochila=0;//inicializo el peso de la mochila para cada combinación
		ganancia_mochila=0;//inicializo la ganancia de la mochila para cada combinación
		
		for (int j=0; j<N; j++){//recorro todo el arreglo cromosoma[]
			if (cromosoma[j]==1) {
				peso_mochila = peso_mochila + productos[j][0];//acumulo el peso
				ganancia_mochila = ganancia_mochila + productos[j][1];//acumulo la ganancia
			}	
		}//hasta aquí tenemos el peso y la ganancia de la combinación
		
		//Una vez que hemos obtenido el peso, vamos a mostrar sólo los que se igualen al peso límite de la mochila (peso_maximo)
		if (peso_mochila<=peso_maximo && mayor_ganancia<=ganancia_mochila){//Añadimos la mayor_ganancia, por requerimiento del problema
			mayor_ganancia=ganancia_mochila;
			mejor_combinacion=i;
			mejor_peso_mochila=peso_mochila;
		}
	}
	//ahora vamos a mostrar al usuario la mejor solución = mayor ganancia
	//como mejor_combinacion está en base decimal, lo convertimos a binario
	carga_binaria(mejor_combinacion,cromosoma,N);			
	cout<<endl<<"Solucion: Combinación = "<<mejor_combinacion<<" Peso = "<<mejor_peso_mochila << " Ganancia = "<<mayor_ganancia<<endl;
	cout<<"Cromosoma: ";
	for (int j=0; j<N; j++){	
		cout<< cromosoma[j] << " ";//mostramos el cromosoma		
	}
	cout<<endl;
	cout<<"Pesos seleccionados: ";
	for (int j=0; j<N; j++){
		if (cromosoma[j]==1){	
		cout<< productos[j][0] << " ";//mostramos los paquetes seleccionados
		}		
	}
	cout<<endl;
	return 0;
}
