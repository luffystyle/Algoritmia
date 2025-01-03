
#include <iostream>
#include <cmath>
#include <iomanip>
#define N 5
using namespace std;

void cargaBinaria(int cromosoma[], int numero, int n) {
    int i;
    for(i=0; i<n; i++) cromosoma[i] = 0; //estoy inicializando en 0, todos los valores del cromsoma
    i=0;
    while(numero>0) {
        cromosoma[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

int main(int argc, char** argv) {

    int cromosoma[N];
    int paquetes[N] = {1, 2, 4, 12, 1};
    int combinaciones = pow(2, N);
    int peso; 
    int pesoMaximo;// como este peso máximo puede variar, entonces lo ponemos como una variable de entrada
    int mejor_peso_mochila = 0;
    int mejor_combinacion = 0; // es para hallar el número decimal que dé el máximo peso
    int cromosoma_maximo[N]; // es lo mismo al mejor_combinacion, pero este en este caso es EL CROMOSOMA y no el número en decimal
    
    cout << "Ingrese el peso máximo de la mochila: ";
    cin >> pesoMaximo;
    
    for(int i = 0; i<combinaciones; i++) {
        cargaBinaria(cromosoma, i, N);
        peso = 0;
        for(int j = 0; j<N; j++) {
            if( cromosoma[j] == 1) {
                peso += cromosoma[j]*paquetes[j];
            }
        }
        // con eso estoy encontrado el MEJOR PESO; es decir, el último peso encontrado que es el mejor
        // por eso, con solo poner peso == pesomaximo, no sirve porque te va a botar varias soluciones
        // pero no sabes cuál de esas es la mejor, por eso le ponemos otra condición
        if(peso <= pesoMaximo && mejor_peso_mochila <= peso) { // o sea, a veces no siempre será igual al peso Máximo
            // Por cada iteración del peso, el peso debe ser mayor que el mejor_peso_mochila para que se guarde,
            // porque si no es mayor, NO TIENES SENTIDO GUARDALO, porque tamos buscando el máximo.
            mejor_peso_mochila = peso;
            //mejor_combinacion = i; // el número en decimal lo guardamos para después transformalo
            for(int k = 0; k<N; k++) cromosoma[k] =  cromosoma_maximo[k]; // aqui guardo el cromosoma maximo, podemos hacerlo 
            // de otra manera, agarrando el número en forma decimal, y al final lo transformamos; sin embargo,
            // aqui estamos guardando DIRECTAMENTE a cromosoma, pasándoles los valores
            if( peso == pesoMaximo) break;  // hago un break porque no se puede hallar otro mejor número que este   
        } 
    }
    // IMPORTANTE, cómo el numero que hallamos no podemos guardarlo en cromosoma(si podemos, pero es más largo)
    // guardamos el número pero en BASE DECIMAL y luego lo transformamos a BINARIO. Es más fácil porque tenemos la función
    // que transforma un número a un número binario que es CARGABINARIO.
    cargaBinaria(cromosoma_maximo, mejor_combinacion, N);
    for(int j = 0; j<N; j++) {
        cout << cromosoma_maximo[j] << " ";
    }
    cout << endl;
    
    cout<< "Los paquetes son: "<< endl;
    for (int j=0; j<N; j++){
        if (cromosoma_maximo[j]==1){	
            cout<< paquetes[j] << " ";//mostramos los paquetes seleccionados
        }		
    }

    return 0;
}

