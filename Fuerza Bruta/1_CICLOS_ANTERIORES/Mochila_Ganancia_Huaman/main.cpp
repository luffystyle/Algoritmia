// PC1 2019-1
// PREGUNTA 1
#include <iostream>
#include <cmath>
#include <iomanip>
#define M 6
using namespace std;

void cargaBinaria(int cromosoma[], int numero, int n) {
    int i;
    for(i=0; i<n; i++) cromosoma[i] = 0; //estoy inicializando en 0, todos los valores del cromosoma
    i=0;
    while(numero>0) {
        cromosoma[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

int main(int argc, char** argv) {

    int cromosoma[M];
    int cromosomaMaximo[M];
    int paquetes[M] = {8, 2, 10, 10, 5, 5};
    int ganancias[M] = {15, 20, 5, 10, 8, 5};
    int peso_maximo = 25;
    int peso, ganancia;
    int gananciaMaxima = 0; // a mejor ganancia
    int mejor_peso = 0;
    int combinaciones = pow(2, M);
    
    for( int i = 0; i<combinaciones; i++) {
        
        cargaBinaria(cromosoma, i, M);
        peso = 0;
        ganancia = 0;
        for( int j = 0; j<M; j++) {
            if(cromosoma[j] == 1) {
                peso += cromosoma[j]*paquetes[j];
                ganancia += cromosoma[j]*ganancias[j];
            }
        }
        
        if( gananciaMaxima <= ganancia && peso <= peso_maximo) {
            gananciaMaxima = ganancia;
            mejor_peso = peso; 
            for( int j = 0; j<M; j++) cromosomaMaximo[j] = cromosoma[j];
        }
    } 
    
    cout << "Artículos: " ;
    for( int i = 0; i<M; i++) {
        if(cromosomaMaximo[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << setw(30) << "Ganancia Total: " << gananciaMaxima <<  endl;
    cout << "El peso es " << mejor_peso <<endl;
    
    return 0;
}
