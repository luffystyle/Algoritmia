/* 
 * File:   main.cpp
 * Author: Miguel Torres
 * Created on April 10, 2023, 11:02 AM
 */
#include <iostream>
#include <iomanip>
using namespace std;

int mapa[][6] = { {0, 0, 0, 1, 0, 1},
                  {0, 0, 1, 0, 0, 0},
                  {0, 1, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0},
                  {0, 1, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0}
};

int busca(int x, int y, int xm, int ym, int x1, int y1, int n, int m) {
    
    int cont = 0;
    
    if( x>= n or y>=n or x<0 or y<0) return 0;
    //No debo olvidar la posicion de caida
    
    if(mapa[x][y] == 1 and x1 == 0 and y1 == 0) cont++;
    
    if( x1==0) {
        for(int i=x+1; i<n; i++) cont += mapa[i][y];
        for(int i=0; i<x; i++) cont += mapa[i][y];
    }
    if( y1 == 0) {
        for(int i = y+1; i<m; i++) cont += mapa[x][i];
        for(int i = 0; i<y; i++) cont += mapa[x][i];
    }
    cont += busca(x + xm, y+ ym, xm, ym, xm, ym, n, m);
    
    return cont;
}

int main(int argc, char** argv) {

    int n = 6, m = 6;
    cout<< busca(3, 2, 0, 1, 0, 0, n, m) <<endl;
    
    return 0;
}
