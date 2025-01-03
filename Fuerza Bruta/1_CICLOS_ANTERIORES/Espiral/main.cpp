/* 
 * File:   main.cpp
 * Author: Miguel Torres
 * Created on April 10, 2023, 10:19 AM
 */
#include <iostream>
#include <iomanip>
#define MAX 10
using namespace std;

void carga( int x, int y, int n, int m, int alma[][MAX]) { 
    
    if( x>=n || y>=m ) return;
    //por el centro
    if( x== n-1 and y == m-1) cout<< alma[x][y];
    
    for( int i = y; i<m-1; i++)  cout<< alma[x][i]<< " " ;
    for( int i = x; i<n-1; i++)  cout<< alma[i][m-1]<< " ";
    for( int i = m-1; i>y; i--)  cout<< alma[n-1][i]<< " ";
    for( int i = n-1; i>x; i--)   cout<< alma[i][y]<<" ";
    carga(x+1, y+1, n-1, m-1, alma);
}

int main(int argc, char** argv) {

    int alma[MAX][MAX];
    int n = 4, m = 5, cont = 1;
    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            alma[i][j] = cont++;
        }
    }
    carga(0, 0, n, m, alma);

    return 0;
}

