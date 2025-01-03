
// PC1 2023-1 
// PREGUNTA 1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void cargaBinaria(int cromosoma[], int numero, int n, int cantEstados) {
    int i ;
    for(  i = 0; i<n; i++) cromosoma[i] = 0;
    i = 0;
    while(numero>0) {
        cromosoma[i] = numero%cantEstados;
        numero = numero/cantEstados;
        i++;
    }
}



int main(int argc, char** argv) {

    
    int cantPaq = 5, cantCam = 4;
    int n = 5;
    int cromosoma[n];
    int cantEstados = 4;
    int camiones[] = {25, 50, 100, 100};
    int paquetes[] = {50, 20, 30, 50, 20};
    int combinaciones = pow(cantCam, cantPaq);
    
    for( int i = 0; i<combinaciones; i++) {
        cargaBinaria(cromosoma, i, n, cantEstados);
        int max_peso = 0;
        int min_peso = 0;
        int peso = 0;
        //for( int j = 0; j<n; j++) cout << cromosoma[j] << " ";
        //cout<<endl;

        for( int j = 0; j<n; j++) {
            peso = camiones[cromosoma[j]] - paquetes[j];
            //if(peso>=0) {
                for(int k = 0; k<n; k++) cromosoma[j] == cromosoma[k];
                //cout << peso << " ";
                cout << cromosoma[j] << " ";
            //} 
            
        }
        cout << endl;
        

        
        
    }
    
    


    return 0;
}

