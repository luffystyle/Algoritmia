

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 2 de noviembre de 2024, 08:05 AM
 */


//PREGUNTA 2
#include <iostream>
#define N 10
using namespace std;

//compejidad LOG(n)
int cuentaCerosIzq(int *arr, int ini, int fin, int contador) {
    if(ini == fin) return contador;
    
    int med = (ini+fin)/2;
    if(arr[med] == 0) {
        return cuentaCerosIzq(arr, med+1, fin, contador + med - ini + 1);
    } else {
        return cuentaCerosIzq(arr, ini, med, contador);
    }
    //return contador;
}
//compejidad LOG(n)
int cuentaCerosDer(int *arr, int ini, int fin, int contador) {
    //if(ini > fin) return contador;
    if(ini == fin) {
        //if(arr[ini] != 0) contador++;
        return contador;
    }
    
    int med = (ini+fin)/2;
    if(arr[med] == 0) {
        return cuentaCerosDer(arr, ini, med, contador + fin - med + 1); // CUENTO MED - 1
        //return cuentaCerosDer(arr, ini, med-1, contador);
    } else {
        return cuentaCerosDer(arr, med+1, fin, contador);
        //return cuentaCerosDer(arr, med, fin, contador + med - ini + 1);
    }
    //return contador;
}

//CUENTA CEROS
int maximaPureza(int *arr, int ini, int fin) {
    
    if(ini == fin) return arr[ini];
    
    int med = (ini + fin)/2;
    
    
}

//void imprimirArreglo(int arr[]) {
//    for(int i = 0; i<N;i++) cout<<arr[i] << " ";
//    cout << endl;
//}

int main(int argc, char** argv) {

    int matriz[][N] = {{0, 0, 0, 3, 3, 7, 5, 5, 1, 1},
                       {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
                       {3, 5, 8, 9, 7, 6, 4, 2, 0, 0},
                       {9, 7, 7, 4, 4, 4, 2, 0, 0, 0},
                       {0, 2, 2, 3, 3, 4, 4, 5, 3, 3},
                       {0, 0, 0, 0, 0, 0, 2, 3, 4, 5},
                       {1, 2, 2, 3, 3, 4, 3, 2, 0, 0},
                       {0, 0, 0, 0, 0, 0, 3, 5, 5, 7},
                       {6, 5, 5, 2, 2, 1, 0, 0, 0, 0},
                       {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}};
    
    
    //imprimirArreglo(matriz[0]);
    //PARTE A
    
    int contador = 0;
    for(int i = 0; i<N;i++) {
        
        if(matriz[i][0] == 0) {
            cout << i+1 << " )"<< N-cuentaCerosIzq(matriz[i], 0, N-1, contador) << endl;
        } else {
            cout << i+1 << " )"<< N-cuentaCerosDer(matriz[i], 0, N-1, contador) << endl;
        }
        
    }
    
    //PARTE B
    int max = 0;
    for(int i = 0; i<N;i++) {
        
        int valor = N-cuentaCerosIzq(matriz[i], 0, N-1, contador);
        if(max < valor) {
            max = valor;
        } 
    }
    cout << "El maximo " << max << endl;
    
    return 0;
}

