#include <iostream>
#define MAX 10
using namespace std;

int lista[MAX];//Arreglo para almacenar los elementos que forman parte de una soluci�n
int y=0;//indice para lista[]
int num_soluciones=0; //para contar las soluciones encontradas

int empaca(int i, int n, int peso_mochila, int paquetes[], int ubicacion[]){
	//CASO BASE
	if (i==n){//Cuando ya recorrimos todos los elementos
		return 0;
	}
	if (peso_mochila<0){//cuando sobrepas� el peso de la mochila
		return 0;
	}
	
	if (paquetes[i]==peso_mochila){
	//Cuando el elemento a analizar es igual al peso restante de la mochila, es decir SE CONSIGUI� UNA SOLUCI�N
		
		lista[y]=paquetes[i];//"guardamos" el paquete en lista[], que es el �ltimo de la soluci�n encontrada.
		ubicacion[i]=1;//activamos el elemento para luego mostrar su ubicaci�n
		
		//Al llegar aqu�, tenemos la soluci�n, entonces la muestro
		int k;//indice para recorrer el resultado
		
		//Resultado 1: 7k 9k 7k Ubicaciones: IA1 IB1 DB2
		cout<<endl<<"Resultado: ";
		for (k=0;k<=y;k++)
			cout<< lista[k] <<" ";
		cout<<"    Ubicaciones: ";
		//OJO: Tener cuidado con c�mo se gestionan las ubicaciones
		for (k=0;k<n;k++){
			if (ubicacion[k]==1){
				if (k%4==0)
					cout<<" IA" << k/4 +1;
				if (k%4==1)
					cout<<" IB" << k/4 +1;
				if (k%4==2)
					cout<<" DA" << k/4 +1;
				if (k%4==3)
					cout<<" DB" << k/4 +1;
			}
		}
		cout<<endl;
		num_soluciones++;//como encontr� una soluci�n, aumento el contador
	}	
	
	//Asumo que el elemento que se analiza en esta instancia ES PARTE DE LA SOLUCI�N
	//entonces la guardo
	lista[y]=paquetes[i];
	ubicacion[i]=1;//activamos el elemento para luego mostrar su ubicaci�n
	y++;
	
	//Aqu� definimos el backtracking
	if (empaca(i+1, n, peso_mochila-paquetes[i], paquetes,ubicacion)){
	//aumentamos i para analizar los siguientes elementos Y
	//reducimos el peso de la mochila - el peso del paquete actual (paquetes[i])
		return 1;
	}
	else{//Aqu� hacemos BT, mantemos el peso recibido y analizamos con el siguiente elemento
		y--;//con esta instrucci�n, retrocedo en mi soluci�n, por eso disminuyo "y" que es el indice de la soluci�n
			//que voy armando en lista[]
		ubicacion[i]=0;
		return empaca(i+1, n, peso_mochila, paquetes,ubicacion);	
	}
}

int main(){
	int paquetes[]={7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11};//Arreglo que tiene los pesos de los elementos
	int ubicacion[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//Arreglo que se activar� seg�n se seleccione o no el elemento en la Soluci�n
	int n=16;//cantidad de elementos del arreglo
	int peso_mochila=23;//capacidad de la mochila
	
	empaca(0,n,peso_mochila,paquetes,ubicacion);
	
	if (num_soluciones)
		cout<<"Hay soluci�n"<<endl;
	else
		cout<<"No hay soluci�n"<<endl;
	
	return 0;
}
