// Problema de direccion IP
// BackTracking
// Examen Final 2021-1, Pregunta 3 Parte A

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#define MAX_LONG 12

using namespace std;


void imprimir_solucion( int digitos[], int N, int solucion[]) {
    int i;
    for( i = 0; i<N; i++) cout << solucion[i] << " ";
    cout << endl;
    i = 0;
    cout << digitos[i];
    for( i = 1; i<N; i++) {
        if(solucion[i] != solucion[i-1]) {
            cout << ".";
            cout << digitos[i];
        } else {
            cout << digitos[i];
        }
    }
    cout << endl;
}

// función para verificar si la solución ACTUAL es VÁLIDA
int es_valido( int paso, int N, int digitos[], int solucion[]) {
    
    // contador_digitos es el número de números de cada grupo A.B.C.D
    // contador es el número de grupos, máximo sería 4 porque es A, B, C y D
    int i, j, contador_digitos = 1, contador = 1, aux;
        
    if( solucion[0] == 0 ) return 0; // si el primer digito es 0, no hay solucion. Solo es válido si 
    
    for(i = 1; i <= paso; i++) {
        // Debemos comprobar si el dígito ACTUAL es diferente al anterior
        if( solucion[i] != solucion[i-1]) {
            contador++;
            // condicion que no cumple, cuando los grupo A.B.C.D son mas de 4 y maximo de digitos son 3
            if(contador_digitos > 3 || contador > 4) return 0; // Rompo la iteración porque YA NO ES VALIDO, ME DEVUELVE EL es_valido EN 0
            
            aux = 0;            
            // Calculamos el valor númerico de la secuencia de dígitos
            for( j = contador_digitos - 1; j >=0 ; j--) aux += digitos[i - (j+1)]*pow(10, j);
            // Verificamos las restricciones para que sean número válidos
            if( aux > 255 || (contador_digitos == 2 && aux < 10) || (contador_digitos == 3 && aux < 100)) return 0;
            contador_digitos = 1;
        } else {
            contador_digitos++;
        }
    }   
    
    aux = 0;
    
    // Calculamos el valor número de la última secuencia de dígitos
    for( j = contador_digitos - 1; j>=0; j--) aux += digitos[i - (j+1)]*pow(10, j);
    
    // Verificamos las restricciones para la última secuencia de dígitos
    if( aux>255 || (contador_digitos == 2 && aux<10) || (contador_digitos == 3 && aux<100)) return 0;
    
    if( (paso == N-1 && contador != 4) || (paso < N -1 && contador > 4) || contador_digitos > 3) return 0; //  No es valido
    else return 1; //  cuando ya es  valido
    
}


void obtenerIPS_Recursivo(int paso, int N, int digitos[], int solucion[]) {
    
    int i = 0;
    // caso de parada
    if( paso == N ) {
        imprimir_solucion(digitos, N, solucion);
        return;
    }
    
    while(1) { // usamos un while porque no sabemos hasta cuando vamos a seguir y luego vamos a hacer un BT
        solucion[paso] = i; // asignamos el valor actual de i a la posicion de paso en la solucion
        cout << "solucion[paso == " << paso << "] y el i es == " << i << endl;
        // qué significa que sea válida? en el valida hacemos el BT porque ahí verificamos cuál es la correcta
        // cuándo ya es valido hacemos la llamada recursiva sí solo sí.
        if( es_valido( paso , N, digitos, solucion) ) { //en el válido está todo la lógica 
            cout << "   SIIIIIII " << endl;
            obtenerIPS_Recursivo(paso + 1, N, digitos, solucion);
            //cout << "  Es valido " << ;
            //cout << "solucion[paso == " << paso << "] y el i es == " << i << endl;
        }
        i++;
        if(solucion[paso] == 1) break;// continuamos con si seguimos con los demas valores que sean -1
        // Si encontramos un número diferente a -1, BREAKEAMOS
    }
    solucion[paso] = -1;
}



int main(int argc, char** argv) {

    // creamos cadena de entrada
    // lo creamos con * porque es una cadena dinámica, porque no sabemos cuanto va a ser su longitud
    char *datos = new char[MAX_LONG + 1];
    cout << "Ingrese la dirección IP: " << endl;
    //cin >> datos;
    strcpy(datos, "25525511169");

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
        cout << "Solucion: " << endl << endl;
        obtenerIPS_Recursivo(0, N, digitos, solucion);
                
        
        cout << endl;
    } else {
        cout << "(No presenta resultados)" << endl;
    }

    return 0;
}

