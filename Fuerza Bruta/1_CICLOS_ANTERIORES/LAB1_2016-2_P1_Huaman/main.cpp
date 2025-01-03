


#include <iostream>
#include <cmath>
#define N 4

using namespace std;

void cargaBinaria(int cromosoma[], int numero, int n) {
    int i;
    for( int i = 0; i<n; i++) cromosoma[i] = 0;
    i = 0;
    while(numero>0) {
        cromosoma[i] = numero%2;
        numero = numero/2;
        i++;
    }
}



void procesarEntradas(int n, int arreglo[][3]) {
    
}



int main(int argc, char** argv) {

    
//    int n;
//    cin >> n;
//    int sexo, ai, bi;
//    for(int i = 0; i<n; i++) {
//        cin >> sexo >> ai >> bi;
//    }
    
    cout << "Ingrese el numero " << endl;
    int arreglo[][3] = { {2, 151, 307}, 
                         {1, 343, 352}, 
                         {1, 117, 145}, 
                         {2,  24, 128} };
    int cromosoma[N*3];
    procesarEntradas(N, arreglo);
    for(int i = 0; i<pow(2, N); i++) {
        cargaBinaria(cromosoma, i, N);
        for(int j = 0; j<N; j++) cout << cromosoma[j] << " ";
        cout << endl;
    }
    
    return 0;
}

