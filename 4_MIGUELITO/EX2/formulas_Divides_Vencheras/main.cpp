/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 5, 2024, 10:21 PM
 */

#include <iostream>
#include <limits.h>

using namespace std;


//void merge(int *arr, int ini, int med, int fin) {
//    
//    int long1, long2, p, q;
//    
//    long1 = med-ini+1;
//    long2 = fin - med;
//    int P[long1+1];
//    int Q[long2+1];
//    P[long1] = INT_MAX;
//    Q[long2] = INT_MAX;
//    
//    for(int i = ini; i<=med; i++)
//        P[i-ini] = arr[i];
//    for(int i = med+1; i<=fin;i++)
//        Q[i-med-1] = arr[i];
//    
//    p = 0;
//    q = 0;
//    
//    
//    for(int i = ini; i<=fin; i++) {
//        if(P[p]<Q[q]) arr[i] = P[p++];
//        else arr[i] = Q[q++];
//    }
//    
//}
//
//void mergeSort(int *arr, int ini, int fin) {
//
//    if(ini == fin) return;
//    int med = (ini+fin)/2;
//    
//    mergeSort(arr, ini, med);
//    mergeSort(arr, med+1, fin);
//    
//    merge(arr, ini, med, fin);
//    
//}
//
//
//int busquedaBinaria( int *arr, int ini, int fin, int elemento) {
//    
//    //if(ini > fin) return -1;
//    if(ini == fin) {
//        if(arr[ini] == elemento) return ini;
//        else return -1;
//    }
//    int med = (ini+fin)/2;
//    
//    if(arr[med] == elemento) return med;
//    if(arr[med] > elemento) {
//        return busquedaBinaria( arr, ini, med, elemento);
//    }
//    if(arr[med] < elemento) {
//        return busquedaBinaria( arr, med+1, fin, elemento);
//    }
//}
//
//
//int cuentaCerosDerecha(int *arr, int ini, int fin, int cuenta) {
//    
//    if(ini>fin) return cuenta;
//    int med = (ini+fin)/2;
//    
//    if(arr[med] == 0)         
//        cuentaCerosDerecha(arr, ini, med-1, fin - med + 1 +cuenta);
//     else 
//        cuentaCerosDerecha(arr, med+1, fin, cuenta);
//    
//}
//
//int cuentaCerosIzq(int *arr, int ini, int fin, int cuenta) {
//    
//    if(ini>fin) return cuenta;
//    
//    int med = (ini+fin)/2;
//
//    if(arr[med] == 0) 
//        cuentaCerosIzq(arr, med+1, fin, med - ini + 1 + cuenta);
//    else 
//        cuentaCerosIzq(arr, ini, med-1, cuenta);
//    
//}
//
//

// {12, 19, 28, 32, 42, 61, 22, 10, 6}
int subeYBaja(int *arr, int ini, int fin) {
    
    if(ini == fin ) return arr[ini];
    
    int med = (ini + fin)/2;
    
    if(arr[med] > arr[med+1]) {
        subeYBaja(arr, ini, med);
    } else {
        subeYBaja(arr, med+1, fin);
    }
}
//
//
//void buscaSolo(int *arr, int ini, int fin) {
//    
//    if(ini > fin) return;
//    if(ini == fin) {
//        cout << arr[ini];
//        return;
//    }
//    
//    int med = (ini+fin)/2;
//    
//    if(med%2==0) { // si el med es par o impar
//        if(arr[med] == arr[med+1]) {
//            buscaSolo(arr, med+2, fin);
//        } else {
//            buscaSolo(arr, ini, med);
//        }
//    } else {
//        if(arr[med] == arr[med-1]) {
//            buscaSolo(arr, med+1, fin);
//        } else {
//            buscaSolo(arr, ini, med-1);
//        }
//    }
//    
//    
//}
//





void merge(int *arr, int ini, int med, int fin) {
    
    int p, q, long1, long2;
    
    long1 = med-ini + 1;
    long2 = fin -med;
    
    int P[long1+1];
    int Q[long2+1];
    P[long1] = INT_MAX;
    Q[long2] = INT_MAX;
    
    for(int i = ini; i<=med; i++) 
        P[i-ini] = arr[i];
    for(int i = med + 1; i<=fin; i++)
        Q[i-med-1] = arr[i];
    p = 0; q = 0;
    for(int i = ini; i<=fin; i++)
        if(P[p]<Q[q]) arr[i] = P[p++];
        else arr[i] = Q[q++];
    
}




