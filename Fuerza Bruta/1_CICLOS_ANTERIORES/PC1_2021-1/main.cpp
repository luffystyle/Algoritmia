/* 
 * File:   main.cpp
 * Author: Miguel Torres
 * Created on April 20, 2023, 6:24 PM
 */
#include <iostream>
#include <cmath>
#define CANT 12
using namespace std;

void cargaBin(int cromo[], int numero) {
    int i, residuo;
    for( i = 0; i < CANT; i++) cromo[i] = 0;
    i = 0;
    while(numero != 0) {
        residuo = numero %2;
        numero = numero/2;
        cromo[i] = residuo;
        i++;
    }
}



int main(int argc, char** argv) {

    int n = (int)pow(2, 12);
    int paq[] = {2, 5, 6, 10, 7, 8, 15, 3, 11, 9, 6, 4};
    int cromo[n];
    int bandera1 , bandera2, bandera3, cant ;
    
    int peso, pesoMax = 20;
    
    for( int i = 0; i<n; i++) {
        cargaBin(cromo, i);
        peso = 0;
        cant = 0;
        for(int j = 0; j < CANT; j++) {
            if( cromo[j] == 1) {
                peso += cromo[j]*paq[j]; 
                cant++;
            }
            
        }
        if(pesoMax == peso and cant==5) {
            bandera1 = 0, bandera2 = 0, bandera3 = 0;
            for(int j = 0; j < CANT; j++){
                if(cromo[j] == 1) {
                    
                    if( j/4 == 0) {
                        if(bandera1 == 0) {
                            cout<<"Bahia 1: ";
                            bandera1 = 1;
                        }
                        cout << paq[j] << " ";
                    } else if( j/4 == 1) {
                        if(bandera2 == 0) {
                            cout<<" Bahia 2: ";
                            bandera1 = 1;
                        }
                        cout << paq[j] << " ";
                    } else if(j/4 == 2){
                        if(bandera3 == 0) {
                            cout<<" Bahia 3: ";
                            bandera1 = 1;
                        }
                        cout << paq[j] << " ";
                    }
                }
                
            }
            cout<<endl;
        }
        //cout << endl;
    }




    return 0;
}

