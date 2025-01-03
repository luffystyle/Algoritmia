#include <iostream>

using namespace std;

// Función para búsqueda secuencial
int bus_secuencial(int arr[], int largo, int k)//k es el parámetro que vamos a buscar
{
    int i, j, temp;
    i = 0;
    while (i < largo && arr[i] != k)//mientras estemos dentro del rango de elementos Y NO encontremos el parámetro, repetimos el bucle
    {
        i++;
    }
    if (i < largo)
        return (i); // Devuelve la posición donde se encontró el elemento
    else
        return (-1); // Devuelve -1 si el elemento no se encuentra en el arreglo
}

// Función de ordenamiento Burbuja
void ord_burbuja(int arr[], int largo)
{
    int i, j, temp;

    for (i = 0; i <= largo - 2; i++)
    {
        cout << endl;
        for (j = 0; j <= largo - 2 - i; j++)
        {
            if (arr[j + 1] < arr[j])//se comparan los adyacentes (o los "juntitos")
            {
            	//Si la posición j+1 es menor a la posición j, entonces intercambiamos.
                temp = arr[j];       
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
            cout << arr[j] << " "; // Muestra los elementos durante el proceso de ordenamiento
        }
    }
}

// Función de ordenamiento Selección
void ord_seleccion(int arr[], int largo)
{
    int i, j, minimo, temp;

    for (i = 0; i <= largo - 2; i++)
    {
        minimo = i;//asumimos como mínimo la posición "i"
        for (j = i + 1; j <= largo - 1; j++)//recorremos desde la siguiente posición (i+1) hasta todo el arreglo.
        {
            if (arr[j] < arr[minimo])//buscamos si hay un nuevo menor
                minimo = j; // si es que hay un nuevo menor, guardo la posición
        }
        //intercambiamos la posición "i" con la posición menor encontrada
        temp = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = temp; // Intercambia el elemento mínimo con el elemento actual
    }
}

int main()
{
    int cont, valor, n = 8;
    int arreglo[] = {3, 2, 1, 4, 2, 7, 9, 5};//conjunto de datos a utilizar

    cout << "Busqueda:";
    valor = bus_secuencial(arreglo, 8, 9);//enviamos el arreglo, n=cantidad de elementos y el parámetro a buscar.
    cout << valor << endl;

    cout << "Orden:";
    ord_burbuja(arreglo, n);//enviamos el arreglo y "n" que es la cantidad de elementos
    cout << endl;
    for (cont = 0; cont < n; cont++)
        cout << arreglo[cont] << " "; // mostramos el arreglo ordenado

    return (0);
}

