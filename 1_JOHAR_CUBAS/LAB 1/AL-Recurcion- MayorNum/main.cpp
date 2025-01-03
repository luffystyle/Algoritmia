/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int buscarMayor(int *arr,int n, int mayor, int inicio){
    //condicion base
    if(inicio==n)return mayor;
    
    if(arr[inicio] > mayor){//formula para ayar el mayor
        mayor = arr[inicio];
    }
    
    return buscarMayor(arr,n,mayor,inicio+1);
}

int buscarArreglo(int *arr,int n,int numBuscado,int inicio){
    //condicion base:
    if(inicio == n) return 0;
    if(arr[inicio] == numBuscado){
        return inicio+1;
    }
    
    return buscarArreglo(arr,n,numBuscado,inicio+1);
}

int main(int argc, char** argv) {

    int arr[5]={7,20,19,8,6};
    int n =5;
    int numMayorEncontrado;
    numMayorEncontrado= buscarMayor(arr,n,arr[0],0);
    cout<<"El numero mayor es : "<<numMayorEncontrado<<endl;
    cout<<buscarArreglo(arr,n,7,0);

    return 0;
}

