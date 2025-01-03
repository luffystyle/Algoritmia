#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 6
#define W 25

void cargaBin(int numero, int cromo[N]) {
    int resto, i;
    for( i = 0; i<N; i++) cromo[i] = 0;
    i = 0;
    while(numero>0) {
        resto = numero%2;
        numero = numero/2;
        cromo[i] = resto;
        i++;
    }
}

int main(int argc, char** argv) {

    int cromo[N], peso, ganancia, maxGanancia = 0;
    int paq[N] = {8, 2, 10, 10, 5, 5};
    int precios[N] = {15, 20, 5, 10, 8, 5};
    int articulos[N] = {1, 2, 3, 4, 5, 6};
    int cromoGanancia[N] = {0, 0, 0, 0, 0, 0};
    int combinaciones =(int)pow(2, N);
    for(int i = 0; i<combinaciones; i++) {
        cargaBin(i, cromo);
        peso = 0;
        ganancia = 0;
        for(int j = 0; j<N; j++) {
            peso += paq[j]*cromo[j];
            ganancia += precios[j]*cromo[j];
        }
        
       
        if(N<=10 and peso <= W and maxGanancia <= ganancia) {
            for(int i = 0; i<N; i++) cromoGanancia[i] = cromo[i];
            maxGanancia = ganancia;
        }
        
    }
    cout<<"Articulos: ";//100110
    for(int i = 0; i<N; i++) {
        if(cromoGanancia[i]==1) {
            cout<<articulos[i]<<" ";
        }
    }
    cout<<"            Ganancia Total: "<<maxGanancia<<endl;

    return 0;
}