void mergeSort(int *arr, int ini, int fin) {
    if(ini == fin) return;
    
    int med = (ini + fin)/2;
    
    mergeSort(arr, ini, med);
    mergeSort(arr, med+1, fin);
    
    merge(arr, ini, med, fin);
}

int busquedaBinaria(int *arr, int ini, int fin, int dato) {
    if(ini>dato) return -1;
    int med = (ini+fin)/2;
    if(arr[med] == dato) return med;
    if(arr[med]>dato) return busquedaBinaria(arr, ini, med, dato);
    if(arr[med]<dato) return busquedaBinaria(arr, med+1, fin, dato);
}


int cuentaCerosDerecha(int *arr, int ini, int fin, int cuenta) {
    
    if(ini > fin) return cuenta;
    int med = (ini+fin)/2;
    if(arr[med] == 0) { // me voy a la izquierda
        cuentaCerosDerecha(arr, ini, med-1, fin-med +1 +cuenta);
    } else {
        cuentaCerosDerecha(arr, med+1, fin, cuenta);
    }
}

//{0, 0, 0, 17, 15, 18, 18, 18, 12, 16
int cuentaCerosIzq(int *arr, int ini, int fin, int cuenta) {
    if(ini > fin) return cuenta;
    int med = (ini+fin)/2;
    if(arr[med] == 0) {
        cuentaCerosIzq(arr, med+1, fin, med-ini+1+cuenta);        
    } else {
        cuentaCerosIzq(arr, ini, med-1, cuenta);
    }
}


// {12, 19, 28, 32, 42, 61, 9, 3}
int subeYBaja(int *arr, int ini, int fin) {
    if(ini == fin) return arr[ini];
    
    int med = (ini+fin)/2;
    
    if(arr[med]<arr[med+1]){
        subeYBaja(arr, med+1, fin);
    } else {
        subeYBaja(arr, ini, med);
    }   
}

// {1,1,2,3,3,4,4,5,5};
void buscaSolo(int *arr, int ini, int fin) {
    
    if(ini == fin) {
        cout << arr[fin] << endl;
        return;
    }
    
    int med = (ini+fin)/2;
    
    if(med%2==0) {
        if(arr[med] == arr[med+1])
            buscaSolo(arr, med+2, fin);
        else
            buscaSolo(arr, ini, med);
    } else {
        if(arr[med] == arr[med-1])
            buscaSolo(arr, med+1, fin);
        else
            buscaSolo(arr, ini, med-1);
    }
    
}





int main(int argc, char** argv) {

    int arr[] = {15, 12, 10, 17, 15, 18, 18, 18, 12, 16};
    //int arr[] = {0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << n << endl;
    mergeSort(arr, 0, n-1);
    for(int i = 0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;
    cout << busquedaBinaria(arr, 0, n-1, 17); cout << endl;
//    
//    
//    //CUENTA CHEROS
    int arreglito1[] = {15, 3, 18, 18, 1, 16, 0, 0, 0, 0};
    int arreglito[] = {0, 0, 0, 4, 15, 18, 18, 18, 12, 16};
    n = sizeof(arreglito)/sizeof(arreglito[0]);
//    
    int cuenta = 0;
    cout << "Existen " << cuentaCerosDerecha(arreglito1, 0, n-1, cuenta) << " ceros derecha" << endl;;
    cout << "Existen " << cuentaCerosIzq(arreglito, 0, n-1, cuenta) << " ceros izquierda" << endl;
//    
//    
//    
    // SUBE Y BAJA    
    int arreglin[] = {12, 19, 28, 32, 42, 61, 9, 3};
    n = sizeof(arreglin)/sizeof(arreglin[0]);
    
    cout << "El mayor EN un arreglo sube y baja es " << subeYBaja(arreglin, 0, n-1); cout << endl << endl;
//    
//    
//    // BUSCAR SOLO
//    
    //int arrelitoSolitario[]={1,1,2,3,3,4,4,5,5};
    int arrelitoSolitario[]={1,1,2, 2,3,3,3,4,4,5,5};
    n = sizeof(arrelitoSolitario)/sizeof(arrelitoSolitario[0]);

    buscaSolo(arrelitoSolitario,0,n-1);
    
    
    return 0;
}

