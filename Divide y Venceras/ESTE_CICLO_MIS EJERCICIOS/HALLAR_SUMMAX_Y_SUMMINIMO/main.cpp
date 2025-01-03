
/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on November 1, 2024, 10:16 PM
 */

#include <iostream>
#include <climits>

using namespace std;

int sumaCentro(int *arr, int ini, int med, int fin) {
    
    int maxIzq = -INT_MAX, maxDer = -INT_MAX;
    int sumIzq=0, sumDer=0;
    
    for(int i = med; i>=ini; i--) {
        sumIzq += arr[i];
        if(maxIzq < sumIzq) {
            maxIzq = sumIzq;
        }
    }
    
    for(int i = med+1; i<=fin; i++) {
        sumDer += arr[i];
        if(maxDer < sumDer) {
            maxDer = sumDer;
        }
    }
    return maxIzq + maxDer;
}






 int sumaMaxima(int *arr, int ini, int fin) {
    
    if(ini == fin) return arr[ini];
    
    int med = (ini + fin)/2;
    
    int sumIzq = sumaMaxima(arr, ini, med);
    int sumDer = sumaMaxima(arr, med + 1, fin);
    int sumCentro = sumaCentro(arr, ini, med, fin);
    
    return max(max(sumIzq, sumDer), sumCentro);
    
}






int sumaCentroMinimo(int *arr, int ini, int med, int fin) {
    
    int minIzq = INT_MAX, minDer = INT_MAX;
    int sumaIzq = 0, sumaDer = 0;
    
    for(int i = med; i>=ini; i--) {
        sumaIzq += arr[i];
        if(minIzq > sumaIzq) minIzq = sumaIzq;
    }
    for(int i = med+1; i<=fin; i++) {
        sumaDer += arr[i];
        if(minDer>sumaDer) minDer = sumaDer;
    }
    return minDer+minIzq;
}




int sumaMinima(int *arr, int ini, int fin) {
    
    if(ini == fin) return arr[ini];
    
    int med = (ini + fin)/2;
    
    int minimoIzq = sumaMinima(arr, ini, med);
    int minimoDer = sumaMinima(arr, med+1, fin);
    int minimoCen = sumaCentroMinimo(arr, ini, med, fin);
    
    return min(min(minimoCen, minimoDer), minimoIzq);
}



int main(int argc, char** argv) {

    
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    //int arr[] = {2, 5, -6, 2, 3, -1, -5, 6};
    
    int n = 8;
    
   cout << sumaMaxima(arr, 0, n-1) << endl;
   //cout << sumaCentro(arr, 0, (n-1)/2, n-1) << endl;
   
    //cout << sumaMinima(arr, 0, n-1) << endl;
    
    return 0;
}

