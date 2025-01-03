

/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 3, 2024, 4:16 PM
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define N 10

int hallarMaximo(int *arr, int ini, int fin) { // OLOG(N)
    int izq, der, med;
    
    if(ini == fin) return arr[ini];
    
    med = (ini+fin)/2;
    izq = hallarMaximo(arr, ini, med);
    der = hallarMaximo(arr, med + 1, fin);
    return max(izq, der); // AQUI ESTÁ LA LOGICA
}


int contarMaximos(int *arr, int ini, int fin, int maximoValor) {
    
    int izq, med, der;
    
    if(ini == fin) {
        if(arr[ini] == maximoValor) return 1; // AQUI ESTÁ LA LOGICA
        else return 0;
    }
    
    med = (ini+fin)/2;
    izq = contarMaximos(arr, ini, med, maximoValor);
    der = contarMaximos(arr, med+1, fin, maximoValor);
   
    return izq + der;
}



int main(int argc, char** argv) {

    int n;
//    cin >> n;
//
//    cout << n << endl;
    
    int matriz[][10] = {{15, 12, 10, 17, 15, 18, 18, 18, 12, 16}, 
                       {14, 17, 17, 17, 17, 12, 14, 14, 12, 12}, 
                       {16, 18, 20, 20, 15, 18, 16, 18, 18, 16}};
    
    
//    int arr[] = {15, 12, 10, 17, 15, 18, 18, 18, 12, 16};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    
//    int maximoValor = hallarMaximo(arr,0, n-1); // log(n)
//    cout <<  maximoValor << endl;// OLog(n)
//    
//    
//    cout << contarMaximos(arr, 0, n-1, maximoValor);// log(n)
    
    
    for(int i = 0; i<3; i++) { // CADA EMPRESA ES N
        int maximo = hallarMaximo(matriz[i],0, 9); // Olog(m)     
        cout << maximo << endl;
    }
    // ENTONCES, EN TOTAL si estaría cumpliendo con N*LOG(M)
    
    
    return 0;
}

