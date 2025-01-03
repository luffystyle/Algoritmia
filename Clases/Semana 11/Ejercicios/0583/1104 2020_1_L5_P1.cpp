#include <iostream>
#define MAX 10
using namespace std;

int lista[MAX];//Arreglo para almacenar los elementos que forman parte de una solución
int y=0;//indice para lista[]
int num_soluciones=0; //para contar las soluciones encontradas


int valida(int i, int predecesores[]){
	if (predecesores[i]==-1)//Si el proyecto en análisis (i) no tiene predecesores, entonces puede seleccionarse
		return 1;
	//Si llegamos a este punto, el proyecto (i) tiene predecesores, entonces
	//Recorro el arreglo lista[], que tiene los proyectos que he seleccionado hasta el momento,
	//Para verificar que puedo tomar el proyecto (i)
	for (int k=0; k<=y;k++){
		if (predecesores[i]==lista[k])
			contador++;
	}
	if (contador)
		return 1;
	else
		return 0;
}
int empaca(int i, int n, int peso_mochila, int paquetes[], int predecesores[]){
	//CASO BASE
	cout<<endl<<"Recursion, i="<< i<< ", n="<< n<< ", peso mochila="<< peso_mochila<<endl;
	if (i==n){//Cuando ya recorrimos todos los elementos
		cout<<"Se recorrio todos los elementos. RETORNA 0"<<endl;
		return 0;
	}
	if (peso_mochila<0){//cuando sobrepasó el peso de la mochila
		cout<<"Sobrepaso el peso de la mochila. RETORNA 0"<<endl;
		return 0;
	}
	
	if (paquetes[i]==peso_mochila){
	//Cuando el elemento a analizar es igual al peso restante de la mochila, es decir SE CONSIGUIÓ UNA SOLUCIÓN
		cout<<"paquetes[i="<<i<<"]="<<paquetes[i]<<" == peso_mochila="<<peso_mochila<<endl;
		cout<<"Retorna 1"<<endl;
		
		lista[y]=paquetes[i];//"guardamos" el paquete en lista[], que es el último de la solución encontrada.
		//Al llegar aquí, tenemos la solución, entonces la muestro
		int k;//indice para recorrer el resultado
		cout<<endl<<"=============== Resultado: ";
		for (k=0;k<=y;k++)
			cout<< lista[k] <<" ";
		cout<<endl;
		
		num_soluciones++;//como encontré una solución, aumento el contador
	}	
	
	//Asumo que el elemento que se analiza en esta instancia ES PARTE DE LA SOLUCIÓN
	//entonces la guardo
	lista[y]=paquetes[i];
	y++;
	
	//Aquí definimos el backtracking
	cout<<"BT, i="<< i<< ", n="<< n<< ", peso mochila="<< peso_mochila<<" paquete[i]="<<paquetes[i]<<endl;
	
	//******************************
	//TAREA: para verificar que valida() y empaca() están bien definidos para encontrar una SOLUCION
	//******************************
	
	if (valida(i,predecesores) && empaca(i+1, n, peso_mochila-paquetes[i], paquetes)){
	//Verificamos si el proyecto que estoy analizando puedo incluirlo o no
	
	//aumentamos i para analizar los siguientes elementos Y
	//reducimos el peso de la mochila - el peso del paquete actual (paquetes[i])
		cout<<"Solución, paquete[i="<<i<<"]="<<paquetes[i]<<endl;
		cout<<"Retorna 1"<<endl;
		return 1;
	}
	else{//Aquí hacemos BT, mantemos el peso recibido y analizamos con el siguiente elemento
		cout<<"Retrocedemos"<<endl;
		y--;//con esta instrucción, retrocedo en mi solución, por eso disminuyo "y" que es el indice de la solución
			//que voy armando en lista[]
		return empaca(i+1, n, peso_mochila, paquetes);	
	}
}

int main(){
	int costo[]={7,1,3,2,4,5,1,5};//Arreglo que tiene los costos de los proyectos
	int predecesores[]={-1,-1,1,-1,2,4,-1,6};//Arrelo que tiene los predecesores
	int n=8;//cantidad de elementos del arreglo
	int presupuesto=10;//capacidad de la mochila
	
	empaca(0,n,presupuesto,costo,predecesores);
	
	if (num_soluciones)
		cout<<"Hay solución"<<endl;
	else
		cout<<"No hay solución"<<endl;
	
	return 0;
}
