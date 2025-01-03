
// PC1 2022-2
// PREGUNTA 1

#include <iostream>
#include <iomanip>
#include <cmath>
#define M 8

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
    int cromosomaMaximo[M]; // es el cromosoma que cumple con todas las condiciones 
    int precios[M] = {4, 5, 4, 2, 6, 3, 4, 1};
    int cantRenovar[M] = {3, 2, 1, 1, 3, 3, 2, 4};
    int p = 19;
    int combinaciones = pow(2, M);
    int monto;
    int mejor_monto = 0;
    int cantidad;
    int maxCantRenovar = 10;
    int mejor_cantidad = 0;
    int tipo_herramienta;
    int cant_tipo_herramienta = 4;
    
    
    for( int i = 0; i<combinaciones; i++) {
        cargaBinaria(cromosoma, i, M);
        monto = 0;
        tipo_herramienta = 0;
        cantidad = 0;
        for( int j = 0; j<M; j++) {
            if( cromosoma[j] == 1) {
                monto += precios[j]*cantRenovar[j];
                cantidad += cantRenovar[j];
                tipo_herramienta++;
            }
        }
        // la cantidad es la variable a MAXIMIZAR, los demás son condiciones; por eso, tienen maxcantidad y mejor cantidad
        // uno es el límite y el otro es LA MEJOR CANTIDAD, porque no siempre llega al límite.
        if( monto <= p && cantidad <= maxCantRenovar && mejor_cantidad <= cantidad && tipo_herramienta <= cant_tipo_herramienta) {
            mejor_cantidad = cantidad;
            mejor_monto = monto;
            for( int j = 0; j<M; j++) cromosomaMaximo[j] = cromosoma[j];
        }
    }
    
    cout << "Mejor Solución: ";    
    for( int i = 0; i<M; i++ ) {
        if(cromosomaMaximo[i] == 1) 
            cout << i + 1 << " ";
    }    
    cout << endl << endl;
    cout << "Monto Total: " << mejor_monto << endl;
    cout << "Cantidad de herramientas: " << mejor_cantidad<<endl;    

    return 0;
}

