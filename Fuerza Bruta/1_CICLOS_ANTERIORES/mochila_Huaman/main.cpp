
#include <iostream>
#include <iomanip>
#include <cmath>
#define N 5
using namespace std;

void carga_binaria(int cromosoma[], int numero, int n) {

    int i;
    for( i = 0; i<n; i++) cromosoma[i]=0;
    i=0;
    
    while(numero>0) {
        cromosoma[i] = numero%2;    
        numero = numero/2;
        i++;        
    }        
}

int main(int argc, char** argv) {


    int paquetes[N] = {1, 2, 4, 12, 1};
    int cromosoma[N];
    int combinaciones;
    int peso;
    int pesoMaximo = 15;
    combinaciones = pow(2, N);
    
    
    for( int i = 0; i <combinaciones; i++) {
        carga_binaria(cromosoma, i, N);
        peso = 0;
        for(int j = 0; j<N; j++) { // aui estoy recorriendo el cromosoma
            if(cromosoma[j] == 1) peso += cromosoma[j]*paquetes[j];            
        }
        
        if(peso == pesoMaximo) {
            cout << "El cromosoma es " <<endl;
            for(int k = 0; k<N;k++) cout << cromosoma[k] << " ";
            cout <<endl;
            //los pesos ahora cuales fueron
            cout << "Pesos seleccionados"<<endl;
            for(int k = 0; k<N;k++) {
                if(cromosoma[k] == 1) {
                    cout << paquetes[k] << " ";
                }
            }
            cout << endl <<endl;
        }
    }

    return 0;
}

