
#include <iostream>
#include <iomanip>
using namespace std;

int mayorNumero(int arreglo[], int n) {
    
    int mashor, resto;
    if( n == 1 ) return arreglo[n-1];
    mashor = arreglo[n-1];// el mayor es 64
    resto = mayorNumero(arreglo, n - 1);
   
    if(mashor<=resto ){
        mashor = resto;
    }
    return mashor;

}

int main(int argc, char** argv) {
  
    int cantidad_elementos = 10, mayor;
    int arreglo[cantidad_elementos] = {5, 32, 60, 22, 15, 66, 80, 1023, 443, 64};
    
    mayor = mayorNumero(arreglo, cantidad_elementos);
    cout<< mayor << endl;

    return 0;
}

