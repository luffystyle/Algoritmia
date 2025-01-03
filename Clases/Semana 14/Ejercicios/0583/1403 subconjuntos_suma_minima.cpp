#include <iostream>
using namespace std;

int subconjunto_suma_igual(int elementos[], int n){
	int i,j, aux;
	int suma=0;
	
	//PASO PREVIO: Ordenar el conjunto de elementos
	//Cualquier método de ordenamiento, salvo restricción del problema
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			if (elementos[i]>elementos[j]){
				//Intercambiamos
				aux=elementos[i];
				elementos[i]=elementos[j];
				elementos[j]=aux;
			}
	
	//Hallamos la suma de los elementos del conjunto
	for (i=0;i<n;i++)
		suma=suma+elementos[i];
	
	//Definimos nuestra matriz de resultados
	int pd[n+1][suma+1];
	
	//CASOS DE PARTIDA, necesarios para la consulta de anteriores resultados en pd[][]
	//fila de elemento = 0
	for (j=1;j<suma+1; j++)
		pd[0][j]=0;
	
	//columna de suma 0
	for (i=0;i<n+1; i++)
		pd[i][0]=1;
		
	//LLenamos nuestra matriz de resultados pd[][]
	for(j=1;j<suma+1; j++){
		for(i=1;i<n+1; i++){
			//Según fórmula para los subconjuntos en PD
			//Primero verificamos si podemos o no tomar el elemento en análisis: j- elemnto(i) >= 0
			if (j-elementos[i-1]>=0){//TOMAMOS EL ELEMENTO
				pd[i][j]=pd[i-1][j-elementos[i-1]];
			}else{//NO TOMAMOS EL ELEMENTO
				pd[i][j]=pd[i-1][j];
			}
			cout<<pd[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Una vez llena la matriz pd[][] voy a calcular si la suma de los 2 subconjuntos son iguales
	
	int diferencia;//si quiero que sean iguales las sumas de los subconjuntos => diferencia=0
	
	//Validamos que hemos llegado a una solución con todos los elementos
	int bandera_solucion=0;
	for (j=suma;j>=0;j--)
		if (pd[n][j]==1){
			diferencia=suma-j;
			if (diferencia==0)
				bandera_solucion=1;
		}
	
	//Validar si hay una solución en la mitad de la suma, 
	//ya que si hay soluciones en suma/2, puedo armar subconjuntos
	for (j=suma/2;j>=0;j--)
		if (pd[n][j]==1){
			//la suma de un subconjunto es j
			//la suma del otro subconjunto es suma-j
			//entonces, suma - j - (j) debe ser la mínima, en este caso igual a 1
			diferencia=suma-j-j;
			if (diferencia==1 && bandera_solucion)
				return 1;
			else
				return 0;
		}
	return 0;
}

int main(){
	int elementos[]={1,6,11,5};
	int n=4;
	
	cout<<"Resultado: "<<subconjunto_suma_igual(elementos, n)<<endl;
	
	return 0;
}
