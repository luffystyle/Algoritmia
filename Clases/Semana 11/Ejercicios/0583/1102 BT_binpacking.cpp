#include <iostream>
using namespace std;

int empaca(int i, int n, int peso_mochila, int paquetes[]){
	//CASO BASE
	cout<<endl<<"Recursión, i="<< i<< ", n="<< n<< ", peso mochila="<< peso_mochila<<endl;
	if (i==n){//Cuando ya recorrimos todos los elementos
		cout<<"Se recorrio todos los elementos. RETORNA 0"<<endl;
		return 0;
	}
	if (peso_mochila<0){//cuando sobrepasó el peso de la mochila
		cout<<"Sobrepaso el peso de la mochila. RETORNA 0"<<endl;
		return 0;
	}
	
	if (paquetes[i]==peso_mochila){
	//Cuando el elemento a analizar es igual al peso restante de la mochila
		cout<<"paquetes[i="<<i<<"]="<<paquetes[i]<<" == peso_mochila="<<peso_mochila<<endl;
		cout<<"Retorna 1"<<endl;
		return 1;
	}
		
	
	//Aquí definimos el backtracking
	cout<<"BT, i="<< i<< ", n="<< n<< ", peso mochila="<< peso_mochila<<" paquete[i]="<<paquetes[i]<<endl;
	if (empaca(i+1, n, peso_mochila-paquetes[i], paquetes)){
	//aumentamos i para analizar los siguientes elementos Y
	//reducimos el peso de la mochila - el peso del paquete actual (paquetes[i])
		cout<<"Solución, paquete[i="<<i<<"]="<<paquetes[i]<<endl;
		cout<<"Retorna 1"<<endl;
		return 1;
	}
	else{//Aquí hacemos BT, mantemos el peso recibido y analizamos con el siguiente elemento
		cout<<"Retrocedemos"<<endl;
		return empaca(i+1, n, peso_mochila, paquetes);	
	}
}

int main(){
	int paquetes[]={1,4,5,7};//Arreglo que tiene los pesos de los paquetes
	int n=4;//cantidad de elementos del arreglo
	int peso_mochila=12;//capacidad de la mochila
	
	if (empaca(0,n,peso_mochila,paquetes))
		cout<<"Hay solución"<<endl;
	else
		cout<<"No hay solución"<<endl;
	
	return 0;
}
