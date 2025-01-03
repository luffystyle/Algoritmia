#include <iostream>
#include <math.h>

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
	int i,j,k,l;
	int contador_productos;
	
	int cantidad_productos_bahia;//cada una tiene N productos (N<=10),
	cout << "N=";
	cin >>cantidad_productos_bahia;
	
	int divisiones_camion; //cuentan con M divisiones para transportar los productos,
	cout << "M=";
	cin >>divisiones_camion;
	
	int peso_maximo; //se sabe que un cami�n puede transportar una carga de C toneladas,
	cout << "C=";
	cin >>peso_maximo;
	
	int bahias[3][cantidad_productos_bahia];//Por enunciado: 
	//"El �rea de despacho cuenta con 3 bah�as o filas de despacho, cada una tiene N productos (N<=10)"
	
	//Solicitamos los datos al usuario
	for (i=0; i<3; i++){
		cout << "Bahia N� "<< i+1 << ": ";
		for (j=0; j<cantidad_productos_bahia;j++){
			cin >> bahias[i][j];
		}
	}
	
	//Manejaremos 1 cromosoma por cada bah�a. Tb se puede manejar 1 s�lo cromosoma. Depende del cliente	
	int cromosoma1[cantidad_productos_bahia];//arreglo para el cromosoma 2^N
	int cromosoma2[cantidad_productos_bahia];//arreglo para el cromosoma 2^N
	int cromosoma3[cantidad_productos_bahia];//arreglo para el cromosoma 2^N
	
	
	int peso_mochila;//para ir calculando el peso del camion para cada combinaci�n
	int combinaciones; //para la cantidad de combinaciones}

	//OJOOOOOOOOOOOOOO!!
	int mejor_peso_mochila=0, mejor_combinacion=0; //variables para obtener la mejor soluci�n (peso y la combinaci�n)
	
	//definimos la cantidad de combinaciones
	combinaciones=pow(2,cantidad_productos_bahia);//cantidad_productos_bahia
	
	//reccoremos todas las combinaciones para analizar cu�les cumplen con lo pide el problema
	//Son 3 cromosomas a recorrer, => son 3 iterativas (for)
	for (i=0; i<combinaciones; i++){//bahia1
		for (j=0; j<combinaciones; j++){//bahia2
			for (k=0; k<combinaciones; k++){//bahia3
				peso_mochila=0;//inicializo el peso del camion para cada combinaci�n
				contador_productos=0;//Inicializo la cantidad de productos que M�XIMO puede ser M (M divisiones para transportar los productos)
				
				//BAHIA 1
				carga_binaria(i,cromosoma1,cantidad_productos_bahia);//para convertir la combinaci�n que est� en base decimal a base 2 (binario)		
				//iniciamos el an�lisis de cada combinaci�n
				for (int l=0; l<cantidad_productos_bahia; l++){//recorro todo el arreglo cromosoma[]
					if (cromosoma1[l]==1) {
						peso_mochila = peso_mochila + bahias[0][l];//acumulo el peso
						contador_productos++;
					}
				}//hasta aqu� tenemos el peso de la combinaci�n
		
		
				//BAHIA 2
				carga_binaria(j,cromosoma2,cantidad_productos_bahia);//para convertir la combinaci�n que est� en base decimal a base 2 (binario)		
				//iniciamos el an�lisis de cada combinaci�n
				for (int l=0; l<cantidad_productos_bahia; l++){//recorro todo el arreglo cromosoma[]
					if (cromosoma2[l]==1) {
						peso_mochila = peso_mochila + bahias[1][l];//acumulo el peso
						contador_productos++;
					}
				}//hasta aqu� tenemos el peso de la combinaci�n
		
				//BAHIA 3
				carga_binaria(k,cromosoma3,cantidad_productos_bahia);//para convertir la combinaci�n que est� en base decimal a base 2 (binario)		
				//iniciamos el an�lisis de cada combinaci�n
				for (int l=0; l<cantidad_productos_bahia; l++){//recorro todo el arreglo cromosoma[]
					if (cromosoma3[l]==1) {
					peso_mochila = peso_mochila + bahias[2][l];//acumulo el peso
					contador_productos++;
					}
				}//hasta aqu� tenemos el peso de la combinaci�n
			
				//Analizamos si cada combinaci�n cumple con lo que nos pide el problema:
				//Queremos TODAS LAS SOLUCIONES
				if (peso_mochila==peso_maximo && contador_productos==divisiones_camion){
					//El peso tiene que ser IGUAL a C toneladas Y
					//la cantidad de productos tiene que ser IGUAL a M divisiones del cami�n
					cout<<"Solucion: " <<endl;
					
					cout<<"Bah�a 1: ";
					for (int l=0; l<cantidad_productos_bahia; l++){//recorro todo el arreglo cromosoma[]
						if (cromosoma1[l]==1) cout<<bahias[0][l]<<" ";//muestro el peso
					}
					cout<<endl;
					
					cout<<"Bah�a 2: ";
					for (int l=0; l<cantidad_productos_bahia; l++){//recorro todo el arreglo cromosoma[]
						if (cromosoma2[l]==1) cout<<bahias[1][l]<<" ";//muestro el peso
					}
					cout<<endl;
					
					cout<<"Bah�a 3: ";
					for (int l=0; l<cantidad_productos_bahia; l++){//recorro todo el arreglo cromosoma[]
						if (cromosoma3[l]==1) cout<<bahias[2][l]<<" ";//muestro el peso
					}
					cout<<endl;
				}
			}
		}
	}	
	return 0;
}
