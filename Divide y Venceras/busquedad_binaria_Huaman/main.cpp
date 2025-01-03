
#include <iostream>
#include <iomanip>

using namespace std;

int busqueda_binaria(int A[], int k, int ini, int fin) {
    
    if(ini == fin) {
        if(A[ini] == k) return ini;
        else return -1;
    }
    
    int medio;
    medio = (ini + fin)/2;
    
    if(A[medio] == k) {
        return medio;
    } else if(A[medio] < k) {
        return busqueda_binaria(A, k, medio+1, fin);
    } else { // por descarte es A[medio]>k
        return busqueda_binaria(A, k, ini, medio-1);
    }   
}

int main(int argc, char** argv) {

    int A[]={1,5,7,9,12,15,17,20};
    int n=8;
    int k=20;

    int posicion=busqueda_binaria(A,k,0,n-1);
    if (posicion==-1)
        cout<<"El elemento no se encuentra."<<endl;
    else 
        cout<<"El elemento se encuentra en la posición: "<<posicion<<endl;

    return 0;
}
