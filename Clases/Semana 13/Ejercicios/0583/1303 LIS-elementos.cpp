#include <iostream>
#define MAX 8
using namespace std;

int LIS[MAX];//Longitud de la subsecuencia creciente

int resuelveLIS(int X[])
{
	int i, j;
	int maxLIS=1; //asumo que mi m�ximo ser� al menor tomar 1 elemento de la secuencia.
	
	for (i=0;i<MAX;i++)
	{
		LIS[i]=1;//El elemento X[i] se considera dentro de la subsecuencia.
		for (j=0; j<i; j++)
		{
			if (X[i]>X[j] && LIS[j]+1> LIS[i]) //X[i]>X[j], verifico si puedo a�adir
											   //OJO: por validar:
											   //LIS[j]+1> LIS[i], verifico si me conviene a�adir
			{
				LIS[i]= LIS[j] + 1; //LIS[j] tiene la longitud de la subsecuencia creciente hasta la posici�n j
			}
		}
		if (LIS[i]>maxLIS)
			maxLIS=LIS[i]; //he hallado un nuevo maximo longitud de la subsecuencia creciente.
	}
	//Aqu� tambi�n podr�a ir el mostrar los elementos de la LIS	
	return maxLIS;
}

int main()
{
	//int n=8; reemplazado por la variable global MAX
	int X[MAX]={-7,10,0,1,3,8,8,1};
	
	int lis= resuelveLIS(X);
	cout << "LIS: : "<< lis << endl;
	
	for (int z=0;z<MAX;z++)
		cout << LIS[z]<< " ";
		
	//Para mostrar los elementos de la LIS:
	//En la variable "lis" tenemos la longitud de la subsecuencia creciente m�s larga
	//En LIS[] tenemos las longitudes de subsecuencia creciente m�s larga hasta la pos "i"
	
	// lis = 4
	//  X[]={-7,10,0, 1, 3, 8, 8, 1};
	//LIS[]={1, 2, 2, 3, 4, 5, 5, 2}
	cout<<endl;
	for (int i=MAX-1; i>=0;i--){//Recorremos el arreglo X[] del �ltimo al inicio
		if (lis==LIS[i]){
			cout<<X[i]<<" ";
			lis--;	
		}
	}
	
	return 0;
}
