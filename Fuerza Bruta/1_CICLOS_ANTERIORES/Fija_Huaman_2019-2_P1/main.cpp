// PROBLEMA DE LA INMOBILIARIA
// PC1

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 8
#define P 250
#define F 3
using namespace std;

void cargaBinaria(int cromosoma[], int numero, int n) {
    int i;
    for( i = 0; i<n;i++) cromosoma[i] = 0;
    i = 0;
    while(numero>0) {
        cromosoma[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

int considerarProyecto(int cromosoma[], int n, int j) {
    
    // tengo que usar por complemento, la parte en donde NO CUMPLE, es decir
    if(j == 3 and ( cromosoma[0] == 0 or cromosoma[1]==0 )) return 0;
    if(j == 5 and cromosoma[1] == 0) return 0;
    if(j == 6 and (cromosoma[5] == 0 or cromosoma[1] == 0)) return 0;
    if(j == 7 and (cromosoma[5] == 0 or cromosoma[1] == 0)) return 0;
    return 1;
}


int main(int argc, char** argv) {

    // F PUEDE TOMAR DESDE 0 HASTA 3
    int costos[N] = {80, 20, 100, 100, 50, 10, 50, 50};
    int ganancias[N] = {150, 80, 300, 150, 80, 50, 120, 150};
    int presu, maxima_ganancia = 0;
    int cromosoma[N], cromosomaMaximo[N];
    int combinaciones = pow(2, N);
    int mejor_i = 0, mejor_presu = 0;
    int ganancia;

    for( int i = 0; i<combinaciones; i++ ) { //
        cargaBinaria(cromosoma, i, N);
        presu = 0;
        ganancia = 0;
        for( int j = 0; j<N; j++ ) {
            if( cromosoma[j] == 1) {
                if( considerarProyecto(cromosoma, N, j) == 0) continue;
                else {
                    presu += costos[j]; 
                    ganancia += ganancias[j];
                    
                }  
            }
        }
        
        if( presu<=P and maxima_ganancia<=ganancia ) {
            maxima_ganancia = ganancia;
            mejor_i = i;
            mejor_presu = presu;
            
        }        
    }
    
    cout << "Solucion: " << maxima_ganancia<< " $"<<endl;
    cout << "el presu es " << mejor_presu <<endl;
    cargaBinaria(cromosoma, mejor_i, N);

    for( int i = 0; i<N; i++) {
        if(cromosoma[i] == 1) {
            cout <<setw(5)<< ganancias[i] << " - "<< costos[i]<<" ";
        }
    }
    cout << endl << endl;
    for( int i = 0; i<N; i++) {
        cout <<setw(7)<< cromosoma[i] << " ";
    }
    cout << endl;

    return 0; 
}
