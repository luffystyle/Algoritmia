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
    cout << "Solucion de los digitos: ";
    for( i = 0; i<N; i++) cout << solucion[i] << " ";
    cout << endl;
    
    cout << "Solución oficial: ";
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
    
    // contador_digitos es el número de números de cada grupo A.B.C.D, máximo serian 3
    // contador es el número de grupos, máximo sería 4 porque es A, B, C y D
    int i, j, contador_digitos = 1, contador = 1, aux;
        
    if( solucion[0] == 0 ) return 0; // si el primer digito es 0, no hay solucion. Solo es válido si 
    
    for(i = 1; i <= paso; i++) {
        // Debemos comprobar si el dígito ACTUAL es diferente al anterior
        if( solucion[i] != solucion[i-1]) { // lo hacemos porque tenemos puros -1, entonces, para diferenciarlos hacemos esa condición
            contador++;
            // condicion que no cumple, cuando los grupo A.B.C.D son mas de 4 y maximo de digitos son 3
            if(contador_digitos > 3 || contador > 4) return 0; // Rompo la iteración porque YA NO ES VALIDO, ME DEVUELVE EL es_valido EN 0
            
            aux = 0;            
            // Calculamos el valor númerico de la secuencia de dígitos
            for( j = contador_digitos - 1; j >=0 ; j--) aux += digitos[i - (j+1)]*pow(10, j);
            //cout << "El número auxiliar 1 es " << aux << endl;
            // Verificamos las restricciones para que sean número válidos
            if( aux > 255 || (contador_digitos == 2 && aux < 10) || (contador_digitos == 3 && aux < 100)) return 0;
            contador_digitos = 1;
        } else {
            contador_digitos++;
        }
    }   
    
    aux = 0;
    
    // Calculamos el valor número de la última secuencia de dígitos
    //cout << "El contador de digitos " << contador_digitos << " y i "<< i << endl;
    for( j = contador_digitos - 1; j>=0; j--) aux += digitos[i - (j+1)]*pow(10, j);
    //cout << "El número auxiliar 2 es " << aux << endl;
    // Verificamos las restricciones para la última secuencia de dígitos
    if( aux>255 || (contador_digitos == 2 && aux<10) || (contador_digitos == 3 && aux<100)) return 0;
    
    if( (paso == N-1 && contador != 4) || (paso < N -1 && contador > 4) || contador_digitos > 3) return 0; //  No es valido
    else return 1; //  cuando ya es  valido
    
}


void obtenerIPS_Recursivo(int paso, int N, int digitos[], int solucion[]) {
    
    
    // caso de parada
    if( paso == N ) {
        imprimir_solucion(digitos, N, solucion);
        return;
    }
    int i = 0;
    while(1) { // usamos un while porque no sabemos hasta cuando vamos a seguir y luego vamos a hacer un BT
        solucion[paso] = i; // asignamos el valor actual de i a la posicion de paso en la solucion
        if( es_valido( paso , N, digitos, solucion) ) { //en el válido está todo la lógica 
            obtenerIPS_Recursivo(paso + 1, N, digitos, solucion); // Con paso+1 avanzo al siguiente casillero
            //cout << "  Es valido " << ;
            //cout << "solucion[paso == " << paso << "] y el i es == " << i << endl;
        }
        i++;
        if(solucion[paso] == 1) break;// continuamos con si seguimos con los demas valores que sean -1
        
    }
    solucion[paso] = -1; //  aqui le asignamos ese valor y cuando acaba esa función HACEMOS BACKTRACKING
}



int main(int argc, char** argv) {

    // creamos cadena de entrada
    // lo creamos con * porque es una cadena dinámica, porque no sabemos cuanto va a ser su longitud
    char *datos = new char[MAX_LONG + 1];
    cout << "Ingrese la dirección IP: " << endl;
    //cin >> datos;
    strcpy(datos, "101069");

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

