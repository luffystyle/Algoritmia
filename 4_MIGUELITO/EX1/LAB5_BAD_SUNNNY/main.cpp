

/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on October 18, 2024, 4:18 PM
 */

#include <iostream>
using namespace std;
#define N 5

int matriz[][N] = {{1, 1, 1, 0, 0}, 
                   {1, 1, 1, 0, 1}, 
                   {0, 0, 1, 0, 0}, 
                   {0, 1, 1, 1, 0}, 
                   {0, 0, 1, 0, 1} };


int buscaFamoso(int cand, int ini, int n) {
    if(ini == n) return cand;
    if(matriz[cand][ini]) buscaFamoso(ini, ini+1, n);
    else buscaFamoso(cand, ini+1, n);
}



int famoso( int n ) { 
    
    int id, cont1 = 0, cont2 = 0;
    id = buscaFamoso(0, 1, n);
    for(int i = 0; i<n; i++) {
        if(id != i) {
            cont1 += matriz[id][i];
            cont2 += matriz[i][id];
        }
    }
    if(cont1 == 0 && cont2 == n-1) return id;
    return -1;
}



int main(int argc, char** argv) {

    int n = N;
    cout << " El famoso tiene id es " << famoso(n);

    return 0;
}

