
#include <iostream>
#include <iomanip>
using namespace std;

void buscarSolitario( int ini, int fin, int arr[]) {
    
    if( ini == fin) {
        cout << "El reusltado es: " << arr[ini] << endl;
        return ;
    }    
    
    int med = (fin + ini)/2;
    
    if( med%2 == 0) {
        if( arr[med] == arr[med+1]) buscarSolitario(med+2, fin, arr);
        else buscarSolitario(ini, med, arr);   
    }else {
        if( arr[med] == arr[med-1]) buscarSolitario(med+1, fin, arr);
        else  buscarSolitario(ini, med-1, arr);        
    }
}

int main(int argc, char** argv) {

    int n = 7;
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    buscarSolitario(0, n-1, arr);

    return 0;
}

