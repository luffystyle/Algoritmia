/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 3, 2024, 7:13 PM
 */

#include <iostream>


using namespace std;


int subeBaja(int *arr, int ini, int fin) {
    
    if(ini == fin) return arr[ini];
    int med;
    
    med = (ini+fin)/2;
    
    if(arr[med]>arr[med+1]) {
        return subeBaja(arr, ini, med);
    }else {
        return subeBaja(arr, med+1, fin);
    } 
}

int buscarSolo(int *arr, int ini, int fin) {
    
    if(ini == fin) {
        return arr[ini];
    }
    if(ini>fin) return -1;
    int med = (ini+fin)/2;
    if(med%2==0) { // que sea par
        if(arr[med] == arr[med-1])
            return buscarSolo(arr, med+1, fin);
        else
            return buscarSolo(arr, ini, med);
    } else {
        if(arr[med] == arr[med+1])
            return buscarSolo(arr, med+2, fin);
        else
            return buscarSolo(arr, ini, med);
    }
}


int main(int argc, char** argv) {

    int arr[] = {0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    //int arr[] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int posradicion;
    
    for(int i = 0; i<n; i++) {
        if(arr[i]>0) {
            posradicion = i;
            break;
        }
    }
    
    cout << "La radiación empieza a " << posradicion << "km. Potencia máxima de ";
    cout << buscarSolo(arr, posradicion, n-1) <<" megatones.";
    
    //cout << subeBaja(arr, posradicion, n-1) <<" megatones.";
    
    return 0;
}

