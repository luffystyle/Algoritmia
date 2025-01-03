#include <iostream>
#include <iomanip>
using namespace std;

int merge( int ini, int fin, int med, int arr[]) {
    int cizq = 0, cder = 0, cont = 1;
    
    for( int i = med; i>ini; i--) {
        if( arr[i] > arr[i-1]) cont++;
        else break;
    }
    for( int i = med; i>ini; i++) {
        if( arr[i+1] > arr[i]) cont++;
        else break;        
    }
    return cont;
}

int max(int a,  int b) {
    if( a<b) return b;
    return a;
}

int max2( int a, int b, int c) {
    return (max(max(a,b), c));
}

int maxIntervalo(int ini, int fin, int arr[]) {
    
    int izq, der, cent;
    
    if( ini == fin) return 1;
    
    int med = (ini + fin) / 2;
    izq = maxIntervalo(ini, med, arr);
    der = maxIntervalo(med+1, fin, arr);
    
    cent = merge(ini, fin, med, arr);
}

int main(int argc, char** argv) {

    int n = 8;
    int arr[] = {10, 20, 25, 30, 40, 10, 13, 18};
    
    cout << maxIntervalo(0, n-1, arr);
    
    return 0;
}

