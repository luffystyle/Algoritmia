#include <iostream>
#include <math.h>
#define N 8 //porque son 8 herramientas

using namespace std;

void carga_binaria(int numero, int cromosoma[], int longitud_cromosoma){
	int i,aux;
	//inicializamos nuestro arreglo cromosoma
	for (i=0; i<longitud_cromosoma; i++){
		cromosoma[i]=0;
	}
	//utilizamos divisiones sucesivas para obtener el n�mero binario
	i=0;
	while (numero>0){
		aux=numero%2;
		numero=numero/2;
		cromosoma[i]=aux;
		i++;
	}
}

int main(){
	
	int maximo_tipo_herramientas;
	cout<<"Maximo (M) tipos de herramientas: ";
	cin>>maximo_tipo_herramientas;
	
	int presupuesto;
	cout<<"Presupuesto (P): ";
	cin>>presupuesto;
	
	int cantidad_tipos_herramientas=8;//Seg�n tabla del enunciado
	int herramientas[cantidad_tipos_herramientas][2]={{4,3}, {5,2}, {4,1}, {2,1}, {6,3}, {3,3}, {4,2},{1,4}};//datos de entrada
	
	int cromosoma[cantidad_tipos_herramientas];//arreglo para el cromosoma 2^8
	int precio,//para ir calculando el precio para cada combinaci�n
	cantidad_herramientas;//para ir calculando la cantidad de herramientas para cada combinaci�n
	
	int combinaciones; //para la cantidad de combinaciones

	//definimos la cantidad de combinaciones
	combinaciones=pow(2,cantidad_tipos_herramientas);//porque son 8 tipos de herramientas

	int mejor_combinacion=0, cantidad_tipo_herramientas=0, mayor_cantidad_herramientas=0; //variables para obtener la mejor soluci�n (peso y la combinaci�n)
	
	for (int i=0; i<combinaciones; i++){//reccoremos todas las combinaciones para analizar cu�les cumplen con lo pide el problema
		carga_binaria(i,cromosoma,N);//para convertir la combinaci�n que est� en base decimal a base 2 (binario)		
		//iniciamos el an�lisis de cada combinaci�n
		precio=0;//inicializo el precio para cada combinaci�n
		cantidad_herramientas=0;//inicializo la cantidad de herramientas para cada combinaci�n
		cantidad_tipo_herramientas=0;////inicializo la cantidad de tipos de herramientas para cada combinaci�n
		
		for (int j=0; j<N; j++){//recorro todo el arreglo cromosoma[]
			if (cromosoma[j]==1) {
				cantidad_tipo_herramientas++;
				precio = precio + (herramientas[j][0]*herramientas[j][1]);//acumulo el precio
				cantidad_herramientas = cantidad_herramientas + herramientas[j][1];//acumulo la cantidad de herramientas
			}	
		}//hasta aqu� tenemos el precio y la cantidad de herramientas de la combinaci�n
		
		//Una vez que hemos obtenido el precio, vamos a mostrar s�lo los que se igualen al presupuesto (presupuesto)
		if (precio<=presupuesto && cantidad_tipo_herramientas<=maximo_tipo_herramientas && mayor_cantidad_herramientas<=cantidad_herramientas){//A�adimos la mayor_ganancia, por requerimiento del problema
			mejor_combinacion=i;
			mayor_cantidad_herramientas=cantidad_herramientas;
		}
	}
	
	//ahora vamos a mostrar al usuario la mejor soluci�n = mayor ganancia
	//como mejor_combinacion est� en base decimal, lo convertimos a binario
	carga_binaria(mejor_combinacion,cromosoma,N);			
	cout<<endl<<"Solucion: Combinaci�n = "<<mejor_combinacion<<" Cantidad de herramientas = "<<mayor_cantidad_herramientas <<endl;
	cout<<"Cromosoma: ";
	for (int j=0; j<N; j++){	
		cout<< cromosoma[j] << " ";//mostramos el cromosoma		
	}
	cout<<endl;
	precio=0;//Para hallar el precio de la mejor soluci�n
	cout<<"Pesos seleccionados: ";
	for (int j=0; j<N; j++){
		if (cromosoma[j]==1){
			cout << j+1 << " ";
			precio= precio + (herramientas[j][0]*herramientas[j][1]);
		}		
	}
	cout<<"Monto total: "<<precio<<endl;
	return 0;
}
