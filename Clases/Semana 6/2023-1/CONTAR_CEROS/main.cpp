
#include <iostream>
#include <iomanip>
using namespace std;

int cuentaCeros(int ini, int fin, int arr[], int cont) {
    
    //if( ini == fin) return cont + arr[ini];
    
    
    if( ini > fin) return cont;
    
    int med = (fin + ini)/2;
    
    if(arr[med] == 0) cuentaCeros(ini, med-1, arr, fin - med + cont + 1);
    else
        cuentaCeros(med+1, fin, arr, cont); // hassta aqui no tengo 0 porque evaluo desde la izq a derecha
    
}



int main(int argc, char** argv) {
    int n = 7;
    //int arr[] = {0, 0, 0, 0, 0, 0, 0};
    int arr[] = {1, 1, 1, 1, 1, 1, 1};
    int cont = 0;
    
    cout << cuentaCeros(0, n-1, arr, cont) ;

    return 0;
}

