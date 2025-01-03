/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on November 2, 2024, 12:35 AM
 */

#include <iostream>
#include <climits>
#define N 5
#define M 6
using namespace std;



int cuentaCeros(int *arr, int ini, int fin, int contador) {
    
    if(ini > fin) {
        return contador;
    }

    int med = (ini + fin)/2;
    if(arr[med] == 0 ) { // me voy  a la izquierda
        return cuentaCeros(arr, ini, med-1, contador + (fin - med + 1));
    } else {
        return cuentaCeros(arr, med + 1, fin, contador);
    }
    
}


//int contarNumeros(int *arr, int *arr2,int ini, int fin, int contador, int numero) {
//    if(ini > fin) return 0;
//    if(ini == fin) {
//        if(arr[ini] == numero) {
//            contador += arr2[ini];
//        }
//        return contador;
//    }
//    
//    int med = (ini + fin)/2;
//    
//    int contIzq = contarNumeros(arr, arr2, ini, med, contador, numero);
//    int contDer = contarNumeros(arr, arr2, med+1, fin, contador, numero);
//    return contador + contIzq + contDer;
//    
//}













int contarNumeros(int *arr, int *arr2,int ini, int fin, int contador, int numero) {
    
    if(ini > fin) return contador;
    
    int med = (ini + fin)/2;
    
    if(arr[med] == numero) {
        
    
        return arr2[med]+contarNumeros(arr, arr2, med+1, fin, contador + (med - ini) + 1, numero);
    }
    else {
        
    
        return contarNumeros(arr, arr2, ini, med-1, contador, numero);
    }
    
}


void convertirArregloUnidimensional(int matriz[][M], int *arr) {
    int contador = 0;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            arr[contador] = matriz[i][j];
            contador++;
        }
    }
    
//    for(int i = 0; i<N*M; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl << endl;
}



void merchi(int A[], int B[], int ini, int med,int fin) {
    int long1, long2, p, q;
    long1 = med-ini+1;
    long2 = fin-med;
    
    int P[long1+1];
    int Q[long2+1];
    
    int PB[long1+1];
    int QB[long2+1];
    
    P[long1] = INT_MAX;
    Q[long2] = INT_MAX;
    
    PB[long1] = INT_MAX;
    QB[long2] = INT_MAX;
    
    
    for(int i = ini; i<=med; i++) {
        P[i-ini] = A[i];
        PB[i-ini] = B[i];
    }
    for(int i = med+1; i<=fin; i++) {
        Q[i-(med+1)] = A[i];
        QB[i-(med+1)] = B[i];
    }
    p = 0; q = 0;
    for(int i= ini; i<=fin; i++) {
        if(P[p] < Q[q]) {
            A[i] = P[p];
            B[i] = PB[p];
            p++;
        }
        else {
            A[i] = Q[q];
            B[i] = QB[q];
            q++;
        }
    }
    
}


void mergeSort(int A[], int B[], int ini, int fin) {
    
    if(ini == fin) return;
    
    int med = (ini + fin)/2;
    
    mergeSort(A, B, ini, med);
    mergeSort(A, B, med+1, fin);
    
    merchi(A, B, ini, med, fin);
}


int main(int argc, char** argv) {
    //int arr[]={1, 1, 1, 1, 0, 0, 0, 0};//Dato de entrada
    
    int matriz_registro[N][M] = {
            {-1, -2, -3, -4, -5, -6},
            {-7, -8, 1, -9, 2, -10},
            {-11, 1, 2, -12, -13, -14},
            {-15, -16, -17, 1, -18, -19},
            {-20, 1, 2, -21, -22, -23}
    };
    int matriz_lineas_instruccion[N][M] = {
            {10, 5, 8, 9, 8, 1},
            {10, 5, 2, 8, 2, 3},
            {4, 2, 1, 4, 8, 1},
            {1, 2, 4, 3, 5, 3},
            {8, 3, 3, 8, 5, 3}
    };
    
    int arrRegistro[N*M]{}, arrInstrucciones[N*M]{};
    convertirArregloUnidimensional(matriz_registro, arrRegistro);
    convertirArregloUnidimensional(matriz_lineas_instruccion, arrInstrucciones);
    int n = sizeof(arrInstrucciones)/ sizeof(arrInstrucciones[0]);
    for(int i = 0; i<N*M; i++) {
        cout << arrRegistro[i] << " ";
    }
    cout << endl;
    for(int i = 0; i<N*M; i++) {
        cout << arrInstrucciones[i] << " ";
    }
    cout << endl << endl;
    
    mergeSort(arrRegistro, arrInstrucciones, 0, n-1);
    
    for(int i = 0; i<N*M; i++) {
        cout << arrRegistro[i] << " ";
    }
    cout << endl;
    for(int i = 0; i<N*M; i++) {
        cout << arrInstrucciones[i] << " ";
    }
    cout << endl << endl;
//    int arr[] = {2, 2, 2, 1, 1, 1, 1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23};
//    int arr2[] = {2, 1, 3, 2, 2, 3, 3, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23};
    
    
    int contador = 0;
    
    //cout << cuentaCeros(arr, 0, n-1, contador);
    int numero = 1;
    
    cout << contarNumeros(arrRegistro, arrInstrucciones, n-7, n-1, contador, numero);   
    
    
    return 0;
}

