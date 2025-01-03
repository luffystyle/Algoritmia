/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on September 13, 2024, 3:51 PM
 */

#include <iostream>
#include <cmath>

using namespace std;



void cargaBinaria(int cromosoma[], int numero, int n) {
    int i;
    for(i = 0; i<n; i++) cromosoma[i] = 0;
    i=0;
    while(numero>0){
        cromosoma[i] = numero%4;
        numero/=4;
        i++;
    }
}




int main(int argc, char** argv) {

    int armas[][2] = {{60, 3}, 
                      {80, 1}, 
                      {38, 2}, 
                      {25, 2}, 
                      {49, 2}, 
                      {57, 1}, 
                      {68, 3}, 
                      {35, 2}, 
                      {62, 2}, 
                      {42, 2}, 
                      {36, 1}, 
                      {54, 3}};
    
    int cromosoma[12], n = 12;
    int combinaciones = (int)pow(4, 12);
    
    for(int i = 0; i<combinaciones; i++) {
        cargaBinaria(cromosoma, i, n);
        for(int j = 0; j<12; j++) cout << cromosoma[j] << " ";
        cout <<endl;
    }
    
    
    return 0;
}

