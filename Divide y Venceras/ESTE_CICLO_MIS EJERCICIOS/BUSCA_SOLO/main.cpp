/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on October 29, 2024, 12:51 AM
 */

// BUSCA SOLO
#include <iostream>

using namespace std;


void buscasolo(int *arr, int ini, int fin) {
    
    
    if(ini > fin) return;
    if( ini == fin) {
        cout << "El solitario es: " << arr[ini] << endl;
        return;
    }    
    
    int med = (ini + fin)/2;
    
    if(med%2==0) { // Es multiplo de 2
        if(arr[med] == arr[med + 1]) buscasolo(arr, med +2, fin);
        else buscasolo(arr, ini, med);
        
    } else {
        if(arr[med] == arr[med-1]) buscasolo(arr, med + 1, fin);
        else buscasolo(arr, ini, med - 1);
    }
    
    
}



int main(int argc, char** argv) {
    
    
    
    int arr[]={1,1,2,3,3,4,4,5,5};
    
    int n= sizeof(arr)/sizeof(arr[0]);
    
    buscasolo(arr,0,n-1);
    
    return 0;
}

