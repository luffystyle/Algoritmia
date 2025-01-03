#include <iostream>
#define MAX 10

using namespace std;

int lista[MAX];//Arreglo donde voy armando mis soluciones, es donde pondr�/sacar� los controles/proyectos que voy analizando
int x = 0, y = 0;
int max_retorno = 0; // Variable para almacenar el retorno m�ximo
int mejor_solucion[MAX]; // Arreglo para almacenar el mejor conjunto de proyectos

// Funci�n que verifica si el elemento en la posici�n k cumple con las restricciones previas
int valida(int k, int n, int pre[][3], int pro[]) {
    int i, cont = 0;
    if (pre[k][0] == -1) {
        return 1; // Si no tiene predecesores, retorna 1
    }
    for (i = 0; i < 3; i++) {
        if (pre[k][i] == -1) {
            break; // Si se encuentra un predecesor igual a -1, se termina la b�squeda
        }
        for (int j = 0; j < n; j++) {
            if (pre[k][i] == lista[j]) {
                cont++; // Si el predecesor est� en la soluci�n, se incrementa el contador
                break; // Se encontr� el predecesor, se termina la b�squeda
            }
        }
    }
    if (cont == i) {
        return 1; // Si se encontraron todos los predecesores, cumple con las restricciones previas
    }
    return 0; // No cumple con las restricciones previas
}

// Funci�n recursiva que realiza el empaquetado de los elementos
void empaca(int i, int n, int peso, int p[], int pre[][3], int proy[], int retorno[]) {
    if (i == n || peso < 0)
        return; // Caso base: si se ha alcanzado el final del arreglo o el peso disponible es negativo, retorna

    if (p[i] == peso && valida(i, y, pre, proy)) {
        // Si el peso actual es igual al peso disponible y cumple con las restricciones previas
        lista[y] = proy[i]; // Se agrega el elemento a la lista de soluci�n
        int z;
        int retorno_total = 0; // Variable para almacenar el retorno total de la soluci�n actual
        for (z = 0; z <= y; z++) {
            cout << "P" << lista[z] + 1<< " ";
            retorno_total += retorno[lista[z]]; // Calcula el retorno total sumando los retornos individuales de los proyectos
        }
        cout << " - Retorno de inversion: " << retorno_total << endl;

        if (retorno_total > max_retorno) {
            max_retorno = retorno_total; // Actualiza el m�ximo retorno de inversi�n
            for (z = 0; z <= y; z++) {
                mejor_solucion[z] = lista[z]; // Almacena el conjunto de proyectos con el m�ximo retorno de inversi�n
            }
            mejor_solucion[z] = -1; // Marca el final del conjunto de proyectos con -1
        }
    }

    lista[y++] = proy[i]; // Se agrega el elemento a la lista de soluci�n
    if (valida(i, y, pre, proy)) {
        empaca(i + 1, n, peso - p[i], p, pre, proy, retorno); // Llamada recursiva con el peso actual reducido por el peso del proyecto
    }
    y--; // Retrocede en el arreglo de soluci�n (backtracking)
    empaca(i + 1, n, peso, p, pre, proy, retorno); // Llamada recursiva con el mismo peso actual
}

int main() {
    int proye[] = {0, 1, 2, 3, 4, 5, 6, 7}; // Arreglo de los elementos a empaquetar
    int costo[] = {8, 2, 10, 10, 5, 1, 5, 5}; // Arreglo de los pesos de los elementos
    int prede[][3] = {
        {-1, -1, -1},   // Proyecto 0 no tiene predecesores
        {-1, -1, -1},   // Proyecto 1 no tiene predecesores
        {0, 1, -1},     // Proyecto 2 tiene predecesores 0 y 1
        {-1, -1, -1},   // Proyecto 3 no tiene predecesores
        {-1, -1, -1},   // Proyecto 4 no tiene predecesores
        {1, -1, -1},    // Proyecto 5 tiene predecesores 1
        {5, -1, -1},    // Proyecto 6 tiene predecesores 5
        {5, -1, -1}     // Proyecto 7 tiene predecesores 5
    };
    int retorno[] = {15, 8, 30, 15, 8, 5, 12, 15}; // Arreglo de retorno de inversi�n de cada proyecto
    int n = 8; // Tama�o de los arreglos
    int presupuesto = 25; // Peso disponible

    empaca(0, n, presupuesto, costo, prede, proye, retorno); // Llamada a la funci�n de empaquetado

    cout << "Conjunto de proyectos con mayor retorno de inversion: ";
    for (int i = 0; mejor_solucion[i] != -1; i++) {
        cout << "P" << mejor_solucion[i] << " ";
    }
    cout << "- Retorno de inversion: " << max_retorno << endl;

    return 0;
}

