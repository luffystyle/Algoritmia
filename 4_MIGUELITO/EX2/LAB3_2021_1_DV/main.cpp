
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on December 3, 2024, 11:11 AM
 */

#include <iostream>

using namespace std;

int buscarEmpresa(int *dia, int ini, int fin, int elemento) {
    
    
    int medio = (ini+fin)/2;
    
    
    
    
}



void solucionDeAcciones(int valoresAcciones[6][7], int ibm) {
    
    double iba;
    
    for(int i = 0; i<6; i++) {
        iba = 0.0;
        for(int k = 0; k<7; k++) {
            iba += valoresAcciones[i][k];
        }
        iba = iba/7;
        if(iba<=ibm) {
            
        } else {
            
        }
    }
    
    
    
}


int main(int argc, char** argv) {

    int C = 7, T = 6;
    int valoresAcciones[6][7] = {{8, 4, 5, 6, 7, 1, 2}, 
                                 {3, 4, 5, 7, 1, 2, 6}, 
                                 {5, 6, 5, 2, 1, 6, 8}, 
                                 {3, 4, 5, 6, 2, 1, 9}, 
                                 {3, 4, 5, 4, 5, 3, 2}, 
                                 {3, 4, 4, 8, 9, 7, 6} };
    
    double ibm = 4.2;
    
    solucionDeAcciones(valoresAcciones, ibm);
    
    
    return 0;
}

