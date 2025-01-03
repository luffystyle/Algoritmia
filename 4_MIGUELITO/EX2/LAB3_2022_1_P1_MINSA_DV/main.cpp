
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 3, 2024, 10:10 AM
 */

#include <iostream>
#include <algorithm>

using namespace std;

int mezklita(int *arr, int ini, int med, int fin) {
    int i, cizq = 0, cder = 0;
    
    
    // Evaluo la la mita de la izquierda
    for(i = med; i>=ini; i--) {
        if(arr[i] > arr[i-1]) cizq++;
        else break; // SINO ES CONSECUTIVO HAGO BREAK
    }
    for(i = med+1; i<=fin; i++) {
        if(arr[i+1] > arr[i]) cder++;
        else break; // SINO ES CONSECUTIVO HAGO BREAK
    }
    return cder+cizq+1; // LA CONECION ENTRE NUMERO, PERO LE SUMAMOS 1 PORQUE TAMBIÉN CONTAMOS AL PROPIO NÚMERO
}



int intervaloMaximoContagiador(int *arreglo, int ini, int fin) {
    
    int med, izq, der, centro;
    if(ini == fin) return 1; // Es uno porque maximo es un valor de subido y es él mismo
    
    med = (ini+fin)/2;
    
    izq = intervaloMaximoContagiador(arreglo, ini, med);
    der = intervaloMaximoContagiador(arreglo, med+1, fin);
    centro = mezklita(arreglo, ini, med, fin); //ESTA CENTRO EVLUA POR LOS MENOS DOS ELEMENTOS DEL ARREGLO
    // en realidad aqui está la lógica de suma en el centro
    
    return max(izq, max(der, centro));
}


int main(int argc, char** argv) {

    int arreglo[] = {10, 20, 15, 10, 12, 10, 13, 18};
    //int arreglo[] = {7, 2, 9, 10, 16, 10, 13, 8, 2, 10};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    
    
    cout << intervaloMaximoContagiador(arreglo, 0, n-1);
    
    
    return 0;
}

