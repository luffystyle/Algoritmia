#include <iostream>
#define ELEM 4
#define W 5

using namespace std;

int max(int num1, int num2){
	if (num1>num2)
		return num1;
	else
		return num2;
}

int imprime_matriz(int V[ELEM+1][W+1]){
	for (int i=0;i<ELEM+1;i++){
		for (int j=0;j<W+1;j++)
	 		cout<<V[i][j]<< " ";
	 	cout<<endl;
	}
	cout<<endl;
}

void llena_mochila(int pesos[], int valores[], int V[ELEM+1][W+1]){
	int i,j;
	//CASOS DE PARTIDA, necesarios para la consulta de anteriores resultados en V[][]
	//fila de 0 elementos
	for (j=0;j<W+1; j++)
		V[0][j]=0;
	
	//columna de capacidad 0
	for (i=0;i<ELEM+1; i++)
		V[i][0]=0;
		
	//LLenamos nuestra matriz de resultados V[][]
	for(j=1;j<W+1; j++){
		for(i=1;i<ELEM+1; i++){
			//Según fórmula de la mochila para PD
			//Primero verificamos si podemos o no tomar el elemento en análisis: j- w(i) >= 0
			if (j-pesos[i-1]>=0){//TOMAMOS EL ELEMENTO
				//Analizar qué V[][] me conviene
				//el V sin considerar el elemento o el V considerando el elemento
				V[i][j]=max( V[i-1][j] , valores[i-1] + V[i-1][j-pesos[i-1]] );
			}else{//NO TOMAMOS EL ELEMENTO
				V[i][j]=V[i-1][j];
			}
		}
	}
}

int main(){
	int pesos[ELEM]={2,1,3,2};
	int valores[ELEM]={12,10,20,15};
	
	int V[ELEM+1][W+1];//matriz de resultados para PD
	
	llena_mochila(pesos, valores, V);
	
	cout<<"Máximo valor es: "<<V[ELEM][W]<<endl;
	
	cout<<"Matriz de resultados"<<endl;
	imprime_matriz(V);
	return 0;
}
