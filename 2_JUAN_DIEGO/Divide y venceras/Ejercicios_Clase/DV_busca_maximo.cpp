#include <iostream>

using namespace std;

int busca_maximo(int arr[],int posicion_inicial,int posicion_final){
    
    int posicion_medio = (posicion_inicial+posicion_final)/2;
    if(posicion_inicial>=posicion_final) return arr[posicion_inicial];
    
    if(arr[posicion_medio]>arr[posicion_medio+1])
        return busca_maximo(arr,posicion_inicial,posicion_medio);
    else
        return busca_maximo(arr,posicion_medio+1,posicion_final);
}

int main() {
    int arreglo[]={12,24,15,12,11,10};
    int n=6;
    
    cout << busca_maximo (arreglo,0,n-1);

    return 0;
}

