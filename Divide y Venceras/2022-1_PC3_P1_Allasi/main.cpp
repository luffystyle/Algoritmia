
#include <iostream>
#include <iomanip>

using namespace std;

int mayor(int izquierda, int derecha, int centro) {
    if (izquierda>=derecha && izquierda>=centro){
        return izquierda;
    }
    else {
        if(derecha>=izquierda && derecha>=centro) return derecha;
        else return centro;
    }
}

int cuenta(int arreglo[], int inicio, int fin) {
    
    // aqui voy a contar los números consecutivos de la izquierda
    int contador_izquierda = 1;
    int medio = (inicio + fin)/2;
    // estoy recorriendo del medio hace la izquierda, por eso DECREMENTO
    for( int i = medio; i>inicio; i--) {
        if(arreglo[i]>arreglo[i-1]) contador_izquierda++;
        else break;
    }
    
    int contador_derecha = 1;
    for( int i = medio + 1; i<fin; i++) {
        if(arreglo[i] < arreglo[i+1]) contador_derecha++;
        else break;
    }
    // Solo retorno cuando en el centro el de el indice de medio+1 es mayor  que el medio
    // esto quiere decir que hay una secuencia de CRECIENTE, cuando no lo hay simplemente retornamos 1
    if( arreglo[medio]<arreglo[medio+1]){
        return contador_izquierda + contador_derecha;
    }
    // cuando no es mayor el valor de la del índice medio+1, retornamos 1
    return 1;   
}

int cuentaConsecutivos(int arreglo[], int inicio, int fin) {
    
    // Caso base
    // cuando se llega a tener un solo valor, debo contar 1 como mínimo, luego retorno ese valor
    // porque después vamos a comparar esos valores y devolver el mayor
    if( inicio == fin) return 1;
    
    int medio = (inicio+fin)/2;
    
    int izquierda, derecha, centro;
    
    // con esto entro a los sub-universos hasta llegar al ultima de la izquierda
    izquierda = cuentaConsecutivos(arreglo, inicio, medio);
    derecha = cuentaConsecutivos(arreglo, medio+1, fin);
    // aqui realmente estamos contando los numeros consecutivos, porque en el anterior solo estamos REGRESANDO
    // de nuestros universos de izquierda y derecha, y por qué?
    // porque es DIVIDE Y VENCERÁS, tenemos que dividir en izquierda y derecha
    centro = cuenta(arreglo, inicio, fin);
      
    return mayor(izquierda, derecha, centro);
    
}

int main(int argc, char** argv) {

    // Esto bloque de código es para el ingreso de datos
//    int n;
//    cout << "Ingrese el número de días del número de contagiados: " <<endl;
//    cin >> n;
//    int arreglo[n];
//    
//    
//    int contagiados;
//    cout << "Ahora ingrese los contagiados de los días registrados: ";
//    for(int i = 0; i<n; i++) {
//        cin >> contagiados;
//        arreglo[i] = contagiados;
//    }
    int n = 8;
    int arreglo[] = {10, 12, 15, 20, 21, 10, 13, 18}; 
    
    int inicio = 0, fin = n-1;
    // siempre en problemas de divide y vencerás tenemos que mandar el inicio y el final
    int cantidad = cuentaConsecutivos(arreglo, inicio, fin);
    
    cout << "El intervalo máximo de incrementos contagiados es: " << cantidad << endl;
    cout << "El índice de incrementos es: " << (double)cantidad/n << endl;
    
    
    
    
    
    return 0;
}

