/*
 * Examen 2 (2021-1), pregunta 3a
 * Desarrollado por Johan Baldeón
 */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_LEN = 12;

//Función para verificar si la solución actual es válida
int es_valido(int N, int solucion[], int paso, int digitos[]) {
    int i, digito_marcado = 0, contador_digitos = 1;
    int contador = 1, num_aux;

    //Verificamos si el primer dígito es 0, solucion[] iniciará con 1 cuando es una IP válida
    if (solucion[0] == 0)
        return 0;

    int j;
    for (i = 1; i <= paso; i++) {
        //Comprobamos si el dígito actual es diferente al anterior
        if (solucion[i] != solucion[i - 1]) {//se trata de otro grupo de números de la IP
            contador++;

            //Verificamos la cantidad de dígitos consecutivos y la cantidad total
            if (contador_digitos > 3 || contador > 4)
			//contador es para la # de grupos de números A.B.C.D
			//contador_digitos para la # de dígitos en cada grupo.
                return 0;

            num_aux = 0;

            //Calculamos el valor numérico de la secuencia de dígitos
            for (j = contador_digitos - 1; j >= 0; j--)
                num_aux += digitos[i - (j + 1)] * pow(10, j);

            //Verificamos las restricciones, para que sean números válidos
            if (num_aux > 255 || (contador_digitos == 2 && num_aux < 10) || (contador_digitos == 3 && num_aux < 100)) {
                return 0;
            }

            contador_digitos = 1;//Reiniciamos el contador de dígitos consecutivos, es porque ya armamos un grupo de números para la IP A.B.C.D
        } else
            contador_digitos++; //Incrementamos el contador de dígitos consecutivos, seguimos armando el grupo de números
    }

    num_aux = 0;

    //Calculamos el valor numérico de la última secuencia de dígitos
    for (j = contador_digitos - 1; j >= 0; j--)
        num_aux += digitos[i - (j + 1)] * pow(10, j);

    //Verificamos las restricciones para la última secuencia de dígitos
    if (num_aux > 255 || (contador_digitos == 2 && num_aux < 10) || (contador_digitos == 3 && num_aux < 100)) {
        return 0;
    }

    //Al estar al final de la supuesta IP, Verificamos las condiciones finales para la validez de TODA la solución
    if ((paso == N - 1 && contador != 4) || (paso < N - 1 && contador > 4) || contador_digitos > 3)
        return 0; //No es válido
    else
        return 1; //Es válido. Recién puedo indicar que la IP es válida.
}

// Función para imprimir la solución actual
void imprimir_solucion(int N, int solucion[], int digitos[]) {
    int i = 0;
    
    for (i=0;i<N;i++)
    	cout<<solucion[i]<<" ";
    cout<<endl;
    
	i = 0;
    cout << digitos[i];
    for (i = 1; i < N; i++)
        if (solucion[i] != solucion[i - 1]) {
            cout << ".";
            cout << digitos[i];
        } else
            cout << digitos[i];
    cout << endl;
}

//Función recursiva para obtener todas las posibles direcciones IP
void obtener_IPs_rec(int N, int solucion[], int paso, int digitos[]) {
    int i = 0;

    //Verificamos si se alcanzó la longitud N y, en ese caso, imprime la solución
    if (paso == N) {
        imprimir_solucion(N, solucion, digitos);
        return;
    }

    do {
        //Asignamos el valor actual de i a la posición de paso en la solución
        solucion[paso] = i;

        //Si la solución es válida, realiza la llamada recursiva para el siguiente paso
        if (es_valido(N, solucion, paso, digitos)) {
            obtener_IPs_rec(N, solucion, paso + 1, digitos);
        }

        //Incrementamos i para probar el siguiente valor
        i++;

    //Continuamos el bucle hasta que se alcance un 1 en la posición actual
    } while (solucion[paso] != 1);

    //Desmarcamos la posición actual en la solución
    solucion[paso] = -1;
}


int main() {
    //Cadena de entrada
    char *datos = new char[MAX_LEN + 1];
    
    cout << "Ingrese una cadena de solo digitos: ";
    strcpy(datos, "25525511169");
    //cin >> datos;

    int i;
    int N = strlen(datos);

    if (N <= MAX_LEN) {
        //Memoria para las soluciones y los dígitos
        int *solucion = new int[N];
        int *digitos = new int[N];

        //Inicializamos dígitos y soluciones
        for (i = 0; i < N; i++) {
            digitos[i] = datos[i] - '0';
            solucion[i] = -1;
        }
        cout << "Esta es la solucion: " ;
        for (i=0;i<N;i++) cout <<solucion[i]<<" ";
    	cout<<endl;
        cout << "Esta es la digitos: " ;
        for (i=0;i<N;i++) cout <<digitos[i]<<" ";
        cout<<endl;


        obtener_IPs_rec(N, solucion, 0, digitos);

        //Liberamos memoria
        delete[] solucion;
        delete[] digitos;
    } else {
        cout << "No se pueden obtener direcciones por ser una cadena muy larga." << std::endl;
    }

    //Liberamos la memoria
    delete[] datos;
    return 0;
}

