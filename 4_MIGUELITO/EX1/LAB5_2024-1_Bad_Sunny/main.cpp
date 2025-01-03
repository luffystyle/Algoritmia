// HECHO POR CUEVA
/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on October 7, 2024, 10:21 AM
 */

#include <iostream>
using namespace std;
#define N 5

//Esta matriz en ese laboratorio debió crearlo el mismo alumno. No te lo dan
int matriz[N][N] = { {1, 1, 1, 0, 0},
                     {1, 1, 1, 0, 1},
                     {0, 0, 1, 0, 0},
                     {0, 1, 1, 1, 0},
                     {0, 0, 1, 0, 1}  
                   };

int conoce(int a, int b) {
    if(matriz[a][b]) return 1;
    return 0;
}

int buscaFamoso(int cand, int ini, int n) { //Uno es candidato y otro tbm es pero como vas a ir sumando le ponemos ini
    if( ini == n) return cand;
    if(conoce(cand, ini))
        buscaFamoso(ini, ini + 1, n);
    else 
        buscaFamoso(cand, ini + 1, n);
}

int famoso(int n) {
    
    int id, cont1 = 0, cont2 = 0;
    id = buscaFamoso(0, 1, n); // Los candidatos inciales que son 0 y 1. Porque es un vs. Sería 0 vs 1. Es nuestra entrada inicial
    
    for( int i = 0; i<n; i++) {
        if(id != i){
            cont1 += conoce(id, i);
            cont2 += conoce(i, id);
        }
    }   
    if(cont1 == 0 and cont2 == n - 1) return id;
    return -1;
}

int main(int argc, char** argv) {

    int n = N;
    cout << "El famoso tiene el id = " << famoso(n);
    
    return 0;
}