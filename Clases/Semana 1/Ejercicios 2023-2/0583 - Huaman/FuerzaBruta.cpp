#include <iostream>

using namespace std;

// Funci�n para b�squeda secuencial
int bus_secuencial(int arr[], int largo, int k)//k es el par�metro que vamos a buscar
{
    int i, j, temp;
    i = 0;
    while (i < largo && arr[i] != k)//mientras estemos dentro del rango de elementos Y NO encontremos el par�metro, repetimos el bucle
    {
        i++;
    }
    if (i < largo)
        return (i); // Devuelve la posici�n donde se encontr� el elemento
    else
        return (-1); // Devuelve -1 si el elemento no se encuentra en el arreglo
}

// Funci�n de ordenamiento Burbuja
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
            	//Si la posici�n j+1 es menor a la posici�n j, entonces intercambiamos.
                temp = arr[j];       
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
            cout << arr[j] << " "; // Muestra los elementos durante el proceso de ordenamiento
        }
    }
}

// Funci�n de ordenamiento Selecci�n
void ord_seleccion(int arr[], int largo)
{
    int i, j, minimo, temp;

    for (i = 0; i <= largo - 2; i++)
    {
        minimo = i;//asumimos como m�nimo la posici�n "i"
        for (j = i + 1; j <= largo - 1; j++)//recorremos desde la siguiente posici�n (i+1) hasta todo el arreglo.
        {
            if (arr[j] < arr[minimo])//buscamos si hay un nuevo menor
                minimo = j; // si es que hay un nuevo menor, guardo la posici�n
        }
        //intercambiamos la posici�n "i" con la posici�n menor encontrada
        temp = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = temp; // Intercambia el elemento m�nimo con el elemento actual
    }
}

int main()
{
    int cont, valor, n = 8;
    int arreglo[] = {3, 2, 1, 4, 2, 7, 9, 5};//conjunto de datos a utilizar

    cout << "Busqueda:";
    valor = bus_secuencial(arreglo, 8, 9);//enviamos el arreglo, n=cantidad de elementos y el par�metro a buscar.
    cout << valor << endl;

    cout << "Orden:";
    ord_burbuja(arreglo, n);//enviamos el arreglo y "n" que es la cantidad de elementos
    cout << endl;
    for (cont = 0; cont < n; cont++)
        cout << arreglo[cont] << " "; // mostramos el arreglo ordenado

    return (0);
}

