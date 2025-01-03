#include <iostream>
using namespace std;

int coinrow(int M[], int n){
	//Lo primero es crea la Tabla de Resultado
	int F[n+1];
	
	//CASOS DE PARTIDA:
	F[0]=0;
	F[1]=M[0];
	
	//Genero mi tabla de resultados:
	int i;
	for (i=2;i<=n;i++){
		int num1, num2;
		num1=M[i-1]+F[i-2];//Cn + F[n-2]
		num2=F[i-1];//F[n-1]
		if (num1>num2)//Max={Cn + F[n-2] , F[n-1]}
			F[i]=num1;
		else
			F[i]=num2;
	}
	
	cout<<"Tabla de resultados: ";
	for (i=0;i<=n;i++){
		cout<<F[i]<<" ";
	}
	cout<<endl;
	
	return F[n];//El valor máximo solicitado se encuentra en el último elemento de F[]


}

int main(){
	int n=6;
	int M[n]={5,1,2,10,6,2};
	
	int valor=coinrow(M,n);
	cout<<"Maximo valor = "<<valor;
	
	return 0;
}
