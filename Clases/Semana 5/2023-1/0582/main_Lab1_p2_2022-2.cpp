#include <iostream>
#include <cmath>
#define N 10

using namespace std;

void ordenar(char palabra[N],int sizePalabra){
	char aux;
	for (int i=0; i<sizePalabra; i++){
		for (int j=0; j<sizePalabra-1;j++){
			if (palabra[j]>palabra[j+1]){
				aux = palabra[j];
				palabra[j] = palabra[j+1];
				palabra[j+1] = aux;
 			}
		}
	}
}

int compara(char palabra[N],char palabraAux[N],int sizePalabra){
	int sonIguales=1;
	for (int i=0; i<sizePalabra; i++){
		if (palabra[i]!=palabraAux[i]){
			sonIguales = 0;
			break;
		}
	}
	return sonIguales;
}

void cargaBin(int num,int cromo[N],int size){
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

void imprimeSolucion(int num,char paquete[N],int size){
	int cromo[N];
	cargaBin(num,cromo,size);
	cout << "Una posible solucion: ";
	for (int j=0; j<size; j++){
		if (cromo[j]==1){
			cout << j+1 << " ";
		}
	}
	cout << endl;
}

int main(){
	/*La parte a*/
	char paquete[N], palabra[N], palabraAux[N];
	int sizePalabra, cromo[N], haySolucion=0, k, cantidadUnos, sonIguales;
	int combinaciones;
	cout << "Ingrese las letras del paquete: ";
	cin >> paquete;
	cout << "Ingrese la palabra: ";
	cin >> palabra;
	cout << "Ingrese el tamaño de la palabra: ";
	cin >> sizePalabra;
	ordenar(palabra,sizePalabra);
	/*La parte b*/
	combinaciones = pow(2,N);
	for (int i=0; i<combinaciones; i++){
		cargaBin(i,cromo,N);
		cantidadUnos = 0;
		for (int j=0; j<N; j++){
			if (cromo[j]==1){
				cantidadUnos++;	
			}
		}
		if (cantidadUnos==sizePalabra){
			k = 0;
			for (int j=0; j<N; j++){
				if (cromo[j]==1){
					palabraAux[k] = paquete[j];
					k++;	
				}
			}
			ordenar(palabraAux,sizePalabra);
			sonIguales = compara(palabra,palabraAux,sizePalabra);
			if (sonIguales){
				imprimeSolucion(i,paquete,N);
				haySolucion = 1;
				//break; /*Para la parte C, le quitas el break*/
			}
		}
	}
	if (!haySolucion){
		cout << "No se encontró una solución";
	}
	return 0;
}
