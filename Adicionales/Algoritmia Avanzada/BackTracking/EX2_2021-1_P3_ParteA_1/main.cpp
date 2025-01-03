// Problema de direccion IP
// BackTracking
// Examen Final 2021-1, Pregunta 3 Parte A


#include <iostream>
#include <iomanip>
#include <cstring>
#define MAX_LONG 12

using namespace std;

int es_valido(int N, int solucion[], int paso, char digitos[]) {
    int i, j, digito_marcado = 0, contador_digitos = 1;
    int contador = 1, numAux;
    
    if(solucion[0] == 0) return 0;
    
}




void obtenerIPS_Recursivo(int paso, char datos[], int digitos[], int solucion[], int N) {
    
    int i;
    // caso de parada
    if( paso == N) return;
    
    while(1) { // usamos un while porque no sabemos hasta cuando vamos a seguir y luego vamos a hacer un BT
        solucion[paso] = i; // asignamos el valor actual de i a la posicion de paso en la solucion
        //if( es_valido(N, solucion, paso, digitos)) obtenerIPS_Recursivo(paso+1, datos, digitos, solucion, N);
        cout << solucion[paso] << " " ;
        i++;
        if(solucion[paso] != -1) break;
    }
    cout << endl;
}



int main(int argc, char** argv) {

    // creamos cadena de entrada
    // lo creamos con * porque es una cadena dinámica, porque no sabemos cuanto va a ser su longitud
    char *datos = new char[MAX_LONG + 1];
    cout << "Ingrese la dirección IP: " << endl;
    cin >> datos;


    int N = strlen(datos); // la longitud de la cadena que ingresamos(datos)
    int solucion[N];
    int digitos[N];
    
    if( N <= MAX_LONG) {
        // inicializamos los digitos en -1
        for(int i = 0; i<N; i++) {
            digitos[i] = datos[i] - '0';
            solucion[i] = -1;
        }
        for(int i = 0; i<N; i++) cout << solucion[i] << " ";
        cout << endl;
        for(int i = 0; i<N; i++) cout << digitos[i] << " ";    
        cout << endl;
        
        obtenerIPS_Recursivo(0, datos, digitos, solucion, N);
                
        
        cout << endl;
    } else {
        cout << "(No presenta resultados)" << endl;
    }

    return 0;
}

