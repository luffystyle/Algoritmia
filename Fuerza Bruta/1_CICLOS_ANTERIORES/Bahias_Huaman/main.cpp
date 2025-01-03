// PC1_2021-1
// PREGUNTA 1

#include <iostream>
#include <cmath>
#include <iomanip>
#define N 4 // cantidad de productos que tiene cada bahía
#define M 5 // las divisiones del camión
#define C 20 // el límite de toneladas del camión

using namespace std;

void cargarBinaria(int cromosoma[], int numero, int n) {
    
    int i;
    for(i = 0; i<n; i++) cromosoma[i] = 0;
    i = 0;
    while(numero>0) {
        cromosoma[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

int main(int argc, char** argv) {

    int cromosoma[3*N];
    int bahia[3*N] = {2, 5, 6, 10, 7, 8, 15, 3, 11, 9, 6, 4};// los pesos en la bahia, lo trabajamos como un SOLO CROMOSOMA
    int combinaciones = pow(2, 3*N);
    int peso;
    int divisiones ;
    int bandera1, bandera2, bandera3;
    
    for( int i = 0; i<combinaciones; i++) {
        cargarBinaria(cromosoma, i, 3*N);
        peso = 0;
        divisiones = 0;
        for(int j = 0; j<3*N;j++) {
            if(cromosoma[j] == 1) {
                peso += cromosoma[j]*bahia[j];
                divisiones++;
            }
        }
        if(peso == C and divisiones == M ) {
            bandera1 = 0, bandera2 = 0, bandera3 = 0;
            for(int j = 0;j<3*N;j++) {
                if(cromosoma[j] == 1) {
                    if(j/N==0 and bandera1 == 0) {
                        cout <<"Bahia 1: ";
                        bandera1 = 1;
                    } else if(j/N==1 and bandera2 == 0) {
                        cout << "Bahia 2: ";
                        bandera2 = 1;
                    } else if(j/N and bandera3 == 0){
                        cout << "Bahia 3: ";
                        bandera3 = 1;
                    }
                    cout << bahia[j] << " ";
                }
            }
            cout<<endl<<endl;
        } 
       
    }

    return 0;
}

