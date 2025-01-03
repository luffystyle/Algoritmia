#include <limits.h>
#include <iostream>

using namespace std;

int minimo(int a, int b) {
    if (a < b) return a;
    return b;
}

int maximo(int a, int b) {
    if (a > b) return a;
    return b;
}

int suma(int arr[], int desde, int hasta) {
    int total = 0;
    for (int i = desde; i <= hasta; i++)
        total += arr[i];
    return total;
}

int maxTareas(int arr[], int n, int k) {
    //Ordenamos el arreglo en forma ascendente
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                //Intercambiamos
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    int dp[k + 1][n + 1];

    //Inicializamos la primera fila de la matriz dp
    //Cada elemento dp[1][i] contiene la suma de los primeros 'i' elementos del arreglo
    for (int i = 1; i <= n; i++)
        dp[1][i] = suma(arr, 0, i - 1);

    //Inicializamos la primera columna de la matriz dp
    //Cada elemento dp[i][1] contiene el primer elemento del arreglo
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];

	//Llenamos el resto de la matriz dp utilizando programación dinámica
	for (int i = 2; i <= k; i++) {
		cout<<"i = "<<i<<endl;
	    for (int j = 2; j <= n; j++) {
	        cout<<"    j = "<<j<<endl;
			//variable max con el valor máximo posible
	        int max = 999999;
	
	        //Encontramos el mínimo entre los máximos parciales anteriores
	        for (int p = 1; p <= j; p++){
				cout<<"        p = "<<p<<endl;
	        	int num1, num2;
	            // Actualizamos max con el mínimo entre su valor actual, el máximo en dp[i-1][p],
	            // y la suma de los elementos en arr desde la posición p hasta j-1
	            num1=dp[i - 1][p];
	            num2=suma(arr, p, j - 1);
	            cout<<"        minimo ( max="<<max<<" , maximo ( "<<num1<<" , "<<num2<<" ) )"<<endl;
	            max = minimo(max, maximo(num1, num2));
			}
			cout<<"    max = "<<max<<endl<<endl;
	        //"Guardamos" el valor mínimo encontrado a la posición (i, j) de la matriz dp
	        dp[i][j] = max;
	    }
	}


    //Mostramos la matriz dp
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    //Retornamos el resultado final, el cual se encuentra en la esquina inferior derecha de la matriz dp
    return dp[k][n];
}


int main() {
    int arr[] = {15, 30, 60, 45, 10};
    //int arr[] = {10, 15, 30, 45, 60};
    int n = 5;
    int k = 2;

    cout << "n="<<n <<" Tiempo máximo es: " << maxTareas(arr, n, k) << endl;
    return 0;
}

