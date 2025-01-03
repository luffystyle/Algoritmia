/*
 * Examen 2 (2021-1), pregunta 3a
 * Desarrollado por Johan Balde�n
 */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_LEN = 12;

//Funci�n para verificar si la soluci�n actual es v�lida
int es_valido(int N, int solucion[], int paso, int digitos[]) {
    int i, digito_marcado = 0, contador_digitos = 1;
    int contador = 1, num_aux;

    //Verificamos si el primer d�gito es 0, solucion[] iniciar� con 1 cuando es una IP v�lida
    if (solucion[0] == 0)
        return 0;

    int j;
    for (i = 1; i <= paso; i++) {
        //Comprobamos si el d�gito actual es diferente al anterior
        if (solucion[i] != solucion[i - 1]) {//se trata de otro grupo de n�meros de la IP
            contador++;

            //Verificamos la cantidad de d�gitos consecutivos y la cantidad total
            if (contador_digitos > 3 || contador > 4)
			//contador es para la # de grupos de n�meros A.B.C.D
			//contador_digitos para la # de d�gitos en cada grupo.
                return 0;

            num_aux = 0;

            //Calculamos el valor num�rico de la secuencia de d�gitos
            for (j = contador_digitos - 1; j >= 0; j--)
                num_aux += digitos[i - (j + 1)] * pow(10, j);

            //Verificamos las restricciones, para que sean n�meros v�lidos
            if (num_aux > 255 || (contador_digitos == 2 && num_aux < 10) || (contador_digitos == 3 && num_aux < 100)) {
                return 0;
            }

            contador_digitos = 1;//Reiniciamos el contador de d�gitos consecutivos, es porque ya armamos un grupo de n�meros para la IP A.B.C.D
        } else
            contador_digitos++; //Incrementamos el contador de d�gitos consecutivos, seguimos armando el grupo de n�meros
    }

    num_aux = 0;

    //Calculamos el valor num�rico de la �ltima secuencia de d�gitos
    for (j = contador_digitos - 1; j >= 0; j--)
        num_aux += digitos[i - (j + 1)] * pow(10, j);

    //Verificamos las restricciones para la �ltima secuencia de d�gitos
    if (num_aux > 255 || (contador_digitos == 2 && num_aux < 10) || (contador_digitos == 3 && num_aux < 100)) {
        return 0;
    }

    //Al estar al final de la supuesta IP, Verificamos las condiciones finales para la validez de TODA la soluci�n
    if ((paso == N - 1 && contador != 4) || (paso < N - 1 && contador > 4) || contador_digitos > 3)
        return 0; //No es v�lido
    else
        return 1; //Es v�lido. Reci�n puedo indicar que la IP es v�lida.
}

// Funci�n para imprimir la soluci�n actual
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

//Funci�n recursiva para obtener todas las posibles direcciones IP
void obtener_IPs_rec(int N, int solucion[], int paso, int digitos[]) {
    int i = 0;

    //Verificamos si se alcanz� la longitud N y, en ese caso, imprime la soluci�n
    if (paso == N) {
        imprimir_solucion(N, solucion, digitos);
        return;
    }

    do {
        //Asignamos el valor actual de i a la posici�n de paso en la soluci�n
        solucion[paso] = i;

        //Si la soluci�n es v�lida, realiza la llamada recursiva para el siguiente paso
        if (es_valido(N, solucion, paso, digitos)) {
            obtener_IPs_rec(N, solucion, paso + 1, digitos);
        }

        //Incrementamos i para probar el siguiente valor
        i++;

    //Continuamos el bucle hasta que se alcance un 1 en la posici�n actual
    } while (solucion[paso] != 1);

    //Desmarcamos la posici�n actual en la soluci�n
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
        //Memoria para las soluciones y los d�gitos
        int *solucion = new int[N];
        int *digitos = new int[N];

        //Inicializamos d�gitos y soluciones
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

