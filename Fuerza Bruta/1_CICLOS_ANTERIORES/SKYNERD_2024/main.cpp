
#include <iostream>

using namespace std;

bool esSkyNerd() {
    
}


void skyNerd(int matriz[][7], int n, int fil, int col, int pos ) {
    
    if( col == n ) return;
    
    for(int i = 0; i<n; i++) {//verifico la columna
        if(matriz[i][col] != 0) {
            skyNerd(matriz, n, fil, col + 1, pos);
        } else { // Es candidato
            if(esSkyNerd() == true) {
                return;
        }
    }
    
    
    skyNerd(matriz, n, fil, col+1);
    
}




int main(int argc, char** argv) {
    int n = 7;
    int matriz[][7] = { {0, 10, 10, 10, 20, 10, 10},
                        {10, 0, 20, 30, 0, 20, 40},
                        {0, 0, 0, 0, 0, 100, 0},
                        {0, 0, 0, 0, 0, 80, 0},
                        {50, 10, 5, 10, 0, 100, 4},
                        {100, 0, 0, 0, 0, 0, 0}, 
                        {0, 0, 0, 0, 0, 0, 0}};
    int fila = 0, columna = 0;
    skyNerd(matriz, n, fil, col, pos);
    
    return 0;
}

