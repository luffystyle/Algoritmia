#include <iostream>
#define MAX 10
using namespace std;

int lista[MAX];//Arreglo para almacenar los elementos que forman parte de una soluci�n
int y=0;//indice para lista[]
int num_soluciones=0; //para contar las soluciones encontradas

int empaca(int i, int n, int peso_mochila, int paquetes[]){
	//CASO BASE
	cout<<endl<<"Recursion, i="<< i<< ", n="<< n<< ", peso mochila="<< peso_mochila<<endl;
	if (i==n){//Cuando ya recorrimos todos los elementos
		cout<<"Se recorrio todos los elementos. RETORNA 0"<<endl;
		return 0;
	}
	if (peso_mochila<0){//cuando sobrepas� el peso de la mochila
		cout<<"Sobrepaso el peso de la mochila. RETORNA 0"<<endl;
		return 0;
	}
	
	if (paquetes[i]==peso_mochila){
	//Cuando el elemento a analizar es igual al peso restante de la mochila, es decir SE CONSIGUI� UNA SOLUCI�N
		cout<<"paquetes[i="<<i<<"]="<<paquetes[i]<<" == peso_mochila="<<peso_mochila<<endl;
		cout<<"Retorna 1"<<endl;
		
		lista[y]=paquetes[i];//"guardamos" el paquete en lista[], que es el �ltimo de la soluci�n encontrada.
		//Al llegar aqu�, tenemos la soluci�n, entonces la muestro
		int k;//indice para recorrer el resultado
		cout<<endl<<"=============== Resultado: ";
		for (k=0;k<=y;k++)
			cout<< lista[k] <<" ";
		cout<<endl;
		
		num_soluciones++;//como encontr� una soluci�n, aumento el contador
	}	
	
	//Asumo que el elemento que se analiza en esta instancia ES PARTE DE LA SOLUCI�N
	//entonces la guardo
	lista[y]=paquetes[i];
	y++;
	
	//Aqu� definimos el backtracking
	cout<<"BT, i="<< i<< ", n="<< n<< ", peso mochila="<< peso_mochila<<" paquete[i]="<<paquetes[i]<<endl;
	if (empaca(i+1, n, peso_mochila-paquetes[i], paquetes)){
	//aumentamos i para analizar los siguientes elementos Y
	//reducimos el peso de la mochila - el peso del paquete actual (paquetes[i])
		cout<<"Soluci�n, paquete[i="<<i<<"]="<<paquetes[i]<<endl;
		cout<<"Retorna 1"<<endl;
		return 1;
	}
	else{//Aqu� hacemos BT, mantemos el peso recibido y analizamos con el siguiente elemento
		cout<<"Retrocedemos"<<endl;
		y--;//con esta instrucci�n, retrocedo en mi soluci�n, por eso disminuyo "y" que es el indice de la soluci�n
			//que voy armando en lista[]
		return empaca(i+1, n, peso_mochila, paquetes);	
	}
}

int main(){
	int paquetes[]={1,4,5,7};//Arreglo que tiene los pesos de los paquetes
	int n=4;//cantidad de elementos del arreglo
	int peso_mochila=12;//capacidad de la mochila
	
	empaca(0,n,peso_mochila,paquetes);
	
	if (num_soluciones)
		cout<<"Hay soluci�n"<<endl;
	else
		cout<<"No hay soluci�n"<<endl;
	
	return 0;
}
