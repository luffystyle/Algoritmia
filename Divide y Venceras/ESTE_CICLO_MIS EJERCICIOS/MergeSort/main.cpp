
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on October 28, 2024, 4:00 PM
 */

#include <iostream>
#include <climits>
// MERGESORT



using namespace std;

void merge(int *arr, int ini, int med, int fin) {
    int long1, long2, p, q;
    long1 = med-ini+1;
    long2 = fin-med;
    int P[long1+1];
    int Q[long2+1];
    P[long1] = 99999;
    Q[long2] = 99999;
    
    for(int i = ini; i<=med; i++){
        P[i-ini] = arr[i];
    }
    for(int i = med+1; i<=fin; i++) {
        Q[i-(med+1)] = arr[i];
    }
    
    p = 0;
    q = 0;
    
    for(int i = ini; i<=fin; i++) {
        if(P[q]<Q[q]) arr[i] = P[p++];
        else arr[i] = Q[q++];
    }
    
}



// INI Y FIN SON POSICIONES
void mergeSort(int *arr, int ini, int fin) {
    
    if( ini == fin) return;
    
    int med = (ini + fin)/2;
    // Con esto llegas a la primera posicion en la recursión
    mergeSort(arr, ini, med); // izquierda
    
    // llega al ultimo elemento de la arreglo
    mergeSort(arr, med + 1, fin); // derecha
    
    merge(arr, ini, med, fin);
}


int main(int argc, char** argv) {

    
    int arr[] = {2, 5, 20, 1, 3, 9, 4, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    int ini = 0, fin = n -1; //Posiciones del inicio y final del arreglo
    mergeSort(arr, ini, fin);
    
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

