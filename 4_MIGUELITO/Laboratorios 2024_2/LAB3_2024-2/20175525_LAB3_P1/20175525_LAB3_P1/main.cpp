
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 2 de noviembre de 2024, 08:05 AM
 */

//PREGUNTA 1
#include <iostream>
#include <climits>

using namespace std;

void merge(int *arr, int ini, int med, int fin) {
    int p, q, long1, long2;
    long1 = med - ini + 1;
    long2 = fin - med;
    int P[long1+1];
    int Q[long2+1];
    P[long1] = INT_MAX;
    Q[long2] = INT_MAX;
    
    for(int i = ini; i<=med; i++) {
        P[i-ini] = arr[i];
    }
    for(int i = med + 1; i<=fin; i++) {
        Q[i-(med+1)] = arr[i];
    }
    p = 0;
    q = 0;
    for(int i = ini; i<=fin; i++) {
        if(P[p] < Q[q]) arr[i] = P[p++];
        else arr[i] = Q[q++];
    }
}


void mergeSort(int *arr, int ini, int fin) {
    if(ini == fin) return ;
    int med = (ini + fin)/2;
    
    mergeSort(arr, ini, med); // izquierda
    mergeSort(arr, med+1, fin);
    
    merge(arr, ini, med, fin);
}


void encontrarImpar(int *arr, int ini, int fin) {
    if(ini>fin) return;
    if(ini == fin) {
        cout << "El empleado " << arr[ini] << " no volvió salió." << endl;
        return ;
    }
    
    int med = (ini + fin)/2;
    if(arr[med]%2 == 0) {
        if(arr[med] == arr[med+1]) 
            encontrarImpar(arr, med + 2, fin);
        else 
            encontrarImpar(arr, ini, med-1);
    } else {
        if(arr[med] == arr[med-1]) 
            encontrarImpar(arr, med + 1, fin);
        else 
            encontrarImpar(arr, ini, med);
    }
}


int main(int argc, char** argv) {

    int arr[] = {1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i  = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr, 0, n-1); //n LOG(n)
    for(int i  = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    encontrarImpar(arr, 0, n-1); // COMPLEJIDAD LOG(N)
    // AL FINAL N(LOG(N) + LOG(N) = N(LOG(N)
    return 0;
}

