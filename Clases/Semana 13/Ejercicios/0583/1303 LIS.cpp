//El código implementa el algoritmo para encontrar la Longest Increasing Subsequence (LIS), 
//que busca la subsecuencia más larga en una secuencia de números en la que los elementos 
//están en orden creciente.

#include <iostream>
using namespace std;

#define MAX 8

//Se utiliza un arreglo LIS para almacenar la longitud de la LIS hasta el índice correspondiente.
int LIS[MAX];

//La función solveLIS toma como argumento un arreglo de números X 
//y devuelve el tamaño de la LIS más larga en X.
int solveLIS(int X[]){
    int i, j;
    int maxLIS = 1;
    	
    //El bucle for externo itera sobre todos los elementos del arreglo X y se inicia con LIS en 1, 
	//ya que cada elemento es una LIS de longitud 1 en sí mismo.
    for (i = 0; i < MAX; i++){
        LIS[i] = 1;
        
        //El bucle for interno verifica si se puede añadir el elemento actual al LIS 
		//y si es beneficioso hacerlo. 
		//Si el elemento actual es mayor que el elemento en el índice anterior (X[i] > X[j])
		//y si añadir el elemento actual al LIS en j más 1 produce una longitud mayor 
		//que la LIS actual en i (LIS[j] + 1 > LIS[i]), 
		//se actualiza la longitud del LIS en i con el valor calculado.
        for (j = 0; j < i; j++)
        {
            // Verificar si puedo añadirme y si me conviene
            if (X[i] > X[j] && LIS[j] + 1 > LIS[i])
			//La primera condición: es creciente?
			//La segunda condición: genera una subsecuencia más larga
			//ENTONCES: encontré una nueva subsecuencia más larg
            {    
                LIS[i] = LIS[j] + 1;
            }    
        }
        if (LIS[i] > maxLIS) maxLIS = LIS[i];
    }   
    //Después de completar los bucles for, 
	//el valor máximo en el arreglo LIS se considera como la LIS más larga y se devuelve.
    return maxLIS;
}


int main() {
	//En la función main, se crea un arreglo de ejemplo X 
	//y se llama a la función solveLIS pasando el arreglo.
    int X[MAX] = {-7, 10, 9, 2, 3, 8, 8, 1};
    int w;
    
    int lis = solveLIS(X);
    
    cout << "LIS= " << lis << endl;
    
    cout<< "Tabla de resultados: ";
    for(w = 0; w < MAX; w++)
        cout << LIS[w] << " ";
        
        
    cout << endl << "Elementos de la subsecuencia creciente más larga: ";
    for (w = MAX - 1; w >= 0; w--) {
        if (LIS[w] == lis) {
            cout << X[w] << " ";
            lis--;
        }
    }
    
    return 0;
}

